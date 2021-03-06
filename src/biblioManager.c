#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "tools.h"
#include "export.h"

char PATH_BIB[35] = "out/start.bib"; // chemin vers le .bib
char PATH_ALL_DOC[35] = "data/bibTeX/all.type"; // chemin vers all.type (fichier ou se trouve toute les infos des document bibtex)

char *typeDoc,
     fields[20][50], // les champs du document
     values[20][512] // les valeurs des champs
     = {"\0"};

int nbfields = 0; // le nombre de champs

int isTypeDocumentExist(char *type){
    FILE* file;
    char  line[256] = {"\0"}, *doc;
    int exist = 0;

    doc = strlw(type);

    file = fopen(PATH_ALL_DOC, "r");
    while (fgets(line, sizeof(line), file)){
        removeLnBreak(line);
        if(strcmp(doc, line) == 0)
           exist = 1;
    }
    fclose(file);

    return exist;
}

void setfields(){
    FILE* file;
    char  absolutePath[130],
          line[50];
   
    //on récupère le chemin absolu de la fiche type du document
    strcpy(absolutePath, getDocumentTypePath(typeDoc));

    //on récupère les champs à remplir du document
    file = fopen(absolutePath, "r");
    while (fgets(line, sizeof(line), file)) {
        removeLnBreak(line);
        strcpy(fields[nbfields],line);
        nbfields++;
    }
    fclose(file);
}

void setvalues(){
    char temp[512];

    for (int j = 0; j < nbfields; j++) // on propose à l'utilisateur de saisir une valeur pour chaque champ du document 
    {
       printf("%s : ", fields[j]);
       scanf("%512[^\n]%*c",temp); //permet de prendre en compte les espaces de la chaînes de caractères
       removeLnBreak(temp);
       strcpy(values[j], temp);
    }
}

int findDocument(char *name){
    int res = 0;

    static char toFind[300];

    strcat(toFind, "{");
    strcat(toFind, name);
    strcat(toFind, ",");

    if(findstr(toFind, PATH_BIB) == 1){
        res = 1;
    }

    return res;
}

void writeInDocument(){
    if(findDocument(values[0]) == 0){ // si le document n'existe pas déjà
        FILE* file;
        char *type = typeDoc;

        file = fopen(PATH_BIB, "a");

        fprintf(file, "\n");
        fprintf(file, "@%s{%s,\n", type, values[0]); // écriture de la premier ligne du document à insérer dans le .bib
        for(int i = 1; i < nbfields; i++){ // écriture des caractéristiques du document avec les valeurs saisie par l'utilisateur
            fprintf(file, "%s = {%s},\n", fields[i], values[i]);
        }
        fprintf(file, "}\n");

        fclose(file);
    }else{
     printf("*** document \"%s\" already exists in the database ***\n", values[0]);
     exit(1);
    }
}

void addDocument(char *type){
    typeDoc = type;
    setfields();
    setvalues();
    writeInDocument();
    addCiteLatex(values[0]);
}

void deleteDocument(char *name){
    pid_t pid = fork(); // fork necessaire sinon impossible de continuer d'exécuter le programme après le execl()
	if ( pid == 0 )
		execl("script/./delete.sh", "script/./delete.sh", (char*) PATH_BIB, name, NULL);
	wait((int*) 1);
    deleteCiteLatex(name);
}

void updateDocument(char *name, char *type){
   deleteDocument(name);
   addDocument(type);
}

void listDocuments(){
    FILE* file;
    char  line[256];

    file = fopen("data/bibtexkey.txt", "r");
    while (fgets(line, sizeof(line), file)) {
       printf(line);
    }
    fclose(file);
}

void exportBiblio(char *ext){
    if(strcmp(ext, "pdf") == 0) // si l'extension est pdf 
    {
        createLatexDoc();
        buildLatexDoc();
    }
    else if(strcmp(ext, "txt") == 0) // sinon si l'extension est txt
    {
        createLatexDoc();
        buildLatexDoc();
        execl("script/./convert.sh", "script/./convert.sh", NULL);
    }
}
