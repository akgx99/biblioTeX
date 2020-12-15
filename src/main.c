#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "biblioManager.h"
#include "export.h"
#include "tools.h"

int main(int argc, char *argv[]){   

    //vérification du bon nombre d'argument
    if(argc < 2 || argc > 4){

        printError("Number of argument invalid");
        return EXIT_FAILURE;
    }
    if( strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0 || strcmp(argv[1], "--help") == 0) {  //-h -help --help

        printHelp();
        return EXIT_SUCCESS;
    }
    else if(strcmp(argv[1], "-add") == 0) {  //-add <type

        if (isTypeDocumentExist(argv[2]) == 1){ // le type de document saisi existe
            printf("*** Ajout d'un document de type %s ***\n", argv[2]);
            addDocument(argv[2]);
            printf("*** Votre document à bien été ajouté à la base ! ***\n");
            return EXIT_SUCCESS;

        }else{ // il n'existe pas
            printError(strcat(argv[2]," is an invalid document type."));
            return EXIT_FAILURE;
        }
    }
    else if(strcmp(argv[1], "-delete") == 0) {  //-delete <name>

        if (0 == findDocument(argv[2]))
        {
            char *err = strcat(argv[2], " document to be deleted does not exist in the database.");
            printError(err);
            return EXIT_FAILURE;
        }else {
            deleteDocument(argv[2]);
            return EXIT_SUCCESS;
        }
    }
    else if(strcmp(argv[1], "-export") == 0) { //-export <type>
        
         if(strcmp(argv[2], "pdf") == 0 || strcmp(argv[2], "txt") == 0){
            exportBiblio(argv[2]);
            return EXIT_SUCCESS;
        }else{
            char *err = strcat(argv[2], ", invalid document extension : pdf or txt only");
            printError(err);
            return EXIT_FAILURE;
        }
    }
    else if(strcmp(argv[1], "-find") == 0) { //-find <name>

         if(argc == 3){
            if(findDocument(argv[2]) == 0){
                printf("\"%s\", this document does not exist in the database.\n", argv[2]);
            } else {
                printf("\"%s\", this document does exist in the database.\n", argv[2]);
            }
            return EXIT_SUCCESS;
        }else{
            char *err = "Specify the name of the document.";
            printError(err);
            return EXIT_FAILURE;
        }
    }
    else if(strcmp(argv[1], "-update") == 0) { //-update <name> <type>
        if(argc == 4){
            if(findDocument(argv[2]) == 1){ // le document existe dans la base
                if (isTypeDocumentExist(argv[3]) == 1){ // le type de document saisi existe
                    updateDocument(argv[2], argv[3]);
                    return EXIT_SUCCESS;
                  }else{ // le type de document n'existe pas
                    printError(strcat(argv[2]," is an invalid document type."));
                    return EXIT_FAILURE;
                }
            } else{ // le document n'existe pas dans la base
                char *err = strcat(argv[2], ", this document does not exist in the database.");
                printError(err);
                return EXIT_FAILURE;
            }
        } else{ // pas le bon nombre d'argument
            char *err = "Specify the name of the document and its new type.";
            printError(err);
            return EXIT_FAILURE;
        }
    }
    else{ // cas d'erreur général
        printError("Argument invalid");
        return EXIT_FAILURE;
    }
}   