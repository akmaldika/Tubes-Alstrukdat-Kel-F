#ifndef SIMULATOR_H
#define SIMULATOR_H


#include "library.h"

typedef struct { 
    Word nama;
    POINT locs;
    PrioQueue inventory;
    PrioQueue delivery;
    Matrix m;
    TIME waktu

}SIMULATOR;


#define NAMA(s) (s).nama
#define LOCS(s) (s).locs
#define INVENTORY(s) (s).inventory
#define DELIVERY(s) (s).delivery
#define NOTIFIKASI(s) (s).notifikasi
#define MAP(s) (s).m
#define TIME(s) (s).waktu

// #define INFONAMA(p) (p)->nama
// #define INFOLOCS(p) (p)->locs
// #define INFOINVENTORY(p) (p)->inventory
// #define INFODELIVERY(p) (p)->delivery
// #define INFONOTIFIKASI(p) (p)->notifikasi
// #define INFOMAP(p) (p)->m
// #define INFOTIME(p) (p)->waktu

void SetSimulator(SIMULATOR *S, POINT locs,Matrix m);

boolean isAdjacent(SIMULATOR *S, Matrix m,char val);

void setLokasi(SIMULATOR *S,POINT p);

void setTIme(SIMULATOR *S, TIME waktu);

void setDelivery(SIMULATOR *S, PrioQueue delivery);

void setInventory(SIMULATOR *S, PrioQueue inventory);

void setNama(SIMULATOR *S, Word Nama);

void setMap(SIMULATOR *S, Matrix Map);
#endif