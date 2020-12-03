#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printHelp(void) {
   FILE *file;
   char buffer[256];

   file = fopen("data/app.info", "r");
   while (fgets(buffer,256, file))
        printf("%s", buffer);
    fclose(file);
}

void printError(char *errStr){
    printf("Error : %s\n", errStr);
    printf("Usage : ./bibTex -help\n");
}

char* strlw(char *str){
    for(int i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }
    return str;
}

char* getDocumentTypePath(char *type){
    char *folderPath = "data/bibTeX/";
    char *fileName = type; 
    char *fileType = ".type";

    static char absolutePath[130];

    strcat(absolutePath, folderPath);
    strcat(absolutePath, fileName);
    strcat(absolutePath, fileType);

    return absolutePath;
}

char* removeLnBreak(char *str){
    char *tmp;
    tmp = strchr(str , '\n');
    if(tmp) 
        *tmp = '\0';

    return tmp;
}
    