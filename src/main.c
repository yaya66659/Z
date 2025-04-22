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
        do
        {
            clearScreen();
            if(erreur)
                printf("Errreure mots de passe differents");
            mps =  definirUnMotdePasse(argv[1], FAUX);
            mps2 = definirUnMotdePasse(argv[1], VRAI);
     
            if(strcmp(mps, mps2) == 0){
                 lanceCmd7zSecure(argv[1], mps);
                 free(mps);
                 free(mps2);
                 break;
            }


         
        } while (1);
        
      
    }
   else
    {
        free(mps);
        free(mps2);
                afficherManuelUtilisation();
    }

return 0;
}