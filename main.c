#include "mesincludes.h"
#include "prototypes.h"

int main(int argc,char * argv[]){
    srand(time(NULL));
    printf("===========================\n");
    printf("Bienvenue dans le Pendu !!!\n");
    printf("===========================\n");

    while (partie != 2)
    {
    printf("**************Menu Principal**************\n");
    printf("Taper 1 pour une nouvelle partie\n");
    printf("Taper 2 pour quitter le jeu\n");
    printf("Taper 3 pour l'aide\n");
    scanf("%d",&partie);
    switch (partie)
    {
    case 1:
        printf("Choississez le mode de jeu :\n");
        printf("=============================\n");
        printf("Taper 1 pour jouer seul et 2 pour jouer à deux: ");
        scanf("%d",&mode);
        if (mode==1)
        {
            strcpy(motSecret,piocherMot());
            Jouer(motSecret);

        }
        else if (mode==2)
        {
            char chaine[20];
            printf("\nJoueur 1 Entrez le mot à deviner :");
            scanf("%s",chaine);
            printf("\nEntrez un indice du mot à deviner :");
            scanf("%s",indice);
            printf("\n\nJoueur 2 c'est à vous de Jouer !\n\n");
            printf("l'indice est :\n");
            puts(indice);
            strcpy(motSecret,chaine);
            Jouer(motSecret);
        }
        else{
            printf("Le mode choisi n'est pas valide !\n");
            break;
        }
        
        break;
    case 2:
        exit(0);
        break;
    case 3:
        AfficherAide();
        break;
    
    default:
        printf("Vous avez fait un choix incorrect relancer le jeu svp !\n");
        exit(0);
        break;
    }
       
    }
    
    
    
}