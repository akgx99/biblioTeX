#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void showStats(char *folder, char *script) {
    
    int system(const char *command);

    chdir(folder);
    system(script);
}