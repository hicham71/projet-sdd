#include <stdio.h>
#include <stdlib.h>
#include "patient.c"
#include "personne_contact.c"
#include "hopital.c"
#include "quarantaine.c"
#include "hotel.c"
#include<conio.h>
/*
0 : Noir
1 : Bleu foncé
2 : Vert foncé
3 : Turquoise
4 : Rouge foncé
5 : Violet
6 : Vert caca d'oie
7 : Gris clair
8 : Gris foncé
9 : Bleu fluo
10 : Vert fluo
11 : Turquoise
12 : Rouge fluo
13 : Violet 2
14 : Jaune
15 : Blanc*/
int main()
{
    char*nom;
    char*genre;
    char*Nom;
    int mat,choix,choix1,choix2;
    hopitaux* found;
    liste_patient *l =initialiserliste();
    Liste_hopitaux *Lh =initialiser_liste_hopital();
    liste_quarantine * lq =initialisier_quarantaine();
    liste_hotel *lho =initialiser_liste_hotel();

do{
        color(5,0);printf("MENU GENERALE DU MINI PROJET :\n");
        color(9,0);printf("1-GESTION DES PATIENTS/HOPITAUX :\n");
        color(9,0);printf("2-GESTION DES PERSONNES/QUARANTAINE :\n");
        color(9,0);printf("donner votre choix :");
        color(13,0);scanf("%d",&choix1);

      switch(choix1){
      case 1 :
      do{
        color(4,0);printf("MENU PRINCIPALE\n");
        color(11,0);printf("1-  AJOUTER UNE PATIENT --:\n");
        color(11,0);printf("2-  MODIFIER ETAT DU PATIENT--:\n");
        color(11,0);printf("3-  SUPPRIMIER PATIENT GEUERIE/MORT--:\n");
        color(11,0);printf("4-  RECHERCHER PATIENT PAR MATRICULE --:\n");
        color(11,0);printf("5-  RECHERCHER PATIENT PAR NOM--:\n");
        color(11,0);printf("6-  RECHERCHER PATIENT PAR GENRE--:\n");
        color(11,0);printf("7-  AFFICHER LISTE PATIENTS ----:\n");
        color(11,0);printf("8-  AJOUTER UN HOPITAL --:\n");
        color(11,0);printf("9-  AFFECTER PATIENTS DANS HOPITAL-- :\n");
        color(11,0);printf("10- AFFICHER LISTE HOPITAUX -- :\n");
        color(11,0);printf("11- MODIEFIER HOPITAL --- :\n");
        color(11,0);printf("12- QUITTER ------ :\n");

        color(4,0);printf("donner votre choix : ");
        color(3,0);scanf("%d",&choix);
       switch(choix){
        case 1 :
            color(4,0);printf("Ajouter un patient : \n");
            ajouterpatient(l,*nouveaupatient());
            break;
        case 2 :
            printf("donner le matricule du patient :");
            scanf("%d",&mat);
             modification_etatpatient(l,Lh,mat);
             break;
        case 3 :
             supprimer_patient_guerie(l);
             break;
        case 4 :
                color(4,0);printf("Matricule");
                color(1,0);scanf("%d",&mat);
                recherchepatient(l,mat);
                break;
        case 5 :
                color(4,0);printf("Nom du patient :");
                color(1,0);scanf("%s",&nom);
                recherchepatient_par_nom(l,&nom);
                break;
        case 6 :
                color(4,0);printf("Genre du patient :");
                color(1,0);scanf("%s",&genre);
                recherchepatient_par_genre(l,&genre);
                break;
        case 7 :
                color(4,0);printf("liste du patient :\n");
                color(6,0);printf("Nom\t\tprenom\t\tetat\t\tgenre\t\tadresse\t\thopital\t\tcode\t\tage\t\tmatricule\n");
                Afficher(l);
                break;
        case 8 :
                color(4,0);printf("ajouter un hopital :");
                ajouter_hopital(Lh,*nouveauhopital());
                break;
        case 9 :
                printf("affectation d'un patient dans un hopital : \n");
                affectation_patienten_hopital(Lh,l);
                break;
        case 10 :
                color(4,0);printf("afficher une liste des hopitaux :");
                affichie_liste_hopitaux(Lh);
                break;
        case 11 :
                color(4,0);printf("Nom de l'hopital :");
                color(1,0);scanf("%s",&Nom);
                modification_hopital(Lh,&Nom);
                break;
        case 12 :
                color(10,0);printf(" AU REVOIR :\n");
                break;
        default :
                color(10,0);printf(" LE CHOIX INCONNUE :\n");
        }
    }while(choix!=12);
    break;
        case 2 :
            do{
                color(4,0);printf("MENU PRINCIPAL:\n");
                color(6,0);printf("1- AJOUTER PERSONNE CONTACT CONTACT :\n");
                color(6,0);printf("2- AFFICHIER LISTE PERSONNES CONTACT CONTACT:\n");
                color(6,0);printf("3- AJOUTER UN HOTEL :\n");
                color(6,0);printf("4- AFFECTER DES PERSONNES CONTACTS DANS UN HOTEL  :\n");
                color(6,0);printf("5- AFFICHIER LISTE DES HOTELS :\n");
                color(6,0);printf("donner votre choix : ");
                color(1,0);scanf("%d",&choix2);
                switch(choix2)
                {
                case 1:
                    ajouter_quarantaine(lq,*nouveau_personne_quarataine(lho));
                    break;
                case 2:
                    affichie_liste_quarantine(lq,lho);
                    break ;
                case 3:
                    color(11,0);printf(" Ajouter un hotel :\n ");
                    ajouter_hotel(lho,*nouveau_hotel());
                    break;
                case 4 :
                    color(9,0);printf("Affectaion d'un persone contact : \n");
                    ajouterdescontactdunpatientunhotel(lho,l);
                    color(7,0);printf(" personnes contacts sont affectés dans un hotel :\n");
                     break;
                case  5:
                     color(9,0);printf("Affiche liste des hotel :");
                     affichie_liste_hotel(*lho);
                    break;
                case 6:
                    color(4,0);printf("AU REVOIR  :\n");
                    break;
                default :
                    color(4,0);printf("LE CHOIX INCONNUE  :\n");
                }
              }while(choix2!=6);
        break;
                case 3:
                    color(4,0);printf("AU RVOIR :\n");
                    break ;
                default :
                       color(4,0);printf("LE CHOIX INCONNUE :\n ");
             }
  }while(choix1!=3);
    return 0;
}
