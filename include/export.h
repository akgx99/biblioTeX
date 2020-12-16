#ifndef H_GL_EXPORT
#define H_GL_EXPORT

/* Permet d'exporter des statistiques sur la bibliographie*/
void showStats(char *folder, char *script);

/*Permet d'exporter la bibliographie au format pdf ou txt*/
void exportBiblio(char *ext);

/* Permet de créer le document LaTeX */
void createLatexDoc();

/* Ajouter une citation au document LaTeX */
void addCiteLatex(char *name);

/* Supprimer une citation du document LaTeX */
void deleteCiteLatex(char *name);

#endif