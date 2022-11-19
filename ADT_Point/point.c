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


boolean isPointSame(POINT p1, POINT p2)
{
    return (Absis(p1) == Absis(p2) && Ordinat(p1) == Ordinat (p2));
}




void Geser (POINT *P, int deltaX, int deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
   
   // ALGORITMA
   Absis(*P) += deltaX;
   Ordinat(*P) += deltaY;
}