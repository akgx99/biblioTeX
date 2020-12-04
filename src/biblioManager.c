#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tools.h"

char *typeDoc,
     field[20][15], // les champs du document
     value[20][50] // les valeurs des champs
     = {"\0"};
int nbField = 0; // le nombre de champs

int isDocumentExist(char *doc){
    return 0;
}

void setField(){
    FILE* file;
    char  absolutePath[130],
          line[256];
   
    //on récupère le chemin absolu de la fiche type du document
    strcpy(absolutePath, getDocumentTypePath(typeDoc));

    //on récupère les champs à remplir du document
    file = fopen(absolutePath, "r");
    while (fgets(line, sizeof(line), file)) {
        removeLnBreak(line);
        strcpy(field[nbField],line);
        nbField++;
    }
    fclose(file);
}

void input(){
    char *temp = typeDoc;

    for (int j = 0; j < nbField; j++) // on propose à l'utilisateur de saisir une valeur pour chaque champ du document 
    {
       printf("%s : ", field[j]);
       scanf("%s", temp);
       removeLnBreak(temp);
       strcpy(value[j], temp);
    }
}

void addDocument(char *type){

    typeDoc = type;

    FILE* file = fopen("data/bibTeX/all.type", "r");
    char line[256] = {"\0"};
    char *t = strlw(typeDoc);
    int exist = 0;

    while (fgets(line, sizeof(line), file)){
        removeLnBreak(line);
        if(strcmp(t, line) == 0)
           exist = 1;
    }
    fclose(file);

    if (exist == 1){ // le type de document saisi existe
        printf("*** Ajout d'un document %s ***\n", t);
        setField();
        input(t);
    }
    else{
        printError(strcat(typeDoc," is an invalid document type."));
    }
}
