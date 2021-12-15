#include<gtk/gtk.h>

typedef struct {
int Jourd;
int Heured;
int Moisd;
float Debitd;
}debit;
typedef struct
{
int jour;
int mois;
int annee;
}DAT;

typedef struct {
 char nom[50];
 char prenom[50]; 
 char CIN[50];
 DAT date;
 char adresse[50];
 char numtelephone[50];
 char password[50];
 char choix[50];
 char genre[50];
 char mail[50];
} utilisateur;
//////////verification///////////

int verif(char CIN[],char password[]);
//////////adminestrateur//////////

void ajouterutilisateur(utilisateur s);

void affichageutilisateur(GtkWidget *liste);

void supprimerutilisateur(char CIN[]);
void modifierutilisateur(utilisateur s);
int rechercherutilisateur(char CIN[]);
int remplirtabutilisateur (utilisateur tab[],int n);
void affichageutilisateurrechercher(GtkWidget *liste);

void affichedebit(GtkWidget *liste);
