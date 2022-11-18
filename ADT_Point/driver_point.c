#include "point.h"
#include "point.c"

int main(){
    POINT P;
    SetPoint(&P,0,0);
    printf("Posisi Saat ini : ");
    TulisPOINT(P);
    
    Geser(&P,100,800);
    printf("Posisi Saat ini Setelah digeser : ");
    TulisPOINT(P);
}