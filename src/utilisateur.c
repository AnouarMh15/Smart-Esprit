
#include "utilisateur.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>
enum
{ 
	ENOM,
	EPRENOM,
	ECIN,
	EJOUR,
	EMOIS,
	EANNEE,
	EGENRE,
	EADRESSE,
	ENUMTELEPHONE,
	EMAIL,
	EPASSWORD,
	ECHOIX,
	COLUMNS,
};
///////////fonction verification/////////

int verif(char CIN[],char password[])
{
	int trouve=-1;
	FILE *f=NULL;
	char ch1[20];
	char ch2[20];
	f=fopen("users.txt","r");
	if(f!=NULL)
	{
	while(fscanf(f,"%s %s ",ch1,ch2)!=EOF)
	{
	if((strcmp(ch1,CIN)==0)&&(strcmp(ch2,password)==0))
	trouve=1;
	}
	fclose(f);
	}
	return trouve;
}


//////////////fonction ajouter/////////////
void ajouterutilisateur(utilisateur s)
{
FILE*f;


f=fopen("utilisateur.txt","a+");

if (f!=NULL)
{
fprintf (f,"%s %s %s %d %d %d %s %s %s %s %s %s\n", s.nom, s.prenom, s.CIN,s.date.jour,s.date.mois,s.date.annee,s.genre, s.adresse,s.numtelephone,s.mail,s.password,s.choix);
}
fclose(f);

}

//////////////fonction supprimer//////////

void supprimerutilisateur(char CIN2[])
{
utilisateur s;
FILE *f1;
FILE *f2;
f1=fopen("utilisateur.txt","r");
f2=fopen("utilis.txt","a");
if (f1==NULL ||f2==NULL)
return;
else{
while(fscanf(f1,"%s %s %s %d %d %d %s %s %s %s %s %s \n",s.nom,s.prenom,s.CIN,&s.date.jour,&s.date.mois,&s.date.annee,s.genre,s.adresse,s.numtelephone,s.mail,s.password,s.choix)!=EOF)
{if (strcmp(CIN2,s.CIN)!=0)
fprintf(f2,"%s %s %s %d %d %d %s %s %s %s %s %s \n",s.nom,s.prenom,s.CIN,s.date.jour,s.date.mois,s.date.annee,s.genre,s.adresse,s.numtelephone,s.mail,s.password,s.choix);

}
fclose(f1);
fclose(f2);
remove("utilisateur.txt");
rename("utilis.txt","utilisateur.txt");
}
}

//////////////fonction affichage//////////

void affichageutilisateur(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[50];
 	char prenom[50]; 
 	char CIN[50];
 	char jour[50];
	char mois[50];
	char annee[50];
	char genre[50];
 	char adresse[50];
 	char numtelephone[50];
 	char mail[50];
	char password[50];
	char choix[50]; 	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("pérnom", renderer, "text",EPRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text",ECIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("genre", renderer, "text",EGENRE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);  

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("adresse", renderer, "text",EADRESSE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("numtelephone", renderer, "text",ENUMTELEPHONE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mail", renderer, "text",EMAIL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("password", renderer, "text",EPASSWORD,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("choix", renderer, "text",ECHOIX,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	f=fopen("utilisateur.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("utilisateur.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s \n",nom,prenom,CIN,jour,mois,annee,genre,adresse,numtelephone,mail,password,choix)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ENOM, nom, EPRENOM, prenom, ECIN , CIN, EJOUR, jour, EMOIS, mois, EANNEE,annee,EGENRE,genre ,EADRESSE, adresse, ENUMTELEPHONE, numtelephone, EMAIL, mail, EPASSWORD, password, ECHOIX, choix, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}

//////////////////////////Fonction Modifier//////////////////////////                       
void modifierutilisateur(utilisateur s1)
{
utilisateur s;
FILE *f1;
FILE *f2;
f1=fopen("utilisateur.txt","r");
f2=fopen("util.txt","a");

if((f1!=NULL)&&(f2!=NULL))
{
while(fscanf(f1,"%s %s %s %d %d %d %s %s %s %s %s %s \n",s.nom,s.prenom,s.CIN,&s.date.jour,&s.date.mois,&s.date.annee,s.genre,s.adresse,s.numtelephone,s.mail,s.password,s.choix)!=EOF)
	{
	if(strcmp(s.CIN,s1.CIN)==0)
		{
		fprintf(f2,"%s %s %s %d %d %d %s %s %s %s %s %s \n",s1.nom,s.prenom,s1.CIN,s1.date.jour,s1.date.mois,s1.date.annee,s1.genre,s1.adresse,s1.numtelephone,s1.mail,s1.password,s1.choix);
		}
	else
		{
		fprintf(f2,"%s %s %s %d %d %d %s %s %s %s %s %s \n",s.nom,s.prenom,s.CIN,s.date.jour,s.date.mois,s.date.annee,s.genre,s.adresse,s.numtelephone,s.mail,s.password,s.choix);
		}
	}

}
fclose(f1);
fclose(f2);
remove("utilisateur.txt");
rename("util.txt","utilisateur.txt");
}
////////////fonction rechercher////////////

int  rechercherutilisateur(char CIN[])
{
    utilisateur tab[1000];
int n;
int k,i;
FILE*f;
k=0;
n=remplirtabutilisateur(tab,n);
for (i=0;i<n;i++)
	{if (strcmp(CIN,tab[i].CIN)==0)
		{
		k=1;
		f=fopen("utilisateurrechecher.txt", "w+");
		if("f!=NULL")
			{fprintf(f,"%s %s %s %d %d %d %s %s %s %s %s %s  \n",tab[i].nom,tab[i].prenom,tab[i].CIN,tab[i].date.jour,tab[i].date.mois,tab[i].date.annee,tab[i].genre,tab[i].adresse,tab[i].numtelephone,tab[i].mail,tab[i].password,tab[i].choix);}
		fclose(f);		
		}
}
return k;
}

////////fonction remplir tableau/////////////

int remplirtabutilisateur(utilisateur tab[],int n)
{
   	char nom[50];
 	char prenom[50]; 
 	char CIN[50];
 	int jour;
	int mois;
	int annee;
	char genre[50];
 	char adresse[50];
 	char numtelephone[50];
 	char mail[50];
	char password[50];
	char choix[50]; 
    FILE* fichier ;
    int i;

    fichier = fopen("utilisateur.txt", "a+");


        while (fscanf(fichier,"%s %s %s %d %d %d %s %s %s %s %s %s \n",nom,prenom,CIN,&jour,&mois,&annee,genre,adresse,numtelephone,mail,password,choix)!=EOF)
        {
            n++;
            strcpy(tab[i].CIN,CIN);
	    strcpy(tab[i].nom,nom);
	    strcpy(tab[i].prenom,prenom);
	    tab[i].date.jour=jour;
            tab[i].date.mois=mois;
	    tab[i].date.annee=annee;
	    strcpy(tab[i].genre,genre);
	    strcpy(tab[i].adresse,adresse);
	    strcpy(tab[i].numtelephone,numtelephone);
	    strcpy(tab[i].mail,mail);
	    strcpy(tab[i].password,password);
            strcpy(tab[i].choix,choix);
            i++;
	    
        }
        

        fclose(fichier);
	return(n);
}
//////////////fonction affichage rechercher//////////

void affichageutilisateurrechercher(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[50];
 	char prenom[50]; 
 	char CIN[50];
 	char jour[50];
	char mois[50];
	char annee[50];
	char genre[50];
 	char adresse[50];
 	char numtelephone[50];
 	char mail[50];
	char password[50];
	char choix[50]; 	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("pérnom", renderer, "text",EPRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text",ECIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("genre", renderer, "text",EGENRE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);  

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("adresse", renderer, "text",EADRESSE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("numtelephone", renderer, "text",ENUMTELEPHONE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mail", renderer, "text",EMAIL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("password", renderer, "text",EPASSWORD,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("choix", renderer, "text",ECHOIX,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	f=fopen("utilisateur.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("utilisateurrechecher.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s \n",nom,prenom,CIN,jour,mois,annee,genre,adresse,numtelephone,mail,password,choix)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ENOM, nom, EPRENOM, prenom, ECIN , CIN, EJOUR, jour, EMOIS, mois, EANNEE, annee, EGENRE, genre , EADRESSE, adresse, ENUMTELEPHONE, numtelephone, EMAIL, mail, EPASSWORD, password, ECHOIX, choix, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}
enum
{ 
 EJourd,
EHeured,
EMoisd,
EDebitd,

 COLUMNS1, };
void affichedebit(GtkWidget  *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	int Jourd;
	int Heured;
	int Moisd;
	float Debitd;
	
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Jourd",renderer, "text", EJourd,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Heured",renderer, "text",EHeured,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Moisd",renderer, "text",EMoisd,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Debitd",renderer, "text",EDebitd,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	}
	store=gtk_list_store_new (COLUMNS1, G_TYPE_INT,  G_TYPE_INT, G_TYPE_INT, G_TYPE_FLOAT);
	f=fopen("debit.txt","r");
	if(f==NULL)
	{
		return;
	}
	else 
	{
		f= fopen("debit.txt","a+");
	 	while(fscanf(f,"%d %d %d %f \n",&Jourd,&Heured,&Moisd,&Debitd)!=EOF)	          						  
		{ if (Debitd>=30) {
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EJourd,Jourd,
			EHeured,Heured,EMoisd,Moisd,EDebitd,Debitd,-1);
		}
		else if (Debitd<10){
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EJourd,Jourd,
			EHeured,Heured,EMoisd,Moisd,EDebitd,Debitd,-1);
		}
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}

