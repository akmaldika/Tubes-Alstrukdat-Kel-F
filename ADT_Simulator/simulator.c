#include "simulator.h"

void CreateSim(SIMULATOR *S, char *filename) {
    Word nama;
    nama.Length = 4;
    nama.String[0] = 'J';
    nama.String[1] = 'o';
    nama.String[2] = 'n';
    nama.String[3] = 'i';
    NAMA(*S) = nama;
    
    POINT newPoint;
    SetPoint(&newPoint, 0, 0);
    TITIK(*S) = newPoint;

    PrioQueue newInventory;
    MakeEmpty(&newInventory, 40);
    INVENTORY(*S) = newInventory; 
    
    PrioQueue newDelivery;
    MakeEmpty(&newDelivery, 40);
    DELIV(*S) = newDelivery;

    Matrix newMap;
    newMap = MapMatrix(filename);
    MAP(*S) = newMap;

    TIME newTime;
    CreateTime(&newTime, 0, 0, 0);
    WAKTU(*S) = newTime;
}

void setNamaSim(SIMULATOR *S, Word nama) {
    NAMA(*S) = nama;
}

void setTitikSim(SIMULATOR *S, POINT point) {
    
    TITIK(*S) = point;
}

void setInventory(SIMULATOR *S, PrioQueue inventory){
    INVENTORY(*S) = inventory;
}

void setDeliverySim(SIMULATOR *S, PrioQueue delivery){
    DELIV(*S) = delivery;
}

void setMapSim(SIMULATOR *S, Matrix map){
    MAP(*S) = map;
}

void setTimeSim(SIMULATOR *S, TIME waktu){
    WAKTU(*S) = waktu;
}

boolean isAdjacent(SIMULATOR S, char val){
    
    Matrix m=MAP(S);
    Matrix idx=getidx(m,'S');
    int y=ELMT(idx,0,0);
    int x=ELMT(idx,0,1);

    boolean flag;
    flag = false;
    
        ((ELMT(m,y,x+1) == val)) ? flag=true:
        ((ELMT(m,y,x-1) == val )) ? flag=true:
        ((ELMT(m,y+1,x) == val) ) ? flag=true:
        ((ELMT(m,y-1,x) == val) ) ? flag=true:
        ((ELMT(m,y+1,x+1) == val) ) ? flag=true:
        ((ELMT(m,y-1,x-1) == val) ) ? flag=true:
        ((ELMT(m,y+1,x-1) == val) ) ? flag=true:
        ((ELMT(m,y-1,x+1) == val) ) ? flag=true: ' ' ;      
        
    return flag;
        
        
    

}