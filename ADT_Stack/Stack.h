/* File : Stack.h */
/* Stack dengan elemen kontigu dan alokasi memori dinamk*/
/* TOP adalah alamat elemen puncak */


#ifndef StackUndoRedo_h
#define StackUndoRedo_h

#include "boolean.h"
#include "..\ADT_Makanan\"
#include "..\ADT_Time\"
#include "..\ADT_Simulator\"
#include "..\ADT_Point\"
#include "..\ADT_Matriks\"

#define Nil -1
/* Nil adalah stack dengan elemen kosong . */
/* Kapasitas Stack adalah kelipatan 100 */

typedef struct
{
    
} ElStackURType;

typedef int address;   /* indeks tabel */

typedef struct { 
  ElStackURType T[CapacityStack]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
  int capacity; /* kapasitas yang sedang ditampung */
} Stack;


/* ********** SELEKTOR ********** */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* *** KONSTRUKTOR *** */
void CreateEmpty(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, ElStackURType X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, ElStackURType* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void IncreaseSize(Stack *S);
/* Capacity bertambah sebanyak Capacity */
..
#endif