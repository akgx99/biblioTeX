#include "menu.h"

int main(void)
{
    addItem("Ajouter un document");
    addItem("Modifier un document");
    addItem("Afficher un document");
    addItem("Supprimer un document");
    addItem("Quitter le programme");

    showMenu();
    
	return 0;
}

