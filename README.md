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

[Commande z - link](https://drive.google.com/file/d/17K8Urh6V-mEel0wF4DtW0ziz1vBT_6sz/view?usp=sharing)

## 🖥️ Utilisation

```bash
z fichier.txt
```
Cela crée une archive sécurisée :

```bash

fichier_Zsecure.7z

```
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

