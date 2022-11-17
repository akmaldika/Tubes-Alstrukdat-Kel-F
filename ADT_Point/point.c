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
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
    printf("%d %d", Absis(P),Ordinat(P));

}           


/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    return (Absis(P1)==Absis(P2) && Ordinat(P1)==Ordinat(P2));
}

boolean NEQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 tidak sama dengan P2 */
    return (!EQ(P1,P2));
}






/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P){
/* Mengirim salinan P dengan absis ditambah satu */              
   
   // ALGORITMA
   Absis(P) += 1;
   return P;
}

POINT NextY (POINT P){
/* Mengirim salinan P dengan ordinat ditambah satu */

    //ALGORTIMA
    Ordinat(P) += 1;
    return P;

}

POINT PlusDelta (POINT P, int deltaX, int deltaY){
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
   
   // ALGORITMA
   Absis(P) += deltaX;
   Ordinat(P) += deltaY;
   return P;
}




void Geser (POINT *P, int deltaX, int deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
   
   // ALGORITMA
   *P = PlusDelta(*P, deltaX, deltaY);
}