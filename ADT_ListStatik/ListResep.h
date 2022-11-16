/* File: ListResep.h */

#ifndef _LISTRESEP_h
#define _LISTRESEP_h

/* KAMUS DEFINISI PROGRAM */
#include "boolean.h"
#include "..\ADT_Tree\NTree.h"
#include "..\ADT_MesinKata\mesinkata.h"
#include "..\ADT_MesinKata\mesinkarakter.h"
#include "..\config_main.h"
#include "..\ADT_MesinKata\string.h"
#include "..\ADT_MultiSet\MultiSet.h"


#define IDX_UNDEF_LR -1
#define CAPACITY_LIST_RESEP CONFIG_SIZELR

typedef NTree ElListResepType;

typedef struct { 
    ElListResepType resep[CAPACITY_LIST_RESEP];
    int NEFFLRESEP;
} ListResep;

/* Definisi ListResep */
/* Indeks yang digunakan [0..CAPACITY_LIST_RESEP-1] */
/* Jika l adalah ListResep, cara deklarasi dan akses: */
/* Deklarasi : l : ListResep */
/* Maka cara akses: 
   ELMTLR(l,i) untuk mengakses elemen ke-i */
/* Definisi : 
   List kosong: NEFFLR == 0
   Definisi elemen pertama: ELMTLR(l,i) dengan i=0 */

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define NEFFLR(l) (l).NEFFLRESEP
#define ELMTLR(l, i) (l).resep[(i)]

/* *** Konstruktor *** */

/* I.S. l sembarang*/
/* F.S  l merupakan ListResep yang kosong*/
void CreateLR(ListResep *l);

/* *** Banyaknya elemen *** */

/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  
int lengthLR(ListResep l);

/* *** Selektor INDEKS *** */

/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
int getFirstIdxLR(ListResep l);

/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
int getLastIdxLR(ListResep l);


/* ********** Test Indeks yang valid ********** */

/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxValidLR(ListResep l, int i);

/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
boolean isIdxEffLR(ListResep l, int i);

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */

/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
boolean isEmptyLR(ListResep l);

/* *** Test List penuh *** */

/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
boolean isFullLR(ListResep l);

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */

/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: */
void readListLR(ListResep *l, char *filename);


void printLR(ListResep l);


/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */

/* Search apakah di ListResep l ada t sehingga */
/* INFONTREE(t) = id. jika iya kembalikan index kemunculan */
/* pertama dari t di l. Jika tidak kembalikan IDX_UNDEF_LR */
int getIdxOfLR(ListResep l, int id);

/* Search apakah resep makanan dengan ID id sudah dicatat pada List Resep*/
/* Jika ada, kembalikan true, sebaliknya kembalikan false*/
boolean isContainResep(ListResep l, int id);
/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */

/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
void insertLastLR(ListResep *l, ElListResepType val);

/* I.S. ListResep tidak boleh kosong */
/* F.S. Jika newResep merupakan subresep dari salah satu resep yang sudah ada */
/*      Maka sisipkan newResep pada subresep tersebut. Jika resep lama merupakan */
/*      sub resep dari newResep, maka gabungkan resep lama ke newResep. Jika */
/*      tidak terjadi, maka tambahkan newResep ke ListResep seperti biasa */
void insertLastLRKonsolidasi(ListResep *l, NTree *newResep);

/* ********** MENGHAPUS ELEMEN ********** */

/* I.S. l terdefinisi, tidak kosong, i merupakan index valid dari l*/
/* F.S. Semua elemen dari l mulai dari index i tergeser ke kiri sekali */
void deleteAtLR(ListResep *l, int i);

/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
void deleteLastLR(ListResep *l, ElListResepType *val);

/* Mengambalikan multiset daftar bahan-bahan makanan yang diperlukan untuk */
/* 'Langsung' membuat makanan dengan id x dalam satu kali aksi */
MultiSet getListBahan(ListResep l, int x);

/* Bonus 3*/
/* Recomendation */

/* Mengembalikan true jika resep bisa dibuat dengan inventory m*/
boolean isResepMakeable(MultiSet *m, NTree resep);

/* Mengembalikan id dari resep yang bisa dibuat dari inventory m */
MultiSet getMakableResep(MultiSet m, ListResep l);




#endif