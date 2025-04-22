#ifndef _FCT_H_
#define _FCT_H_

#define _SIZE_BUFFER_ 3256
typedef enum{
FAUX,
VRAI
}booleen;

void activeAffichageUTF8DansLaConsole();
void videBuffer();

char * definirUnMotdePasse();
char * confirmerMotsDePasse();

void lanceCmd7zSecure(char * nomfichier, char * motDePasse);

char * retourneNomDeFichierSansExtention(char * nomFichier);
char * returneExtension(char * nomfichier);

void clearScreen();
void pause();

void afficherManuelUtilisation();

#endif //_FCT_H_
