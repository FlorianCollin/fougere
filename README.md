# Projet : Représentation de la fougère de Barnsley

L'objectif de ce projet est de réaliser la fougère de Barnsley (fractal) et ainsi tester nos connaisance en language C et en manipulation d'image.

Vous trouverez tous les fichiers source (.c) dans le dossier "src" et les en-têtes (.h) dans le dossier "include".

La compilation du projet ne nécessite aucune bibliothèque externe, mais seulement une version récente de gcc.

La compilation se fait en tapant la commande "make" dans votre terminal, ce qui créera l'exécutable "program" dans le dossier "bin".

Les fichiers ".o" se trouvent dans le dossier "obj" et peuvent être supprimés avec la commande "make clean".



## Installation de SDL2 et SDL_image

### Introduction:
SDL2 (Simple DirectMedia Layer 2) est une bibliothèque multiplateforme pour la gestion des entrées, des graphismes, du son et de la fenêtre. SDL_image est une bibliothèque d'extension de SDL pour charger des images dans différents formats.

Dans ce guide, nous allons expliquer comment installer SDL2 et SDL_image sur différents systèmes d'exploitation.

#### Installation de SDL2 et SDL_image sous Linux:
Sur les distributions Linux basées sur Debian, SDL2 et SDL_image peuvent être installés en utilisant les commandes suivantes dans le terminal:

sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-image-dev

Pour les autres distributions Linux, il est possible de compiler les bibliothèques à partir des sources. Pour cela, il faut télécharger les sources sur le site officiel de SDL et suivre les instructions pour la compilation.



#### Installation de SDL2 et SDL_image sous MacOS <3 :
L'installation de SDL2 et SDL_image sur MacOS peut être réalisée en utilisant Homebrew. Pour cela, il faut exécuter les commandes suivantes dans le terminal:

brew install sdl2
brew install sdl2_image

L'installation de SDL2 et SDL_image est assez simple sur les différents systèmes d'exploitation. Avec ces bibliothèques installées, il est possible de créer des applications graphiques, sonores et interactives multiplateformes.

Dans mon cas je l'utilise pour afficher et manipuler la fractale dans une fenêtre.