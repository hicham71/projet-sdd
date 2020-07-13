#include "personne_contact.h"
#include<time.h>
personne_contact *nouveaupersonnecontact()
{
    int n,j;
    personne_contact *P = (personne_contact*)malloc(sizeof(personne_contact));
    liste_m *m =initialiser_maladep();
    if(P==NULL)
    {
        exit(-1);
    }
    color(15,0);printf("/*****les informations des personnes contacts *****/:\n");
    color(12,0);printf("Nom de personne : ");
    color(7,0);scanf("%s",&P->nom);

    color(12,0);printf("prenom de personne : ");
    color(7,0);scanf("%s",&P->prenom);

    color(12,0);printf("Adresse de personne : ");
    color(7,0);scanf("%s",&P->adresse);

    color(12,0);printf("Age de personne : ");
    color(7,0);scanf("%d",&P->age);

    color(12,0);printf("boulvard de personne : ");
    color(7,0);scanf("%s",&P->boulvard);

    strcpy(P->NomHotel,"vide");
    color(4,0);printf("Ce personne souffre-t-il de maladies chroniques? oui(1)/non(2) :");
    scanf("%d",&n);
    if(n==1){
    color(12,0);printf("Nombre de maladies : ");
    color(7,0);scanf("%d",&n);
        for(j=0;j<n;j++)
        {
         ajouter_maladiep(m,*maladiesdepersonne());
        }
         P->mp =m;
    }
        P->dateD = datesysteme();
        P->dateF = dateFin0(P->dateD);
    return P;
}
Date datesysteme()
{
    Date D;
     time_t intps;
    struct tm * tm;
    intps = time(NULL);
    tm = localtime(&intps);
     D.jj =tm->tm_mday;
     D.mm =tm->tm_mon+1;
     D.aa =tm->tm_year+1900;

     return D;

}
Date dateFin0(Date D)
{
    Date F;
    int rest;
    if(D.mm == 1 || D.mm == 3 || D.mm == 5 || D.mm == 7 || D.mm == 8 || D.mm == 10)
    {
        if(D.jj + 21 > 31)
        {
            F.jj = D.jj + 21;
            rest = F.jj - 31;
            F.jj = rest;
            F.mm = D.mm + 1;
            F.aa = D.aa;
        }
        else
            F = D;
    }



    else if(D.mm == 4 || D.mm == 6 || D.mm == 9 || D.mm == 11 )
    {
        if(D.jj + 21 > 30)
        {
            F.jj = D.jj + 21;
            rest = F.jj - 30;
            F.jj = rest;
            F.mm = D.mm + 1;
            F.aa = D.aa;
        }
        else
            F = D;
    }
    else if(D.mm == 12 )
    {
        if(D.jj + 21 > 31)
        {
            F.jj = D.jj + 21;
            rest = F.jj - 31;
            F.jj = rest;
            F.mm = D.mm + 1;
            F.aa = D.aa + 1;
        }
        else
            F = D;
    }
     else if(D.mm == 2 )
    {
        if(D.jj + 21 > 28)
        {
            F.jj = D.jj + 21;
            rest = F.jj - 28;
            F.jj = rest;
            F.mm = D.mm + 1;
            F.aa = D.aa;
        }
        else
            F = D;
    }



    return F;
}
maladies *maladiesdepersonne()
{
    int n,i;
    maladies *m  =(maladies*)malloc(sizeof(maladies));
    if(m==NULL)
    {
        exit(-1);
    }
    color(5,0);printf("Nom de maladie: ");
    color(7,0);scanf("%s",&m->nom);
    return m;
}
void affichie_maladiep(maladies m)
{
        color(7,0);printf("%s--->",m.nom);
}
liste_m *initialiser_maladep()
{
    liste_m *l = malloc(sizeof(liste_m));
    if(l==NULL)
    {
        exit(-1);
    }
    *l=NULL;
    return l;
}
void affichier_liste_m(liste_m *L)
{
    NODE *n = *L;
    if(L!=NULL)
    {
        while(n!=NULL)
        {
            affichie_maladiep(n->data);
            n=n->next;
        }
    }
}
void ajouter_maladiep(liste_m *L,maladies m)
{
    NODE * n=malloc(sizeof(NODE));
    NODE *ptp =*L;
    n->data =m;
    n->next =NULL;
    if(*L!=NULL)
    {
        while(ptp->next!=NULL)
        {
            ptp =ptp->next;
        }
        ptp->next =n;
    }
    else
        *L=n;
}
void affichiepersonnecontact(personne_contact P)
{
     printf("***************** info personne******************\n");
     color(7,0);printf("Nom : %s\n",P.nom);
     color(7,0);printf("prenom : %s\n",P.prenom);
     color(7,0);printf("L'age : %d\n",P.age);
     color(7,0);printf("Adresse : %s\n",P.adresse);
     color(7,0);printf("Nom d'hotel :%s\n",P.NomHotel);
     color(7,0);printf("Boulvard : %s\n",P.boulvard);
     color(8,0);printf("date de debut de confinement :\n");
     printf("%02d/%02d/%d\n",P.dateD.jj,P.dateD.mm,P.dateD.aa);
     color(8,0);printf("date de fin de confinement :\n");
      printf("%02d/%02d/%d\n",P.dateF.jj,P.dateF.mm,P.dateF.aa);
     if(P.mp!=NULL){
     color(8,0);printf("liste des maladies de pesonne contact :\n");
     affichier_liste_m(P.mp);}
     printf(" \n ***************** ****************************\n");
}

liste_personne_contact *initialiserlistepersonne()
{
    liste_personne_contact *L =malloc(sizeof(liste_personne_contact));
    if(L==NULL)
    {
        exit(-1);
    }
    *L =NULL;
    return L;
}
void Affichelistepersonne(liste_personne_contact *L)
{
    Element *E =*L;
    if(L!=NULL)
    {
        while(E!=NULL)
        {

            affichiepersonnecontact(E->Data);
            E=E->suivant;
        }
    }
}
void ajouterpersonne(liste_personne_contact * L,personne_contact P)
{

    Element *E=(Element*)malloc(sizeof(Element));
    Element *tmp = *L;
    E->Data = P;
    E->suivant = NULL;
    if(*L!=NULL)
    {
        while(tmp->suivant!=NULL)
        {
            tmp = tmp->suivant;
        }
        tmp->suivant = E;
    }
    else
        *L =E;

}
