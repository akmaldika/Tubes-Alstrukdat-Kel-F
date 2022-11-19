#ifndef MULTISET_H
#define MULTISET_H

#include <stdio.h>
#include "boolean.h"
#include "../library.h"

typedef struct {
    ListMakanan MakananExp;
    ListMakanan MakananDeliv;
    ListMakanan MakananUsed;
    ListMakanan MakananNew;
    boolean isUndo;
} Notifikasi;

/* Konstruktor */
/* I.S. Sembarang */
/* F.S. terbuat notifikasi yang baru */
void CreateNotifikasi(Notifikasi *n);

/* Selektor */
#define EXPIREDFOOD(n) (n).MakananExp
#define DELIVEREDFOOD(n) (n).MakananDeliv
#define USEDFOOD(n) (n).MakananUsed
#define NEWFOOD(n) (n).MakananNew
#define ISUNDO(n) (n).isUndo

/* Test Kosong */

boolean isExpFoodEmpty(Notifikasi n) {
    // KAMUS
    // ALGORITMA
    return (LengthLM(EXPIREDFOOD(n)) == 0);
}

boolean isDeliveredFoodEmpty(Notifikasi n) {
    // KAMUS
    // ALGORITMA
    return (LengthLM(DELIVEREDFOOD(n)) == 0);
}

boolean isMakedEmpty(Notifikasi n) {
    // KAMUS
    // ALGORITMA
    return (LengthLM(USEDFOOD(n)) == 0);
}

boolean isNewFoodEmpty(Notifikasi n) {
    // KAMUS
    // ALGORITMA
    return (LengthLM(NEWFOOD(n)) == 0);
}

/* Prosedur untuk menampilkan notifikasi */

/* I.S. Notifikasi n terdefinisi */
/* F.S. Jika ada makanan expired, tampilkan notifikasi, dan jika dalam kondisi UNDO, */
/*      tampilkan notifikasi yang sesuai juga */
void displayExpFood(Notifikasi n) {
    // KAMUS
    int i;
    // ALGOTIMA
    if (ISUNDO(n)) {
        printf("Makanan berikut sudah expired dan dibuang dari inventory\n");
        for (i = 0; i < LengthLM(EXPIREDFOOD(n)); i++); {
            printf("- %s\n", GetNamaMkn(EXPIREDFOOD(n), i).Tabword);
        }
    } else {
        printf("Makanan berikut yang tadinya expired sudah kembali ke inventory\n");
        for (i = 0; i < LengthLM(EXPIREDFOOD(n)); i++); {
            printf("- %s\n", GetNamaMkn(EXPIREDFOOD(n), i).Tabword);
        }
    }
}
/* I.S. Notifikasi n terdefinisi */
/* F.S. Jika ada makanan expired, tampilkan notifikasi, dan jika dalam kondisi UNDO, */
/*      tampilkan notifikasi yang sesuai juga */
void displayDelivFood(Notifikasi n);

/* I.S. Notifikasi n terdefinisi */
/* F.S. Jika ada makanan expired, tampilkan notifikasi, dan jika dalam kondisi UNDO, */
/*      tampilkan notifikasi yang sesuai juga */
void displayUsedFood(Notifikasi n);

/* I.S. Notifikasi n terdefinisi */
/* F.S. Jika ada makanan expired, tampilkan notifikasi, dan jika dalam kondisi UNDO, */
/*      tampilkan notifikasi yang sesuai juga */
void displayNewFood(Notifikasi n);

/* I.S. Notifikasi n terdefinisi */
/* F.S. Jika ada makanan expired, tampilkan notifikasi, dan jika dalam kondisi UNDO, */
/*      tampilkan notifikasi yang sesuai juga */
void displayNotifikasi(Notifikasi n);






#endif