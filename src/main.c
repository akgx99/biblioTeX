#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "biblioManager.h"

void printHelp(void) {
   system("cat info.app");
}

void printError(char *errStr){
    printf("Error : %s\n", errStr);
    printf("Usage : ./bibTex -help\n");
}

int main(int argc, char *argv[])
{   

    //vérification du bon nombre d'argument
    if(argc < 2 || argc > 3){
        printError("Number of argument invalid");
        return EXIT_FAILURE;
    }

    //-h -help
    if( strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0) {
        printHelp();
        return EXIT_SUCCESS;
    }

    //-add
     if( strcmp(argv[1], "-add") == 0) {
        
        return EXIT_SUCCESS;
    }

    //-delete <document>
     if( strcmp(argv[1], "-delete") == 0 && isDocumentExist(argv[2])) {
        
        return EXIT_SUCCESS;
    }
    else if(!isDocumentExist(argv[2])){
        char *err = strcat(argv[2], " document to be deleted does not exist in the database.");;
        printError(err);
        return EXIT_FAILURE;
    }
}   