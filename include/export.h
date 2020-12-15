#ifndef H_GL_EXPORT
#define H_GL_EXPORT

/* Permet d'exporter des statistiques sur la bibliographie*/
void showStats(char *folder, char *script);

/*Permet d'exporter la bibliographie au format pdf ou txt*/
void exportBiblio(char *ext);

void createLatexDoc();

#endif