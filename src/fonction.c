#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include<gtk/gtk.h>

enum
{
	ETITRE,
	EEMAIL,
	EREC,
	EID,
	EGENRE,
	EJOUR,
	EMOIS,
	EANNEE,
	COLUMNS,
};
///////////////ajouter//////////////////////////
void ajouterreclamation(reclamation h)
{
FILE *f;
f=fopen("reclamation.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %d %d %d %s %s %s %s  \n",h.titre,h.date.jour,h.date.mois,h.date.annee,h.email,h.genre,h.rec,h.id);
    
fclose(f);
}
}
////////////////////////afficher 1et2 //////////////////////////////////////////////
void afficherreclamation(GtkWidget *liste)
{

   GtkCellRenderer  *renderer;
   GtkTreeViewColumn  *column;
   GtkTreeIter  iter;
   GtkListStore  *store;

   char titre [50];
   char email[50];
   char rec[50];
   char id[50];
   char genre[50];
   char jour[50];
   char mois[50];
   char annee[50];
   
   store=NULL;
	FILE *f;
	store = gtk_tree_view_get_model (liste);
	if (store==NULL)
       {
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("titre", renderer, "text",ETITRE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("email", renderer, "text",EEMAIL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("rec", renderer, "text",EREC,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",EID,NULL);
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

	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	f=fopen("reclamation.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("reclamation.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s \n",titre,jour,mois,annee,email,genre,rec,id)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ETITRE, titre, EJOUR, jour, EMOIS, mois, EANNEE, annee, EEMAIL, email,EGENRE, genre, EREC , rec, EID, id, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}
///////////////////////////supprimer/////////////////////////////////////////////
void supprimerreclamation(char id[],char titre[])
{
reclamation h;
FILE *f, *g;
f=fopen("reclamation.txt","r");
g=fopen("aux.txt","w");
if (f==NULL || g==NULL)
    return;
else{

while(fscanf(f,"%s %d %d %d %s %s %s %s  \n",h.titre,&h.date.jour,&h.date.mois,&h.date.annee,h.email,h.genre,h.rec,h.id)!=EOF)

{
if ((strcmp (id,h.id)!=0)||(strcmp(titre,h.titre)!=0))
{
fprintf(g,"%s %d %d %d %s %s %s %s \n",h.titre,h.date.jour,h.date.mois,h.date.annee,h.email,h.genre,h.rec,h.id);
}
}
fclose(g);
fclose(f);
remove("reclamation.txt");

rename ("aux.txt", "reclamation.txt");
}

}
///////////////////////////////modifier//////////////////////////////////////////
void modifierreclamation(reclamation h1)
{
reclamation h;
FILE *f1;
FILE *f2;
f1=fopen("reclamation.txt","r");
f2=fopen("modifier.txt","a");

if((f1!=NULL)&&(f2!=NULL))
{
while(fscanf(f1,"%s %d %d %d %s %s %s %s \n",h.titre,&h.date.jour,&h.date.mois,&h.date.annee,h.email,h.genre,h.rec,h.id)!=EOF)
	{
	if(strcmp(h.id,h1.id)==0)
		{
		fprintf(f2,"%s %d %d %d %s %s %s %s \n",h1.titre,h1.date.jour,h1.date.mois,h1.date.annee,h1.email,h1.genre,h1.rec,h1.id);
		}
	else
		{
		fprintf(f2,"%s %d %d %d %s %s %s %s \n",h.titre,h.date.jour,h.date.mois,h.date.annee,h.email,h.genre,h.rec,h.id);
		}
	}

}
fclose(f1);
fclose(f2);
remove("reclamation.txt");
rename("modifier.txt","reclamation.txt");
}
////////////////////////////////remplirtab////////////////////////////////////////////////////////////

int remplirtabreclamation (reclamation tab[],int nbr)
{
    char titre[50];
    char email[50];
    char rec[50];
    char id[50];
    char genre[50];
    int jour;
    int mois;
    int annee;		
    
    FILE *f1 ;
    int i=0;

    f1 = fopen("reclamation.txt", "a+");


        while (fscanf(f1,"%s %d %d %d %s %s %s %s \n",titre,&jour,&mois,&annee,email,genre,rec,id)!=EOF)
        {
            nbr++;
            strcpy(tab[i].titre,titre);
	    tab[i].date.jour=jour;
            tab[i].date.mois=mois;
	    tab[i].date.annee=annee;
	    strcpy(tab[i].email,email);
            strcpy(tab[i].rec,rec);
	    strcpy(tab[i].genre,genre);
	    strcpy(tab[i].id,id);
            i++;
	    
        }
        

        fclose(f1);
	return(nbr);
}
/////////////////////////chercher/////////////////////////////////////////////
int chercherreclamation(char id[])
{
reclamation tabl[200];
int nbr;
int e,i;
FILE*f;
e=0;
nbr=remplirtabreclamation (tabl,nbr);
for (i=0;i<nbr;i++)
	{if (strcmp(id,tabl[i].id)==0)
		{
		e=1;
		f=fopen("reclamationchercher.txt", "w+");
		if("f!=NULL")
			{fprintf(f,"%s %d %d %d %s %s %s %s \n",tabl[i].titre,tabl[i].date.jour,tabl[i].date.mois,tabl[i].date.annee,tabl[i].email,tabl[i].genre,tabl[i].rec,tabl[i].id);}
		fclose(f);		
		}
	}

return(e);
}
//////////////////////////afficherchercher///////////////////////////////////////////
void afficherchercherreclamation(GtkWidget *liste)
{

   GtkCellRenderer  *renderer;
   GtkTreeViewColumn  *column;
   GtkTreeIter  iter;
   GtkListStore  *store;

   char titre [50];
   char email[50];
   char rec[50];
   char id[50];
   char genre[50];
   char jour[50];
   char mois[50];
   char annee[50];
   
   store=NULL;
	FILE *f;
	store = gtk_tree_view_get_model (liste);
	if (store==NULL)
       {
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("titre", renderer, "text",ETITRE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("email", renderer, "text",EEMAIL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("rec", renderer, "text",EREC,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",EID,NULL);
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

	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	f=fopen("reclamation.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("reclamationchercher.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s \n",titre,jour,mois,annee,email,genre,rec,id)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ETITRE, titre, EJOUR, jour, EMOIS, mois, EANNEE, annee, EEMAIL, email,EGENRE, genre, EREC , rec, EID, id, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}
/////////////plus_reclame//////////////////////////////////////////////////////////////////////////////////////////////////

int plus_reclame(){
 FILE *f1 ;
    int h=0,r=0,n;
	 char titre [50];
   char email[50];
   char rec[50];
   char id[50];
   char genre[50];
   char jour[50];
   char mois[50];
   char annee[50];

    f1 = fopen("reclamation.txt", "r");

while(fscanf(f1,"%s %s %s %s %s %s %s %s \n",titre,jour,mois,annee,email,genre,rec,id)!=EOF)
{
if (strcmp(titre,"Hebergement")==0)
h++;
else 
r++;
}
if (r>h)
n=0;
else if (h>r)
n=1;
else
n=2;
return n;
}
