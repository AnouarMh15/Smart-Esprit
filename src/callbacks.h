#include <gtk/gtk.h>


void
on_treeview_aff_stock_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_wnd_ajouter_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_afficher_stock_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_wnd_modif_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_wnd_supp_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_wnd_rech_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_wind_rupture_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_restaurant_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_general_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_nouveau_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_ancien_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button1_retour_ajt_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_ajt_stock_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_modi_stock_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2_rechstock_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button2_retour_rech_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_retournon_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_retrechercher_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_rechercher_stock_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview3_affrupture_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button3_retour_rupture_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button6_ajoutercapteur_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button6_modcapteur_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button6_supcapt_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button6_rechcapteur_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button6_listecapteur_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton3_fumee_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_mouvement_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button6_retour_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button6_modifcapteur_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button6_affcapteur_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton7_confirmer_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button6_rrsupcapt_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button7_actualiser_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button7_supaffcapteur_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button7_supcapteur_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview4_capteur_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview5_affrechcapteur_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button8_rechcapteur_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button8_rraff_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button8_actaff_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview6_captfumee_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview6_captmouv_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button9_rrliste_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_calendar1_stock_day_selected        (GtkCalendar     *calendar,
                                        gpointer         user_data);

void
on_button2_retour_sup_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_supprimer_produit_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton3_suprupture_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_admin_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_nutrition_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_foyer_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_stock_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_reclamation_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_alarme_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_dashboard_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_accueil1_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_cnx1_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_inscri1_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_decnx_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ajouter1_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_brahim_modif_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_rechercher1_rech_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supprimer1_supp_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_actualiser1_aff_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_continue_aj_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_annul_supp_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_continue_modif_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_insc1_insc_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_insc_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_accueil2_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_cnx2_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_accueil3_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_cnx3_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_accueil4_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_cnx4_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_accueil5_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_cnx5_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_accueil6_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_cnx6_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_admin_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_debit_admin_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_accueil_dashboard_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_debit_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_homme1_aj_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme1_aj_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_homme1_mod_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme1_mod_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview_debit_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_radiobutton9med_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton10med_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton11med_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button1med_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton12med_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton13med_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton14med_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button2med_enter                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton17med_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton16med_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton15med_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button3med_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4med_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_calendar3med_day_selected           (GtkCalendar     *calendar,
                                        gpointer         user_data);

void
on_button5med_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton5med_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton4med_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3med_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2med_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1med_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button9med_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1med_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button6med_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2med_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button8med_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview3med_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button7med_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2med_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton10med_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton11med_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton9med_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton12med_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton13med_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton14med_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton16med_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton17med_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton15med_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview_liste_reclamation_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_ajouter_liste_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supprimer_liste_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modifier_liste_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_afficher_liste_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_chercher_liste_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_plus_reclame_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_homme_ajouter_rec_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme_ajouter_rec_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_accueil_ajouter_rec_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ok_ajouter_rec_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_confirmer_supprimer_rec_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_supp_supprimer_rec_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_accueil_supprimer_rec_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_homme_modifier_rec_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme_modifier_rec_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_modif_modifier_rec_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_accueil_modifier_rec_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_chercher_rec_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_cher_chercher_rec_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_accueil_chercher_rec_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_button16_ajoutercapteur_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button16_ajoutercapteur_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton3_fumee_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_mouvement_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_fumee_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_mouvement_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_decnx_capteur_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_femme1_aj_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_homme1_aj_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_homme1_mod_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme1_mod_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_restaurant_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_general_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button2_retourmod_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton2_hom_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_fem_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_e1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_e2_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_e3_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_e4_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_boutton2_modifier_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_hom_ajt_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_fem_ajt_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button1_ajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_aff_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_deconexion_raouf_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_ajout_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_supr_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_rech_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_modif_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_afficher_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_Totalniveau_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_retour_supp_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3_supprimer_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonR_retourchercher_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3_rechercher_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview3_rech_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button1R_retourwtach2_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton5R_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton6R_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton7R_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton8R_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_calcul_etage_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_retourajout_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2R_retouraffrech_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_homme_ajouter_rec_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme_ajouter_rec_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_homme_modifier_rec_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme_modifier_rec_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview4_capteur_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_stockdexx_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button5med_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton5R_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton6R_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton7R_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton8R_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_calcul_etagedash_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button5meddash_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton5med_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton4med_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3med_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2med_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1med_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_debit_admindash_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_plus_reclamedash_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3_rupdash_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button6_listecapteurdash_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_debit_admin_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttondcxmed_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttondcxamine_clicked              (GtkButton       *button,
                                        gpointer         user_data);
