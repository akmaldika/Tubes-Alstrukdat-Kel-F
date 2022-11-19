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
#include "..\ADT_Time\time.h"

#define IDX_UNDEF_LM -1

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
   ..Mkn
*/


/* ********** KONSTRUKTOR ********** */
void CreateListMakanan(ListMakanan *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List Makanan kosong dengan kapasitas CONFIG_SIZELM */

/* ********** SELEKTOR ********** */
/* l adalah ListMakanan */
#define LengthLM(l) (l).NElmt           /* get/set ukuran list */
#define ListMkn(l) (l).Lmakanan           /* get/set pointer list */
#define ElmtLM(l,i) (l).Lmakanan[i]         /* get/set elemen list ke-i */

IDEM GetIdMkn(ListMakanan l, int i);
/* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
/* Mengembalikan int ID makanan index ke-i */

NamaMakanan GetNamaMkn(ListMakanan l, int i);
/* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
/* Mengembalikan String nama makanan index ke-i*/

TIME GetKadaluarsaMkn(ListMakanan l, int i);
/* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
/* Mengembalikan _TIPE_TIME_ dari kadaluarsa makanan index ke-i*/

TIME GetActionTimeMkn(ListMakanan l, int i);
/* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
/* Mengembalikan _TIPE_TIME_ dari Waktu pengiriman makanan index ke-i*/

Word GetActionLocMkn(ListMakanan l, int i);
/* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
/* Mengembalikan String lokasi aksi makanan index ke-i*/

// POINT GetUkuranMkn(ListMakanan l, int i);
/* l terdefinisi dan i valid untuk l, yaitu [0..NElmt-1] */
/* Mengembalikan _TIPE_UKURAN_MAKANAN_  makanan index ke-i*/

/* ***** Operasi pencarian elemen ***** */
boolean isIdValid(ListMakanan l, IDEM id);
/* Mengembalikan true jika id ada di dalam list */

IdxTypeLM SearchIndexbyId(ListMakanan l, IDEM id);
/* mengembalikan index jika menemukan Id pada list */
/* mengembalikan IDX_UNDEF_LM jika ID tidak ada */
/* Precond : untuk setiap parameter Id adalah valid dan pasti ada dalam list makanan */

ElListMakananType MknId(ListMakanan l, IDEM id);
/* mengambalikan tipe Makanan berdasarkan ID makanan */

NamaMakanan NamaMknId(ListMakanan l, IDEM id);
/* mengambalikan nama makanan berdasarkan ID makanan */

TIME KedaluarsaMknId(ListMakanan l, IDEM id);
/* Mengembalikan nama makanan berdasarkan ID makanan */

TIME ActionTimeMknId(ListMakanan l, IDEM id);
/* Mengembalikan waktu pengiriman makanan berdasarkan Id makanan*/

LokasiAksi ActionLocId(ListMakanan l, IDEM id);
/* Mengembalikan lokasi aksi makanan berdasarkan Id makanan */

// POINT UkuranMknId(ListMakanan l, IDEM);
/* mengambalikan _UKURAN_MAKANAN_ berdasarkan ID */

void accumLM(ListMakanan *l1, ListMakanan l2);
/* I.S. l1 dan l2 terdefinisi, jumlah dari panjang l1 dan l2 tidak melebih CONFIG_SIZELM */
/* F.S. isi dari l2 tersalin dan ditambahkan ke l1*/

/* ********** INPUT / OUTPUT ********** */
void SetUpListMakanan(ListMakanan *l, char *filename);
/* I.S. Sembarang */
/* I.F. Terbentuk list makanan berdasarkan hasil konfigurasi */
/* NElmt list pasti sama dengan CONFIG_SIZELM */

ListMakanan DisplayBuyAbleLM(ListMakanan l);
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
ListMakanan DisplayActionAbleLM(ListMakanan l, char *Lchar);
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