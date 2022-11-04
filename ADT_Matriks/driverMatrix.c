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
    displayMap(p);
    while (input != 'b'){
    
        scanf("%c",&input); //gerakan menggunakan wasd
        

        system("cls");

        displayMap(p);
        ((int) tolower(input) == 'a') ? MoveWest(&p) :
        ((int) tolower(input) == 'd') ? MoveEast(&p) :
        ((int) tolower(input) == 'w') ? MoveNorth(&p) :
        ((int) tolower(input) == 's') ? MoveSouth(&p) : "";

    }



}