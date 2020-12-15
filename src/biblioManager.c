#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tools.h"

char PATH_BIB[35] = "out/start.bib"; // chemin vers le .bib
char PATH_ALL_DOC[35] = "data/bibTeX/all.type"; // chemin vers all.type (fichier ou se trouve toute les infos des document bibtex)

char *typeDoc,
     fields[20][50], // les champs du document
     values[20][512] // les valeurs des champs
     = {"\0"};

int nbfields = 0; // le nombre de champs

int isDocumentExist(){
    FILE* file;
    char  line[256] = {"\0"};
    int exist = 0;

    typeDoc = strlw(typeDoc);

    file = fopen(PATH_ALL_DOC, "r");
    while (fgets(line, sizeof(line), file)){
        removeLnBreak(line);
        if(strcmp(typeDoc, line) == 0)
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

void writeInDocument(){
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
}

void addDocument(char *type){

    typeDoc = type;

    if (isDocumentExist() == 1){ // le type de document saisi existe
        printf("*** Ajout d'un document de type %s ***\n", typeDoc);
        setfields();
        setvalues();
        writeInDocument();
    }
    else{ // il n'existe pas
        printError(strcat(typeDoc," is an invalid document type."));
    }
}

void find(char *name){

    static char toFind[300];

    strcat(toFind, "{");
    strcat(toFind, name);
    strcat(toFind, ",");

    if(findstr(toFind, PATH_BIB) == 1){
        printf("Le document \"%s\" existe dans la base.\n", name);
    }
    else{
         printf("Le document \"%s\" n'existe pas dans la base.\n", name);
    }
}
