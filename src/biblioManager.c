#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

int isDocumentExist(char *doc){
    return 0;
}

void dataEntriesDocument(char *type){

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

    char *types[8] = {"book","article", "incollection", "inproceedings", "misc", "standard", "techreport", "these"};
    char *t = strlw(type);

    printf("*** Ajout d'un document %s ***\n", t);
    
    if (strcmp(t, types[0]) == 0) //book
    {
        dataEntriesDocument(t);
    } else{
        printError(strcat(type," is an invalid document type."));
    }
}
