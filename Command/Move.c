#include "../ADT_Simulator/simulator.h"
#include "../ADT_Matriks/matrix.h"
#include "../ADT_Point/point.h"
#include "../ADT_Queue/PrioQueue.h"


void MoveE(SIMULATOR *S, boolean *MoveSuccess){
    Matrix m=MAP(*S);
    TIME t=WAKTU(*S);
    POINT p=TITIK(*S);
    *MoveSuccess=false;
    MoveEast(&m,MoveSuccess) ;
    if (MoveSuccess){
        Geser(&p,1,0);
        setTitikSim(S,p);
        t=TPrevMin(t);
        setTimeSim(S,t);
        setMapSim(S,m);
    }

}

void MoveW(SIMULATOR *S,boolean *MoveSuccess){
    Matrix m=MAP(*S);
    TIME t=WAKTU(*S);
    POINT p=TITIK(*S);
    *MoveSuccess=false;
    MoveWest(&m,MoveSuccess) ;
    if (MoveSuccess){
        Geser(&p,-1,0);
        setTitikSim(S,p);
        t=TPrevMin(t);
        setTimeSim(S,t);
        setMapSim(S,m);
    }

}

void MoveN(SIMULATOR *S,boolean *MoveSuccess){
    Matrix m=MAP(*S);
    TIME t=WAKTU(*S);
    POINT p=TITIK(*S);
    *MoveSuccess=false;
    MoveNorth(&m,MoveSuccess) ;
    if (MoveSuccess){
        Geser(&p,0,-1);
        setTitikSim(S,p);
        t=TPrevMin(t);
        setTimeSim(S,t);
        setMapSim(S,m);
    }
}

void MoveS(SIMULATOR *S,boolean *MoveSuccess){
    Matrix m=MAP(*S);
    TIME t=WAKTU(*S);
    POINT p=TITIK(*S);
    PrioQueue q=DELIV(*S);
    *MoveSuccess=false;
    MoveSouth(&m,MoveSuccess) ;
    if (MoveSuccess){
        Geser(&p,0,1);
        setTitikSim(S,p);
        t=TPrevMin(t);
        setTimeSim(S,t);
        setMapSim(S,m);
    }
}
void Move(SIMULATOR *S, Word X,boolean *MoveSuccess){
    if (isWordSame(X,"EAST")){
        MoveE(S,MoveSuccess);
    }else if (isWordSame(X,"WEST")){
        MoveW(S,MoveSuccess);
    }else if (isWordSame(X,"NORTH")){
        MoveN(S,MoveSuccess);
    }else if (isWordSame(X,"SOUTH")){
        MoveS(S,MoveSuccess);
    }
}
