#include <stdio.h>
#include "matrix.h"
#include <math.h>
#include "boolean.h"
#include "matrix.c"
#include <ctype.h>
#include <stdlib.h>
#include "point.h"
#include "simulator.h"
#include "point.c"
#include "simulator.c"


int main(){
    Matrix p;
    POINT Point;
    int x,y;
    Matrix idx;
    SIMULATOR S;
    idx=getidx(p,'S');
    y=ELMT(idx,0,0);
    x=ELMT(idx,0,1);
    


    p=MapMatrix();
    CreatePoint(&Point,x,y);
    char input;
    while (input != 'b'){
    
        scanf("%c",&input); //gerakan menggunakan wasd
        

        system("cls");

        displayMap(p);
        ((int) tolower(input) == 'a') ? MoveWest(&p) :
        ((int) tolower(input) == 'd') ? MoveEast(&p) :
        ((int) tolower(input) == 'w') ? MoveNorth(&p) :
        ((int) tolower(input) == 's') ? MoveSouth(&p) : "";
        
        if (isAdjacent(&S,p)) {                
            printf("cek adjacent berhasil : adjacent = true\n");
                Matrix temp=getidx(p,'S');
                y=ELMT(temp,0,0);
                x=ELMT(temp,0,1);
                printf("%d %d\n",x,y);
        }   else{
            printf("false\n");
                Matrix temp=getidx(p,'S');
                y=ELMT(temp,0,0);
                x=ELMT(temp,0,1);
                printf("%d %d\n",x,y);
        }        

    }




}