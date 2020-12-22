#ifndef H_GL_IMPORT
#define H_GL_IMPORT

/* Permet de récupérer les données à insérer dans le bib*/
void getData(char *path);

/* Permet de récupérer les champs du document depuis le fichier */
void setFields(char *tab);

/* Permet de récupérer les valeurs du document depuis le fichier */
void setValues(char *tab);

/* Permet de dire si les données correspondent au type de document */
int isRightDocumenTypeFormat(char *type);

#endif