#include "hotel.h"
#include "personne_contact.h"
hotel *nouveau_hotel()
{
   hotel *ht =malloc(sizeof(hotel));
    if(ht==NULL)
    {
        exit(-1);
    }
    color(15,0);printf("/**********les informations de l'hotel *************/ :\n");
    color(10,0);printf("donner le nom de l'hotel :");
    fflush(stdin);
    color(15,0);gets(&ht->Nom);

    color(10,0);printf("lieu de l'hotel :");
    color(15,0);scanf("%s",&ht->lieu);

    color(10,0);printf("boulvard de l'hotel :");
    color(15,0);scanf("%s",&ht->boulvard);

    color(10,0);printf("nombre des chambres  maximale de l'hotel :");
    color(15,0);scanf("%d",&ht->nbrchambremax);
    ht->nbrchambredispo =ht->nbrchambremax;

    ht->ph =initialiserlistepersonne();
    return ht;

}
void affiche_hotel(hotel ht)
{
    color(11,0);printf("/*****info****/\n");
    color(11,0);printf("Nom : %s\n",ht.Nom);
    color(11,0);printf("lieu : %s\n",ht.lieu);
    color(11,0);printf("Boulvard :%s\n ",ht.boulvard);
    color(11,0);printf("nombre chambre  : %d\n",ht.nbrchambremax);
    Affichelistepersonne(ht.ph);
}

liste_hotel *initialiser_liste_hotel()
{

    liste_hotel *l=malloc(sizeof(liste_hotel));
    Node *N =malloc(sizeof(Node));
    if(l==NULL || N==NULL)
    {
        exit(-1);
    }
    N->data =*nouveau_hotel();
    N->suivant =NULL;
    *l=N;
    return l;
}

void affichie_liste_hotel(liste_hotel lho)
{
    Node *N =lho;
    if(lho!=NULL)
    {
        while(N!=NULL)
        {
             affiche_hotel(N->data);
             N= N->suivant;
        }
    }
}

void ajouter_hotel(liste_hotel *lho,hotel ht)
{
    Node *N =(Node*)malloc(sizeof(Node));
    Node *ptp =*lho;
    N->data =ht;
    N->suivant =NULL;
    if(*lho!=NULL)
    {
        while(ptp->suivant!=NULL)
        {
            ptp =ptp->suivant;
        }
        ptp->suivant =N;
    }
    else
        *lho=N;
}
void ajouterpersonneenhotel(hotel n,liste_personne_contact *P)
{
    Element *tmp = *P;
       while(tmp!=NULL)
        {
            if((strcmp(n.boulvard,tmp->Data.boulvard)==0)&& ((strcmp(tmp->Data.NomHotel,n.Nom)) && (strcmp(tmp->Data.NomHotel,"vide")==0))){
          strcpy(tmp->Data.NomHotel,n.Nom);
          ajouterpersonne(n.ph,tmp->Data);
          }
          tmp =tmp->suivant;
        }

}
void ajouterdescontactdunpatientunhotel(liste_hotel *l,liste_patient *lp){

    Node *n =*l;
  while(n!=NULL)
  {
    if(n->data.nbrchambredispo >0){
    element_patient *e = *lp;
    while(e!=NULL){
                ajouterpersonneenhotel(n->data,e->data.pc);

                 e =e->suivant;
             }
             n->data.nbrchambredispo--;
       }
              n = n->suivant;
    }
  }
