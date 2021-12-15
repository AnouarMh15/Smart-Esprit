#ifndef _nutrit_h
#define _nutrit_h
#include <gtk/gtk.h>



typedef struct
{
    char entree[20];
    char plat[20];
    char dessert[20];
    char produit_laitier[20];
}Menu;
typedef struct
{
    Menu T[3];
}Menu_dujour;
void afficher(GtkWidget *liste,Menu menu);
void affichermeilleur(GtkWidget *liste, int T[],int lm,int TAB[]);
void maffich(GtkWidget *liste, Menu_dujour maffiche);

void formater(char chaine[]);
void reconstruire(char chaine[]);
int ajoutermenu(int date,int nummenu, Menu ajout);
int modifiermenu(int date, int nummenu, Menu nouveau);
int supprimermenu(int date, int nummenu);
Menu cherchermenu(int date, int nummenu);
Menu_dujour affichermenu(int date);
int meilleurmenu(int T[]);

#endif
