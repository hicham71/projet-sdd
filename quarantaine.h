#ifndef QUARANTAINE_H_INCLUDED
#define QUARANTAINE_H_INCLUDED
#include "hotel.h"

typedef struct
{
    liste_personne_contact *pc;
}persenneenquarantaine;

typedef struct
{
    persenneenquarantaine data;
    struct quarantine *suivant;
}quarantine;

typedef quarantine *liste_quarantine;
liste_hotel *lho;

persenneenquarantaine * nouveau_personne_quarataine(liste_hotel*lho);
liste_quarantine * initialisier_quarantaine();
void affichie_personne_quarantine(persenneenquarantaine pq,liste_hotel*lho);
void affichie_liste_quarantine(liste_quarantine * lq,liste_hotel * lho);
void ajouter_quarantaine(liste_quarantine *lq,persenneenquarantaine pq);
#endif // QUARANTAINE_H_INCLUDED
