#include <stdio.h>
#include "matrix.h"
#include <math.h>
#include "boolean.h"
#include "matrix.c"
#include <ctype.h>
#include <stdlib.h>

int main(){
    Matrix p;
    p=MapMatrix();
    char input;
    boolean sukses;
    while (input != 'b'){
    
        scanf("%c",&input); //gerakan menggunakan wasd
        

        system("cls");

        displayMap(p);
        ((int) tolower(input) == 'a') ? MoveWest(&p,&sukses) :
        ((int) tolower(input) == 'd') ? MoveEast(&p,&sukses) :
        ((int) tolower(input) == 'w') ? MoveNorth(&p,&sukses) :
        ((int) tolower(input) == 's') ? MoveSouth(&p,&sukses) : "";

    }



}