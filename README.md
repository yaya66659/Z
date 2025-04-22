# Projet Z - Cryptage sécurisé d’archives

## 🔐 Description

**Z** est un utilitaire en ligne de commande écrit en **C** qui permet de chiffrer des fichiers en créant une archive 7z sécurisée avec mot de passe. Il s’appuie sur l’utilitaire **7-Zip** pour générer une archive avec entête chiffrée (`-mhe=on`), garantissant que même la liste des fichiers est protégée.

---

## ⚙️ Fonctionnalités

- Demande un mot de passe de l'utilisateur.
- Confirme le mot de passe pour éviter les erreurs.
- Utilise 7-Zip pour générer une archive `.7z` chiffrée.
- Affiche un manuel d'utilisation clair si l'utilisateur oublie l'argument.
- Console codée pour supporter l’affichage UTF-8 sous Windows.

---

## [->] Telechargement:

[Commande z - link1 Google Drive](https://drive.google.com/file/d/17K8Urh6V-mEel0wF4DtW0ziz1vBT_6sz/view?usp=sharing)
[Commande z - link2 release GitHUb](https://github.com/yaya66659/Z/releases/latest)

 ❗ Formats exclus de la commande `z`

L'outil `z` utilise 7-Zip pour créer une archive **.7z chiffrée avec mot de passe**.  
Certains formats de fichiers sont **incompatibles** avec ce chiffrement ou déjà compressés.

### ❌ Formats non supportés ou à éviter :

| Extension     | Raison                                                                 |
|---------------|------------------------------------------------------------------------|
| `.zip`        | Chiffrement partiel (entête visible) ou faible (ZipCrypto)             |
| `.rar`        | 7z ne permet pas de créer des `.rar` avec mot de passe                 |
| `.gz`, `.bz2` | Formats sans support de chiffrement ou de mot de passe                 |
| `.xz`, `.tar` | Pas de chiffrement, formats purement de compression                    |
| `.iso`, `.wim`| Images disque, non compatibles avec mot de passe via 7z                |
| `.cab`        | Format système, pas conçu pour le chiffrement                          |
| `.7z`         | Déjà une archive 7z, inutile (et risqué) de la re-chiffrer             |

---

### ✅ Formats recommandés

Utilisez la commande `z` sur des **fichiers classiques** avant archivage :

- `.txt`, `.pdf`, `.jpg`, `.png`, `.docx`, `.mp3`, `.mp4`, etc.
- tout fichier personnel ou dossier à protéger

---

### 📌 Astuce

> Évitez de sécuriser un fichier déjà compressé ou protégé.  
> L’outil `z` est conçu pour chiffrer des **données originales**, non encore archivées.

## 🖥️ Utilisation

```bash
z fichier.txt
```
Cela crée une archive sécurisée :

```bash

fichier_Zsecure.7z

```
La commanede seul :
```bash
z
```
ou
```bash
z -h
z --help
```
Affichera le manuelle d'utilisation.

```bash
z fichier.txt -debug

```
Affichera les information de debugage.

## 📦 Commande utilisée
```bash

7z a -t7z -mhe=on -pMON_MDP archive.7z fichier
```
## 🧩 Pré-requis
Windows (supporté actuellement)

L’utilitaire 7-Zip installé

7z.exe doit être accessible dans le PATH système
Et mettre le chemin vers :  z.exe dans le PATH système ou utilisteur vous permettra de **l'utiliser depuis n'importe ou dans le terminal.**

##📁 Structure du projet

Z/

├── src/

│   ├── main.c

│   ├── fct.c

├── headers/

│   └── fct.h

├── bin/

├── obj/

├── README.md

└── Makefile



## 👨‍💻 Auteur
Yann Pichat
Développeur C passionné par la sécurité des données et la simplicité des outils CLI.


## 📜 Licence
Ce projet est distribué sous la licence suivante :

Licence Z - Usage non commercial

Vous êtes autorisé à :

Utiliser ce logiciel à des fins personnelles ou éducatives.

Copier, modifier et redistribuer ce logiciel ou des versions modifiées.

À condition que :

Toute redistribution inclue cette licence.

Aucune utilisation commerciale ne soit faite de ce logiciel ou de ses dérivés.

Il est strictement interdit :

D’utiliser ce logiciel dans un produit ou service vendu, monétisé ou utilisé à des fins commerciales.

De revendre, louer ou proposer ce logiciel dans une offre payante.

Ce logiciel est fourni "tel quel", sans garantie. L'auteur ne pourra être tenu responsable d'aucun dommage lié à son usage.

