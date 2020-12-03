#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

int isDocumentExist(char *doc){
    return 0;
}

void input(char *type){

    //on récupère le chemin absolu de la fiche type du document
    char absolutePath[130];
    strcpy(absolutePath, getDocumentTypePath(type));

    FILE* file = fopen(absolutePath, "r");
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line); 
    }
    printf("\n");

    fclose(file);

}

void addDocument(char *type){
    
    FILE* file = fopen("data/bibTeX/all.type", "r");
    char line[256] = {"\0"}; // field[20][15] 20 lignes de 15 caractères maximum
    char *t = strlw(type);
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
        printError(strcat(type," is an invalid document type."));
    }
}
