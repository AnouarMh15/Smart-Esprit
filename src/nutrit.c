#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"nutrit.h"
#include<gtk/gtk.h>



enum{
	ENT,
	PLA,
	DES,
	LAIT,
	COLUMNS
};

void afficher(GtkWidget *liste,Menu menu)
{


GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store=NULL;

store=gtk_tree_view_get_model(liste);

     if (store==NULL)
{

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Entrée",renderer,"text",ENT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Plat principal",renderer,"text",PLA,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dessert",renderer,"text",DES,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Produit Laitier",renderer,"text",LAIT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ENT,menu.entree,PLA,menu.plat,DES,menu.dessert,LAIT,menu.produit_laitier,-1);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}

}

enum{
	SEM,
	PDEJ,
	DEJ,
	DIN,
	COOLUMNS
};

void affichermeilleur(GtkWidget *liste, int T[],int lm,int TAB[])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
int i;

store=NULL;

store=gtk_tree_view_get_model(liste);

     if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Semaine",renderer,"text",SEM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour du meilleur petit déjeuner",renderer,"text",PDEJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour du meilleur déjeuner",renderer,"text",DEJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour du meilleur diner",renderer,"text",DIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



store=gtk_list_store_new(COOLUMNS,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);


for (i=0;i<5;i++)
{ if (TAB[i]==1)
{if (i>0){
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,SEM,i+1,PDEJ,T[3*i]%7,DEJ,T[3*i+1]%7,DIN,T[3*i+2]%7,-1);
}
else {
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,SEM,i+1,PDEJ,T[3*i],DEJ,T[3*i+1],DIN,T[3*i+2],-1);
}

}
}
}
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}
enum{
	MENN,
	ENTT,
	PLAA,
	DESS,
	LAITT,
	COOOLUMNS
};
void maffich(GtkWidget *liste, Menu_dujour maffiche)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store=NULL;
int i;

store=gtk_tree_view_get_model(liste);

     if (store==NULL)
{

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Menu",renderer,"text",MENN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Entrée",renderer,"text",ENTT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Plat principal",renderer,"text",PLAA,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dessert",renderer,"text",DESS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Produit Laitier",renderer,"text",LAITT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COOOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
for (i=0;i<3;i++)
{ if (i==0)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,MENN,"Petit déjeuner",ENTT,maffiche.T[i].entree,PLAA,maffiche.T[i].plat,DESS,maffiche.T[i].dessert,LAITT,maffiche.T[i].produit_laitier,-1);


}
if (i==1)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,MENN,"Déjeuner",ENTT,maffiche.T[i].entree,PLAA,maffiche.T[i].plat,DESS,maffiche.T[i].dessert,LAITT,maffiche.T[i].produit_laitier,-1);


}
if (i==2)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,MENN,"Diner",ENTT,maffiche.T[i].entree,PLAA,maffiche.T[i].plat,DESS,maffiche.T[i].dessert,LAITT,maffiche.T[i].produit_laitier,-1);


}
}
}
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}



int ajoutermenu(int date,int nummenu, Menu ajout)
{


    FILE *f1= NULL,*f2=NULL;
    int y;
    char char1[20];
    char char2[20];
    char char3[20];
    char char4[20];
    int x,exist=0;



    f1=fopen("listemenu.txt","r");
   f2=fopen("tmp.txt","w");

    if((f1!=NULL ))
    {
        while ((fscanf(f1,"%d %d %s %s %s %s\n",&y,&x,char1,char2,char3,char4 )!=EOF))
        {
            if((y==date)&&(x==nummenu))

            { exist=1;
fprintf(f2,"%d %d %s %s %s %s\n",y,x,char1,char2,char3,char4 );

            }

            else
                fprintf(f2,"%d %d %s %s %s %s\n",y,x,char1,char2,char3,char4 );

        }
   
    }
 if (!exist)
    fprintf(f2,"%d %d %s %s %s %s\n",date,nummenu,ajout.entree,ajout.plat,ajout.dessert,ajout.produit_laitier);
    fclose(f1);
    fclose(f2);
    
   
   remove("listemenu.txt") ;
    rename("tmp.txt","listemenu.txt");
return exist;
}
    
 
int modifiermenu(int date, int nummenu, Menu nouveau)
{

    FILE *f1= NULL,*f2=NULL;
    int y;
    char char1[20];
    char char2[20];
    char char3[20];
    char char4[20];
    int x,modification=0;


    f1=fopen("listemenu.txt","r");
    f2=fopen("tmp.txt","w");



    while ((fscanf(f1,"%d %d %s %s %s %s",&y,&x,char1,char2,char3,char4 )!=EOF))
    {
        if((y==date)&&(x==nummenu))
        {

           modification=1;


            fprintf(f2,"%d %d %s %s %s %s \n",date,nummenu,nouveau.entree,nouveau.plat,nouveau.dessert,nouveau.produit_laitier);

        }
        else
            fprintf(f2,"%d %d %s %s %s %s \n",y,x,char1,char2,char3,char4 );
    }








    fclose(f1);
    fclose(f2);
    remove("listemenu.txt") ;
    rename("tmp.txt","listemenu.txt");
return modification;
}

int supprimermenu(int date, int nummenu)
{

    FILE *f1= NULL,*f2=NULL;

    char char1[20];
    char char2[20];
    char char3[20];
    char char4[20];
    int x,y,suppression=0;


    f1=fopen("listemenu.txt","r");
    f2=fopen("tmp.txt","w");


    while ((fscanf(f1,"%d %d %s %s %s %s",&y,&x,char1,char2,char3,char4 )!=EOF))
    {
        if((y==date)&&(x==nummenu))
        {

           suppression=1;
        }
        else
            fprintf(f2,"%d %d %s %s %s %s \n",y,x,char1,char2,char3,char4 );
    }







    fclose(f1);
    fclose(f2);
    remove("listemenu.txt") ;
    rename("tmp.txt","listemenu.txt");
return suppression;
}
Menu cherchermenu(int date, int nummenu)
{
    FILE *f1= NULL;

    char char1[20];
    char char2[20];
    char char3[20];
    char char4[20];

    int x,y;
    int trouv=0;
    Menu recherche;

    strcpy(recherche.entree,"VACANT");

    f1=fopen("listemenu.txt","r");


    if(f1!=NULL)
    {
        while ((fscanf(f1,"%d %d %s %s %s %s",&y,&x,char1,char2,char3,char4 )!=EOF)&&!trouv)
        {
            if((date==y)&&(x==nummenu))
            {
                trouv=1;
                reconstruire(char1);
                reconstruire(char2);
                reconstruire(char3);
                reconstruire(char4);
                strcpy(recherche.entree,char1);
                strcpy(recherche.plat,char2);
                strcpy(recherche.dessert,char3);
                strcpy(recherche.produit_laitier,char4);

            }

        }





    }

    
    fclose(f1);
    return recherche;
}
Menu_dujour affichermenu(int date)
{
    FILE *f1= NULL;
    Menu_dujour M;
    char char1[20];
    char char2[20];
    char char3[20];
    char char4[20];

    int j,x,y;
 for (j=0;j<3;j++)
   {
      strcpy(M.T[j].entree,"à remplir");
                strcpy(M.T[j].plat,"à remplir");
                strcpy(M.T[j].dessert,"à remplir");
                strcpy(M.T[j].produit_laitier,"à remplir");
}
    f1=fopen("listemenu.txt","r");


    if(f1!=NULL)
    {
        while ((fscanf(f1,"%d %d %s %s %s %s\n",&y,&x,char1,char2,char3,char4 )!=EOF))
        {
            if(y==date)
            {
                reconstruire(char1);
                reconstruire(char2);
                reconstruire(char3);
                reconstruire(char4);
                strcpy(M.T[x-1].entree,char1);
                strcpy(M.T[x-1].plat,char2);
                strcpy(M.T[x-1].dessert,char3);
                strcpy(M.T[x-1].produit_laitier,char4);
                
            }

        }

        fclose(f1);
        return M;









    }
}
int meilleurmenu(int T[])
{
    FILE *f= NULL;
    char tmp[10];
    double res,min1=1000000,min2=1000000,min3=1000000;


    int x,y,i,c,j=0,semaine=0;

    char z[10];
    Menu recherche;


    f=fopen("dechets.txt","r");


    if(f!=NULL)
    {



        while ((fscanf(f,"%d %d %s",&x,&y,z)!=EOF))
        {

            strcpy(tmp,z);
            res = atof(tmp);

            if (y==1)
            {
                if (min1>res)
                {
                    min1=res;
                    T[semaine*3+0]=x;
                }
            }
            else if(y==2)
            {
                if (min2>res)
                {
                    min2=res;
                    T[semaine*3+1]=x;

                }
            }
            else
            {
                if (min3>res)
                {
                    min3=res;
                    T[semaine*3+2]=x;

                }
            }

            j=j+1;
            if((j%21)==0)
            {
                semaine=semaine+1;
                min1=1000000;
                min2=1000000;
                min3=1000000;
            }


        }
        fclose(f);

    }





    
    return (3*(semaine+1));
}

void formater(char chaine[])
{
    int i;
    for(i=0; i<strlen(chaine); i++)
    {
        if(chaine[i]==' ')
            chaine[i]='.';

    }
}
void reconstruire(char chaine[])
{
    int i;
    for(i=0; i<strlen(chaine); i++)
    {
        if(chaine[i]=='.')
            chaine[i]=' ';

    }
}
