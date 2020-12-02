#include <string.h>
#include <stdio.h>
#include "tools.h"

int isDocumentExist(char *doc){
    return 0;
}

void addDocument(char *type){

    char *types[8] = {"book","article", "incollection", "inproceedings", "misc", "standard", "techreport", "these"};
    char *t = strlw(type);

    printf("*** Ajout d'un document %s ***\n", t);
    
    if (strcmp(t, types[0]) == 0) //book
    {
          printf("Test réussi ! Si ! Si !\n");
    } else{
        printError(strcat(type," is an invalid document type."));
    }
}