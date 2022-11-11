/* File MultiSet.h*/

#ifndef _MULTISET_h
#define _MULTISET_h

#include "boolean.h"
#include "..\config_main.h"

#define CAPACITY_MULTISET CONFIG_SIZELM

typedef struct {
    int Elmt;
    int Multiplicty;
} ElMultiSetType;

typedef struct {
    ElMultiSetType buffer[CAPACITY_MULTISET];
    int NEFFMultiSet;
} MultiSet;

#endif