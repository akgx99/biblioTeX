#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

char *typeDoc;

int isDocumentExist(char *doc){
    return 0;
}

void input(){

    FILE* file;
    char  absolutePath[130],
          line[256], 
          field[20][15]= {"\0"}; // field[20][15] 20 lignes de 15 caractères maximum
    int i = 0;

    //on récupère le chemin absolu de la fiche type du document
    strcpy(absolutePath, getDocumentTypePath(typeDoc));

    //on récupère les champs à remplir du document
    file = fopen(absolutePath, "r");
    while (fgets(line, sizeof(line), file)) {
        removeLnBreak(line);
        strcpy(field[i],line);
        i++;
    }
    fclose(file);

    for (int j = 0; j < i; j++)
    {
       printf("%s :\n", field[j]);
    }
}

void addDocument(char *type){

    typeDoc = type;

    FILE* file = fopen("data/bibTeX/all.type", "r");
    char line[256] = {"\0"}; // field[20][15] 20 lignes de 15 caractères maximum
    char *t = strlw(typeDoc);
    int exist = 0;

    while (fgets(line, sizeof(line), file)){
        removeLnBreak(line);
        if(strcmp(t, line) == 0)
           exist = 1;
    }
    fclose(file);

    if (exist == 1){
        printf("*** Ajout d'un document %s ***\n", t);
        input(t);
    }
    else{
        printError(strcat(typeDoc," is an invalid document type."));
    }
}
