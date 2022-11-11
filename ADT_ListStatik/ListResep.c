/* File: ListResep.c */

/* KAMUS DEFINISI PROGRAM */
#include "boolean.h"
#include "ListResep.h"
#include <stdio.h>

#define CAPACITY_LIST_RESEP CONFIG_SIZELR

// typedef Address ElListResepType;

// typedef struct { 
//     ElListResepType resep[CAPACITY_LIST_RESEP];
//     int NEFFLRESEP;
// } ListResep;

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
// #define NEFFLR(l) (l).NEFFLRESEP
// #define ELMTLR(l, i) (l).resep[i]

/* *** Konstruktor *** */

/* I.S. l sembarang*/
/* F.S  l merupakan ListResep yang kosong*/
void CreateLR(ListResep *l) {
    NEFFLR(*l) = 0;
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */

/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  
int lengthLR(ListResep l) {
    return NEFFLR(l);
}

/* *** Selektor INDEKS *** */

/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
int getFirstIdxLR(ListResep l) {
    return 0;
}

/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
int getLastIdxLR(ListResep l) {
    return (NEFFLR(l) - 1);
}

/* ********** Test Indeks yang valid ********** */
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxValidLR(ListResep l, int i) {
    return ((0 <= i) && (i <= CAPACITY_LIST_RESEP));
}

/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
boolean isIdxEffLR(ListResep l, int i) {
    return ((getFirstIdxLR(l) <= i) && (i <= getLastIdxLR(l)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */

/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */

boolean isEmptyLR(ListResep l) {
    return NEFFLR(l) == 0;
}

/* *** Test List penuh *** */

/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
boolean isFullLR(ListResep l) {
    return NEFFLR(l) == CAPACITY_LIST_RESEP;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */

/* I.S. l sembarang */
/* F.S. List l terdefinisi */
void readListLR(ListResep *l) {
    // KAMUS
    int n, baris, i, k, id;
    // ALGORITMA
    STARTLINE("../Config/Config_Resep.txt");
    ADVWORD();
    n = wordToInt(currentWord);
    printf("%d\n", n);
    ADVLINE();
    for (baris = 1; baris <= n; baris++) {
        // Akuisi integer pertama sebagai resep utama
        ADVWORD();
        id = wordToInt(currentWord);
        

        i = 0;
        while (currentLength < currentLine.Length) {
            ADVWORD();
            k = wordToInt(currentWord);
            printf("%d ", k);
        }
        printf("\n");
        ADVLINE();
    }
}

/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
void printLR(ListResep l) {
    // KAMUS
    int i;
    // ALGORITMA
    for (i = 0; i < NEFFLR(l) ; i++) {
        printf("Index ke %d\n", i);
        printNTree(ELMTLR(l, i), 0);
    }
}


/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */



/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF = -1 */
/* Skema Searching yang digunakan bebas */
int indexOfLR(ListResep l, ElListResepType val) {
    // KAMUS
    // ALGORITMA

}
/* Search apakah resep makanan dengan ID id sudah dicatat pada List Resep*/
/* Jika ada, kembalikan true, sebaliknya kembalikan false*/
boolean isContainResep(ListResep l, int id) {
    // KAMUS
    NTree currResep;
    int i, currID;
    boolean isFound;
    // ALGORITMA
    // Inisialisasi
    i = 0;
    isFound = false;
    while (isIdxEffLR(l, i) && !isFound) {
        currResep = ELMTLR(l, i);
        currID = INFONTREE(currResep);
        if (currID == id) {
            isFound = true;
        } i++;
    } return isFound;
}

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
/* I.S. List lR boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
void insertLastLR(ListResep *l, ElListResepType val) {
    ELMTLR(*l, getLastIdxLR(*l) + 1) = val;
    NEFFLR(*l) = NEFFLR(*l) + 1;
}
/* I.S. ListResep tidak boleh kosong */
/* F.S. Jika newResep merupakan subresep dari salah satu resep yang sudah ada */
/*      Maka sisipkan newResep pada subresep tersebut. Jika resep lama merupakan */
/*      sub resep dari newResep, maka gabungkan resep lama ke newResep. Jika */
/*      tidak terjadi, maka tambahkan newResep ke ListResep seperti biasa */
void insertLastLRKonsolidasi(ListResep *l, NTree *newResep) {
    // KAMUS
    NTree currResep;
    int i;
    // ALGORITMA
    /* Pemrosesan apabila ada subresep dari newResep yang 
       sama dengan resep-resep yang sudah ada di ListResp l*/
    for (i = 0; isIdxEffLR(*l, i); i++) {
        currResep = ELMTLR(*l, i);
        if (isContainInfo(*newResep, INFONTREE(currResep))) {
            addChildBySpecificInfo(newResep, ELMTLR(*l, i));
        }
    } 

    /* Pemrosesan apabila ada subresep dari resep-resep di l yang
       sanma dengan newResep */
    for (i = 0; isIdxEffLR(*l, i); i++) {
        currResep = ELMTLR(*l, i);
        if (isContainInfo(currResep, INFONTREE(*newResep))) {
            addChildBySpecificInfo(&ELMTLR(*l, i), *newResep);
        }
    }
    insertLastLR(l, *newResep);


}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */

/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void deleteFirstLR(ListResep *l, ElListResepType *val);

/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void deleteAtLR(ListResep *l, ElListResepType *val, int idx);

/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
void deleteLastLR(ListResep *l, ElListResepType *val);

/* Manajemen lokasi resep pada ListResep*/

/* I.S. l terdefinisi, tidak kosong, i merupakan index valid dari l*/
/* F.S. Semua elemen dari l mulai dari index i tergeser ke kiri sekali */
void shiftLeftLRAtIndex(ListResep *l, int i) {
    // KAMUS
    NTree currResep, nextResep;
    // ALGORITMA
    while (i < NEFFLR(*l) - 1) {
        ELMTLR(*l, i) = ELMTLR(*l, i+1);
        i++;
    }
    ELMTLR(*l, i) = NULL;
    NEFFLR(*l) = NEFFLR(*l) - 1;
}

void compressLR(ListResep *l) {

}