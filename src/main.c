#include <stdlib.h>
#include <string.h>
#include "biblioManager.h"
#include "tools.h"

int main(int argc, char *argv[])
{   

    //vérification du bon nombre d'argument
    if(argc < 2 || argc > 3){

        printError("Number of argument invalid");
        return EXIT_FAILURE;
    }
    if( strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0 || strcmp(argv[1], "--help") == 0) {  //-h -help --help

        printHelp();
        return EXIT_SUCCESS;
    }
    else if(strcmp(argv[1], "-add") == 0) {  //-add <type>

        addDocument(argv[2]);
        return EXIT_SUCCESS;
    }
    else if(strcmp(argv[1], "-delete") == 0) {  //-delete <document>

        if (!isDocumentExist(argv[2]))
        {
            char *err = strcat(argv[2], " document to be deleted does not exist in the database.");;
            printError(err);
            return EXIT_FAILURE;
        }
        
        return EXIT_SUCCESS;
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
    else{ // cas d'erreur général
        printError("Argument invalid");
        return EXIT_FAILURE;
    }
}   