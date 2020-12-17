#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "tools.h"

char PATH_TO_BIBTEXKEY[35] = "data/bibtexkey.txt";
char PATH_TO_TEX[35] = "out/start.tex";

void showStats(char *folder, char *script) {
    
    int system(const char *command);

    chdir(folder);
    system(script);
}

void createLatexDoc(){
    FILE *f, *file;
    char  line[50],
          value[100][50];
    int nbLine = 0;
   
    //on récupère les champs à remplir du document
    f = fopen(PATH_TO_BIBTEXKEY, "r");
    while (fgets(line, sizeof(line), f)) {
        removeLnBreak(line);
        strcpy(value[nbLine],line);
        nbLine++;
    }
    fclose(f);

    file = fopen(PATH_TO_TEX, "w");
    fprintf(file, "\\documentclass[a4paper]{article}\n");
    fprintf(file, "\\usepackage[utf8]{inputenc}\n");
    fprintf(file, "\\usepackage[T1]{fontenc}\n");
    fprintf(file, "\\usepackage{hyperref}\n");
    fprintf(file, "\n \n");

    fprintf(file, "\\begin{document}\n");
     for(int i = 0; i < nbLine; i++){
        fprintf(file, "     \\cite{%s}\n", value[i]);
    }

    fprintf(file, "     \\bibliographystyle{alpha}\n");
    fprintf(file, "     \\bibliography{start}\n");

    fprintf(file, "\\end{document}");

    fclose(file);
}

void addCiteLatex(char *name){
    FILE* file;

    file = fopen(PATH_TO_BIBTEXKEY, "a");
    fprintf(file, "%s\n", name);
    fclose(file);
}

void deleteCiteLatex(char *name){
   char line[1024] ;
   FILE* f = fopen(PATH_TO_BIBTEXKEY, "w");

   while (fgets(line , sizeof(line) , f )!= NULL)
   {
      if (strstr(line , name )!= NULL)
      {
         strcpy(line, " ");
      }
   }
}

void buildLatexDoc(){
    execl("script/./buildLatexDoc.sh", "script/./buildLatexDoc.sh", NULL);
}

void exportBiblio(char *ext){
    if(strcmp(ext, "pdf") == 0) // si l'extension est pdf 
    {
        createLatexDoc();
        buildLatexDoc();
    }
    else if(strcmp(ext, "txt") == 0) // sinon si l'extension est txt
    {
        createLatexDoc();
        buildLatexDoc();
        execl("pdftotext", "pdtotext", "out/start.pdf", NULL);
    }
}
