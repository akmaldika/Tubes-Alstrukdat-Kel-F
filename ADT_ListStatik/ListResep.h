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
void readListLR(ListResep *l);

/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
void printLR(ListResep l);


/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */


/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
int indexOfLR(ListResep l, ElListResepType val);

/* Search apakah resep makanan dengan ID id sudah dicatat pada List Resep*/
/* Jika ada, kembalikan true, sebaliknya kembalikan false*/
boolean isContainResep(ListResep l, int id);
/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */

/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void insertFirstLR(ListResep *l, ElListResepType val);

/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void insertAtLR(ListResep *l, ElListResepType val, int idx);

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
/* *** Menghapus elemen pertama *** */

/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void deleteFirstLR(ListResep *l, ElListResepType *val);

/* I.S. l terdefinisi, tidak kosong, i merupakan index valid dari l*/
/* F.S. Semua elemen dari l mulai dari index i tergeser ke kiri sekali */
void deleteAtLR(ListResep *l, int i);

/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
void deleteLastLR(ListResep *l, ElListResepType *val);




#endif