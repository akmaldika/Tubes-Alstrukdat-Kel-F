#include <stdio.h>
#include "simulator.h"
#include "boolean.h"
#include "point.h"
// #include "C:\Users\ASUS\Documents\TBALSTRUKDAT\Tubes-Alstrukdat-Kel-F\ADT_Matriks\matrix.c"
#include "C:\Users\ASUS\Documents\TBALSTRUKDAT\Tubes-Alstrukdat-Kel-F\ADT_Matriks\matrix.h"


boolean isAdjacent(SIMULATOR *S, Matrix m){
    
    Matrix idx=getidx(m,'S');
    int y=ELMT(idx,0,0);
    int x=ELMT(idx,0,1);

    boolean flag;
    flag = false;
    
        ((ELMT(m,y,x+1) == 'M') || (ELMT(m,y,x+1) == 'T') || (ELMT(m,y,x+1) == 'C')|| (ELMT(m,y,x+1) == 'F') ||(ELMT(m,y,x+1) == 'B')) ? flag=true:
        ((ELMT(m,y,x-1) == 'M') || (ELMT(m,y,x-1) == 'T') || (ELMT(m,y,x-1) == 'C')|| (ELMT(m,y,x-1) == 'F') ||(ELMT(m,y,x-1) == 'B')) ? flag=true:
        ((ELMT(m,y+1,x) == 'M') || (ELMT(m,y+1,x) == 'T') || (ELMT(m,y+1,x) == 'C')|| (ELMT(m,y+1,x) == 'F') ||(ELMT(m,y+1,x) == 'B')) ? flag=true:
        ((ELMT(m,y-1,x) == 'M') || (ELMT(m,y-1,x) == 'T') || (ELMT(m,y-1,x) == 'C')|| (ELMT(m,y-1,x) == 'F') ||(ELMT(m,y-1,x) == 'B')) ? flag=true:
        ((ELMT(m,y+1,x+1) == 'M') || (ELMT(m,y+1,x+1) == 'T') || (ELMT(m,y+1,x+1) == 'C')|| (ELMT(m,y+1,x+1) == 'F') ||(ELMT(m,y+1,x+1) == 'B')) ? flag=true:
        ((ELMT(m,y-1,x-1) == 'M') || (ELMT(m,y-1,x-1) == 'T') || (ELMT(m,y-1,x-1) == 'C')|| (ELMT(m,y-1,x-1) == 'F') ||(ELMT(m,y-1,x-1) == 'B')) ? flag=true:
        ((ELMT(m,y+1,x-1) == 'M') || (ELMT(m,y+1,x-1) == 'T') || (ELMT(m,y+1,x-1) == 'C')|| (ELMT(m,y+1,x-1) == 'F') ||(ELMT(m,y+1,x-1) == 'B')) ? flag=true:
        ((ELMT(m,y-1,x+1) == 'M') || (ELMT(m,y-1,x+1) == 'T') || (ELMT(m,y-1,x+1) == 'C')|| (ELMT(m,y-1,x+1) == 'F') ||(ELMT(m,y-1,x+1) == 'B')) ? flag=true: ' ' ;      
        
    return flag;
        
        
    

}