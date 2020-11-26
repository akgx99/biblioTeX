#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 10

int pos = 0;
char *entries[MAX_ENTRIES];

void addItem(char *contenu){
    if(pos < MAX_ENTRIES){
        entries[pos] = contenu;
    }
    pos++;
}

void showItems(void){
    int i;

    for(i=0; i<pos; i++)
    {
        printf("%d --> %s\n", i, entries[i]);
    }
}

void showMenu(void){
    int choice;
    bool running = 1;

    showItems();

     while (running)
    {
        scanf("%d", &choice);

        switch (choice)
        {
        case 4:
            running = 0;
            printf("A bientôt\n");
            break;
        
        default:
            system("clear");
            printf("Faîtes un choix entre 0 et %d\n", pos-1);
            showItems();
            break;
        }
    }

}
