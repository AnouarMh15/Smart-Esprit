#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <gtk/gtk.h>
typedef struct {
int jour;
int mois;
int annee;
}DATEa;
typedef struct {
char titre[50];
char email[50];
char rec[50];
char id[50];
char genre[50];
DATEa date;
}reclamation;
///////////////////////////////
void ajouterreclamation(reclamation h);
///////////////////////////////
void modifierreclamation(reclamation h);
///////////////////////////////////////////
void supprimerreclamation(char id[],char titre[]);
//////////////////////////////////
void afficherreclamation(GtkWidget *liste);
////////////////////////////////////////////
void afficherchercherreclamation(GtkWidget *liste);
int chercherreclamation(char id[]);
int remplirtabreclamation (reclamation tab[],int nbr);
////////////////////////////////
int plus_reclame();
#endif 
