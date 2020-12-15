#ifndef H_GL_BIBLIOMANAGER
#define H_GL_BIBLIOMANAGER

/* Permet de dire si un type document existe ou non */
int isTypeDocumentExist(char *type);

/* Permet de récupérer les champs du document depuis sa fiche type */
void setFields();

/* Permet à l'utilisateur de saisir des données pour un document */
void setValues();

/* Permet d'écrire dans un fichier .bib les données d'un document */
void writeInDocument();

/* Permet d'ajouter un document à la base de données */
void addDocument(char *type);

/* Permet de déterminer si document existe ou non dans la base de données */
int find(char *name);

/* Permet de supprimer un document de la base de données*/
void delete(char *name);

#endif