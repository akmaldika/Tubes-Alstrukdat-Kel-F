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

/* Mengecek apakah ada makanan yang expired */
boolean isExpFoodEmpty(Notifikasi n);

/* Mengecek apakah ada makanan yang sudah sampai */
boolean isDeliveredFoodEmpty(Notifikasi n);

/* Mengecek apakah ada makanan yang dijadikan bahan makanan */
boolean isMakedEmpty(Notifikasi n);

/* Mengecek apakah ada makanan yang baru dibuay */
boolean isNewFoodEmpty(Notifikasi n);

/* Prosedur untuk menampilkan notifikasi */

/* I.S. Notifikasi n terdefinisi */
/* F.S. Jika ada makanan expired, tampilkan notifikasi, dan jika dalam kondisi UNDO, */
/*      tampilkan notifikasi yang sesuai juga */
void displayExpFood(Notifikasi n);

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

/* I.S. Notifikasi n terdefinisi */
/* F.S. Isi n berubah di bagian notifikasi makanan delivery dan expired sesuai input*/
void setExpDelivNotif(Notifikasi *n, ListMakanan expFood, ListMakanan delivFood);

/* I.S. Notifikasi n terdefinisi */
/* F.S. Isi n berubah di semua bagian sesuai input*/
void setAllNotif(Notifikasi *n, ListMakanan expFood, ListMakanan delivFood, ListMakanan usedFood, ListMakanan newFood);


#endif