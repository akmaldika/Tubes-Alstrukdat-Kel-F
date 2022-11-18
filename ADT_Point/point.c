#include <stdio.h>
#include "point.h"
#include <math.h>


/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
void SetPoint(POINT *P, int X, int Y){
    Absis(*P)=X;
    Ordinat(*P)=Y;

}

void TulisPOINT (POINT P){
    printf("(%d,%d)\n", Absis(P),Ordinat(P));
}







void Geser (POINT *P, int deltaX, int deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
   
   // ALGORITMA
   Absis(*P) += deltaX;
   Ordinat(*P) += deltaY;
}