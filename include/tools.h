#ifndef H_GL_TOOLS
#define H_GL_TOOLS

/* Permet d'afficher une brève description de l'utilisation de l'application */
void printHelp(void);

/* Permet d'afficher une erreur */
void printError(char *errStr);

/* Permet de mettre une chaîne de caractère en miniscule */
char* strlw(char *str);

/* Retourne le chemin de la fiche type d'un document */
char* getDocumentTypePath(char *type);

#endif