#ifndef MACRO_H
#define MACRO_H
// define : 

// Longueurs :

#define SCALE 1200.0

#define OH SCALE
#define OA 0.335*OH
#define OB 0.877*OH
#define OC 1.086*OH
#define OD 0.765*OH
#define OE 0.339*OH

// Angles (rad) :

#define HOA 0.9421
#define HOB -0.0647
#define HOC -0.3
#define HOD -0.263
#define HOE -1.175

#define WIDTH 1600 
#define HEIGHT 900 //height


// define des valeurs necessaires pour la recursivité

// À partir d'une figure on dessine trois figure une rouge "r", une bleu "b" et une verte "g"

// Positions
#define OOg 0.16
#define OOr 0.12
#define OOb 0.08
// Angles (radians)
#define HOgHg -0.05
#define HOrHr 3.141592/2.0
#define HObHb -3.141592/2.0
// Tailles
#define OgHg 0.86
#define OrHr 0.27
#define ObHb 0.30

// ATTENTION !!! La figure bleu est inversée

#endif