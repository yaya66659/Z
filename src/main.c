// -*- coding: utf-8 -*-

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"headers/fct.h"
int main(int argc, char *argv[])
{
    activeAffichageUTF8DansLaConsole();

    char* mps;
    char * mps2;
    booleen erreur = FAUX;
    if(argv[1]){
        if(argv[2])
        {
           
            if(strcmp(argv[2], "-debug") == 0){
                char * nomFichierSansExtension = retourneNomDeFichierSansExtention(argv[1]);
                char * extension = returneExtension(argv[1]);
                char * nomFichier  = argv[1];
                clearScreen();
                printf("\n\t Z mode debug\n\n");

                printf("Info de debugage :  \n");
                switch (returnTypeDeFic(argv[1]))
                {
                case INTROUVABLE:
                      printf("\tErreur : fichier ou dossier introuvable.\n");

                    break;
                    case DOSSIER:
                        printf("\t\"%s\" est un dossier et ne possede donc pas de nom d'extension\n", nomFichier);
                   
                    break;
                    case FICHIER:
                    printf("\t\"%s\" est un fichier\n",nomFichier);
                    printf("\t - nomfichier sans extension: \"%s\"\n", nomFichierSansExtension);
                    printf("\t - Extension seule : \"%s\" \n", extension);
                   
                    break;
                
                default:
                printf("erreure switch typeDeFic\n");
                    break;
                }
               free(nomFichier);
                free(nomFichierSansExtension);
                free(extension);
                pause();
                clearScreen();
                exit(EXIT_SUCCESS);
                


            }
        }

        if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        {
            
            afficherManuelUtilisation();
        }
        else{

            if(returnTypeDeFic(argv[1]) == FICHIER)
            {
                char * extension = returneExtension(argv[1]);

                if (strcmp(extension, ".zip") == 0 || strcmp(extension, ".gz") == 0 || strcmp(extension, ".bz2") == 0 ||
                strcmp(extension, ".xz") == 0 || strcmp(extension, ".rar") == 0 || strcmp(extension, ".iso") == 0 ||
                strcmp(extension, ".wim") == 0 || strcmp(extension, ".cab") == 0 || strcmp(extension, ".7z") == 0) {
                    printf("❌ Erreur : le format .%s n'est pas compatible avec la commande z (chiffrement non supporté).\n", extension);
                    free(extension);
                    pause();                   
                    clearScreen();
                    exit(EXIT_FAILURE);;
                    }
    
                    free(extension);
            }
            else if(returnTypeDeFic(argv[1]) == INTROUVABLE)
            {
                clearScreen();
                    printf("!!Erreur : fichier ou dossier introuvable!!\n");
                    free(mps);
                    free(mps2);
                    pause();
                    exit(EXIT_FAILURE);
            }
        
           
           
   

                    do
                    {
                        clearScreen();
                        if(erreur){
                            printf("Errreure mots de passe differents");
                            erreur = FAUX;
                        }
                            
                        mps =  definirUnMotdePasse(argv[1], FAUX);
                        mps2 = definirUnMotdePasse(argv[1], VRAI);
                
                        if(strcmp(mps, mps2) == 0){
                            lanceCmd7zSecure(argv[1], mps);
                            free(mps);
                            free(mps2);
                            break;
                        }else{
                            erreur = VRAI;
                        }


                    
                    } while (1);
        }
        
           
        
      
    }
   else
    {
        
                afficherManuelUtilisation();
    }

        free(mps);
        free(mps2);

return 0;
}