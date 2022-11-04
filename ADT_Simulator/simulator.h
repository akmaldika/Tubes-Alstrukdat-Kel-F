#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "boolean.h"

typedef struct { 
    char nama;
    int locs;
    char inventory;


} SIMULATOR;


#define NAMA(s) (s).nama
#define LOCS(s) (s).locs
#define INVENTORY(s) (s).inventory

void StartSimulator(SIMULATOR *s);

boolean isAdjacent(int locs);



#endif