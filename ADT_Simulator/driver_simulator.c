#include <stdio.h>
#include "simulator.h"



int main(){
    Matrix p;
    Matrix idx;
    SIMULATOR S;
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

        if (isAdjacent(S,'M')){
            printf("Adjacent dengan M");
        }

        if (isAdjacent(S,'T')){
            printf("Adjacent dengan T");
        }

        if (isAdjacent(S,'C')){
            printf("Adjacent dengan C");
        }

        if (isAdjacent(S,'F')){
            printf("Adjacent dengan F");
        }

        if (isAdjacent(S,'B')){
            printf("Adjacent dengan B")
        }

    }


}