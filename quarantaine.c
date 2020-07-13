#include "quarantaine.h"

persenneenquarantaine * nouveau_personne_quarataine(liste_hotel *lho)
{
    int pt =0;
    int nbr ,i,j,n;
    Node *e =*lho;
    persenneenquarantaine *pq = malloc(sizeof(persenneenquarantaine));
    liste_personne_contact *lc =initialiserlistepersonne();
    personne_contact *pc =*lc;
    liste_personne_contact * ptp;
    Element *tmpp;
    if(pq == NULL)
    {
        exit(-1);
    }
    while(e!=NULL)
    {
        int pc=0;
        ptp =e->data.ph;
        tmpp =*ptp;
         while(tmpp!=NULL)
           {
              color(1,0);printf("Hotel Numero %d :\n",pt+1);
              color(1,0);printf("personne contact %d :\n",pc+1);
              color(4,0);printf("voulez vous ajouter des personne contact contact oui(1)/non(2) :");
              color(1,0);scanf("%d",&n);
              if(n==1){
              color(1,0);printf("donner nombre de personne contact contact:");
              color(1,0);scanf("%d",&nbr);

              for(i=0;i<nbr;i++)
               {
                ajouterpersonne(lc,*nouveaupersonnecontact());
               }
                 pq->pc =lc;
              }
            pc++;
          tmpp =tmpp->suivant;
        }
        pt++;
        e = e->suivant;

    }

    return pq;
}
void affichie_personne_quarantine(persenneenquarantaine pq,liste_hotel*lho)
{
    Node *e =*lho;
    liste_personne_contact * ptp;
    Element *tmpp;
    printf("/******info*******/");
    printf("personne contact :\n");
    while(e!=NULL)
    {
         ptp =e->data.ph;
         tmpp =*ptp;
         while(tmpp!=NULL)
          {
            affichiepersonnecontact(tmpp->Data);
             tmpp =tmpp->suivant;
           }
        e = e->suivant;

    }
    if(pq.pc!=NULL)
    {
         printf("liste des personnes contact contact :\n");
         Affichelistepersonne(pq.pc);
    }
}
liste_quarantine * initialisier_quarantaine()
{
    liste_quarantine *lq =malloc(sizeof(liste_quarantine));
    if(lq==NULL)
    {
        exit(-1);
    }
    *lq=NULL;
    return lq;
}

void affichie_liste_quarantine(liste_quarantine *lq,liste_hotel * lho)
{
    quarantine *q =*lq;
             if(*lq!=NULL)
              {
                 while(q!=NULL)
                   {
                        affichie_personne_quarantine(q->data,lho);
                        q =q->suivant;
                   }
               }
}

void ajouter_quarantaine(liste_quarantine *lq,persenneenquarantaine pq)
{
    quarantine *q =malloc(sizeof(quarantine));
    quarantine *ptmp =*lq;
    q->data =pq;
    q->suivant =NULL;
    if(*lq!=NULL)
    {
        while(q->suivant!=NULL)
        {

            ptmp =ptmp->suivant;
        }
        ptmp->suivant =q;
    }
    else
        *lq = q;
}
