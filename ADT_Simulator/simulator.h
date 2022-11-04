#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "boolean.h"

typedef struct { 
    char nama;
    int locs;
    char inventory;
    char notifikasi;


} SIMULATOR;


#define NAMA(s) (s).nama
#define LOCS(s) (s).locs
#define INVENTORY(s) (s).inventory


boolean isAdjacent(int locs);



#endif