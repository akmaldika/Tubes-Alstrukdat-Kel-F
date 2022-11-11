/* File: ListMakanan.c */
/* Implementasi header ListMakanan.h */

#include "ListMakanan.h"

static ListMakanan ListMkn;

/* ********** KONSTRUKTOR ********** */
void CreateListMakanan(ListMakanan *l)
{
    /* I.S. l sembarang */
    /* F.S. Terbentuk List Makanan kosong dengan kapasitas CONFIG_SIZELM */
    LengthLM(*l) = 0;
}

/* ********** SELEKTOR ********** */
/* l adalah ListMakanan; selektor khusus dalam file; l tak dapat berubah */
// #define LengthLM(l) (l).NElmt           /* get/set ukuran list */
// #define ListMkn(l) (l)._MAKANAN_        /* get/set pointer list */
// #define ElmtLM(l,i) LMakanan[i]         /* get/set elemen list ke-i */

IDEM GetIdMkn(ListMakanan l, int i)
{
    /* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
    /* Mengembalikan int ID makanan index ke-i */
    return ID(ElmtLM(l,i));
}

NamaMakanan GetNamaMkn(ListMakanan l, int i)
{
    /* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
    /* Mengembalikan String nama makanan index ke-i*/
    return Judul(ElmtLM(l,i));
}

TIME GetKadaluarsaMkn(ListMakanan l, int i)
{
    /* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
    /* Mengembalikan _TIPE_TIME_ dari kadaluarsa makanan index ke-i*/
    return Exp(ElmtLM(l,i));
}

TIME GetDeliverTimeMkn(ListMakanan l, int i)
{
    /* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
    /* Mengembalikan _TIPE_TIME_ dari Waktu pengiriman makanan index ke-i*/
    return Deliv(ElmtLM(l,i));
}

Word GetActionLocMkn(ListMakanan l, int i)
{
    /* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
    /* Mengembalikan String lokasi aksi makanan index ke-i*/
    return Locate(ElmtLM(l,i));
}

// POINT GetUkuranMkn(ListMakanan l, int i);
/* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
/* Mengembalikan _TIPE_UKURAN_MAKANAN_  makanan index ke-i*/

/* ***** Operasi pencarian elemen ***** */
boolean isIdValid(ListMakanan l, IDEM id)
{
    /* Mengembalikan true jika id ada di dalam list */
    /* KAMUS LOKAL */
    IdxType i;
    boolean found;

    /* ALGORITMA */
    while (!found && i <= LengthLM(l))
    {
        found = ID(ElmtLM(l,i)) == id;
        i++;
    }

    return found;
}

/* Precond : untuk setiap parameter Id adalah valid dan pasti ada dalam list makanan */
IdxType SearchIndexId(ListMakanan l, IDEM id)
{
    /* mengembalikan index jika menemukan Id pada list */
    /* KAMUS LOKAL */
    IdxType i;
    boolean found;

    /* ALGORITMA */
    i = 0;
    found = false;
    while(!found && i <= LengthLM(l))
    {
        if (ID(ElmtLM(l,i)) == id)
        {
            found = true;
        }
        else
        {
            i++;
        }
    }

    return i;
}


ElListMakananType MknId(ListMakanan l, IDEM id)
{
    /* mengambalikan tipe Makanan berdasarkan ID makanan */
    /* KAMUS LOKAL */
    IdxType i;

    /* ALGORITMA */
    i = SearchIndexId(l, id);
    return ElmtLM(l,i);
}

NamaMakanan NamaMknId(ListMakanan l, IDEM id)
{
    /* mengambalikan nama makanan berdasarkan ID makanan */
    return Judul(MknId(l, id));
}

TIME KedaluarsaMknId(ListMakanan l, IDEM id)
{
    /* Mengembalikan nama makanan berdasarkan ID makanan */
    return Exp(MknId(l,id));
}

TIME DeliverTimeMknId(ListMakanan l, IDEM id)
{
    /* Mengembalikan waktu pengiriman makanan berdasarkan Id makanan*/
    return Deliv(MknId(l, id));
}

LokasiAksi ActionLocId(ListMakanan l, IDEM id)
{
    /* Mengembalikan lokasi aksi makanan berdasarkan Id makanan */
    return Locate(MknId(l, id));
}

// POINT UkuranMknId(ListMakanan l, IDEM);
/* mengambalikan _UKURAN_MAKANAN_ berdasarkan ID */


/* ********** INPUT / OUTPUT ********** */
void SetUpListMakanan()
{
    /* I.S. Sembarang */
    /* I.F. Terbentuk list makanan berdasarkan hasil konfigurasi */
    /* NElmt list pasti sama dengan CONFIG_SIZELM */
    /* KMAMUS LOKAL */
    int BanyakMakanan;
    IdxType i;
    TIME tempT;
    int D, M, H;

    CreateListMakanan(&ListMkn);
    STARTLINE("../Config/Config_Makanan.txt");
    STARTWORD();
    LengthLM(ListMkn) = wordToInt(currentWord);
    i = 0;
    while (!EOP)
    {
        // ID
        ADVLINE();
        STARTWORD();
        ID(ElmtLM(ListMkn, i)) = wordToInt(currentWord);
        // Judul Makanan
        ADVLINE();
        Judul(ElmtLM(ListMkn, i)) = currentLine;
        // exp Time
        ADVLINE();
        STARTWORD();
        D = wordToInt(currentWord);
        ADVWORD();
        M = wordToInt(currentWord);
        ADVWORD();
        H = wordToInt(currentWord);
        CreateTime(&tempT, D, M, H);
        Exp(ElmtLM(ListMkn, i)) = tempT;
        // deliv Time
        ADVLINE();
        STARTWORD();
        D = wordToInt(currentWord);
        ADVWORD();
        M = wordToInt(currentWord);
        ADVWORD();
        H = wordToInt(currentWord);
        CreateTime(&tempT, D, M, H);
        Deliv(ElmtLM(ListMkn, i)) = tempT;
        // lokasi
        ADVLINE();
        STARTWORD();
        Locate(ElmtLM(ListMkn, i)) = currentWord;
        i++;
    }
    
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
        if (GetActionLocMkn(l, i).String == "BUY")
        {
            printf("%d. %s\t()", i, GetNamaMkn(l, i).Tabword); //*************************************************************************************
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
        if (GetActionLocMkn(l, i).String == str)
        {
            printf("%d. %s", i, GetNamaMkn(l, i).Tabword);
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
        while(GetNamaMkn(l, i).Tabword[cntStr] != '\0')
        {
            printf("%c", GetNamaMkn(l, i).Tabword[cntStr]);
            cntStr++;
        }
        while(cntStr < 34)
        {
            printf(" ");
            cntStr++;
        }
        printf(" | ");
        cntStr = 0; // Kedaluarsa Time
        while(GetActionLocMkn(l, i).String[cntStr] != '\0')
        {
            printf("%c", GetActionLocMkn(l, i).String[cntStr]);
            cntStr++;
        }
        while(cntStr < 24)
        {
            printf(" ");
            cntStr++;
        }
        printf(" | ");
        cntStr = 0; // Action Loc
        while(GetActionLocMkn(l, i).String[cntStr] != '\0')
        {
            printf("%c", GetActionLocMkn(l, i).String[cntStr]);
            cntStr++;
        }
        while(cntStr < 24)
        {
            printf(" ");
            cntStr++;
        }
        printf(" | ");
        cntStr = 0; // Delivery Time - minta request @NerbFox
        // while(GetDeliverTimeMkn(l, i).String[cntStr] != '\0')
        // {
        //     printf("%c", GetDeliverTimeMkn(l, i).String[cntStr]);
        //     cntStr++;
        // }
        // while(cntStr < 24)
        // {
        //     printf(" ");
        //     cntStr++;
        // }
        printf(" | ");
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