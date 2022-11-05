/* File: ListMakanan.h */
/* Pemrosesan list kontigu, eksplisit, penyimpanan statik */

#ifndef _LISTMAKANAN_h
#define _LISTMAKANAN_h

/* KAMUS DEFINISI PROGRAM */

#include "boolean.h"
#include "..\config_main.h"
#include "..\ADT_MesinKata\mesinkata.h"
#include "..\ADT_MesinKata\string.h"
#include "..\ADT_Makanan\makanan.h"
// #include "..\ADT_Time\"


/* CONFIG_SIZELM adalah SetUp Ukuran Makanan sesuai konfigurasi pada file config_main.h */

typedef int IdxTypeLM; /* Type index */
typedef MAKANAN ElListMakananType;

typedef struct
{
  ElListMakananType Lmakanan[CONFIG_SIZELM];
  int NElmt;
} ListMakanan;
/* Index yang digunakan [0..CONFIG_SIZELM-1] */
/* Definisi :
   List kosong NElmt = 0 
   Pattern function/procedure agar tidak konflik :
   ..LM / LMkn
   ..Mkn*/
 
/* ********** KONSTRUKTOR ********** */
void CreateListMakanan(ListMakanan *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List Makanan kosong dengan kapasitas CONFIG_SIZELM */

/* ********** SELEKTOR ********** */
/* l adalah ListMakanan */
#define LengthLM(l) (l).NElmt           /* get ukuran list */
#define ListMkn(l) (l).Lmakanan           /* get pointer list */
#define ElmtLM(l,i) (l).Lmakanan[i]         /* get elemen list ke-i */

MAKANAN.id GetIdMkn(ListMakanan l, int i);
/* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
/* Mengembalikan int ID makanan index ke-i */

_NAMA_MAKANAN_ GetNamaMkn(ListMakanan l, int i);
/* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
/* Mengembalikan String nama makanan index ke-i*/

_WAKTU_KADALUARSA_MAKANAN_ GetKadaluarsaMkn(ListMakanan l, int i);
/* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
/* Mengembalikan _TIPE_TIME_ dari kadaluarsa makanan index ke-i*/

_WAKTU_DELIVER_MAKANAN_ GetDeliverTimeMkn(ListMakanan l, int i);
/* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
/* Mengembalikan _TIPE_TIME_ dari Waktu pengiriman makanan index ke-i*/

_LOKASI_AKSI_MAKANAN_ GetActionLocMkn(ListMakanan l, int i);
/* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
/* Mengembalikan String lokasi aksi makanan index ke-i*/

_UKURAN_MAKANAN_ GetUkuranMkn(ListMakanan l, int i);
/* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
/* Mengembalikan _TIPE_UKURAN_MAKANAN_  makanan index ke-i*/

/* ********** INPUT / OUTPUT ********** */
void SetUpListMakanan(ListMakanan *l, char* namaFile);
/* I.S. Sembarang */
/* I.F. Terbentuk list makanan berdasarkan hasil konfigurasi */
/* NElmt list pasti sama dengan CONFIG_SIZELM */

void DisplayBuyAbleLM(ListMakanan l);
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

void DisplayActionAbleLM(ListMakanan l, char* str);
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

void DisplayCatalog(ListMakanan l);
/* I.S. l tidak kosong terdapat command 'CATALOG' */
/* F.S menampilkan Katalog makanan ketika command "CATALOG"*/
/* Katalog adalah semua makanan dan bahan yang tersedia pada program */
/* contoh tampilan :
  List Makanan
  (nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time)
  Cabai - 3 jam - BUY - 2 jam
  Ayam Mentah - 5 menit - BUY - 4 jam
  Ayam Potong - 5 menit - CHOP - 0
  Ayam Goreng - 8 jam - FRY - 0
 */

#endif