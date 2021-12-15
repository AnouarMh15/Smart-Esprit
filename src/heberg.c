#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heberg.h"
#include<gtk/gtk.h>

enum{
ENOM,
EPRENOM,
ECIN,
ESEXE,
ENUMEROTEL,
EADRESSE,
EEAMIL,
EJOUR,
EMOIS,
EANNEE,
EETAGE,
ENUMCHA,
ENIV,
ESPEC,
COLUMNS,
};
//////////////////////Fonction ajouter //////////////////
void ajouterhebergement(hebergement g)
{
FILE *f;
f=fopen("hebergement.txt","a+");

        fprintf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s \n",g.nom,g.prenom,g.cin,g.date.jour,g.date.mois,g.date.annee,g.numerotel,g.adresse,g.email,g.sexe,g.etage,g.numcha,g.niv,g.spec);
    
fclose(f);
}
//////////////////////Fonction supprimer //////////////////
void supprimerhebergement(char cin [])
{
hebergement g;
FILE *f1;
FILE *f2;

f1=fopen("hebergement.txt","r");
f2=fopen("heberge.txt","w");
while(fscanf(f1,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s \n",g.nom,g.prenom,g.cin,&g.date.jour,&g.date.mois,&g.date.annee,g.numerotel,g.adresse,g.email,g.sexe,g.etage,g.numcha,g.niv,g.spec)!=EOF)
{if (strcmp(cin,g.cin)!=0)
fprintf(f2,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s \n",g.nom,g.prenom,g.cin,g.date.jour,g.date.mois,g.date.annee,g.numerotel,g.adresse,g.email,g.sexe,g.etage,g.numcha,g.niv,g.spec);
}
fclose(f1);
fclose(f2);
remove("hebergement.txt");
rename("heberge.txt","hebergement.txt");

}
//////////////////////Fonction afficher //////////////////
void afficherhebergement (GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[30];
	char prenom[30];
	char cin[30];
	char sexe[30];
	char jour[10];
	char mois[10];
	char annee[10];
	char numerotel[30];
	char adresse[30];
	char email[10];
        char etage[40];
	char numcha[40];
        char niv[40];
        char spec[40];
	hebergement g;
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",EPRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text",ECIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("sexe", renderer, "text",ESEXE,NULL);
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
	column = gtk_tree_view_column_new_with_attributes("numerotel", renderer, "text",ENUMEROTEL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("adresse", renderer, "text",EADRESSE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("email", renderer, "text",EEAMIL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etage", renderer, "text",EETAGE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("numcha", renderer, "text",ENUMCHA,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("niv",renderer,"text",ENIV,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("spec",renderer,"text",ESPEC,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);
	f=fopen("hebergement.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("hebergement.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",nom,prenom,cin,jour,mois,annee,numerotel,adresse,email,sexe,etage,numcha,niv,spec)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ENOM, nom, EPRENOM, prenom, ECIN , cin, EJOUR, jour, EMOIS, mois, EANNEE, annee, ENUMEROTEL, numerotel, EADRESSE, adresse, EEAMIL, email, ESEXE, sexe, EETAGE, etage, ENUMCHA, numcha, ENIV, niv, ESPEC, spec, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}
//////////////////////Fonction modifier//////////////////
void modifierhebergement(hebergement g1)
{
hebergement g;
FILE *f1;
FILE *f2;
f1=fopen("hebergement.txt","r");
f2=fopen("heberg.txt","a");

if((f1!=NULL)&&(f2!=NULL))
{
while(fscanf(f1,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s \n",g.nom,g.prenom,g.cin,&g.date.jour,&g.date.mois,&g.date.annee,g.numerotel,g.adresse,g.email,g.sexe,g.etage,g.numcha,g.niv,g.spec)!=EOF)
	{
	if(strcmp(g.cin,g1.cin)==0)
		{
		fprintf(f2,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s \n",g1.nom,g1.prenom,g1.cin,g1.date.jour,g1.date.mois,g1.date.annee,g1.numerotel,g1.adresse,g1.email,g1.sexe,g1.etage,g1.numcha,g1.niv,g1.spec);
		}
	else
		{
		fprintf(f2,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s \n",g.nom,g.prenom,g.cin,g.date.jour,g.date.mois,g.date.annee,g.numerotel,g.adresse,g.email,g.sexe,g.etage,g.numcha,g.niv,g.spec);
		}
	}

}
fclose(f1);
fclose(f2);
remove("hebergement.txt");
rename("heberg.txt","hebergement.txt");
}
//////////////////////////Fonction pour remplir un tableau//////////////////////////

int remplirtabheberg (hebergement tab[],int nb)
{
    char nom[20],prenom[20];
    char cin[20];	
    char sexe[20],numerotel[20];
    char adresse[20],email[20];
    char etage[20],numcha[20];
    char niv[40],spec[40];
    int jour,mois,annee;
    FILE* fichier ;
    int i=0;

    fichier = fopen("hebergement.txt", "a+");


        while (fscanf(fichier,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s  \n",nom,prenom,cin,&jour,&mois,&annee,numerotel,adresse,email,sexe,etage,numcha,niv,spec)!=EOF)
        {
            nb++;
	    strcpy(tab[i].nom,nom);
	    strcpy(tab[i].prenom,prenom);
	    strcpy(tab[i].cin,cin);
	    tab[i].date.jour=jour;
            tab[i].date.mois=mois;
	    tab[i].date.annee=annee;
	    strcpy(tab[i].sexe,sexe);
	    strcpy(tab[i].numerotel,numerotel);
	    strcpy(tab[i].adresse,adresse);
	    strcpy(tab[i].email,email);
	    strcpy(tab[i].nom,nom);
	    strcpy(tab[i].etage,etage);
	    strcpy(tab[i].numcha,numcha);
            strcpy(tab[i].niv,niv);
            strcpy(tab[i].spec,spec);
            i++;
	    
        }
        

        fclose(fichier);
	return(nb);
}
//////////////////////////Fonction Rechercher//////////////////////////

int rechercherhebergement(char cin[])
{
hebergement tabl[100];
int nb;
int ce,i;
FILE*f;
ce=0;
nb=remplirtabheberg (tabl,nb);
for (i=0;i<nb;i++)
	{if (strcmp(cin,tabl[i].cin)==0)
		{
		ce=1;
		f=fopen("hebergementrechercher.txt", "w+");
		if("f!=NULL")
			{fprintf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s  \n",tabl[i].nom,tabl[i].prenom,tabl[i].cin,tabl[i].date.jour,tabl[i].date.mois,tabl[i].date.annee,tabl[i].numerotel,tabl[i].adresse,tabl[i].email,tabl[i].sexe,tabl[i].etage,tabl[i].numcha,tabl[i].niv,tabl[i].spec);}
		fclose(f);		
		}
	}

return(ce);
}
//////////////////////////Fonction Affichage rechercher//////////////////////////
affichage_hebergement_rechercher(GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[30];
	char prenom[30];
	char cin[30];
	char sexe[30];
	char jour[10];
	char mois[10];
	char annee[10];
	char numerotel[30];
	char adresse[30];
	char email[10];
        char etage[40];
	char numcha[40];
        char niv[40];
        char spec[40];
	hebergement g;
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",EPRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text",ECIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("sexe", renderer, "text",ESEXE,NULL);
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
	column = gtk_tree_view_column_new_with_attributes("numerotel", renderer, "text",ENUMEROTEL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("adresse", renderer, "text",EADRESSE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("email", renderer, "text",EEAMIL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etage", renderer, "text",EETAGE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("numcha", renderer, "text",ENUMCHA,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

       renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("niv",renderer,"text",ENIV,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("spec",renderer,"text",ESPEC,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,G_TYPE_STRING,  G_TYPE_STRING);
	f=fopen("hebergement.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("hebergementrechercher.txt","a+");
		while(fscanf(f," %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",nom,prenom,cin,jour,mois,annee,numerotel,adresse,email,sexe,etage,numcha,niv,spec)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ENOM, nom, EPRENOM, prenom, ECIN , cin, EJOUR,jour, EMOIS,mois, EANNEE,annee, ENUMEROTEL,numerotel, EADRESSE,adresse, EEAMIL,email,ESEXE,sexe, EETAGE,etage, ENUMCHA,numcha,ENIV,niv,ESPEC,spec -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}
//////// fonc tache2////////////////
int niveau(int calcul[],char txt[])
{


 FILE *f;
    char ch1[30];
    char ch2[30];
    int a,b,c,d,e,g,h,e1=0,e2=0,e3=0,e4=0,s=0;
    char ch3[20];
    f=fopen(txt,"r");
  if(f!=NULL)
  {
    
          
		while(fscanf(f,"%s %s %d %d %d %d %s %d %d %d \n",ch1,ch2,&a,&b,&c,&d,ch3,&e,&g,&h)!= EOF)
			
        	{ 		if((calcul[0]==1) && (d==1))

                                 {
                                  e1++;

                                 }

  				if((calcul[1]==1) && (d==2))
                                {
                                 e2++;

                                }

 				if((calcul[2]==1) && (d==3))
                                {
              			 e3++;

            			}

 				if((calcul[3]==1) && (d==4))
            			{
              			e4++;

            			}

 				
       
    		}
s=e1+e2+e3+e4;
 }
    fclose(f);
return s;
	}

