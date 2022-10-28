/* File: ListMakanan.h */
/* Pemrosesan list kontigu, eksplisit, penyimpanan statik */

#ifndef _LISTMAKANAN_h
#define _LISTMAKANAN_h

/* KAMUS DEFINISI PROGRAM */

#include "boolean.h"
// #include "..\ADT_Makanan\"

/* SETUP UKURAN MAKANAN */
#define COFIGSIZE 6

typedef int IdxTypeLM; /* Type index */

typedef struct
{
  _MAKANAN_ makanan[CONFIGSIZE];
  int NElmt;
} ListMakanan;
/* Index yang digunakan [0..CONFIGSIZE-1] */
/* Definisi :
   List kosong NElmt = 0 
   Pattern function/procedure agar tidak konflik :
   ..LM / LMkn
   ..Mkn*/
 
/* ********** KONSTRUKTOR ********** */
void CreateListMakanan(ListMakanan *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List Makanan kosong dengan kapasitas konfigurasi */

/* ********** SELEKTOR ********** */
/* l adalah ListMakanan */
#define GetLengthLM(l) (l).NElmt             /* get ukuran list */
#define GetLM(l) (l)._MAKANAN_       /* get pointer list */
#define GetElmtLM(l,i) LMakanan[i]         /* get elemen list ke-i */

_ID_MAKANAN_ GetIdMkn(l, i);
/* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
/* Mengembalikan int ID makanan index ke-i */

_NAMA_MAKANAN_ GetNamaMkn(l,i);
/* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
/* Mengembalikan String nama makanan index ke-i*/

_WAKTU_KADALUARSA_MAKANAN GetKadaluarsaMkn(l,i);


/* **********  ********** */
#endif


