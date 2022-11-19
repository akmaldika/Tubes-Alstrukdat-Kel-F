#include "../ADT_Notifikasi/Notifikasi.h"

#include <stdio.h>
#include "boolean.h"
#include "../library.h"
#include "Notifikasi.h"

// typedef struct {
//     ListMakanan MakananExp;
//     ListMakanan MakananDeliv;
//     ListMakanan MakananUsed;
//     ListMakanan MakananNew;
//     boolean isUndo;
// } Notifikasi;

/* Konstruktor */
/* I.S. Sembarang */
/* F.S. terbuat notifikasi yang baru */
void CreateNotifikasi(Notifikasi *n) {

}

/* Selektor */
// #define EXPIREDFOOD(n) (n).MakananExp
// #define DELIVEREDFOOD(n) (n).MakananDeliv
// #define USEDFOOD(n) (n).MakananUsed
// #define NEWFOOD(n) (n).MakananNew
// #define ISUNDO(n) (n).isUndo

/* Test Kosong */

/* Mengecek apakah ada makanan yang expired */
boolean isExpFoodEmpty(Notifikasi n) {
    // KAMUS
    // ALGORITMA
    return (LengthLM(EXPIREDFOOD(n)) == 0);
}

/* Mengecek apakah ada makanan yang sudah sampai */
boolean isDeliveredFoodEmpty(Notifikasi n) {
    // KAMUS
    // ALGORITMA
    return (LengthLM(DELIVEREDFOOD(n)) == 0);
}

/* Mengecek apakah ada makanan yang dijadikan bahan makanan */
boolean isMakedEmpty(Notifikasi n) {
    // KAMUS
    // ALGORITMA
    return (LengthLM(USEDFOOD(n)) == 0);
}

/* Mengecek apakah ada makanan yang baru dibuay */
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
/* F.S. Jika ada makanan yang sampai, tampilkan notifikasi, dan jika dalam kondisi UNDO, */
/*      tampilkan notifikasi yang sesuai juga */
void displayDelivFood(Notifikasi n);

/* I.S. Notifikasi n terdefinisi */
/* F.S. Jika ada makanan yang sudah dipakai, tampilkan notifikasi, dan jika dalam kondisi UNDO, */
/*      tampilkan notifikasi yang sesuai juga */
void displayUsedFood(Notifikasi n);

/* I.S. Notifikasi n terdefinisi */
/* F.S. Jika ada makanan yang baru, tampilkan notifikasi, dan jika dalam kondisi UNDO, */
/*      tampilkan notifikasi yang sesuai juga */
void displayNewFood(Notifikasi n);

/* I.S. Notifikasi n terdefinisi */
/* F.S. Tampilkan notifikasi secara keseluruhan */
void displayNotifikasi(Notifikasi n);