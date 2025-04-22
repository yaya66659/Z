#ifndef _FCT_H_
#define _FCT_H_

#define _SIZE_BUFFER_ 3256

typedef enum{
FAUX,
VRAI
}booleen;

typedef enum{
    INTROUVABLE,
    FICHIER,
    DOSSIER
}typeDefic;

void activeAffichageUTF8DansLaConsole();
void videBuffer();

char * definirUnMotdePasse();
char * confirmerMotsDePasse();

void lanceCmd7zSecure(char * nomfichier, char * motDePasse);

char * retourneNomDeFichierSansExtention(char * nomFichier);
int compteNombreDePointDansLAChaine(char * nomfichier);
char * returneExtension(char * nomfichier);

void clearScreen();
void pause();

/*return un typeDeFic  INTROUVABLE, FICHIER, DOSSIER du nom de fichier passer en argument*/
typeDefic returnTypeDeFic(char * nomFichier);

void afficherManuelUtilisation();

#endif //_FCT_H_
