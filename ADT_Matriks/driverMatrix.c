#include <stdio.h>
#include "matrix.h"
#include <math.h>
#include "boolean.h"
#include "matrix.c"

int main(){
    Matrix p;
    p=MapMatrix();
    MoveWest(&p);
    displayMatrix(p);


}