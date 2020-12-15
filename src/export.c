#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "tools.h"

void showStats(char *folder, char *script) {
    
    int system(const char *command);

    chdir(folder);
    system(script);
}

void exportBiblio(char *ext){
    if(strcmp(ext, "pdf") == 0) // si l'extension est pdf 
    {
        printf("*** Export de la bibliographie en pdf ***\n");
    }
    else if(strcmp(ext, "txt") == 0) // sinon si l'extension est txt
    {
        printf("*** Export de la bibliographie en txt ***\n");
    }
}
