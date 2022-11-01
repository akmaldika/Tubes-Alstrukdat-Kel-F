#ifndef MAKANAN_H
#define MAKANAN_H

#include "boolean.h"



/* Ukuran maksimum baris dan kolom */
#define ROW_CAP 100
#define brsmin 0


typedef int IdxType; /* Index baris, kolom */
typedef int ElMakananType;

typedef struct
{
   int id; /* banyaknya/ukuran baris yg terdefinisi */
   char Judul;
   __TIME__ exp;
   __TIME__ durasi;
   int loc;
   
} MAKANAN;

#define ID(m) (m).id
#define Judul(m) (m).judul
#define exp(m) (m).exp
#define durasi(m) (m).durasi
#define loc(m) (m).loc




void CreateMakanan(MAKANAN *m, int id, char judul, __TIME__ exp,__TIME__ durasi,int loc); 

int getId(MAKANAN m);

char getJudul(MAKANAN m);

__TIME__ getExp(MAKANAN m);

__TIME__ getDurasi(MAKANAN *m);

int getLoc(MAKANAN *m);

