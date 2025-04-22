// -*- coding: utf-8 -*-

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>

#include "headers/fct.h"
/*7z a -t7z -mhe=on -pMON_MDP archive.7z dossier_ou_fichier*/

void activeAffichageUTF8DansLaConsole(){

    system("chcp 65001"); //definit la console en UTF-8 en Changent la code page de la console
    SetConsoleOutputCP(CP_UTF8);// Force l'affichage correct des caractères UTF-8 

}

void videBuffer(){
    int c;
    while((c = getchar()),c == '\0' && c== EOF);
}

char * definirUnMotdePasse(char * nomFichier, booleen confirmation){
   int retScanf = 0;
   booleen erreure = FAUX;
   char  * motDePasse;

   motDePasse = malloc(sizeof(char)*_SIZE_BUFFER_);
   
   do
   {
    
    if(erreure)
        printf("Mot de passe invalide ou vide\n");

        if(confirmation)
        printf("Confirmer le mot de passe \n");
   else
     printf("Saisir un mot de passe pour le cryptage de l'archive \"%s\"\n", nomFichier);

    retScanf = scanf("%255[0-9A-Za-z£%%$#*_-]s", motDePasse);
    
    videBuffer();
   } while (retScanf != 1);

   return motDePasse;
    
}


void lanceCmd7zSecure(char * nomfichier, char * motDePasse){
    char * nomfichierSansExtention;

    if(returnTypeDeFic(nomfichier) == DOSSIER)
    {
         nomfichierSansExtention = nomfichier;
    }
    else if(returnTypeDeFic(nomfichier) == FICHIER)
    {
        nomfichierSansExtention = retourneNomDeFichierSansExtention(nomfichier);

    }

    
    char cmdZ[_SIZE_BUFFER_] = "7z a -t7z -mhe=on -p\"";
    strcat(cmdZ, motDePasse);
    strcat(cmdZ,"\" \"");
    strcat(cmdZ, nomfichierSansExtention);
    strcat(cmdZ, "_Zsecure.7z\" \"");
    strcat(cmdZ, nomfichier);
    strcat(cmdZ,"\"");

    printf("Securisation Z avec la commande : %s\n", cmdZ);
    pause();
    system(cmdZ);
    printf("Securisation de %s Z avec la commande : %s vers> %s_secure.7z\n",nomfichier, cmdZ, nomfichierSansExtention);
    pause();
    clearScreen();
}

void clearScreen(){
    system("cls");
}

void pause(){
    printf("Saisir ENTER pour continuer...");
    getchar();
}

char * retourneNomDeFichierSansExtention(char * nomFichier){
    char *  nomFichierSansExtention = NULL;
    int posFinDeChaine = 0;
    int compteurDePoint = 0;

    nomFichierSansExtention = malloc((sizeof(char)*_SIZE_BUFFER_));
    if(nomFichierSansExtention == NULL)
    {
        printf("Erreur maloc ficSansExtension!!!!!");
        pause();
        clearScreen();
        exit(EXIT_FAILURE);
    }

    for(int i =0, x = 0; i< strlen(nomFichier); i++){
        if(nomFichier[i] == '.')
        {
            compteurDePoint++;
            if(compteurDePoint == compteNombreDePointDansLAChaine(nomFichier))
               break;
            
        }
      
       

     nomFichierSansExtention[x++] = nomFichier[i];
     posFinDeChaine = x;
    
    }
   
    nomFichierSansExtention[posFinDeChaine] = '\0';

   
return nomFichierSansExtention;
}

int compteNombreDePointDansLAChaine(char * nomfichier){
    int compteur = 0;
    for(int i = 0; i< strlen(nomfichier); i++)
    {
            if(nomfichier[i] == '.')
                compteur++;
    }

return compteur;

}

char * returneExtension(char * nomfichier){
    char * extention = NULL;
    int posFinDeChaine = 0 ;

    extention = malloc((sizeof(char)*_SIZE_BUFFER_));
    if(extention == NULL)
    {
        printf("Erreur maloc extension!!!");
        pause();
        clearScreen();
        exit(EXIT_FAILURE);

    }

    
    for(int i = 0, x = 0; i < strlen(nomfichier); i++){
        if(nomfichier[i] == '.')
        {
                           
            strcpy(extention, "");
            x=0;
        }
        

        
            if(i+1 < strlen(nomfichier) && nomfichier[i+1] == '.' )
            {
                strcpy(extention, "");
                x=0;
                
            }
            else{
                extention[x++] = nomfichier[i];
            }
            
           
       
            
        posFinDeChaine = x;
       
        
}

extention[posFinDeChaine] = '\0';

       


return  extention;
}


typeDefic returnTypeDeFic(char * nomFichier){
    DWORD attr = GetFileAttributesA(nomFichier);

    if(attr == INVALID_FILE_ATTRIBUTES)
        return INTROUVABLE;
    else if(attr & FILE_ATTRIBUTE_DIRECTORY)
            return DOSSIER;
    else
            return FICHIER;
}

void afficherManuelUtilisation() {
    clearScreen();
    printf("╔══════════════════════════════════════════════════════╗\n");
    printf("║               MANUEL D’UTILISATION - Z              ║\n");
    printf("╚══════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("Syntaxe :\n");
    printf("    z [nomdufichier]\n");
    printf("\n");
    printf("Formats EXCLUS (non compatibles avec la sécurisation) :\n");
    printf("  ❌ .zip   -> chiffrement faible ou incomplet\n");
    printf("  ❌ .rar   -> non supporté en création par 7z\n");
    printf("  ❌ .gz, .bz2, .xz, .tar -> pas de support du mot de passe\n");
    printf("  ❌ .iso, .wim, .cab     -> formats image/disque non chiffrables\n");
    printf("  ❌ .7z    -> déjà archivé (inutile de re-chiffrer)\n");
    printf("\n");
    printf("Utilisez plutôt cette commande sur des fichiers ordinaires :\n");
    printf("  ✅ .txt, .pdf, .jpg, .mp3, .docx, etc.\n");
    printf("\n");
    printf("Astuce : évitez de passer un fichier déjà compressé ou protégé.\n");
    printf("         L’outil est prévu pour protéger vos données AVANT l’archivage.\n");
    printf("Description :\n");
    printf("  - le chemin du dossier Z/Bin ou ce trouve  z.exe doit être installé et\n");
    printf("    accessible dans le PATH.\n");
    printf("    Cette commande permet de créer une archive sécurisée\n");
    printf("    protégée par mot de passe avec 7-Zip (.7z).\n");
    printf("\n");
    printf("Étapes du programme :\n");
    printf("  1. Demande d’un mot de passe pour chiffrer l’archive.\n");
    printf("  2. Demande de confirmation du mot de passe.\n");
    printf("  3. Création d’une archive 7z avec mot de passe et\n");
    printf("     entête chiffrée (option -mhe=on).\n");
    printf("\n");
    printf("Exemple :\n");
    printf("    z monFichier.txt\n");
    printf("    -> Créera : monFichier_Zsecure.7z\n");
    printf("    z monFichier.txt -debug\n");
    printf("    -> affiche les inforamtion de debugagge.\n");
    printf("    z -h\n");
    printf("    -> affiche ce manuel.\n");
    printf("    z  --help\n");
    printf("    -> affiche ce manuel.\n");
    printf("\n");
    printf("Remarques :\n");
    printf("  - La commade 7z utiliser  est la suivante: "); 
    printf("    \"7z a -t7z -mhe=on -pMON_MDP archive.7z dossier_ou_fichier\"   ");
    printf("  - L’utilitaire 7z doit être installé et accessible dans le PATH.\n");
    printf("  - Le fichier original reste inchangé.\n");
    printf("  - L’archive générée est chiffrée de manière sécurisée.\n");
    printf("\n");
    printf("╔══════════════════════════════════════════════════════╗\n");
    printf("║                    BONNE UTILISATION !               ║\n");
    printf("╚══════════════════════════════════════════════════════╝\n");
    pause();  // Fonction définie dans fct.c
}