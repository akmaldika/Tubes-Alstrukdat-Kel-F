#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "boolean.h"
#include "point.h"
#include "matrix.h"
#include "PrioQueue.h"
typedef struct { 
    char nama;
    POINT locs;
    PrioQueue inventory;
    PrioQueue delivery;
    char notifikasi;
    Matrix m;

}SIMULATOR;


#define NAMA(s) (s).nama
#define LOCS(s) (s).locs
#define INVENTORY(s) (s).inventory
#define DELIVERY(s) (s).delivery
#define NOTIFIKASI(s) (s).notifikasi
#define MAP(s) (s).m

boolean isAdjacent(SIMULATOR *S, Matrix m);



#endif