#include <stdio.h>
#include "boolean.h"
#include "makanan.h"

void CreateMakanan(MAKANAN *m, int id, char judul, __TIME__ exp,__TIME__ durasi,int loc){
        ID(*m)= id;
        judul(*m)= judul;
        exp(*m)= exp;

}

int getId(MAKANAN m){
        return ID(m);
}

char getJudul(MAKANAN m){
        return Judul(m);
}

__TIME__ getExp(MAKANAN m){
        return exp(m);
}

__TIME__ getDurasi(MAKANAN *m);
        return durasi(m);

int getLoc(MAKANAN *m){
        // return loc(m);
}