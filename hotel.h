#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED
#include "patient.h"
#include "personne_contact.h"
typedef struct
{
    char Nom[25],lieu[25],boulvard[25];
    int nbrchambredispo,nbrchambremax;
    liste_personne_contact *ph;

}hotel;
typedef struct
{
    hotel data;
    struct Node *suivant;
}Node;

typedef Node * liste_hotel;
liste_patient *lc;

hotel *nouveau_hotel();
void affiche_hotel(hotel ht);
liste_hotel *initialiser_liste_hotel();
void affichie_liste_hotel(liste_hotel lho);
void ajouter_hotel(liste_hotel*lho,hotel ht);
void ajouterpersonneenhotel(hotel n,liste_personne_contact *P);
void affichiertouslescontact(liste_hotel*l);
void affichierlescontactdunhotel(Node *N);
void ajouterdescontactdunpatientunhotel(liste_hotel *l,liste_patient *lp);
#endif // HOTEL_H_INCLUDED
