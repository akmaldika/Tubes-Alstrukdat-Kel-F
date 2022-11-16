#include <stdio.h>
#include "simulator.h"
#include "boolean.h"
#include "..\ADT_Point\point.h"
// #include "C:\Users\ASUS\Documents\TBALSTRUKDAT\Tubes-Alstrukdat-Kel-F\ADT_Matriks\matrix.c"
#include "..\ADT_Matriks\matrix.h"


// boolean isAdjacent(SIMULATOR *S, Matrix m){
    
//     Matrix idx=getidx(m,'S');
//     int y=ELMT(idx,0,0);
//     int x=ELMT(idx,0,1);

//     boolean flag;
//     flag = false;
    
//         ((ELMT(m,y,x+1) == 'M') || (ELMT(m,y,x+1) == 'T') || (ELMT(m,y,x+1) == 'C')|| (ELMT(m,y,x+1) == 'F') ||(ELMT(m,y,x+1) == 'B')) ? flag=true:
//         ((ELMT(m,y,x-1) == 'M') || (ELMT(m,y,x-1) == 'T') || (ELMT(m,y,x-1) == 'C')|| (ELMT(m,y,x-1) == 'F') ||(ELMT(m,y,x-1) == 'B')) ? flag=true:
//         ((ELMT(m,y+1,x) == 'M') || (ELMT(m,y+1,x) == 'T') || (ELMT(m,y+1,x) == 'C')|| (ELMT(m,y+1,x) == 'F') ||(ELMT(m,y+1,x) == 'B')) ? flag=true:
//         ((ELMT(m,y-1,x) == 'M') || (ELMT(m,y-1,x) == 'T') || (ELMT(m,y-1,x) == 'C')|| (ELMT(m,y-1,x) == 'F') ||(ELMT(m,y-1,x) == 'B')) ? flag=true:
//         ((ELMT(m,y+1,x+1) == 'M') || (ELMT(m,y+1,x+1) == 'T') || (ELMT(m,y+1,x+1) == 'C')|| (ELMT(m,y+1,x+1) == 'F') ||(ELMT(m,y+1,x+1) == 'B')) ? flag=true:
//         ((ELMT(m,y-1,x-1) == 'M') || (ELMT(m,y-1,x-1) == 'T') || (ELMT(m,y-1,x-1) == 'C')|| (ELMT(m,y-1,x-1) == 'F') ||(ELMT(m,y-1,x-1) == 'B')) ? flag=true:
//         ((ELMT(m,y+1,x-1) == 'M') || (ELMT(m,y+1,x-1) == 'T') || (ELMT(m,y+1,x-1) == 'C')|| (ELMT(m,y+1,x-1) == 'F') ||(ELMT(m,y+1,x-1) == 'B')) ? flag=true:
//         ((ELMT(m,y-1,x+1) == 'M') || (ELMT(m,y-1,x+1) == 'T') || (ELMT(m,y-1,x+1) == 'C')|| (ELMT(m,y-1,x+1) == 'F') ||(ELMT(m,y-1,x+1) == 'B')) ? flag=true: ' ' ;      
        
//     return flag;
        
        
// }

void SetSimulator(SIMULATOR *S, POINT locs,Matrix m){
    LOCS(*S) = locs;
    MAP(*S) = m;
}

void setLokasi(SIMULATOR * S, POINT p) {
/* Mengganti lokasi simulator */
    
    // ALGORITMA 
    Absis(LOCS(*S)) = Absis(p);
    Ordinat(LOCS(*S)) = Ordinat(p);
}

void setMap(SIMULATOR *S, Matrix m){
    MAP(*S)=m;
}

void setNama(SIMULATOR *S, Word Nama){
    NAMA(*S)=Nama;
}

void setInventory(SIMULATOR *S, PrioQueue inventory){
    INVENTORY(*S)=inventory;
}

void setDelivery(SIMULATOR *S, PrioQueue delivery){
    DELIVERY(*S)=delivery;
}

void setTIme(SIMULATOR *S, TIME waktu){
    TIME(*S)=waktu;
}
// void simulatorToState(SIMULATOR S, PrioQueue delivery, TIME currentTime, Matrix m, SIMULATOR *temp) {
// /* mengkonversi simulator s ke State*/
// /* digunakan saat mau menyimpan State ke stack */

//     // ALGORITMA
//     InfoWaktu(*temp) = currentTime;
//     InfoKoordinat(*temp) = Lokasi(s);
//     InfoInventory(*temp) = Inventory(s);
//     InfoNotif(*temp) = currentNotif;
//     InfoKulkas(*temp) = currentKulkas;
//     InfoDelivery(*temp) = deliverylist;
// }

boolean isAdjacent(SIMULATOR *S, Matrix m, char val){
    
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