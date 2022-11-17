#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "../library.h"

typedef struct Simulator{ 
    Word nama;
    POINT titik;
    PrioQueue inventory;
    PrioQueue delivery;
    Matrix map;
    TIME waktu
} SIMULATOR;

#define NAMA(s) (s).nama
#define TITIK(s) (s).titik
#define INVENTORY(s) (s).inventory
#define DELIV(s) (s).delivery
#define MAP(s) (s).map
#define WAKTU(s) (s).waktu

void CreateSim(SIMULATOR *S);

void setNamaSim(SIMULATOR *S, Word nama);

void setTitikSim(SIMULATOR *S, POINT point);

void setInventory(SIMULATOR *S, PrioQueue inventory);

void setDelivery(SIMULATOR *S, PrioQueue delivery);

void setMapSim(SIMULATOR *S, Matrix map);

void setTimeSim(SIMULATOR *S, TIME waktu);

#endif