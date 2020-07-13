#include "patient.h"
#include<windows.h>
#include <string.h>
 void color(int t,int f){
            HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
    }
patient *nouveaupatient()
{
    int nbr,i,n,j,op;
     patient *p = (patient*)malloc(sizeof(patient));
     liste_personne_contact *L =initialiserlistepersonne();
     liste *m =initialiser_malade();
    if(p==NULL)
    {
        exit(-1);
    }
    printf("/***************entre les informations de patient*************/:\n");

    color(5,0);printf("Nom du patient : ");
    color(4,0);scanf("%s",&p->nom);

    color(5,0);printf("prenom du patient : ");
    color(4,0);scanf("%s",&p->prenom);

    color(5,0);printf("etat : normal(1)/critique(2): ");
    color(4,0);scanf("%d",&op);
    if(op==1 || op==2)
    strcpy(p->cas,etat[op-1]);

    color(5,0);printf("genre : homme(1)/femme(2) :");
    color(4,0);scanf("%d",&op);
    if(op==1 || op==2)
    strcpy(p->genre,genre[op-1]);

    color(5,0);printf("Adresse du patient : ");
    color(4,0);scanf("%s",&p->adresse);

    color(5,0);printf("code postal du patient :");
    color(4,0);scanf("%d",&p->codeP);

    color(5,0);printf("Age du patient :");
    color(4,0);scanf("%d",&p->age);

    color(5,0);printf("Matricule du patient : ");
    color(4,0);scanf("%d",&p->matricule);
     strcpy(p->hopital,"vide");
    color(4,0);printf("Ce patient souffre-t-il de maladies chroniques? oui(1)/non(2) :");
    scanf("%d",&n);
    if(n==1){
    color(5,0);printf("Nombre des maladies du patient :");
    color(4,0);scanf("%d",&n);
         for(j=0;j<n;j++)
          {
            ajouter_maladie(m,*maladiesdepatient());
          }
        p->mc = m;
    }
     p->cont =contamination_patient();

     color(5,0);printf("Nombe des personnes contact :");
     color(4,0);scanf("%d",&nbr);
     for(i=0;i<nbr;i++)
     {
        ajouterpersonne(L,*nouveaupersonnecontact());
     }
       p->pc =L;

    return p;
}
bool contamination_patient()
{
    int n;
    color(5,0);printf("contamination introduit(1)/local(2) :");
    color(4,0);scanf("%d",&n);
    if(n==1)
    {
        return true;

    }
    return false ;
}
maladies_chronique *maladiesdepatient()
{
    int n,i;
    maladies_chronique *m  =(maladies_chronique*)malloc(sizeof(maladies_chronique));
    if(m==NULL)
    {
        exit(-1);
    }
    color(1,0);printf("Nom de maladies: ");
    color(4,0);scanf("%s",&m->nom);
    return m;
}
void affichie_maladie(maladies_chronique m)
{
        color(4,0);printf("%s---> ",m.nom);

}
liste *initialiser_malade()
{
    liste *l = malloc(sizeof(liste));
    if(l==NULL)
    {
        exit(-1);
    }
    *l=NULL;
    return l;
}
void affichier_liste(liste *L)
{
    node *n = *L;
    if(L!=NULL)
    {
        while(n!=NULL)
        {
            affichie_maladie(n->data);
            n=n->next;
        }
    }
}
void ajouter_maladie(liste *L,maladies_chronique m)
{
    node * n=malloc(sizeof(node));
    node *ptp =*L;
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

void affichiepatient(patient p)
{
     color(4,0);printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%d\t\t%d\t\t%d\n",p.nom,p.prenom,p.cas,p.genre,p.adresse,p.hopital,p.codeP,p.age,p.matricule);
     if(p.mc!=NULL){
     printf("la liste des maladies du patient :\n");
     affichier_liste(p.mc);}
     printf("\n");
     printf("contamination : %d ",p.cont);
     printf("\n");
     Affichelistepersonne(p.pc);
     printf(" \n ***************** ****************************\n");
}
liste_patient *initialiserliste()
{
    liste_patient *l =malloc(sizeof(liste_patient));
    element_patient *e =malloc(sizeof(element_patient));
    if(l==NULL || e==NULL)
    {
        exit(-1);
    }
    e->data =*nouveaupatient();
    e->suivant = NULL;
    *l = e;
    return l;
}
void Afficher(liste_patient *l)
{
    element_patient *e = *l;
    if(l!=NULL)
    {
        while(e!=NULL)
        {
            affichiepatient(e->data);
            e=e->suivant;
        }
    }
}
void ajouterpatient(liste_patient * l,patient p)
{
    element_patient *e=(element_patient*)malloc(sizeof(element_patient));
    element_patient *tmp = *l;
    e->data = p;
    e->suivant = NULL;
    if(*l!=NULL)
    {
        while(tmp->suivant!=NULL)
        {
            tmp = tmp->suivant;
        }
        tmp->suivant = e;
    }
    else
        *l =e;
}
void recherchepatient(liste_patient *l,int matricule)
{

    element_patient *tmp = *l;
    while(tmp!=NULL)
    {
        if(tmp->data.matricule == matricule)
        {
            affichiepatient(tmp->data);
        }
        tmp =tmp->suivant;
    }
}
void recherchepatient_par_nom(liste_patient*l,char*nom)
{

    element_patient *tmp =*l;
    while(tmp!=NULL)
    {
        if(strcmp(tmp->data.nom,nom)==0)
        {
            affichiepatient(tmp->data);
        }
        tmp =tmp->suivant;
    }
}
void recherchepatient_par_genre(liste_patient*l,char*genre)
{
    element_patient *tmp =*l;
    while(tmp!=NULL)
    {
        if(strcmp(tmp->data.genre,genre)==0)
        {
            affichiepatient(tmp->data);
        }
        tmp =tmp->suivant;
    }
}
element_patient *supprimier_patient(element_patient*tmp,element_patient*ptmp)
{
    element_patient *spp=ptmp;
    tmp->suivant=ptmp->suivant;
    free(spp->data.pc);
    free(spp->data.mc);
    free(spp);
    return tmp;
}
void supprimer_patient_guerie(liste_patient *l)
{
    element_patient *tmp = *l;
    element_patient *ptmp = tmp->suivant;
    element_patient*temp =NULL;
    if(l!=NULL)
    {

        if((strcmp(tmp->data.cas, etat[2])==0) || (strcmp(tmp->data.cas,etat[3])==0))
        {
            printf("%s  %s est suppprimer \n",tmp->data.nom,tmp->data.prenom);
            temp = tmp->suivant;
            free(tmp->data.pc);
            free(tmp->data.mc);
            free(tmp);
            tmp = temp;
            *l= tmp;
        }
        else
        {
            while(ptmp!=NULL)
            {
                if((strcmp(ptmp->data.cas,etat[2])==0) || (strcmp(ptmp->data.cas,etat[3])==0))
                {
                    printf("%s  %s est suppprimer \n",ptmp->data.nom,ptmp->data.prenom);
                    ptmp =supprimier_patient(tmp,ptmp);
                }
                tmp=ptmp;
                ptmp=ptmp->suivant;
            }
        }
    }
}
