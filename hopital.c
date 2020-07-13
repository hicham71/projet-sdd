#include "hopital.h"
hopitaux *nouveauhopital()
{
    hopitaux *H =(hopitaux*)malloc(sizeof(hopitaux));
    if(H==NULL)
    {
        exit(-1);
    }
    printf("/**********les informations de l'hopital *************/ :\n");

    color(1,0);printf("Nom de l'hopital : ");
    color(14,0);scanf("%s",&H->Nom);

    color(1,0);printf("l'adresse de l'hopital : ");
    fflush(stdin);
    color(14,0);gets(H->adresse);

    color(1,0);printf("nombre de lit maximal de l'hopital :");
    color(14,0);scanf("%d",&H->nombrelitmax);
    H->nombredelitdispo =H->nombrelitmax;

    color(1,0);printf("le code postal de l'hopital : ");
    color(14,0);scanf("%d",&H->Codep);

    color(1,0);printf("nombre des salles pour les besoins specifiques : ");
    color(14,0);scanf("%d",&H->nombresalesbesoine);

    color(1,0);printf("nombre des medcines : ");
    color(14,0);scanf("%d",&H->nombredemedcines);

    color(1,0);printf("nombre de paramedicaux : ");
    color(14,0);scanf("%d",&H->nombredeparamedicaux);
    return H;
}

void affichehopital(hopitaux h)
{
    printf("/*****info*****/\n");

    printf("Nom de l'hopital : %s\n",h.Nom);
    printf("Adresse de l'hopital : %s\n",h.adresse);
    printf("nombre de lit :%d\n",h.nombrelitmax);
    printf("nombre des salles :%d\n",h.nombresalesbesoine);
    printf("nombre de code postal : %d\n",h.Codep);
    printf("nombre de medcines :%d\n",h.nombredemedcines);
    printf("nombre de paramedicaux :%d\n",h.nombredeparamedicaux);
    printf(" \n ***************** ****************************\n");
}

Liste_hopitaux *initialiser_liste_hopital()
{
    Liste_hopitaux *l =malloc(sizeof(Liste_hopitaux));
    ELEMENT *E =malloc(sizeof(ELEMENT));
    if(l==NULL && E==NULL)
    {
        exit(-1);
    }
    E->data = *nouveauhopital();
    E->suivant =NULL;
    *l=E;
    return l;
}

void affichie_liste_hopitaux(Liste_hopitaux *Lh)
{
    ELEMENT *E =*Lh;
    if(*Lh!=NULL)
    {
        while(E!=NULL)
        {
            affichehopital(E->data);
            E =E->suivant;
        }
    }
}

void ajouter_hopital(Liste_hopitaux*Lh,hopitaux h)
{

    ELEMENT *E =(ELEMENT*)malloc(sizeof(ELEMENT));
    ELEMENT *ptp =*Lh;
    E->data =h;
    E->suivant =NULL;
    if(*Lh!=NULL)
    {
        while(ptp->suivant!=NULL)
        {
            ptp =ptp->suivant;
        }
        ptp->suivant =E;
    }
    else
        *Lh=E;
}
void modification_hopital(Liste_hopitaux *Lh,char *Nom)
{
    int n;
  ELEMENT *E =*Lh;
   while(E!=NULL)
   {
       if(strcmp(E->data.Nom,Nom)==0)
       {
           printf("voulez vous modifier oui(1)/non(2) :");
           scanf("%d",&n);
           if(n==1){
           printf(" nouveau nombre maximal :");
           scanf("%d",&E->data.nombrelitmax);
           }
           printf("voulez vous modifier le nombre de la disponibilité des salles oui(1)/non(2) : ");
           scanf("%d",&n);
           if(n==1)
           {
             printf("Nouveau nombre de la disponibilité des salles : ");
             scanf("%d",&E->data.nombresalesbesoine);
           }
           printf("voulez vous modifier le nombre de médecins spécialisés oui(1)/non(2) :  ");
           scanf("%d",&n);
           if(n==1)
           {
               printf("Nouveau nombre de médecins spécialisés :");
               scanf("%d",&E->data.nombredemedcines);
           }
           printf("voulez vous modifier le nombre de  paramédicaux :");
           scanf("%d",&n);
           if(n==1)
           {
               printf("Nouveau nombre de  paramédicaux :");
               scanf("%d",&E->data.nombredeparamedicaux);
           }
       }
      E =E->suivant;
   }
}
void affectation_patienten_hopital(Liste_hopitaux *Lh,liste_patient*l)
{
    ELEMENT *E =*Lh;
    if(*Lh!=NULL || *l!=NULL)
    {
        while(E!=NULL)
        {
          element_patient *e=*l;
           while(e!=NULL)
             {
              if((e->data.codeP == E->data.Codep) && (strcmp(e->data.hopital ,E->data.Nom) && (strcmp(e->data.hopital,"vide")==0)))
                {
                    affichehopital(E->data);
                   if(E->data.nombredelitdispo>0){
                    strcpy(e->data.hopital,E->data.Nom);
                    E->data.nombredelitdispo--;}
                    affichiepatient(e->data);
                }
                e = e->suivant;
              }
            E = E->suivant;
        }
    }
}

void modification_etatpatient(liste_patient *l,Liste_hopitaux*Lh,int mat)
{
    int sh,p=0,n;
    element_patient * tmp =*l;
    while(tmp != NULL)
    {
        ELEMENT *E =*Lh;
        while(E!=NULL)
        {
        if((strcmp(tmp->data.hopital,E->data.Nom)==0) && tmp->data.matricule==mat){
        printf("voulez vous modifier l'etat du patient %d oui(1)/nomn(2) :",p+1);
        scanf("%d",&n);
           if(n==1){
                 if(strcmp(tmp->data.cas,etat[0])==0){
                    printf("le choix : critique(2)/geuerie(3)/mort(4) :");
                     scanf("%d",&sh);
                    if(sh==3 || sh==4)
                     {

                      strcpy(tmp->data.cas,etat[sh-1]);
                        E->data.nombredelitdispo++;
                     }
                     else if(sh ==2)
                        {
                          strcpy(tmp->data.cas,etat[sh-1]);
                        }
                }
         else if(strcmp(tmp->data.cas,etat[1])==0){
            printf("le choix : normal(1)/guerie(3)/mort(4) :");
            scanf("%d",&sh);
            if(sh==3 || sh==4)
            {
                strcpy(tmp->data.cas,etat[sh-1]);
                 E->data.nombredelitdispo++;
            }
             else if(sh ==1)
                        {
                          strcpy(tmp->data.cas,etat[sh-1]);
                        }
         }
         else
            printf("etat du patient est %s:",tmp->data.cas);
        }
        }

           E =E->suivant;
         }
        p++;
        tmp = tmp->suivant;
    }

}
