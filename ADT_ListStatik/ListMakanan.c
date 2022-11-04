/* File: ListMakanan.c */
/* Implementasi header ListMakanan.h */

#include "ListMakanan.h"

/* ********** KONSTRUKTOR ********** */
void CreateListMakanan(ListMakanan *l)
{
    /* I.S. l sembarang */
    /* F.S. Terbentuk List Makanan kosong dengan kapasitas CONFIG_SIZELM */
    LengthLM(*l) = 0;
}

/* ********** SELEKTOR ********** */
/* l adalah ListMakanan; selektor khusus dalam file; l tak dapat berubah */
// #define LengthLM(l) (l).NElmt           /* get ukuran list */
// #define ListMkn(l) (l)._MAKANAN_        /* get pointer list */
// #define ElmtLM(l,i) LMakanan[i]         /* get elemen list ke-i */

_ID_MAKANAN_ GetIdMkn(ListMakanan l, int i)
{
    /* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
    /* Mengembalikan int ID makanan index ke-i */
    return;
}
_NAMA_MAKANAN_ GetNamaMkn(ListMakanan l, int i)
{
    /* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
    /* Mengembalikan String nama makanan index ke-i*/
    return;
}
_WAKTU_KADALUARSA_MAKANAN_ GetKadaluarsaMkn(ListMakanan l, int i)
{
    /* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
    /* Mengembalikan _TIPE_TIME_ dari kadaluarsa makanan index ke-i*/
    return;
}
_WAKTU_DELIVER_MAKANAN_ GetDeliverTimeMkn(ListMakanan l, int i);
{
    /* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
    /* Mengembalikan _TIPE_TIME_ dari Waktu pengiriman makanan index ke-i*/
    return;
}
_LOKASI_AKSI_MAKANAN_ GetActionLocMkn(ListMakanan l, int i);
{
    /* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
    /* Mengembalikan String lokasi aksi makanan index ke-i*/
    return;
}
_UKURAN_MAKANAN_ GetUkuranMkn(ListMakanan l, int i);
{
    /* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
    /* Mengembalikan _TIPE_UKURAN_MAKANAN_  makanan index ke-i*/
    return;
}

/* ********** INPUT / OUTPUT ********** */
void SetUpListMakanan(ListMakanan *l, char *namaFile)
{
    /* I.S. Sembarang */
    /* I.F. Terbentuk list makanan berdasarkan hasil konfigurasi */
    /* NElmt list pasti sama dengan CONFIG_SIZELM */
    STARTLINE(namaFile);
    
}

void DisplayBuyAbleLM(ListMakanan l)
{
    /* I.S. l tidak kosong, terdapat command BUY dan Simulator adjecent dengan B */
    /* F.S. menampilkan bahan makanan yang memiliki String _LOKASI_AKSI_MAKANAN_ "BUY" */
    /* contoh tampilan :
        =========================
        =          BUY          =
        =========================
        List Bahan Makanan:
        1. Cabai (2 menit)
        2. Bawang (1 menit)
        3. Ayam Mentah (5 jam)
    */
    /* KAMUS LOKAL */
    int i;

    /* ALGORITMA */
    printf("=========================\n");
    printf("=          BUY          =\n");
    printf("=========================\n");
    printf("List Bahan Makanan");
    i = 0;
    while (i < LengthLM(l))
    {
        if (GetActionLocMkn(l, i) == "BUY")
        {
            printf("%d. %s\t()", i, GetNamaMkn(l, i)); //*************************************************************************************
            printf("\n");
        }
        i++;
    }
}

void DisplayActionAbleLM(ListMakanan l, char *str)
{
    /* I.S. l tidak kosong str valid yaitu command / simuulator terdapat pada FRY, CHOP, BOIL, MIX */
    /* F.S menampilkan bahan makanan yang memiliki String _LOKASI_AKSI_MAKANAN_ str */
    /* contoh tampilan :
    =========================
    =          FRY          =
    =========================
    List Bahan Makanan yang Bisa Dibuat:
    1. Ayam Goreng
    2. Sambal Goreng
    */
    /* KAMUS LOKAL */
    int i;

    /* ALGORITMA */
    i = 0;
    printf("===========");
    while (str[i] != '\0')
    {
        printf("=");
        i++;
    }
    printf("===========\n");
    printf("=          ");
    printf("%s", str);
    printf("          =\n");
    i = 0;
    printf("===========");
    while (str[i] != '\0')
    {
        printf("=");
        i++;
    }
    printf("===========\n");

    i = 0;
    printf("List Bahan Makanan yang Bisa Dibuat:\n");
    while (i < LengthLM(l))
    {
        if (GetActionLocMkn(l, i) == str)
        {
            printf("%d. %s", i, GetNamaMkn(l, i));
            printf("\n");
        }
        i++;
    }
}

void DisplayCatalog(ListMakanan l)
{
    /* I.S. l tidak kosong */
    /* F.S menampilkan Katalog makanan ketika command "CATALOG"*/
    /* Katalog adalah semua makanan dan bahan yang tersedia pada program */
    /* contoh tampilan :
    List Makanan
    |- Nama -|- Durasi Kedaluwarsa -|- Aksi yang  -|- Delivery Time -|
    |        |                      |- Diperlukan -|                 |
    Cabai - 3 jam - BUY - 2 jam
    Ayam Mentah - 5 menit - BUY - 4 jam
    Ayam Potong - 5 menit - CHOP - 0
    Ayam Goreng - 8 jam - FRY - 0
    */
    /* KAMUS LOKAL */
    int i, cntStr;

    int i;
    printf("\xc9");
    for (i = 1; i <= 45; i++)
    {
        printf("\xcd"); // ░
    }
    printf(" LIST MAKANAN ");
    for (i = 1; i <= 46; i++)
    {
        printf("\xcd"); // ░
    }
    printf("\xbb");
    printf("\n");

    printf(" |-%15sNama%15s-|-%4sDurasi Kedaluarsa%3s-|-%sAksi yang %s-|-%6sDelivery Time%5s-|\n", "", "", "", "", "", "", "", "");
    printf(" | %15s    %15s | %4s                 %3s | %sDiperlukan%s | %6s             %5s |\n", "", "", "", "", "", "", "", "");

    for (i = 0; i < LengthLM(l); i++)
    {   
        printf(" | ");
        cntStr = 0; // Nama Makanan
        while(GetNamaMkn(l, i)[cntStr] != '\0')
        {
            printf("%c", GetNamaMkn(l, i)[cntStr]);
            cntStr++;
        }
        while(cntStr < 34)
        {
            printf(" ");
            cntStr++;
        }
        printf(" | ");
        cntStr = 0; // Kedaluarsa Time
        while(GetActionLocMkn(l, i)[cntStr] != '\0')
        {
            printf("%c", GetActionLocMkn(l, i)[cntStr]);
            cntStr++;
        }
        while(cntStr < 24)
        {
            printf(" ");
            cntStr++;
        }
        printf(" | ");
        cntStr = 0; // Action Loc
        while(GetActionLocMkn(l, i)[cntStr] != '\0')
        {
            printf("%c", GetActionLocMkn(l, i)[cntStr]);
            cntStr++;
        }
        while(cntStr < 24)
        {
            printf(" ");
            cntStr++;
        }
        printf(" | ");
        cntStr = 0; // Delivery Time
    }

    printf("\xc8");
    for (i = 1; i <= 45; i++)
    {
        printf("\xcd"); // ░
    }
    printf(" PROGRAM BNMO ");
    for (i = 1; i <= 46; i++)
    {
        printf("\xcd"); // ░
    }
    printf("\xbc");
    printf("\n");
}