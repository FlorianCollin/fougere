# Projet : Représentation de la fougère de Barnsley

L'objectif de ce projet est de réaliser la fougère de Barnsley (fractal) et ainsi tester nos connaisance en language C et en manipulation d'image.

## Structure du project :

.
├── Makefile
├── README.md
├── bin
│   └── program
├── include
│   ├── bmpTools.h
│   └── mathTools.h
├── obj
│   ├── bmpTools.o
│   ├── ioTools.o
│   ├── main.o
│   └── mathTools.o
├── premier_pic.bmp
├── src
│   ├── bmpTools.c
│   ├── ioTools.c
│   ├── main.c
│   └── mathTools.c
└── test

Vous trouverez tous les fichiers source (.c) dans le dossier "src" et les en-têtes (.h) dans le dossier "include".

La compilation du projet ne nécessite aucune bibliothèque externe, mais seulement une version récente de gcc.

La compilation se fait en tapant la commande "make" dans votre terminal, ce qui créera l'exécutable "program" dans le dossier "bin".

Les fichiers ".o" se trouvent dans le dossier "obj" et peuvent être supprimés avec la commande "make clean".


## Documentation des fonctions :

### bmpTools :

- "PIC new_pic(int width, int height);" créer une instance de la structure picture (PIC) et l'init en definisant sa taille width x height, puis la retourne, on réalise ainsi une affectation par copie.

- "int save_pic(PIC pic, const char* file_name);" sauvegarde la "picture" elle créer le fichier .bmp qui correrspond au PIC donner en argument.
  
- "int set_pix(PIC pic, int x, int y, COLOR color);" set la couleur d'un pixel.
  
- "int set_all_pix(PIC pic, COLOR color);" set la couleur de tout les pixels
  
- "int draw_line(PIC pic, int x1, int y1, int x2, int y2, COLOR color);" dessine une ligne.
  
- "int draw_line2(PIC pic, int x1, int y1, int x2, int y2, COLOR color);"




