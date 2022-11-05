#include "../ADT_Time/boolean.h"
#include "../ADT_Time/time.h"

#ifndef MAKANAN_H
#define MAKANAN_H

/* Ukuran maksimum baris dan kolom */
#define ROW_CAP 100
#define brsmin 0

typedef int IdxType; /* Index baris, kolom */
typedef int ElMakananType;

typedef struct
{
   int id; /* banyaknya/ukuran baris yg terdefinisi */
   char Judul;
   TIME exp;
   TIME durasi;
   int loc;

} MAKANAN;

#define ID(m) (m).id
#define judul(m) (m).Judul
#define exp(m) (m).exp
#define durasi(m) (m).durasi
#define loc(m) (m).loc

void CreateMakanan(MAKANAN *m, int id, char judul, TIME exp, TIME durasi, int loc);

int getId(MAKANAN m);

char getJudul(MAKANAN m);

TIME getExp(MAKANAN m);

TIME getDurasi(MAKANAN m);

int getLoc(MAKANAN *m);

#endif