#include "boolean.h"
#include "../ADT_Time/time.h"
#include "../ADT_MesinKata/mesinkata.h"

#ifndef MAKANAN_H
#define MAKANAN_H

typedef int IDEM;
typedef Line NamaMakanan;
typedef Word LokasiAksi;

typedef struct
{
   IDEM id;
   NamaMakanan Nama;
   TIME exp;
   TIME deliv;
   LokasiAksi loc;
} MAKANAN;

/* ***** SELEKTOR ***** */
#define ID(m) (m).id
#define Judul(m) (m).Nama
#define Exp(m) (m).exp
#define Deliv(m) (m).deliv
#define Locate(m) (m).loc

/* **** KONSTRUKTOR **** */
void CreateMakanan(MAKANAN *m, IDEM id, NamaMakanan namaMakanan, TIME exp, TIME deliv, LokasiAksi loc);
/* I.S. m sembarang */
/* F.s. m terdefinisi dengan elemen pembentuknya sesuai masukan parameter */

boolean isMakananSame(MAKANAN m1, MAKANAN m2);
/* Mengembalikan True jika m1 dan m2 memiliki id yang sama */

#endif