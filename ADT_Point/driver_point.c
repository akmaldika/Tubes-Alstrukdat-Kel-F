#include "point.h"
#include "point.c"

int main(){
    POINT P;
    POINT P2;
    SetPoint(&P2,0,0);
    SetPoint(&P,0,0);
    if (isPointSame(P,P2)){
        printf("true");
    }
    printf("Posisi Saat ini : ");
    TulisPOINT(P);
    
    Geser(&P,100,800);
    printf("Posisi Saat ini Setelah digeser : ");
    TulisPOINT(P);
}