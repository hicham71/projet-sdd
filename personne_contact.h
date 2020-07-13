#ifndef PERSONNE_CONTACT_H_INCLUDED
#define PERSONNE_CONTACT_H_INCLUDED

typedef struct {
  char nom[25];
}maladies;

typedef struct {
 maladies data;
 struct NODE *next;
}NODE;

typedef NODE *liste_m;
typedef struct
{
   int jj,mm,aa;
}Date;
typedef struct
{
    char nom[25];
    char prenom[25];
    int age;
    char adresse[40];
    liste_m  mp ;
    Date dateD ,dateF;
    char boulvard[25];
    char NomHotel[25];
}personne_contact;

typedef struct {
  personne_contact Data;
  struct Element*suivant;
}Element;

typedef Element *liste_personne_contact;


maladies *maladiesdepersonne();
liste_m *initialiser_maladep();
void affichie_maladiep(maladies m);
void affichier_liste_m(liste_m *L);
void ajouter_maladiep(liste_m * L,maladies m);
Date datesysteme();
Date dateFin0(Date D);
personne_contact *nouveaupersonnecontact();
void affichiepersonnecontact(personne_contact P);
liste_personne_contact *initialiserlistepersonne();
void Affichelistepersonne(liste_personne_contact *L);
void ajouterpersonne(liste_personne_contact * L,personne_contact P);
#endif // PERSONNE_CONTACT_H_INCLUDED
