#ifndef H_GL_BIBLIOMANAGER
#define H_GL_BIBLIOMANAGER

/* Permet de dire si un type document existe ou non */
int isDocumentExist();

/* Permet de récupérer les champs du document depuis sa fiche type */
void setField();

/* Permet à l'utilisateur de saisir des données pour un document */
void input();

/* Permet d'écrire dans un fichier .bib les données d'un document */
void write();

/* Permet d'ajouter un document à la base de données */
void addDocument(char *type);

#endif