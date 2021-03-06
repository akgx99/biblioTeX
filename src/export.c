#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
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
    pid_t pid = fork(); // fork necessaire sinon impossible de continuer d'exécuter le programme après le execl()
	if ( pid == 0 )
		execl("script/./deleteCiteLaTeX.sh", "script/./deleteCiteLaTeX.sh", (char*) name, PATH_TO_BIBTEXKEY, NULL);
	wait((int*) 1);
}

void buildLatexDoc(){
    pid_t pid = fork(); // fork necessaire sinon impossible de continuer d'exécuter le programme après le execl()
	if ( pid == 0 )
		execl("script/./buildLatexDoc.sh", "script/./buildLatexDoc.sh", NULL);
	wait((int*) 1);   
}
