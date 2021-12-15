#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "stock.h"
#include "utilisateur.h"
#include "nutrit.h"
#include "fonction.h"
#include "capteur.h"
#include "heberg.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"

int x,y;
int l,t;
int xc=0;
int conf=0;
int *zo=&conf;
int v,w;
int j,m,a,jou,moi,ann;
int TAB[5]={0,0,0,0,0};
int nummenu=1;
int x,y;
int z,w;
int calcul[4]={0,0,0,0};
char so[200];
///////////////////Window Stock /////////////
///////Boutton Ajouter////////////
void
on_treeview_aff_stock_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* identifiant;
gchar* nom;
gchar* quantite;
gchar* type;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* choix;
gchar* etat;
gchar* datee;
produit p;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
GtkWidget* window_modif,*windowstock,*tre,*id,*n,*quant,*typ,*jj,*mm,*aa,*choi,*eta,*dat;

if (gtk_tree_model_get_iter(model, &iter,path))
{


gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&identifiant,1,&nom,2,&quantite,3,&type,4,&jour,5,&mois,6,&annee,7,&choix,8,&etat,9,&datee,-1);

windowstock=create_window_stock();
window_modif=create_window_ajouter();
gtk_widget_hide(windowstock);
gtk_widget_show(window_modif);

id=lookup_widget(window_modif,"entry1_identifiant");
gtk_entry_set_text(GTK_ENTRY(id),identifiant);

n=lookup_widget(window_modif,"entry1_nom");
gtk_entry_set_text(GTK_ENTRY(n),nom);

quant=lookup_widget(window_modif,"spinbutton1_quantite");
gtk_entry_set_text(GTK_ENTRY(quant),quantite);

jj=lookup_widget(window_modif,"spinbutton1_annee");
gtk_entry_set_text(GTK_ENTRY(jj),jour);

mm=lookup_widget(window_modif,"spinbutton1_jour");
gtk_entry_set_text(GTK_ENTRY(mm),mois);

aa=lookup_widget(window_modif,"spinbutton1_mois");
gtk_entry_set_text(GTK_ENTRY(aa),annee);


}
}
///////////////////Window Stock /////////////

///////Boutton Ajouter////////////

void
on_button_wnd_ajouter_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajou, *windowstock;
windowstock=lookup_widget(button,"window_stock");
gtk_widget_destroy(windowstock);
windowajou=create_window_ajouter();
gtk_widget_show (windowajou);
}

///////Boutton Affichage ////////////
void
on_button_afficher_stock_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tree,*windowstock;
windowstock=lookup_widget(button,"window_stock");
gtk_widget_destroy(windowstock);
windowstock=create_window_stock();
tree=lookup_widget(windowstock,"treeview_aff_stock");

affichageproduit(tree);

gtk_widget_hide(windowstock);
gtk_widget_show(windowstock);
}

///////Boutton modifier////////////
void
on_button_wnd_modif_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajou, *windowstock;
windowstock=lookup_widget(button,"window_stock");
gtk_widget_destroy(windowstock);
windowajou=create_window_ajouter();
gtk_widget_show (windowajou);
}

///////Boutton Supprimer ////////////
void
on_button_wnd_supp_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsupp, *windowstock;
windowstock=lookup_widget(button,"window_stock");
gtk_widget_destroy(windowstock);
windowsupp=create_window_supprimer();
gtk_widget_show (windowsupp);
}

///////Boutton Rechercher ////////////
void
on_button_wnd_rech_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowrechercher, *windowstock;
windowstock=lookup_widget(button,"window_stock");
gtk_widget_destroy(windowstock);
windowrechercher=create_window_rechercher();
gtk_widget_show(windowrechercher);
}

///////Boutton Rupture ////////////
void
on_button_wind_rupture_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
produit a;
GtkWidget *windowrupture, *windowstock,*output1;
GtkWidget *tree1;
FILE *f1;
f1=fopen("produitrupturer.txt","r");

remove("produitrupturer.txt");
windowstock=lookup_widget(button,"window_stock");
gtk_widget_destroy(windowstock);

a=rupturer();
windowrupture=create_window_rupture ();
tree1=lookup_widget(windowrupture,"treeview3_affrupture");
affichageproduitrupturer(tree1);

gtk_widget_hide(windowrupture);
gtk_widget_show(windowrupture);

}

////////////////////////////////Window Ajouter /////////////////////////
///////////////Bouton radio ajouterr////////////////
void
on_radiobutton1_restaurant_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=0;}
}


void
on_radiobutton1_general_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}

//////////////////case a cocher ajouter ////////////
void
on_checkbutton1_nouveau_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{l=0;}
}


void
on_checkbutton1_ancien_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active((togglebutton)))
{l=1;}
}
/////////////////////////CAlendrierr///////////
void
on_calendar1_stock_day_selected        (GtkCalendar     *calendar,
                                        gpointer         user_data)
{
gtk_calendar_get_date(calendar,&j,&m,&a);
m+=1;
}


void
on_button1_retour_ajt_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowstock ,*windowajout;
windowajout=lookup_widget(button,"window_ajouter");
gtk_widget_destroy(windowajout);
windowstock=create_window_stock();
gtk_widget_show (windowstock);
}

///////////////////////bouton ajouterr //////////////////////
void
on_button1_ajt_stock_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
produit p;
GtkWidget *windowajout, *windowstock,*type,*jour,*mois,*annee,*id,*nom,*quantite,*choix,*etat,*output;
char date[15];
windowajout=create_window_ajouter();
windowstock=create_window_stock();
id = lookup_widget(button,"entry1_identifiant");
nom = lookup_widget(button,"entry1_nom");
quantite = lookup_widget(button,"spinbutton1_quantite");
type=lookup_widget(button,"comboboxentry1_type");
jour = lookup_widget(button,"spinbutton1_jour");
mois = lookup_widget(button,"spinbutton1_mois");
annee = lookup_widget(button,"spinbutton1_annee");
strcpy(p.identifiant,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
p.quantite=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (quantite));
strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
p.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour));
p.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois));
p.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee));
sprintf(date,"%d/%d/%d",j,m,a);
    strcpy(p.datee,date); 
if ((strcmp(p.identifiant,""))==0||(strcmp(p.nom,"")==0)||(strcmp(p.type,"")==0))
{  output=lookup_widget(button,"label15anwer");
gtk_label_set_text(GTK_LABEL(output)," Veuillez remplir tout les champs SVP!");
}
if(x==1 )
{strcpy(p.choix,"general");} 
else
{strcpy(p.choix,"restaurant");}
if(l==1)
{strcpy(p.etat,"ancien");} 
else
{strcpy(p.etat,"nouveau");}

if((strcmp(p.identifiant,""))==0||(strcmp(p.nom,"")==0)||(strcmp(p.type,"")==0))
  {output=lookup_widget(button,"label15anwer");
gtk_label_set_text(GTK_LABEL(output)," Veuillez remplir tout les champs SVP!");
}
else  {
ajouterproduit(p);
x=0;
l=0;

windowajout=lookup_widget(button,"window_ajouter");
gtk_widget_destroy(windowajout);
windowstock=create_window_stock();
gtk_widget_show(windowstock);}
}

/////////////Bouton enregistrer modification /////////
void
on_button1_modi_stock_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
produit a1;
GtkWidget *windowajout, *windowstock ,*msg, *id1, *nom1, *quant1,*type1,*jour1,*mois1,*annee1,*choix1,*etat1,*output16;
char date1[15];
char ch[50];
id1 = lookup_widget(button,"entry1_identifiant");
nom1 = lookup_widget(button,"entry1_nom");
quant1 = lookup_widget(button,"spinbutton1_quantite");
type1=lookup_widget(button,"comboboxentry1_type");
jour1 = lookup_widget(button,"spinbutton1_jour");
mois1 = lookup_widget(button,"spinbutton1_mois");
annee1 = lookup_widget(button,"spinbutton1_annee");
strcpy(a1.identifiant,gtk_entry_get_text(GTK_ENTRY(id1)));
strcpy(a1.nom,gtk_entry_get_text(GTK_ENTRY(nom1)));
a1.quantite=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (quant1));
strcpy(a1.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type1)));
a1.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour1));
a1.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois1));
a1.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee1));
sprintf(date1,"%d/%d/%d",j,m,a);
    strcpy(a1.datee,date1); 
if(x==1 )
{strcpy(a1.choix,"general");} 
else
{strcpy(a1.choix,"restaurant");}
if(l==1)
{strcpy(a1.etat,"ancien");} 
else
{strcpy(a1.etat,"nouveau");}
modifierproduit(a1);
x=0;
l=0;
output16=lookup_widget(button,"label15anwer");
gtk_label_set_text(GTK_LABEL(output16)," Modification du produit avec succés :)");

}


//////////////////////////////Window Rechercher ///////////////////////////////////
void
on_treeview2_rechstock_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* identifiant;
gchar* nom;
gchar* quantite;
gchar* type;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* choix;
gchar* etat;
gchar* datee;
produit p;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
GtkWidget* window_modif,*windowstock,*tre,*id,*n,*quant,*typ,*jj,*mm,*aa,*choi,*eta,*dat;

if (gtk_tree_model_get_iter(model, &iter,path))
{


gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&identifiant,1,&nom,2,&quantite,3,&type,4,&jour,5,&mois,6,&annee,7,&choix,8,&etat,9,&datee,-1);

windowstock=create_window_stock();
window_modif=create_window_ajouter();
gtk_widget_hide(windowstock);
gtk_widget_show(window_modif);

id=lookup_widget(window_modif,"entry1_identifiant");
gtk_entry_set_text(GTK_ENTRY(id),identifiant);

n=lookup_widget(window_modif,"entry1_nom");
gtk_entry_set_text(GTK_ENTRY(n),nom);

quant=lookup_widget(window_modif,"spinbutton1_quantite");
gtk_entry_set_text(GTK_ENTRY(quant),quantite);

jj=lookup_widget(window_modif,"spinbutton1_annee");
gtk_entry_set_text(GTK_ENTRY(jj),jour);

mm=lookup_widget(window_modif,"spinbutton1_jour");
gtk_entry_set_text(GTK_ENTRY(mm),mois);

aa=lookup_widget(window_modif,"spinbutton1_mois");
gtk_entry_set_text(GTK_ENTRY(aa),annee);


}
}
///////////////////Boutton Retour non/////////////////
void
on_button2_retournon_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *n, *windowrech;
n=lookup_widget(button,"create_non");
gtk_widget_destroy(n);
windowrech=create_window_rechercher();
gtk_widget_show (windowrech);
}

///////////////////Boutton Retour aff rechercher/////////////////
void
on_button2_retrechercher_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *o, *windowstock;
o=lookup_widget(button,"create_oui");
gtk_widget_destroy(o);
windowstock=create_window_stock();
gtk_widget_show (windowstock);
}


void
on_button2_rechercher_stock_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
char identir[20];
GtkWidget *idenr, *rech,*o, *n;
GtkWidget *tree;
GtkWidget *windowrechercher;

int ce;
windowrechercher=lookup_widget(button,"window_rechercher");
o=create_oui();
n=create_non();
idenr = lookup_widget(button,"entry3_identifiant");
strcpy(identir,gtk_entry_get_text(GTK_ENTRY(idenr)));

ce=rechercherproduit(identir);

if (ce==0)
	{
		gtk_widget_show(n);
	}
if (ce==1)	
	{	

gtk_widget_destroy(windowrechercher);
tree=lookup_widget(o,"treeview2_rechstock");

affichageproduitrechercher(tree);
gtk_widget_show(o);
}
}
void
on_button2_retour_rech_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowstock ,*windowrech;
windowrech=lookup_widget(button,"oui");
gtk_widget_destroy(windowrech);
windowstock=create_window_stock();
gtk_widget_show (windowstock);
}
//////////////////////////////Window Rupture ///////////////////////////////////
void
on_treeview3_affrupture_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* identifiant;
gchar* nom;
gchar* quantite;
gchar* type;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* choix;
gchar* etat;
gchar* datee;
produit p;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
GtkWidget* window_modif,*windowstock,*tre,*id,*n,*quant,*typ,*jj,*mm,*aa,*choi,*eta,*dat;

if (gtk_tree_model_get_iter(model, &iter,path))
{


gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&identifiant,1,&nom,2,&quantite,3,&type,4,&jour,5,&mois,6,&annee,7,&choix,8,&etat,9,&datee,-1);

windowstock=create_window_stock();
window_modif=create_window_ajouter();
gtk_widget_hide(windowstock);
gtk_widget_show(window_modif);

id=lookup_widget(window_modif,"entry1_identifiant");
gtk_entry_set_text(GTK_ENTRY(id),identifiant);

n=lookup_widget(window_modif,"entry1_nom");
gtk_entry_set_text(GTK_ENTRY(n),nom);

quant=lookup_widget(window_modif,"spinbutton1_quantite");
gtk_entry_set_text(GTK_ENTRY(quant),quantite);

jj=lookup_widget(window_modif,"spinbutton1_jour");
gtk_entry_set_text(GTK_ENTRY(jj),jour);

mm=lookup_widget(window_modif,"spinbutton1_mois");
gtk_entry_set_text(GTK_ENTRY(mm),mois);

aa=lookup_widget(window_modif,"spinbutton1_annee");
gtk_entry_set_text(GTK_ENTRY(aa),annee);


}
}


void
on_button3_retour_rupture_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowrupture, *windowstock;
windowrupture=lookup_widget(button,"window_rupture");
gtk_widget_destroy(windowrupture);
windowstock=create_window_stock();
gtk_widget_show (windowstock);
}




void
on_button2_retour_sup_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsup, *windowstock;
windowsup=lookup_widget(button,"window_supprimer");
gtk_widget_destroy(windowsup);
windowstock=create_window_stock();
gtk_widget_show (windowstock);
}


void
on_button2_supprimer_produit_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
char identi[20];
GtkWidget *windowsup, *windowstock, *iden,*output15;
iden = lookup_widget(button,"entry2_identifiant");
strcpy(identi,gtk_entry_get_text(GTK_ENTRY(iden)));
supprimerproduit(identi);
output15=lookup_widget(button,"label_anwer1");
gtk_label_set_text(GTK_LABEL(output15)," Le produit supprimé avec succés :)");

}


void
on_checkbutton3_suprupture_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowrupture ;
GtkWidget *tree1;
remove("produitrupturer.txt");
windowrupture=lookup_widget(button,"window_rupture");
gtk_widget_destroy(windowrupture);
windowrupture=create_window_rupture ();
tree1=lookup_widget(windowrupture,"treeview3_affrupture");
affichageproduitrupturer(tree1);

gtk_widget_hide(windowrupture);
gtk_widget_show(windowrupture);
}
void
on_button_stockdexx_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue, *windowstock ,*wndsupp,*wndoui,*wndnon,*wndrech,*wndrupt,*wndajout;
windowstock=lookup_widget(button,"window_stock");
gtk_widget_destroy (windowstock);
wndsupp=lookup_widget(button,"window_supprimer");
gtk_widget_destroy(wndsupp);
wndoui=lookup_widget(button,"oui");
gtk_widget_destroy(wndoui);
wndnon=lookup_widget(button,"non");
gtk_widget_destroy(wndnon);
wndrech=lookup_widget(button,"window_rechercher");
gtk_widget_destroy(wndrech);
wndrupt=lookup_widget(button,"window_rupture");
gtk_widget_destroy(wndrupt);
wndajout=lookup_widget(button,"window_ajouter");
gtk_widget_destroy(wndajout);
windowbienvenue=create_window_bienvenue();
gtk_widget_show(windowbienvenue);
}
/////////////////////////////////////////////////////////OUssammmaa//////////////////////////
void
on_button6_ajoutercapteur_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* fenetre_ajout;
     GtkWidget* fenetre_princ;
fenetre_ajout=lookup_widget (button,"window_ajtcapt");
fenetre_ajout=create_window_ajtcapt ();
gtk_widget_show(fenetre_ajout);
afficher_capteur(fenetre_ajout);
fenetre_princ=lookup_widget (button,"window_gestcapt");
gtk_widget_destroy(fenetre_princ);
}


void
on_button6_modcapteur_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* fenetre_modif;
     GtkWidget* fenetre_princ;
fenetre_modif=lookup_widget (button,"window_ajtcapt");
fenetre_modif=create_window_ajtcapt ();
gtk_widget_show(fenetre_modif);
afficher_capteur(fenetre_modif);
fenetre_princ=lookup_widget (button,"window_gestcapt");
gtk_widget_destroy(fenetre_princ);
}


void
on_button6_supcapt_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* fenetre_supp;
     GtkWidget* fenetre_princ;
fenetre_supp=lookup_widget (button,"window_supcapt");
fenetre_supp=create_window_supcapt ();
gtk_widget_show(fenetre_supp);
afficher_capteur(fenetre_supp);
fenetre_princ=lookup_widget (button,"window_gestcapt");
gtk_widget_destroy(fenetre_princ);
}


void
on_button6_rechcapteur_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* fenetre_rech;
     GtkWidget* fenetre_princ;
fenetre_rech=lookup_widget (button,"window_affcapt");
fenetre_rech=create_window_affcapt ();
gtk_widget_show(fenetre_rech);
afficher_capteur(fenetre_rech);
fenetre_princ=lookup_widget (button,"window_gestcapt");
gtk_widget_destroy(fenetre_princ);
}


void
on_button6_listecapteur_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_al;
  GtkWidget *fenetre_princ;
GtkWidget *tree;
GtkWidget *tree1;
fenetre_al=lookup_widget (button,"window_listcapt");
fenetre_al=create_window_listcapt ();
gtk_widget_show(fenetre_al);
tree1=lookup_widget(fenetre_al,"treeview6_captfumee");
afficher_alarme(tree1);
tree1=lookup_widget(fenetre_al,"treeview6_captmouv");
afficher_alarme1(tree1);
fenetre_princ=lookup_widget (button,"window_gestcapt");
gtk_widget_destroy(fenetre_princ);
}




void
on_button6_retour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_principale, *fenetre_ajout_modif;
fenetre_ajout_modif=lookup_widget(button,"window_ajtcapt");
fenetre_principale=lookup_widget(button,"window_gestcapt");

gtk_widget_destroy(fenetre_ajout_modif);
fenetre_principale=create_window_gestcapt();
gtk_widget_show(fenetre_principale);
}

void
on_radiobutton3_fumee_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
xc=1;
}

}


void
on_radiobutton3_mouvement_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
xc=2;
}
}

void
on_button6_modifcapteur_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
capteur C;
   GtkWidget *IdentifianteCapt;
   GtkWidget *MarqueCapt;
   GtkWidget *TypeCapt;
   GtkWidget *JourCapt;
   GtkWidget *MoisCapt;
   GtkWidget *AnneeCapt;
   GtkWidget *ComboboxValeurMini;
   GtkWidget *ComboboxValeurMaxi;
   GtkWidget *ComboboxZoCov;
   GtkWidget *outputMsg;
   int mod,verif;
   char text[200];
  
   
GtkWidget *fenetre_ajout;

fenetre_ajout=lookup_widget(button,"window_ajtcapt");
IdentifianteCapt=lookup_widget(button,"entry6_identifiant");
MarqueCapt=lookup_widget(button,"entry6_marque");
strcpy(C.captID,gtk_entry_get_text(GTK_ENTRY(IdentifianteCapt)));
strcpy(C.captMarque,gtk_entry_get_text(GTK_ENTRY(MarqueCapt)));
/////////////////////////////////////////////////////////
JourCapt=lookup_widget(button,"spinbutton6_jour");
MoisCapt=lookup_widget(button,"spinbutton6_mois");
AnneeCapt=lookup_widget(button,"spinbutton6_annee");
C.JourCap=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(JourCapt));
C.MoisCap=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MoisCapt));
C.AnneeCap=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(AnneeCapt));
///////////////////////////////////////////////////////////
ComboboxValeurMaxi=lookup_widget(button,"combobox6_valeurmax");
ComboboxValeurMini=lookup_widget(button,"combobox6_valeurmin");
ComboboxZoCov=lookup_widget(button,"combobox6_zone");
strcpy(C.captValMin,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxValeurMini)));
strcpy(C.captValMax,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxValeurMaxi)));
strcpy(C.captZone,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxZoCov)));
///////////////////////////////////////////////////////////////////////////
if(xc==1)
{strcpy(C.captType,"Fumee");}
else
if(xc==2)
{strcpy(C.captType,"Mouvement");}
 // mod=modifier_capt(C); 
verif=exist_capteur(C.captID);

switch(verif)
    
{
    case 0:  
    { strcpy (text,"Identifiant n'existe pas");
    outputMsg=lookup_widget(button,("label50"));
    gtk_label_set_text(GTK_LABEL(outputMsg),text);
    }
    break;
    case 1:
   
    {  mod=modifier_capt(C);
     strcpy (text,"Modifie Réussi");
     outputMsg=lookup_widget(button,("label50"));
     gtk_label_set_text(GTK_LABEL(outputMsg),text);
     }
    break; 
    break;
} 

}


void
on_button6_affcapteur_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

fenetre_ajout=lookup_widget(button,"window_ajtcapt");

gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=lookup_widget(button,"window_affcapt");
fenetre_afficher=create_window_affcapt();

gtk_widget_show(fenetre_afficher);


treeview1=lookup_widget(fenetre_afficher,"treeview4_capteur");

afficher_capteur(treeview1);


}


void
on_checkbutton7_confirmer_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
*zo=1;
else
*zo=0;
}


void
on_button6_rrsupcapt_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_principale, *fenetre_ajout_supp;
fenetre_ajout_supp=lookup_widget(button,"window_supcapt");
fenetre_principale=lookup_widget(button,"window_gestcapt");

gtk_widget_destroy(fenetre_ajout_supp);
fenetre_principale=create_window_gestcapt();
gtk_widget_show(fenetre_principale);
}


void
on_button7_actualiser_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *fenetre_aff;
fenetre_aff=create_window_supcapt();
gtk_widget_show(fenetre_aff);

afficher_capteur(fenetre_aff);

fenetre_aff=lookup_widget(button,"window_supcapt");

gtk_widget_destroy(fenetre_aff);
}


void
on_button7_supaffcapteur_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *fenetre_supp;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
fenetre_afficher=lookup_widget(button,"window_affcapt");
fenetre_afficher=create_window_affcapt();

gtk_widget_show(fenetre_afficher);


treeview1=lookup_widget(fenetre_afficher,"treeview4_capteur");

afficher_capteur(treeview1);
fenetre_supp=lookup_widget(button,"window_supcapt");
gtk_widget_destroy(fenetre_supp);
}


void
on_button7_supcapteur_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *input1;
          
     GtkWidget  *fenetre_supp;
     GtkWidget *outputMsg;
     int supp,verif;
     char text[200];
    char ID[20];
     

fenetre_supp=lookup_widget(button,"window_supcapt");
input1=lookup_widget(button,"entry7_identifiant");   
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(input1)));
if(conf)
//supp=supprimer_capt(ID);

{verif=exist_capteur(ID);


switch(verif)
    
{
    case 0:
   
     
    { strcpy (text,"Identifiant à supprimer n'existe pas");
    outputMsg=lookup_widget(button,("label55"));
    gtk_label_set_text(GTK_LABEL(outputMsg),text);
    }
  
    break;
    case 1:
     
     {
      supp=supprimer_capt(ID);
     strcpy (text,"Suppression Réussi");
     outputMsg=lookup_widget(button,("label57"));
     gtk_label_set_text(GTK_LABEL(outputMsg),text);
     }
    
    break; 
    break;
}
}
else 
{strcpy (text,"La confirmation est obligatoire!");
    outputMsg=lookup_widget(button,("label52"));
    gtk_label_set_text(GTK_LABEL(outputMsg),text);
}
}


void
on_treeview4_capteur_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)

{
GtkTreeIter iter;
gchar* identi;
gchar* marque;
gchar* typ;
gchar* jourr;
gchar* moiss;
gchar* anneee;
gchar* valmin;
gchar* valmax;
gchar* zone;
capteur c;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
GtkWidget* window_modif,*windowaff,*tre,*idt,*m,*ty,*jjj,*mmm,*aaa,*vmi,*vmx,*zo;

if (gtk_tree_model_get_iter(model, &iter,path))
{


gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&identi,1,&marque,2,&typ,3,&jourr,4,&moiss,5,&anneee,6,&valmin,7,&valmax,8,&zone,-1);

windowaff=create_window_affcapt();
window_modif=create_window_ajtcapt();
gtk_widget_hide(windowaff);

gtk_widget_show(window_modif);

idt=lookup_widget(window_modif,"entry6_identifiant");
gtk_entry_set_text(GTK_ENTRY(idt),identi);

m=lookup_widget(window_modif,"entry6_marque");
gtk_entry_set_text(GTK_ENTRY(m),marque);




}

}
void
on_treeview5_affrechcapteur_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button8_rechcapteur_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Fenetrerech;
   GtkWidget *idy;
   GtkWidget *treeviewrech;
      GtkWidget *outputMsg;
   int verif;
    char text[200];
   char id[20];
   
Fenetrerech=lookup_widget(button,"window_affcapt");
idy=lookup_widget(button,"entry8_identifiant");
treeviewrech=lookup_widget(button,"treeview5_affrechcapteur");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(idy)));
verif=exist_capteur(id);

switch(verif)
    
{
    case 0:  
    { strcpy (text,"Identifiant n'existe pas");
    outputMsg=lookup_widget(button,("label61"));
    gtk_label_set_text(GTK_LABEL(outputMsg),text);
    }
    break;
    case 1:
   
    {  rechercher_capteur(treeviewrech, id);
       remove(treeviewrech);
       strcpy (text,"Identifiant existe");
       outputMsg=lookup_widget(button,("label61"));
       gtk_label_set_text(GTK_LABEL(outputMsg),text);
      }
    break; 
    break;
} 
}


void
on_button8_rraff_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_principale, *fenetre_aff;
fenetre_aff=lookup_widget(button,"window_affcapt");
fenetre_principale=lookup_widget(button,"window_gestcapt");

gtk_widget_destroy(fenetre_aff);
fenetre_principale=create_window_gestcapt();
gtk_widget_show(fenetre_principale);
}


void
on_button8_actaff_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *fenetre_aff,*treeview;
fenetre_aff=create_window_affcapt();
gtk_widget_show(fenetre_aff);
treeview=lookup_widget(fenetre_aff,"treeview4_capteur");
afficher_capteur(treeview);

fenetre_aff=lookup_widget(button,"window_affcapt");

gtk_widget_destroy(fenetre_aff);
}


void
on_treeview6_captfumee_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_treeview6_captmouv_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button9_rrliste_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* fenetre_al;
     GtkWidget* fenetre_princ;
fenetre_princ=lookup_widget (button,"window_gestcapt");
fenetre_princ=create_window_gestcapt ();
gtk_widget_show(fenetre_princ);
fenetre_al=lookup_widget (button,"window_listcapt");
gtk_widget_destroy(fenetre_al);
}

void
on_button16_ajoutercapteur_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
capteur C;
   GtkWidget *IdentifianteCapt;
   GtkWidget *MarqueCapt;
   GtkWidget *TypeCapt;
   GtkWidget *JourCapt;
   GtkWidget *MoisCapt;
   GtkWidget *AnneeCapt;
   GtkWidget *ComboboxValeurMini;
   GtkWidget *ComboboxValeurMaxi;
   GtkWidget *ComboboxZoCov;
   GtkWidget *outputMsg;
   int ajout,verif;
   char text[200];
  
  
  
GtkWidget *fenetre_ajout;

fenetre_ajout=lookup_widget(button,"window_ajtcapt");
IdentifianteCapt=lookup_widget(button,"entry6_identifiant");
MarqueCapt=lookup_widget(button,"entry6_marque");
strcpy(C.captID,gtk_entry_get_text(GTK_ENTRY(IdentifianteCapt)));
strcpy(C.captMarque,gtk_entry_get_text(GTK_ENTRY(MarqueCapt)));
/////////////////////////////////////////////////////////
JourCapt=lookup_widget(button,"spinbutton6_jour");
MoisCapt=lookup_widget(button,"spinbutton6_mois");
AnneeCapt=lookup_widget(button,"spinbutton6_annee");
C.JourCap=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(JourCapt));
C.MoisCap=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MoisCapt));
C.AnneeCap=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(AnneeCapt));
///////////////////////////////////////////////////////////
ComboboxValeurMaxi=lookup_widget(button,"combobox6_valeurmax");
ComboboxValeurMini=lookup_widget(button,"combobox6_valeurmin");
ComboboxZoCov=lookup_widget(button,"combobox6_zone");
strcpy(C.captValMin,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxValeurMini)));
strcpy(C.captValMax,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxValeurMaxi)));
strcpy(C.captZone,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxZoCov)));
///////////////////////////////////////////////////////////////////////////
if(xc==1)
{strcpy(C.captType,"Fumee");}
else
if(xc==2)
{strcpy(C.captType,"Mouvement");}
       
//ajout=ajouter_capt(C);

verif=exist_capteur(C.captID);

switch(verif)
    
{
    case 0:  
    { ajout=ajouter_capt(C); 
     strcpy (text,"Ajout Réussi");
     outputMsg=lookup_widget(button,("label50"));
     gtk_label_set_text(GTK_LABEL(outputMsg),text);
     }
    break;
    case 1:
    { strcpy (text,"Identifiant déja existe");
    outputMsg=lookup_widget(button,("label50"));
    gtk_label_set_text(GTK_LABEL(outputMsg),text);
    }
    break;
}
}


/////////////////////brahim//////////////////////

int x,y,z;
void
on_button_admin_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue, *windowconnexion1;
windowbienvenue=lookup_widget(button,"window_bienvenue");
gtk_widget_destroy(windowbienvenue);
windowconnexion1=create_window_connexion1();
gtk_widget_show(windowconnexion1);
}


void
on_button_nutrition_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue, *windowconnexion2;
windowbienvenue=lookup_widget(button,"window_bienvenue");
gtk_widget_destroy(windowbienvenue);
windowconnexion2=create_window_connexion2();
gtk_widget_show(windowconnexion2);
}


void
on_button_foyer_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue, *windowconnexion3;
windowbienvenue=lookup_widget(button,"window_bienvenue");
gtk_widget_destroy(windowbienvenue);
windowconnexion3=create_window_connexion3();
gtk_widget_show(windowconnexion3);
}


void
on_button_stock_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue, *windowconnexion4;
windowbienvenue=lookup_widget(button,"window_bienvenue");
gtk_widget_destroy(windowbienvenue);
windowconnexion4=create_window_connexion4();
gtk_widget_show(windowconnexion4);
}


void
on_button_reclamation_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue, *windowconnexion5;
windowbienvenue=lookup_widget(button,"window_bienvenue");
gtk_widget_destroy(windowbienvenue);
windowconnexion5=create_window_connexion5();
gtk_widget_show(windowconnexion5);
}


void
on_button_alarme_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue, *windowconnexion6;
windowbienvenue=lookup_widget(button,"window_bienvenue");
gtk_widget_destroy(windowbienvenue);
windowconnexion6=create_window_connexion6();
gtk_widget_show(windowconnexion6);
}


void
on_button_accueil1_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue, *windowconnexion1;
windowconnexion1=lookup_widget(button,"window_connexion1");
gtk_widget_destroy(windowconnexion1);
windowbienvenue=create_window_bienvenue();
gtk_widget_show(windowbienvenue);
}


void
on_button_cnx1_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *CIN3, *password3, *windowconnexion1,*windowadmin ,*output;
char CIN4[50];
char password4[50];
int trouve;

CIN3 = lookup_widget(button, "entry_id1_cnx") ;
password3 = lookup_widget(button, "entry_pw1_cnx") ;
strcpy(CIN4, gtk_entry_get_text(GTK_ENTRY(CIN3))); 
strcpy(password4, gtk_entry_get_text(GTK_ENTRY(password3))); 
trouve=verif(CIN4,password4);

if(trouve==1)
{
windowconnexion1=lookup_widget(button,"window_connexion1");
gtk_widget_destroy(windowconnexion1);
windowadmin=create_window_admin();
gtk_widget_show(windowadmin);
}
else
{
output=lookup_widget(button,"label_erreur_cnx11");
gtk_label_set_text(GTK_LABEL(output), "UTILISATEUR INTROUVABLE");
}

}


void
on_button_decnx_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue, *windowadmin;
windowadmin=lookup_widget(button,"window_admin");
gtk_widget_destroy(windowadmin);
windowbienvenue=create_window_bienvenue();
gtk_widget_show(windowbienvenue);
}





void
on_button_ajouter1_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
utilisateur s;
GtkWidget *no,*pre,*cin,*jour,*mois,*annee,*adr,*numtel,*mail,*pw ,*genre,*choix, *windowajoutsucc;
no = lookup_widget(button,"entry_nom1_aj");
pre = lookup_widget(button,"entry_prenom1_aj");
cin = lookup_widget(button,"entry_id1_aj");
jour = lookup_widget(button,"spinbutton_jour_brahim");
mois = lookup_widget(button,"spinbutton_mois_brahim");
annee = lookup_widget(button,"spinbutton_brahim_annee");
adr = lookup_widget(button,"entry_adr1_aj");
numtel = lookup_widget(button,"entry_numtel1_aj");
mail = lookup_widget(button,"entry_mail1_aj");
pw = lookup_widget(button,"entry_pw1_aj");
choix = lookup_widget (button ,"combobox_choix1_aj");
strcpy(s.nom,gtk_entry_get_text(GTK_ENTRY(no)));
strcpy(s.prenom,gtk_entry_get_text(GTK_ENTRY(pre)));
strcpy(s.CIN,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(s.adresse,gtk_entry_get_text(GTK_ENTRY(adr)));
strcpy(s.numtelephone,gtk_entry_get_text(GTK_ENTRY(numtel)));
strcpy(s.mail,gtk_entry_get_text(GTK_ENTRY(mail)));
strcpy(s.password,gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(s.choix, gtk_combo_box_get_active_text(GTK_COMBO_BOX(choix)));
s.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour));
s.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois));
s.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee));
if(x==1 )
{strcpy(s.genre,"femme");} 
else
{strcpy(s.genre,"homme");} 
ajouterutilisateur(s);
x=0;

windowajoutsucc=create_window_ajout_succ();
gtk_widget_show (windowajoutsucc);
}

void
on_radiobutton_femme1_aj_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=0;}
}


void
on_radiobutton_homme1_aj_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}




void
on_button_rechercher1_rech_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
char CIN5[50];
int k;

GtkWidget *idenr, *rech,*windowaffichagerecherche, *output,*windowadmin;
GtkWidget *treee;
GtkWidget *windowrechercher;
windowrechercher=lookup_widget(button,"window_rechercher");
windowadmin=create_window_admin();
idenr = lookup_widget(button,"entry_id1_rech11");
strcpy(CIN5,gtk_entry_get_text(GTK_ENTRY(idenr)));
k=rechercherutilisateur(CIN5);

if (k==0)	
	{	

	output=lookup_widget(button,"label_erreur_rech11");
	gtk_label_set_text(GTK_LABEL(output), "UTILISATEUR INTROUVABLE");
}

else
	{
	windowadmin=lookup_widget(button,"window_admin");
	gtk_widget_destroy(windowadmin);
	windowaffichagerecherche=create_window_affichage_recherche11();
	gtk_widget_show(windowaffichagerecherche);
	treee=lookup_widget(windowaffichagerecherche,"treeview_affichage_recherche11");

	affichageutilisateurrechercher(treee);


	}

}


void
on_button_supprimer1_supp_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
char CIN2[50];
FILE *f=fopen("utilisateur.txt","r");
utilisateur s;

GtkWidget *windowsup, *windoww, *iden,*output;
iden = lookup_widget(button,"entry_id1_supp");
output=lookup_widget(button,"label_erreur_supp11");
windoww=create_window_confirmer_supp();
strcpy(CIN2,gtk_entry_get_text(GTK_ENTRY(iden)));
while(fscanf(f,"%s \n",s.CIN)!=EOF)
{
if (strcmp(CIN2,s.CIN)==0)
{
supprimerutilisateur(CIN2);

gtk_widget_show(windoww);
}

}
}
void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* prenom;
gchar* CIN;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* genre;
gchar* adresse;
gchar* numtelephone;
gchar* mail;
gchar* password;
gchar* choix;
utilisateur s;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
GtkWidget* windowad,*tre,*CI,*no,*preno,*genr,*jou,*moi,*anne,*choi,*adress,*numtelephon,*mai,*passwor;

if (gtk_tree_model_get_iter(model, &iter,path))
{


gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&CIN,3,&jour,4,&mois,5,&annee,6,&genre,7,&adresse,8,&numtelephone,9,&mail,10,&password,11,&choix,-1);



windowad=create_window_admin();
gtk_widget_hide(windowad);

gtk_widget_show(windowad);

no=lookup_widget(windowad,"entry_nom1_mod");
gtk_entry_set_text(GTK_ENTRY(no),nom);

preno=lookup_widget(windowad,"entry_prenom1_mod");
gtk_entry_set_text(GTK_ENTRY(preno),prenom);

CI=lookup_widget(windowad,"entry_id1_mod");
gtk_entry_set_text(GTK_ENTRY(CI),CIN);

jou=lookup_widget(windowad,"spinbutton_jour1_mod");
gtk_entry_set_text(GTK_ENTRY(jou),jour);

moi=lookup_widget(windowad,"spinbuttonmois1_mod");
gtk_entry_set_text(GTK_ENTRY(moi),mois);

anne=lookup_widget(windowad,"spinbutton_annee1_mod");
gtk_entry_set_text(GTK_ENTRY(anne),annee);

adress=lookup_widget(windowad,"entry_adr1_mod");
gtk_entry_set_text(GTK_ENTRY(adress),adresse);

numtelephon=lookup_widget(windowad,"entry_numtel1_mod");
gtk_entry_set_text(GTK_ENTRY(numtelephon),numtelephone);

mai=lookup_widget(windowad,"entry_mail1_mod");
gtk_entry_set_text(GTK_ENTRY(mai),mail);

passwor=lookup_widget(windowad,"entry_pw1_mod");
gtk_entry_set_text(GTK_ENTRY(passwor),password);


}

}


void
on_button_actualiser1_aff_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tree,*windowadmin,*ibrahim;
windowadmin=lookup_widget(button,"window_admin");
ibrahim=create_window_admin();
gtk_widget_show(ibrahim);
gtk_widget_hide(windowadmin);
tree=lookup_widget(ibrahim,"treeview1");

affichageutilisateur(tree);

}


void
on_button_continue_aj_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajoutsuc;
windowajoutsuc=lookup_widget(button,"window_ajout_succ");
gtk_widget_destroy(windowajoutsuc);
}




void
on_button_annul_supp_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowadmin , *windowsupp; 
windowsupp=lookup_widget(button,"window_confirmer_supp");
gtk_widget_destroy(windowsupp);
}




void
on_button_inscri1_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *inscription1, *windowconnexion1;
windowconnexion1=lookup_widget(button,"window_connexion1");
gtk_widget_destroy(windowconnexion1);
inscription1=create_window_inscription1();
gtk_widget_show (inscription1);
}


void
on_button_insc1_insc_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
char nom1[50];
 char prenom1[50]; 
 char CIN1[50];
 char password1[50];
 char choix1[50];
GtkWidget *windowinscription1, *windowconnexion1,*no,*pre,*cin,*pw,*choix;
no = lookup_widget(button,"entry_nom1_insc");
pre = lookup_widget(button,"entry_prenom1_insc");
cin = lookup_widget(button,"entry_id1_insc");
pw = lookup_widget(button,"entry_pw1_insc");
choix = lookup_widget (button ,"combobox_choix1_insc");
strcpy(nom1,gtk_entry_get_text(GTK_ENTRY(no)));
strcpy(prenom1,gtk_entry_get_text(GTK_ENTRY(pre)));
strcpy(CIN1,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(password1,gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(choix1, gtk_combo_box_get_active_text(GTK_COMBO_BOX(choix)));
f=fopen("users.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s\n",nom1,prenom1,CIN1,password1,choix1);
fclose(f);
}

windowinscription1=lookup_widget(button,"window_inscription1");
gtk_widget_destroy(windowinscription1);
windowconnexion1=create_window_connexion1();
gtk_widget_show(windowconnexion1);
}


void
on_button_retour_insc_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowinscription1, *windowconnexion1;
windowinscription1=lookup_widget(button,"window_inscription1");
gtk_widget_destroy(windowinscription1);
windowconnexion1=create_window_connexion1();
gtk_widget_show(windowconnexion1);
}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	
}

void
on_button_confirm1_modif_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_accueil2_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue, *windowconnexion2;
windowconnexion2=lookup_widget(button,"window_connexion2");
gtk_widget_destroy(windowconnexion2);
windowbienvenue=create_window_bienvenue();
gtk_widget_show(windowbienvenue);
}


void
on_button_cnx2_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *CIN3, *password3, *windowconnexion2,*windownutri ,*output;
char CIN4[50];
char password4[50];
int trouve;

CIN3 = lookup_widget(button, "entry_id2_cnx") ;
password3 = lookup_widget(button, "entry_pw2_cnx") ;
strcpy(CIN4, gtk_entry_get_text(GTK_ENTRY(CIN3))); 
strcpy(password4, gtk_entry_get_text(GTK_ENTRY(password3))); 
trouve=verif(CIN4,password4);

if(trouve==1)
{
windowconnexion2=lookup_widget(button,"window_connexion2");
gtk_widget_destroy(windowconnexion2);
windownutri=create_window1med();
gtk_widget_show(windownutri);
}
else
{
output=lookup_widget(button,"label_erreur_cnx21");
gtk_label_set_text(GTK_LABEL(output), "UTILISATEUR INTROUVABLE");
}

}
void
on_button_cnx3_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *CIN3, *password3, *windowconnexion3,*windowafff ,*output;
char CIN4[50];
char password4[50];
int trouve;

CIN3 = lookup_widget(button, "entry_id3_cnx") ;
password3 = lookup_widget(button, "entry_pw3_cnx") ;
strcpy(CIN4, gtk_entry_get_text(GTK_ENTRY(CIN3))); 
strcpy(password4, gtk_entry_get_text(GTK_ENTRY(password3))); 
trouve=verif(CIN4,password4);

if(trouve==1)
{
windowconnexion3=lookup_widget(button,"window_connexion3");
gtk_widget_destroy(windowconnexion3);
windowafff=create_fenetre_afficher();
gtk_widget_show(windowafff);
}
else
{
output=lookup_widget(button,"label_erreur_cnx31");
gtk_label_set_text(GTK_LABEL(output), "UTILISATEUR INTROUVABLE");
}

}
void
on_button_accueil4_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue, *windowconnexion4;
windowconnexion4=lookup_widget(button,"window_connexion4");
gtk_widget_destroy(windowconnexion4);
windowbienvenue=create_window_bienvenue();
gtk_widget_show(windowbienvenue);
}


void
on_button_cnx4_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *CIN3, *password3, *windowconnexion4,*windowstock ,*output;
char CIN4[50];
char password4[50];
int trouve;

CIN3 = lookup_widget(button, "entry_id4_cnx") ;
password3 = lookup_widget(button, "entry_pw4_cnx") ;
strcpy(CIN4, gtk_entry_get_text(GTK_ENTRY(CIN3))); 
strcpy(password4, gtk_entry_get_text(GTK_ENTRY(password3))); 
trouve=verif(CIN4,password4);

if(trouve==1)
{
windowconnexion4=lookup_widget(button,"window_connexion4");
gtk_widget_destroy(windowconnexion4);
windowstock=create_window_stock();
gtk_widget_show(windowstock);
}
else
{
output=lookup_widget(button,"label_erreur_cnx41");
gtk_label_set_text(GTK_LABEL(output), "UTILISATEUR INTROUVABLE");
}
}

void
on_button_accueil5_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue, *windowconnexion5;
windowconnexion5=lookup_widget(button,"window_connexion5");
gtk_widget_destroy(windowconnexion5);
windowbienvenue=create_window_bienvenue();
gtk_widget_show(windowbienvenue);
}


void
on_button_cnx5_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *CIN3, *password3, *windowconnexion5,*windowreclam ,*output;
char CIN4[50];
char password4[50];
int trouve;

CIN3 = lookup_widget(button, "entry_id5_cnx") ;
password3 = lookup_widget(button, "entry_pw5_cnx") ;
strcpy(CIN4, gtk_entry_get_text(GTK_ENTRY(CIN3))); 
strcpy(password4, gtk_entry_get_text(GTK_ENTRY(password3))); 
trouve=verif(CIN4,password4);

if(trouve==1)
{
windowconnexion5=lookup_widget(button,"window_connexion5");
gtk_widget_destroy(windowconnexion5);
windowreclam=create_window_liste_reclamation();
gtk_widget_show(windowreclam);
}
else
{
output=lookup_widget(button,"label_erreur_cnx51");
gtk_label_set_text(GTK_LABEL(output), "UTILISATEUR INTROUVABLE");
}

}

void
on_button_cnx6_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *CIN3, *password3, *windowconnexion6,*windowcapt ,*output;
char CIN4[50];
char password4[50];
int trouve;

CIN3 = lookup_widget(button, "entry_id6_cnx") ;
password3 = lookup_widget(button, "entry_pw6_cnx") ;
strcpy(CIN4, gtk_entry_get_text(GTK_ENTRY(CIN3))); 
strcpy(password4, gtk_entry_get_text(GTK_ENTRY(password3))); 
trouve=verif(CIN4,password4);

if(trouve==1)
{
windowconnexion6=lookup_widget(button,"window_connexion6");
gtk_widget_destroy(windowconnexion6);
windowcapt=create_window_gestcapt();
gtk_widget_show(windowcapt);
}
else
{
output=lookup_widget(button,"label_erreur_cnx61");
gtk_label_set_text(GTK_LABEL(output), "UTILISATEUR INTROUVABLE");
}
}

void
on_button_accueil6_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue, *windowconnexion6;
windowconnexion6=lookup_widget(button,"window_connexion6");
gtk_widget_destroy(windowconnexion6);
windowbienvenue=create_window_bienvenue();
gtk_widget_show(windowbienvenue);
}


void
on_button_accueil3_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue, *windowconnexion3;
windowconnexion3=lookup_widget(button,"window_connexion3");
gtk_widget_destroy(windowconnexion3);
windowbienvenue=create_window_bienvenue();
gtk_widget_show(windowbienvenue);
}


void
on_button_retour_admin_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowadmin, *windowaffichagerecherche;
windowaffichagerecherche=lookup_widget(button,"window_affichage_recherche1");
gtk_widget_destroy(windowaffichagerecherche);
windowadmin=create_window_admin();
gtk_widget_show(windowadmin);
}





void
on_button_brahim_modif_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
utilisateur s1;
GtkWidget *no1,*pre1,*cin1,*jour1,*mois1,*annee1,*adr1,*numtel1,*mail1,*pw1 ,*genre1,*choix1, *windowmodifsucc;
no1 = lookup_widget(button,"entry_nom1_mod");
pre1 = lookup_widget(button,"entry_prenom1_mod");
cin1 = lookup_widget(button,"entry_id1_mod");
jour1 = lookup_widget(button,"spinbutton_jour1_mod");
mois1 = lookup_widget(button,"spinbuttonmois1_mod");
annee1 = lookup_widget(button,"spinbutton_annee1_mod");
adr1 = lookup_widget(button,"entry_adr1_mod");
numtel1 = lookup_widget(button,"entry_numtel1_mod");
mail1 = lookup_widget(button,"entry_mail1_mod");
pw1 = lookup_widget(button,"entry_pw1_mod");
choix1 = lookup_widget (button ,"combobox_choix1_mod");
strcpy(s1.nom,gtk_entry_get_text(GTK_ENTRY(no1)));
strcpy(s1.prenom,gtk_entry_get_text(GTK_ENTRY(pre1)));
strcpy(s1.CIN,gtk_entry_get_text(GTK_ENTRY(cin1)));
strcpy(s1.adresse,gtk_entry_get_text(GTK_ENTRY(adr1)));
strcpy(s1.numtelephone,gtk_entry_get_text(GTK_ENTRY(numtel1)));
strcpy(s1.mail,gtk_entry_get_text(GTK_ENTRY(mail1)));
strcpy(s1.password,gtk_entry_get_text(GTK_ENTRY(pw1)));
strcpy(s1.choix, gtk_combo_box_get_active_text(GTK_COMBO_BOX(choix1)));
s1.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour1));
s1.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois1));
s1.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee1));
if(y==1 )
{strcpy(s1.genre,"femme");} 
else
{strcpy(s1.genre,"homme");} 
modifierutilisateur(s1);
y=0;

windowmodifsucc=create_window_confirm_modif();
gtk_widget_show (windowmodifsucc);

}
void
on_radiobutton_homme1_mod_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=0;}
}


void
on_radiobutton_femme1_mod_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=1;}
}
void
on_button_continue_modif_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodifsucc;
windowmodifsucc=lookup_widget(button,"window_confirm_succ");
gtk_widget_destroy(windowmodifsucc);
}


void
on_button_dashboard_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue, *windowdashboard;
windowbienvenue=lookup_widget(button,"window_bienvenue");
gtk_widget_destroy(windowbienvenue);
windowdashboard=create_window_dashboard11();
gtk_widget_show(windowdashboard);
}


void
on_button_debit_admin_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowaffichdebit, *windowdashboard,*treee;
windowdashboard=lookup_widget(button,"window_dashboard11");
gtk_widget_destroy(windowdashboard);
windowaffichdebit=create_window_affichage_debit();
gtk_widget_show(windowaffichdebit);
treee=lookup_widget(windowaffichdebit,"treeview_debit");
affichedebit(treee);
}


void
on_button_accueil_dashboard_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue, *windowdash;
windowdash=lookup_widget(button,"window_dashboard11");
gtk_widget_destroy(windowdash);
windowbienvenue=create_window_bienvenue();
gtk_widget_show(windowbienvenue);
}


void
on_button_retour_debit_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowadmin, *windowaffichdebit;
windowaffichdebit=lookup_widget(button,"window_affichage_debit");
gtk_widget_destroy(windowaffichdebit);
windowadmin=create_window_admin();
gtk_widget_show(windowadmin);
}


void
on_treeview_debit_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


/////////////////////Mohamed///////////////////////////////


void
on_button1med_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{




GtkWidget *entr, *plat, *dess, *plait, *jour, *output,*output2;
Menu menutoadd;
int day;
int y;
    char char1[20];
    char char2[20];
    char char3[20];
    char char4[20];
    int x;

entr=lookup_widget(button,"entry1med");
plat=lookup_widget(button,"entry2med");
dess=lookup_widget(button,"entry3med");
plait=lookup_widget(button,"entry4med");
jour=lookup_widget(button,"spinbutton1med");

strcpy(menutoadd.entree,gtk_entry_get_text(GTK_ENTRY(entr)));
strcpy(menutoadd.plat,gtk_entry_get_text(GTK_ENTRY(plat)));
strcpy(menutoadd.dessert,gtk_entry_get_text(GTK_ENTRY(dess)));
strcpy(menutoadd.produit_laitier,gtk_entry_get_text(GTK_ENTRY(plait)));
day=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));






if ((strcmp(menutoadd.entree,""))==0||(strcmp(menutoadd.plat,"")==0)||(strcmp(menutoadd.dessert,"")==0)||(strcmp(menutoadd.produit_laitier,"")==0))
{  output=lookup_widget(button,"label15med");
output2=lookup_widget(button,"label50med");
gtk_label_set_text(GTK_LABEL(output),"");
gtk_label_set_text(GTK_LABEL(output2),"Données manquantes. \n Veuillez remplir tout les champs!");
}
else{

formater(menutoadd.entree);
formater(menutoadd.plat);
formater(menutoadd.dessert);
formater(menutoadd.produit_laitier);

if(!ajoutermenu(day,nummenu,menutoadd))
    {
        output=lookup_widget(button,"label15med");
output2=lookup_widget(button,"label50med");
gtk_label_set_text(GTK_LABEL(output),"le menu a bien été saisi.");
gtk_label_set_text(GTK_LABEL(output2),"");
}
             else
{       output=lookup_widget(button,"label15med");
output2=lookup_widget(button,"label50med");
gtk_label_set_text(GTK_LABEL(output),"le menu a déja été saisi.");
gtk_label_set_text(GTK_LABEL(output2),"");
                  
                  }
                 
}


}


void
on_button3med_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
GtkWidget *entr, *plat, *dess, *plait, *jour, *output,*output2;
Menu menutoadd;
int day;
int y;
    char char1[20];
    char char2[20];
    char char3[20];
    char char4[20];
    int x;

entr=lookup_widget(button,"entry5med");
plat=lookup_widget(button,"entry6med");
dess=lookup_widget(button,"entry7med");
plait=lookup_widget(button,"entry8med");
jour=lookup_widget(button,"spinbutton3med"); 

strcpy(menutoadd.entree,gtk_entry_get_text(GTK_ENTRY(entr)));
strcpy(menutoadd.plat,gtk_entry_get_text(GTK_ENTRY(plat)));
strcpy(menutoadd.dessert,gtk_entry_get_text(GTK_ENTRY(dess)));
strcpy(menutoadd.produit_laitier,gtk_entry_get_text(GTK_ENTRY(plait)));
day=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
formater(menutoadd.entree);
formater(menutoadd.plat);
formater(menutoadd.dessert);
formater(menutoadd.produit_laitier);








        if ((strcmp(menutoadd.entree,""))==0||(strcmp(menutoadd.plat,"")==0)||(strcmp(menutoadd.dessert,"")==0)||(strcmp(menutoadd.produit_laitier,"")==0))
{  output=lookup_widget(button,"label31med");
output2=lookup_widget(button,"label51med");
gtk_label_set_text(GTK_LABEL(output),"");
gtk_label_set_text(GTK_LABEL(output2),"Données manquantes. \n Veuillez remplir tout les champs!");
}
        
           
else{
                
            if (!modifiermenu(day,nummenu,menutoadd)){
                   output2=lookup_widget(button,"label51med");
output=lookup_widget(button,"label31med");
gtk_label_set_text(GTK_LABEL(output2),"");
gtk_label_set_text(GTK_LABEL(output),"le menu n'a pas encore été saisi.");
                 

                  }
                  else{


output2=lookup_widget(button,"label51med");
output=lookup_widget(button,"label31med");
gtk_label_set_text(GTK_LABEL(output),"le menu a bien été modifié.");
gtk_label_set_text(GTK_LABEL(output2),"");

}

}



}


void
on_button4med_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{


GtkWidget *jour, *output,*window2,*treeview1,*combobox1, *output2;
int day;
int typ=0;
Menu men;

combobox1=lookup_widget(button,"combobox1med");

if (!(gtk_combo_box_get_active(GTK_COMBO_BOX(combobox1))==-1)){
output2=lookup_widget(button,"label53med");
gtk_label_set_text(GTK_LABEL(output2),"");


 if (strcmp("Petit déjeuner",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
typ=1;

 else if (strcmp("Déjeuner",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
typ=2;

else if (strcmp("Diner",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
typ=3;



jour=lookup_widget(button,"spinbutton4med"); 
day=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));


men=cherchermenu(day,typ);

            if (strcmp(men.entree,"VACANT")==0)
               
{
output=lookup_widget(button,"label48med");
gtk_label_set_text(GTK_LABEL(output),"le menu n'a pas encore été saisi.");
}
            else
            {
              
              window2=lookup_widget(button,"window2med");
              window2=create_window2med();
              gtk_widget_show(window2);
              treeview1=lookup_widget(window2,"treeview1med");
 
              afficher(treeview1,men);
               
            }

}
else
{output2=lookup_widget(button,"label53med");
gtk_label_set_text(GTK_LABEL(output2),"Veuillez choisir un menu.");
}
}


void
on_button5med_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *jour, *output,*window3,*treeview2;
int day;

Menu_dujour menue;


day=jou;
menue= affichermenu(day);



 




          
              
              window3=lookup_widget(button,"window3med");
              window3=create_window3med();
              gtk_widget_show(window3);
              treeview2=lookup_widget(window3,"treeview2med");
 
              maffich(treeview2,menue);
               
            }







void
on_button9med_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window4,*treeview3,*output;
int lm,i,min=0;
int T[20];
lm=meilleurmenu(T);









           for (i=0;i<5;i++)
{
if (TAB[i]==1)
min=1;
}
            
         if (min==1)
{
     output=lookup_widget(button,"label52med");
gtk_label_set_text(GTK_LABEL(output),"");
              window4=lookup_widget(button,"window4med");
              window4=create_window4med();
              gtk_widget_show(window4);
              treeview3=lookup_widget(window4,"treeview3med");
 
              affichermeilleur(treeview3,T,lm,TAB);
            }
else 
 {
output=lookup_widget(button,"label52med");
gtk_label_set_text(GTK_LABEL(output),"Veuillez cocher au moins une case.");             
}
 
              


}


void
on_button6med_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
window2=lookup_widget(button,"window2med");
gtk_widget_destroy(window2);

}


void
on_button8med_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window3;
window3=lookup_widget(button,"window3med");
gtk_widget_destroy(window3);

}


void
on_button7med_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window4;
window4=lookup_widget(button,"window4med");
gtk_widget_destroy(window4);

}


void
on_radiobutton10med_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
nummenu=2;

}


void
on_radiobutton11med_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
nummenu=3;

}


void
on_radiobutton9med_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
nummenu=1;

}


void
on_radiobutton16med_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
nummenu=2;

}


void
on_radiobutton17med_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
nummenu=3;

}





void
on_checkbutton1med_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(togglebutton))
TAB[0]=1;
if(!(gtk_toggle_button_get_active(togglebutton)))
TAB[0]=0;
}


void
on_checkbutton3med_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
TAB[2]=1;
if(!(gtk_toggle_button_get_active(togglebutton)))
TAB[2]=0;

}


void
on_checkbutton4med_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
TAB[3]=1;
if(!(gtk_toggle_button_get_active(togglebutton)))
TAB[3]=0;
}


void
on_checkbutton5med_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
TAB[4]=1;
if(!(gtk_toggle_button_get_active(togglebutton)))
TAB[4]=0;
}


void
on_checkbutton2med_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(togglebutton))
TAB[1]=1;
if(!(gtk_toggle_button_get_active(togglebutton)))
TAB[1]=0;

}


void
on_radiobutton12med_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
nummenu=1;

}


void
on_radiobutton13med_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
nummenu=2;

}


void
on_radiobutton14med_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
nummenu=3;

}


void
on_radiobutton15med_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
nummenu=1;

}


void
on_treeview1med_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_treeview2med_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* dateee;
gchar* entreee;
gchar* plat;
gchar* dessert;
gchar* laitier;
Menu m;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
GtkWidget *windownut,*tre,*dt,*ent,*pla,*dess,*lait;

if (gtk_tree_model_get_iter(model, &iter,path))
{


gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&dateee,1,&entreee,2,&plat,3,&dessert,4,&laitier,-1);

windownut=create_window1med();
gtk_widget_hide(windownut);

gtk_widget_show(windownut);

dt=lookup_widget(windownut,"spinbutton1med");
gtk_entry_set_text(GTK_ENTRY(dt),dateee);

ent=lookup_widget(windownut,"entry1med");
gtk_entry_set_text(GTK_ENTRY(ent),entreee);

pla=lookup_widget(windownut,"entry2med");
gtk_entry_set_text(GTK_ENTRY(pla),plat);


dess=lookup_widget(windownut,"entry3med");
gtk_entry_set_text(GTK_ENTRY(dess),dessert);

lait=lookup_widget(windownut,"entry4med");
gtk_entry_set_text(GTK_ENTRY(lait),laitier);


}
}


void
on_treeview3med_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_calendar3med_day_selected           (GtkCalendar     *calendar,
                                        gpointer         user_data)
{
gtk_calendar_get_date(calendar,&ann,&moi,&jou);
moi+=1;
}

void
on_button2med_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
int day;
int y;
    char char1[20];
    char char2[20];
    char char3[20];
    char char4[20];
    int x;
GtkWidget  *jour, *output;
jour=lookup_widget(button,"spinbutton2med"); 
day=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));



 
            if(!supprimermenu(day,nummenu))

                {
          
                   output=lookup_widget(button,"label23med");
gtk_label_set_text(GTK_LABEL(output),"Il n'y a pas de menu à supprimer.");
                  

                  }
                  else{


output=lookup_widget(button,"label23med");
gtk_label_set_text(GTK_LABEL(output),"le menu a bien été supprimé.");

}

}

///////////////amine///////////////



void
on_treeview_liste_reclamation_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* titre;
gchar* id;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* genre;
gchar* email;
gchar* rec;

reclamation h;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
GtkWidget* windowliste,*email12,*rec12,*jour12,*mois12,*annee12,*id12,*titre12,*genre12;

if (gtk_tree_model_get_iter(model, &iter,path))
{


gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&titre,1,&email,2,&rec,3,&id,4,&genre,5,&jour,6,&mois,7,&annee, -1);



windowliste=create_window_modifier_reclamation();

gtk_widget_hide(windowliste);
gtk_widget_show(windowliste);

id12=lookup_widget(windowliste,"entry_id_modifier_rec");
gtk_entry_set_text(GTK_ENTRY(id12),id);

jour12=lookup_widget(windowliste,"spinbutton_jour_modifier_rec");
gtk_entry_set_text(GTK_ENTRY(jour12),jour);


mois12=lookup_widget(windowliste,"spinbutton_mois_modifier_rec");
gtk_entry_set_text(GTK_ENTRY(mois12),mois);

annee12=lookup_widget(windowliste,"spinbutton_annee_modifier_rec");
gtk_entry_set_text(GTK_ENTRY(annee12),annee);

email12=lookup_widget(windowliste,"entry_email_modifier_rec");
gtk_entry_set_text(GTK_ENTRY(email12),email);

rec12=lookup_widget(windowliste,"entry_rec_modifier_rec");
gtk_entry_set_text(GTK_ENTRY(rec12),rec);
}
}

void
on_button_ajouter_liste_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter11 ; 

ajouter11 = create_window_ajouter_reclamation();
gtk_widget_show(ajouter11);
}


void
on_button_supprimer_liste_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer11 ; 

supprimer11 = create_window_supprimer_reclamation();
gtk_widget_show(supprimer11);
}


void
on_button_modifier_liste_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifier11 ; 

modifier11 = create_window_modifier_reclamation();
gtk_widget_show(modifier11);
}


void
on_button_afficher_liste_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tree,*windowrec;
windowrec=lookup_widget(button,"window_liste_reclamation");
gtk_widget_destroy(windowrec);
windowrec=create_window_liste_reclamation();

tree=lookup_widget(windowrec,"treeview_liste_reclamation");

afficherreclamation(tree);
gtk_widget_hide(windowrec);
gtk_widget_show(windowrec);
}


void
on_button_chercher_liste_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *chercher11 ; 

chercher11 = create_window_chercher_reclamation();
gtk_widget_show(chercher11);
}


void
on_button_plus_reclame_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
int p; 



GtkWidget *reclame11 ,*output11; 
p = plus_reclame();
reclame11 = create_window_plus_reclame();
gtk_widget_show(reclame11);
if (p==0)
{
output11=lookup_widget(reclame11,"label_plus_reclame");
gtk_label_set_text(GTK_LABEL(output11),"Restauration");
}
else if (p==1)
{
output11=lookup_widget(reclame11,"label_plus_reclame");
gtk_label_set_text(GTK_LABEL(output11),"Hebergement");
}
else 
{
output11=lookup_widget(reclame11,"label_plus_reclame");
gtk_label_set_text(GTK_LABEL(output11),"Egalite");
}
}

////////////////ajouter rec///////////////////////////


void
on_radiobutton_homme_ajouter_rec_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{v=0;}
}


void
on_radiobutton_femme_ajouter_rec_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{v=1;}
}

void
on_button_accueil_ajouter_rec_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *acceuil3 ;
acceuil3=lookup_widget(button,"window_ajouter_reclamation");
gtk_widget_destroy(acceuil3);
}


void
on_button_ok_ajouter_rec_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
 reclamation h;
GtkWidget *titre,*email,*rec,*id,*genre,*jour,*mois,*annee;
titre=lookup_widget(button, "comboboxentry_titre_ajouter_rec");
email=lookup_widget(button, "entry_email_ajouter_rec");
rec=lookup_widget(button, "entry_rec_ajouter_rec");
id=lookup_widget(button, "entry_id_ajouter_rec");
jour=lookup_widget(button, "spinbutton_jour_ajouter_rec");
mois=lookup_widget(button, "spinbutton_mois_ajouter_rec");
annee=lookup_widget(button, "spinbutton_annee_ajouter_rec");

strcpy(h.titre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(titre)));
strcpy(h.email,gtk_entry_get_text(GTK_ENTRY(email)));
strcpy(h.rec,gtk_entry_get_text(GTK_ENTRY(rec)));
strcpy(h.id,gtk_entry_get_text(GTK_ENTRY(id)));
h.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
h.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
h.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
if(v==1)
{
strcpy(h.genre,"femme");
}
else
{
strcpy(h.genre,"homme");
}
ajouterreclamation (h);
v=0;
}

////////////////supprimer rec////////////////////////
int confirmation=0;
int *r=&confirmation;
void
on_checkbutton_confirmer_supprimer_rec_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
*r=1;
else
*r=0;
}


void
on_button_supp_supprimer_rec_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
char titre3[50];
char id3[50];

GtkWidget *id4,*titre4,*confirmation11;
titre4=lookup_widget(button, "comboboxentry_titre_supprimer_rec");
id4 = lookup_widget(button,"entry_id_supprimer_rec");
strcpy(titre3,gtk_combo_box_get_active_text(GTK_COMBO_BOX(titre4)));
strcpy(id3,gtk_entry_get_text(GTK_ENTRY(id4)));
if (confirmation==1)
supprimerreclamation(id3,titre3);
else
{
confirmation11=lookup_widget(button,"label_confirmer_supprimer_rec");
gtk_label_set_text(GTK_LABEL(confirmation11),"la confirmation est obligatoire");
}
}


void
on_button_accueil_supprimer_rec_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *acceuil4 ;
acceuil4=lookup_widget(button,"window_supprimer_reclamation");
gtk_widget_destroy(acceuil4);
}

///////////////modifier rec//////////////

void
on_radiobutton_homme_modifier_rec_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{w=0;}
}


void
on_radiobutton_femme_modifier_rec_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{w=1;}
}
void
on_button_modif_modifier_rec_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
reclamation h1;
GtkWidget *titre12,*email12,*rec12,*id12,*genre12,*jour12,*mois12,*annee12;
titre12=lookup_widget(button, "comboboxentry_titre_modifier_rec");
email12=lookup_widget(button, "entry_email_modifier_rec");
rec12=lookup_widget(button, "entry_rec_modifier_rec");
id12=lookup_widget(button, "entry_id_modifier_rec");
jour12=lookup_widget(button, "spinbutton_jour_modifier_rec");
mois12=lookup_widget(button, "spinbutton_mois_modifier_rec");
annee12=lookup_widget(button, "spinbutton_annee_modifier_rec");

strcpy(h1.titre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(titre12)));
strcpy(h1.email,gtk_entry_get_text(GTK_ENTRY(email12)));
strcpy(h1.rec,gtk_entry_get_text(GTK_ENTRY(rec12)));
strcpy(h1.id,gtk_entry_get_text(GTK_ENTRY(id12)));
h1.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour12));
h1.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois12));
h1.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee12));
if(w==1)
{
strcpy(h1.genre,"femme");
}
else
{
strcpy(h1.genre,"homme");
}
modifierreclamation (h1);
w=0;
}


void
on_button_accueil_modifier_rec_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *acceuil5 ;
acceuil5=lookup_widget(button,"window_modifier_reclamation");
gtk_widget_destroy(acceuil5);
}

/////////////////chercher rec///////////////////////////
void
on_treeview_chercher_rec_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button_cher_chercher_rec_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{

char identir[50];
GtkWidget *idenr, *rech,*output,*cher11;
GtkWidget *tree;

int e;
idenr = lookup_widget(button,"entry_id_chercher_rec");
strcpy(identir,gtk_entry_get_text(GTK_ENTRY(idenr)));
e=chercherreclamation(identir);
if (e==0)
	{
	
	output=lookup_widget(button,"label_chercher_rec");
	gtk_label_set_text(GTK_LABEL(output),"id n'existe pas");
	
	}
if (e==1)	
	{	

rech=create_window_chercher_reclamation();
tree=lookup_widget(rech,"treeview_chercher_rec");

afficherchercherreclamation(tree);

gtk_widget_hide(rech);
gtk_widget_show(rech);
}
}


void
on_button_accueil_chercher_rec_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *acceuil6 ;
acceuil6=lookup_widget(button,"window_chercher_reclamation");
gtk_widget_destroy(acceuil6);
}






void
on_button_decnx_capteur_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue, *windowgestcapt;
windowgestcapt=lookup_widget(button,"window_gestcapt");
gtk_widget_destroy(windowgestcapt);
windowbienvenue=create_window_bienvenue();
gtk_widget_show(windowbienvenue);
}


////////////////////////////////RAouf//////////////////////////////////
void
on_radiobutton_hom_ajt_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=0;}
}


void
on_radiobutton_fem_ajt_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}




void
on_button1_ajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
hebergement g;
GtkWidget *windowajout, *windowaff,*nom,*pre,*cin,*nmtel,*adr,*mail,*jour,*mois,*annee,*sexe,*numdechambre,*niv,*spec;
windowajout=create_fenetre_ajout();
nom = lookup_widget(button,"entry1_nom_ajt");
pre = lookup_widget(button,"entry1_prenom_ajt");
cin = lookup_widget(button,"entry1_cin_ajt");
nmtel=lookup_widget(button,"entry1_nmtel");
adr=lookup_widget(button,"entry1_adresse");
mail=lookup_widget(button,"entry1_email");
numdechambre=lookup_widget(button,"entrynumdechambre");
jour = lookup_widget(button,"spinbutton1_jour_ajt");
mois = lookup_widget(button,"spinbutton1_mois_ajt");
annee = lookup_widget(button,"spinbutton1_annee_ajt");
niv=lookup_widget(button,"raoufcomboboxentry1");
spec=lookup_widget(button,"raoufcomboboxentry2");
strcpy(g.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(g.prenom,gtk_entry_get_text(GTK_ENTRY(pre)));
strcpy(g.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(g.numerotel,gtk_entry_get_text(GTK_ENTRY(nmtel)));
strcpy(g.adresse,gtk_entry_get_text(GTK_ENTRY(adr)));
strcpy(g.email,gtk_entry_get_text(GTK_ENTRY(mail)));
strcpy(g.numcha,gtk_entry_get_text(GTK_ENTRY(numdechambre)));
strcpy(g.niv,gtk_combo_box_get_active_text(GTK_COMBO_BOX(niv)));
strcpy(g.spec,gtk_combo_box_get_active_text(GTK_COMBO_BOX(spec)));
g.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour));
g.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois));
g.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee));
if(x==1)
{strcpy(g.sexe,"femme");} 
else
{strcpy(g.sexe,"homme");}
if (y==4)
{strcpy(g.etage,"4");} 
else if (y==3)
{strcpy(g.etage,"3");}
else if (y==2)
{strcpy(g.etage,"2");}
else 
{strcpy(g.etage,"1");}
ajouterhebergement(g);
x=0;
y=0;

windowajout=lookup_widget(button,"fenetre_ajout");
gtk_widget_destroy(windowajout);
windowaff=create_fenetre_afficher();
gtk_widget_show(windowaff);
}



void
on_button1_retour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button2_retour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeview1_aff_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nomm;
gchar* prenomm;
gchar* cinn;
gchar* jourrr;
gchar* moisss;
gchar* anneeee;
gchar* sexee;
gchar* numtell;
gchar* adreess;
gchar* emaill;
gchar* etagee;
gchar* numchamb;
gchar* niveauu;
gchar* special;

produit p;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
GtkWidget* fenetre_ajout,*fenetre_afficher,*tre,*no,*prn,*c,*spc,*jjjj,*mmmm,*aaaa,*sxx,*nt,*adrs,*mal,*etag,*nch,*nive;

if (gtk_tree_model_get_iter(model, &iter,path))
{


gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nomm,1,&prenomm,2,&cinn,3,&jourrr,4,&moisss,5,&anneeee,6,&numtell,7,&adreess,8,&emaill,9,&sexee,10,&etagee,11,&numchamb,12,&niveauu,13,&special,-1);

fenetre_afficher=create_fenetre_afficher();
fenetre_ajout=create_fenetre_ajout();
gtk_widget_hide(fenetre_afficher);
gtk_widget_show(fenetre_ajout);

no=lookup_widget(fenetre_ajout,"entry1_nom_ajt");
gtk_entry_set_text(GTK_ENTRY(no),nomm);

prn=lookup_widget(fenetre_ajout,"entry1_prenom_ajt");
gtk_entry_set_text(GTK_ENTRY(prn),prenomm);

c=lookup_widget(fenetre_ajout,"entry1_cin_ajt");
gtk_entry_set_text(GTK_ENTRY(c),cinn);

jjjj=lookup_widget(fenetre_ajout,"spinbutton1_jour_ajt");
gtk_entry_set_text(GTK_ENTRY(jjjj),jourrr);

mmmm=lookup_widget(fenetre_ajout,"spinbutton1_mois_ajt");
gtk_entry_set_text(GTK_ENTRY(mmmm),moisss);

aaaa=lookup_widget(fenetre_ajout,"spinbutton1_annee_ajt");
gtk_entry_set_text(GTK_ENTRY(aaaa),anneeee);

nt=lookup_widget(fenetre_ajout,"entry1_nmtel");
gtk_entry_set_text(GTK_ENTRY(nt),numtell);

adrs=lookup_widget(fenetre_ajout,"entry1_adresse");
gtk_entry_set_text(GTK_ENTRY(adrs),adreess);

mal=lookup_widget(fenetre_ajout,"entry1_email");
gtk_entry_set_text(GTK_ENTRY(mal),emaill);

nch=lookup_widget(fenetre_ajout,"entrynumdechambre");
gtk_entry_set_text(GTK_ENTRY(nch),numchamb);


}
}

/////////////boutton rech fenetre d'affichage///////////////////
void
on_button2_rech_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowrechercher,*windowaff;
windowaff=lookup_widget(button,"fenetre_afficher");
gtk_widget_destroy(windowaff);
windowrechercher=create_heber_rech();
gtk_widget_show(windowrechercher);
}

/////////////boutton ajout fenetre d'affichage///////////////////
void
on_button2_ajout_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajout,*windowaff;
windowaff=lookup_widget(button,"fenetre_afficher");
gtk_widget_destroy(windowaff);
windowajout=create_fenetre_ajout();
gtk_widget_show(windowajout);
}

/////////////boutton modifier fenetre d'affichage///////////////////
void
on_button2_modif_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodif, *windowaff;
windowaff=lookup_widget(button,"fenetre_afficher");
gtk_widget_destroy(windowaff);
windowmodif=create_window_modifier();
gtk_widget_show (windowmodif);
}

/////////////boutton supp fenetre d'affichage///////////////////
void
on_button2_supr_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsupp,*windowaff;
windowaff=lookup_widget(button,"fenetre_afficher");
gtk_widget_destroy(windowaff);
windowsupp=create_heber_sup();
gtk_widget_show (windowsupp);
}

/////////////affichage de tree////////////////////////
void
on_button2_afficher_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tree,*windowafficher;
windowafficher=lookup_widget(button,"fenetre_afficher");
tree=lookup_widget(windowafficher,"treeview1_aff");
windowafficher=create_fenetre_afficher();
gtk_widget_show(windowafficher);
gtk_widget_destroy(windowafficher);

afficherhebergement (tree);


}


void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=3;}
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=2;}
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=1;}
}


void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=4;}
}


void
on_treeview2_mod_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button2_affmod_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}

//////////////////retour modifier///////////////////////
void
on_button2_retourmod_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodif, *windowafficher;
windowmodif=lookup_widget(button,"window_modifier");
gtk_widget_destroy(windowmodif);
windowafficher=create_fenetre_afficher();
gtk_widget_show (windowafficher);
}


void
on_checkbutton2_e1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{w=1;}
}


void
on_checkbutton2_e2_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{w=2;}
}


void
on_checkbutton2_e3_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{w=3;}
}


void
on_checkbutton2_e4_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{w=4;}
}


void
on_boutton2_modifier_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
hebergement g1;
GtkWidget *windowmodif, *windowafficher, *nom1,*pre1,*cin1,*nmtel1,*adr1,*mail1,*jour1,*mois1,*annee1,*sexe1,*numdechambre1,*niv1,*spec1;
nom1 = lookup_widget(button,"entry2_nom_mod");
pre1 = lookup_widget(button,"entry2_prenom_mod");
cin1 = lookup_widget(button,"entry2_cin_mod");
nmtel1=lookup_widget(button,"entry2_numtel");
adr1=lookup_widget(button,"entry2_adresse");
mail1=lookup_widget(button,"entry2_email");
numdechambre1=lookup_widget(button,"entry2_numchamb");
jour1 = lookup_widget(button,"spinbutton2_jour_mod");
mois1 = lookup_widget(button,"spinbutton2_mois_mod");
annee1 = lookup_widget(button,"spinbutton2_annee_mod");
niv1=lookup_widget(button,"raoufcomboboxentry3");
spec1=lookup_widget(button,"raoufcomboboxentry4");
strcpy(g1.nom,gtk_entry_get_text(GTK_ENTRY(nom1)));
strcpy(g1.prenom,gtk_entry_get_text(GTK_ENTRY(pre1)));
strcpy(g1.cin,gtk_entry_get_text(GTK_ENTRY(cin1)));
strcpy(g1.numerotel,gtk_entry_get_text(GTK_ENTRY(nmtel1)));
strcpy(g1.adresse,gtk_entry_get_text(GTK_ENTRY(adr1)));
strcpy(g1.email,gtk_entry_get_text(GTK_ENTRY(mail1)));
strcpy(g1.numcha,gtk_entry_get_text(GTK_ENTRY(numdechambre1)));
strcpy(g1.niv,gtk_combo_box_get_active_text(GTK_COMBO_BOX(niv1)));
strcpy(g1.spec,gtk_combo_box_get_active_text(GTK_COMBO_BOX(spec1)));
g1.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour1));
g1.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois1));
g1.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee1));
if(z==1)
{strcpy(g1.sexe,"femme");} 
else
{strcpy(g1.sexe,"homme");}
if (w==4)
{strcpy(g1.etage,"4");} 
else if (w==3)
{strcpy(g1.etage,"3");}
else if (w==2)
{strcpy(g1.etage,"2");}
else 
{strcpy(g1.etage,"1");}
modifierhebergement(g1);
z=0;
w=0;
windowmodif=lookup_widget(button,"window_modifier");
gtk_widget_destroy(windowmodif);
windowafficher=create_fenetre_afficher();
gtk_widget_show (windowafficher);
}


void
on_radiobutton2_hom_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=0;}
}


void
on_radiobutton2_fem_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=1;}
}


void
on_button3_supprimer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
char cin[20];
char text[20];
char text3[20];
int ce;
GtkWidget *windowsup, *windowaff, *iden;
GtkWidget *outputMsg2;
GtkWidget *outputMsg3;
iden = lookup_widget(button,"entry4_cin");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(iden)));
ce=rechercherhebergement(cin);
if (ce==0)
	{
	strcpy(text,"Cin n'existe pas");
        outputMsg2=lookup_widget(button,"label74"); 
        gtk_label_set_text(GTK_LABEL(outputMsg2),text);	
	}
else {	
supprimerhebergement(cin);

strcpy(text3,"Operation terminer");
outputMsg3=lookup_widget(button,"label75"); 
gtk_label_set_text(GTK_LABEL(outputMsg3),text3);


}
}


void
on_button3_rechercher_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
char cin[20];
char text[20];
GtkWidget *ci, *rech,*oui,*non;
GtkWidget *tree;
GtkWidget *windowrechercher;
GtkWidget *outputMsg1;

int ce;
windowrechercher=lookup_widget(button,"heber_rech");
oui=create_heber_affrech();
ci = lookup_widget(button,"entry4_rech");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(ci)));
ce=rechercherhebergement(cin);
if (ce==0)
	{
	strcpy(text,"Cin n'existe pas");
        outputMsg1=lookup_widget(button,"label73"); 
        gtk_label_set_text(GTK_LABEL(outputMsg1),text);	
	}
if (ce==1)	
	{	

gtk_widget_destroy(windowrechercher);
tree=lookup_widget(oui,"treeview3_rech");

affichage_hebergement_rechercher(tree);
gtk_widget_show(oui);
}		
}


void
on_treeview3_rech_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}



void
on_button_niveau_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button2_retour_supp_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsup, *windowaff;

windowsup=lookup_widget(button,"heber_sup");
gtk_widget_destroy(windowsup);
windowaff=create_fenetre_afficher();
gtk_widget_show(windowaff);

////windowsupp=lookup_widget(button,"window_supprimer");
////gtk_widget_destroy(windowsupp);
///windowafficher=create_fenetre_afficher();
///gtk_widget_show (windowafficher);

}





void
on_button1_retourajout_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajout, *windowaff;
windowajout=lookup_widget(button,"fenetre_ajout");
gtk_widget_destroy(windowajout);
windowaff=create_fenetre_afficher();
gtk_widget_show (windowaff);
}

///////////bouton vers window tache2/////////////////
void
on_button1_Totalniveau_clicked         (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkCalendar *ajc;
GtkWidget *windowaff,*windowniv;
hebergement g;
guint day,month,year;
ajc=lookup_widget(objet,"ajc");
gtk_calendar_get_date(GTK_CALENDAR(ajc),&day,&month,&year);
g.date.jour=year;
g.date.mois=month+1;
g.date.annee=day;

windowaff=lookup_widget(objet,"fenetre_afficher");
gtk_widget_destroy(windowaff);
windowniv=create_nbr_de_niveau();
gtk_widget_show(windowniv);

}
//////////bouton retour chercher/////////////////////
void
on_buttonR_retourchercher_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowrech, *windowaff;
windowrech=lookup_widget(button,"heber_rech");
gtk_widget_destroy(windowrech);
windowaff=create_fenetre_afficher();
gtk_widget_show (windowaff);
}

/////////////// retour window tache2/////////////////
void
on_button1R_retourwtach2_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowtache2, *windowaff;
windowtache2=lookup_widget(button,"nbr de niveau");
gtk_widget_destroy(windowtache2);
windowaff=create_fenetre_afficher();
gtk_widget_show (windowaff);
}

/////////////retour window affichage de chercher//////
void
on_button2R_retouraffrech_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowaffrech, *windowaff;
windowaffrech=lookup_widget(button,"heber_affrech");
gtk_widget_destroy(windowaffrech);
windowaff=create_fenetre_afficher();
gtk_widget_show (windowaff);
}




void
on_button_calcul_etage_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *somme;
int sum;
somme = lookup_widget(button, "label66") ;
sum=niveau(calcul,"hebergement.txt");
sprintf(so,"%d",sum);
gtk_label_set_text(GTK_LABEL(somme),so);
}


void
on_checkbutton5R_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[0]=1;
}
else
{calcul[0]=0;}
}




void
on_checkbutton6R_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[1]=1;
}
else
{calcul[1]=0;}
}


void
on_checkbutton7R_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[2]=1;
}
else
{calcul[2]=0;}
}


void
on_checkbutton8R_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[3]=1;}
else
{calcul[3]=0;}
}

//////////////deconexion vers home/////////////////
void
on_button_deconexion_raouf_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue, *windowaff;
windowaff=lookup_widget(button,"fenetre_afficher");
gtk_widget_destroy(windowaff);
windowbienvenue=create_window_bienvenue();
gtk_widget_show(windowbienvenue);
}






///////////////////////////////////dashboard///////////////////////////////
void
on_button_calcul_etagedash_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *somme;
int sum;
somme = lookup_widget(button, "label66") ;
sum=niveau(calcul,"hebergement.txt");
sprintf(so,"%d",sum);
gtk_label_set_text(GTK_LABEL(somme),so);
}


void
on_button5meddash_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tree,*windowdash,*output;
int lm,i,min=0;
int T[20];
lm=meilleurmenu(T);
           for (i=0;i<5;i++)
{
if (TAB[i]==1)
min=1;
}
            
         if (min==1)
{
     output=lookup_widget(button,"label52med");
gtk_label_set_text(GTK_LABEL(output),"");
              windowdash=lookup_widget(button,"window_dashboard11");
		gtk_widget_destroy(windowdash);
		windowdash=create_window_dashboard11();
		tree=lookup_widget(windowdash,"treeview3meddash");

		affichermeilleur(tree,T,lm,TAB);

		gtk_widget_hide(windowdash);
		gtk_widget_show(windowdash);
 
              
            }
else 
 {
output=lookup_widget(button,"label52med");
gtk_label_set_text(GTK_LABEL(output),"Veuillez cocher au moins une case.");             
}

}




void
on_button_debit_admindash_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treee,*windowdash;
windowdash=lookup_widget(button,"window_dashboard11");		gtk_widget_destroy(windowdash);
windowdash=create_window_dashboard11();		treee=lookup_widget(windowdash,"treeview_debitdash");

affichedebit(treee);
gtk_widget_hide(windowdash);
gtk_widget_show(windowdash);


}


void
on_button_plus_reclamedash_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
int p; 
GtkWidget *windowdash ,*output11; 
p = plus_reclame();
windowdash = create_window_dashboard11();
gtk_widget_show(windowdash);
if (p==0)
{
output11=lookup_widget(windowdash,"label_plus_reclame");
gtk_label_set_text(GTK_LABEL(output11),"Restauration");
}
else if (p==1)
{
output11=lookup_widget(windowdash,"label_plus_reclame");
gtk_label_set_text(GTK_LABEL(output11),"Hebergement");
}
else 
{
output11=lookup_widget(windowdash,"label_plus_reclame");
gtk_label_set_text(GTK_LABEL(output11),"Egalite");
}
}


void
on_button3_rupdash_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
produit a;
GtkWidget  *windowdash;
GtkWidget *tree1;
remove("produitrupturer.txt");
windowdash=lookup_widget(button,"window_dashboard11");
gtk_widget_destroy(windowdash);

a=rupturer();
windowdash=create_window_dashboard11 ();
tree1=lookup_widget(windowdash,"treeview4");
affichageproduitrupturer(tree1);

gtk_widget_hide(windowdash);
gtk_widget_show(windowdash);
}


void
on_button6_listecapteurdash_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowdash;
GtkWidget *tree;
GtkWidget *tree1;
windowdash=lookup_widget(button,"window_dashboard11");
gtk_widget_destroy(windowdash);
windowdash=create_window_dashboard11 ();
tree1=lookup_widget(windowdash,"treeview6_captfumeedash");
afficher_alarme(tree1);
tree1=lookup_widget(windowdash,"treeview6_captmouvdash");
afficher_alarme1(tree1);
gtk_widget_hide(windowdash);
gtk_widget_show(windowdash);
}





void
on_buttondcxmed_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue, *windowmed, *windowmed1, *windowmed2, *windowmed3;
windowmed=lookup_widget(button,"window1med");
gtk_widget_destroy(windowmed);
windowmed1=lookup_widget(button,"window2med");
gtk_widget_destroy(windowmed1);
windowmed2=lookup_widget(button,"window3med");
gtk_widget_destroy(windowmed2);
windowmed3=lookup_widget(button,"window4med");
gtk_widget_destroy(windowmed3);
windowbienvenue=create_window_bienvenue();
gtk_widget_show(windowbienvenue);

}


void
on_buttondcxamine_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue, *windowmed, *windowmed1, *windowmed2, *windowmed3, *windowmed4;
windowmed=lookup_widget(button,"window_liste_reclamation");
gtk_widget_destroy(windowmed);
windowmed1=lookup_widget(button,"window_ajouter_reclamation");
gtk_widget_destroy(windowmed1);
windowmed2=lookup_widget(button,"window_modifier_reclamation");
gtk_widget_destroy(windowmed2);
windowmed3=lookup_widget(button,"window_chercher_reclamation");
gtk_widget_destroy(windowmed3);
windowmed4=lookup_widget(button,"window_plus_reclame");
gtk_widget_destroy(windowmed4);
windowbienvenue=create_window_bienvenue();
gtk_widget_show(windowbienvenue);
}

