#include<gtk/gtk.h>

typedef struct{
int jour;
int mois;
int annee;
}DATEHEB;

typedef struct
{char nom [40];
char prenom[40];
char cin[40];
char sexe[40];
char numerotel[40];
char adresse[40];
char email[40];
char etage[40];
char numcha[40];
char spec[40];
char niv[40];
DATEHEB date;
}hebergement;

///////////////tache 1//////////////////////////////////// 
void ajouterhebergement(hebergement g);
void supprimerhebergement(char cin []);
void afficherhebergement (GtkWidget *liste);
void modifierhebergement(hebergement g1);
int remplirtabheberg (hebergement tab[],int nb);
int rechercherhebergement(char cin[]);
void affichage_hebergement_rechercher(GtkWidget *liste);
///////////////tache 2//////////////////////////////////////
int niveau(int calcul[],char txt[]);
