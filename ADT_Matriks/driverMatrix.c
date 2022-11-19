#include <stdio.h>
#include "matrix.h"
#include <math.h>
#include "boolean.h"
#include "matrix.c"
#include <ctype.h>
#include <stdlib.h>

int main(){
    Matrix p;
    Matrix idx;
    char *filename='../Confifg/Config_Peta.txt';
    p=MapMatrix(filename); //Membaca Konfigurasi
    char input;
    boolean sukses; //Kondisi Berhasil Move
    while (input != 'b'){
    
        scanf("%c",&input); //gerakan menggunakan wasd
        

        system("cls");

        displayMap(p);
        ((int) tolower(input) == 'a') ? MoveWest(&p,&sukses) :
        ((int) tolower(input) == 'd') ? MoveEast(&p,&sukses) :
        ((int) tolower(input) == 'w') ? MoveNorth(&p,&sukses) :
        ((int) tolower(input) == 's') ? MoveSouth(&p,&sukses) : "";

    }

    idx = getidx(p,'S'); //mengambil index S
    printf("(%d,%d)\n",ELMT(idx,0,1),ELMT(idx,0,0));

    printf("Last Idx Row: %d\n",getLastIdxRow(p));
    printf("Last Idx Col: %d\n",getLastIdxCol(p));
}