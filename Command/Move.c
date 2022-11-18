#include "../ADT_Simulator/simulator.h"
#include "../ADT_Matriks/matrix.h"
#include "../ADT_Point/point.h"
void MoveE(SIMULATOR *S){
    Matrix m=MAP(*S);
    TIME t=WAKTU(*S);
    POINT p=TITIK(*S);
    boolean sukses=false;
    MoveEast(&m,&sukses) ;
    if (sukses){
        Geser(&p,1,0);
        setLokasi(&S,p);
        t=TPrevMin(t);
        setTIme(&S,t);
        setMap(&S,m);
    }

}

void MoveW(SIMULATOR *S){
    Matrix m=MAP(*S);
    TIME t=WAKTU(*S);
    POINT p=TITIK(*S);
    boolean sukses=false;
    MoveWest(&m,&sukses) ;
    if (sukses){
        Geser(&p,-1,0);
        setLokasi(&S,p);
        t=TPrevMin(t);
        setTimeSim(&S,t);
        setMap(&S,m);
    }

}

void MoveN(SIMULATOR *S){
    Matrix m=MAP(*S);
    TIME t=WAKTU(*S);
    POINT p=TITIK(*S);
    boolean sukses=false;
    MoveNorth(&m,&sukses) ;
    if (sukses){
    Geser(&p,0,-1);
    setLokasi(&S,p);
    t=TPrevMin(t);
    setTimeSim(&S,t);
    setMap(&S,m);
    }
}

void MoveS(SIMULATOR *S){
    Matrix m=MAP(*S);
    TIME t=WAKTU(*S);
    POINT p=TITIK(*S);
    boolean sukses=false;
    MoveSouth(&m,&sukses) ;
    if (sukses){
    Geser(&p,0,1);
    setLokasi(&S,p);
    t=TPrevMin(t);
    setTimeSim(&S,t);
    setMap(&S,m);
    }

}