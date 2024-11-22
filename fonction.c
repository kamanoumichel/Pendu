#include "mesincludes.h"





int nbharsard;


int compt=1;
char ch;

char chainedepermutation[10];




char lireCaractere() {
char caractere = 0;
caractere = getchar(); // On lit le premier caractère
caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà
// On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)
while (getchar() != '\n') ;
return caractere;
}

void AfficherAide(){
    printf("Voici les regles du Jeu.\n");
    printf("===========================\n");
    printf("Supposons que le mot caché soit ROUGE. Vous proposez une\n");
    printf("lettre à l'ordinateur, par exemple la lettre A.\n");
    printf("L'ordinateur vérifie si cette lettre se trouve dans le mot caché.\n");
    printf("À partir de là, deux possibilités : la lettre se trouve effectivement\n");
    printf("dans le mot : dans ce cas, on dévoile le mot avec les lettres qu'on a déjà trouvées;\n");
    printf("la lettre ne se trouve pas dans le mot (c'est le cas ici, car A n'est pas dans ROUGE) :\n");
    printf("on indique au joueur que la lettre ne s'y trouve pas et on diminue le nombre de coups restants.\nQuand il ne nous reste plus de coups (0 coup), le jeu est terminé et on a perdu.\n");
}





char* piocherMot(){

        //Variable me permettant de manipuler les fichiers
        FILE *f=NULL;
        f=fopen("dico.txt","r");
        if(f==NULL){
            perror("Erreur d'ouverture du fichier.\n");
            return 0;
            exit(0);
        }

        while ((ch=fgetc(f))!=EOF)
        {    
                if (ch=='\n')
                {
                    compt++;
                }       
        }
        rewind(f);
        nbharsard= (rand() % compt) + 1;

        int tempon=0;

        while (fgets(chainedepermutation,10,f)!=NULL)
        {        
            if(tempon == nbharsard){
                
                char *variableinter= malloc(10*sizeof(char));
                strcpy(variableinter,chainedepermutation);

                return variableinter;
                break;
            }
            tempon++;
            
        }
        fclose(f);


}


void Jouer(char motSecret[]){
    
    //On initialise le formatage de l'affichage des essaies exemple *********

    char temp[20]; 
    int nbCoups=10;
    char mottenter;

    for (size_t i = 0; i < strlen(motSecret); i++)
    {
        temp[i]='*';
    }

    while(nbCoups!=0){
        printf("Il vous reste %d coups a jouer\n",nbCoups);
        printf("Quel est le mot secret ? %s\n",temp);
        printf("Proposez une lettre :\n");
        mottenter=lireCaractere();
        if(strchr(motSecret,mottenter)!=NULL){
            for (int i = 0; i < 10; i++)
            {
                if(motSecret[i]==mottenter){
                    
                    temp[i]=mottenter;
                }
        
            }
            if (strcmp(temp,motSecret)==0)
            {
                printf("Bravo ! vous avez gagné !\n");
                printf("Le mot secret etait bien %s\n",temp);
                break;
            }
            
        }
        else{
            nbCoups--;
            switch (nbCoups)
            {
            case 10:
                printf("_\n");
                break;
            case 9:
                printf("__\n");
            break;
            case 8:
                printf("__\n");
                printf("   |\n");
                break;
            case 7:
                printf("__\n");
                printf("\\ |\n");

                break;
            case 6:
                printf("__\n");
                printf("\\ |\n");
                printf("  o\n");
                break;
            case 5:
                printf("__\n");
                printf("\\ |\n");
                printf("  o\n");
                printf(" /\n");
                break;
            case 4:
                printf("__\n");
                printf("\\ |\n");
                printf("  o\n");
                printf(" /|\n");
                break;
            case 3:
                printf("__\n");
                printf("\\ |\n");
                printf("  o\n");
                printf(" /|\\\n");
                break;
            case 2:
                printf("__\n");
                printf("\\ |\n");
                printf("  o\n");
                printf(" /|\\\n");
                printf(" / \n");
                break;
            case 1:
                printf("__\n");
                printf("\\ |\n");
                printf("  o\n");
                printf(" /|\\\n");
                printf(" / \\\n");
                break;
            
            default:
                break;
            }
            

            if (nbCoups==0)
            {
                printf("Ah Ah Ah vous avez perdu le mot à trouvé était %s !!!\n",motSecret);
            }
            
        }
          
        }

}