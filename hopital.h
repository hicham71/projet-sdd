#ifndef HOPITAL_H_INCLUDED
#define HOPITAL_H_INCLUDED
#include "patient.h"
typedef struct {
 int nombredelitdispo,nombresalesbesoine,nombredemedcines,nombredeparamedicaux;
 int Codep,nombrelitmax; //code postal de boulvard
 char Nom[30],adresse[50];
}hopitaux;
typedef struct {
 hopitaux data;
 struct ELEMENT *suivant;
}ELEMENT;

typedef ELEMENT *Liste_hopitaux;
hopitaux *nouveauhopital();
void affichehopital(hopitaux h);
Liste_hopitaux *initialiser_liste_hopital();
void affichie_liste_hopitaux(Liste_hopitaux *Lh);
void ajouter_hopital(Liste_hopitaux*Lh,hopitaux h);
void modification_hopital(Liste_hopitaux*Lh,char *Nom);
void affectation_patienten_hopital(Liste_hopitaux *Lh,liste_patient *l);
void modification_etatpatient(liste_patient *l,Liste_hopitaux*Lh,int mat);
#endif // HOPITAL_H_INCLUDED
