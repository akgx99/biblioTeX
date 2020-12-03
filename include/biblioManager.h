#ifndef H_GL_BIBLIOMANAGER
#define H_GL_BIBLIOMANAGER

/* Permet de dire si un document existe ou non dans la base */
int isDocumentExist(char *doc);

/* Permet d'ajouter un document à la base de données */
void addDocument(char *type);

/* Permet de lire les données saisies par l'utilisateur pour un document */
void dataEntriesDocument(char *type);

#endif