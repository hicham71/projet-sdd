#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED
#include "personne_contact.h"
typedef int bool ;
#define false  0
#define true  1
const char *etat[] = {"normal","critique","geurie","mort"};
const char *genre[] = {"homme","femme"};
 //les structures des maladies chroniques
typedef struct {
  char nom[25];
}maladies_chronique;

typedef struct {
 maladies_chronique data;
 struct node *next;
}node;

typedef node *liste;
//les structures du patient
typedef struct {
  int matricule;
  int age;
  int codeP;
  bool cont;
  char nom[25],prenom[25];
  char adresse[40],cas[20],genre[20];
  liste_personne_contact *pc;
  liste mc;
  char hopital[25];
}patient;
typedef struct{
   patient data;
   struct element_patient * suivant;
}element_patient;

typedef element_patient *liste_patient;

//liste des maladies chronique du patient

maladies_chronique *maladiesdepatient();
liste *initialiser_malade();
void affichie_maladie(maladies_chronique m);
void affichier_liste(liste *L);
void ajouter_maladie(liste * L,maladies_chronique m);
// liste des patient qui a coronavirus
patient *nouveaupatient();
void affichiepatient(patient p);
liste_patient *initialiserliste();
void Afficher(liste_patient *l);
void ajouterpatient(liste_patient * l,patient p);
bool contamination_patient();
void recherchepatient(liste_patient *l,int matricule);
void recherchepatient_par_nom(liste_patient *l,char *nom);
void recherchepatient_par_genre(liste_patient *l,char *genre);
element_patient *supprimier_patient(element_patient*tmp,element_patient*ptmp);
void supprimer_patient_guerie(liste_patient *l);
#endif // PATIENT_H_INCLUDED
