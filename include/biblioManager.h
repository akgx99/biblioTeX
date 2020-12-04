#ifndef H_GL_BIBLIOMANAGER
#define H_GL_BIBLIOMANAGER

/* Permet de dire si un document existe ou non dans la base */
int isDocumentExist();

/* Permet de récupérer les champs du document depuis sa fiche type */
void setField();

/* Permet de saisir des données pour un document */
void input();

/* Permet d'ajouter un document à la base de données */
void addDocument(char *type);

#endif