#ifndef H_GL_EXPORT
#define H_GL_EXPORT

/* Permet d'exporter des statistiques sur la bibliographie*/
void showStats(char *folder, char *script);

/* Permet de créer le document LaTeX */
void createLatexDoc();

/* Permet de compiler le document latex avec les références */
void buildLatexDoc();

/* Ajouter une citation au document LaTeX */
void addCiteLatex(char *name);

/* Supprimer une citation du document LaTeX */
void deleteCiteLatex(char *name);

#endif