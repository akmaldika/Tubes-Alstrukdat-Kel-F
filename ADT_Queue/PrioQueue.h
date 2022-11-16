/* File : prioqueue.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */

/* Fungsi : Untuk penyimpanan makanan (Inventory) */
/* PrioQueue dengan pendekatan Array List Dinamik untuk penyimpanan makanan dengan expiry */

#ifndef prioqueuechar_H
#define prioqueuechar_H

// #include "boolean.h"
#include "../ADT_Time/time.h"
#include "../ADT_Time/boolean.h"
#include "../ADT_Makanan/makanan.h"
#include "../ADT_ListStatik/ListMakanan.h" 

#define Nil -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
// typedef struct
// {
//     MAKANAN makanan;
//     // TIME time;
//     // int time;
//     // char info; /* elemen karakter */
// } MAKANAN;

typedef int address; /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueueChar : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct
{
    MAKANAN *T;   /* tabel penyimpan elemen */
    address HEAD; /* alamat penghapusan */
    address TAIL; /* alamat penambahan */
    int MaxEl;    /* Max elemen queue */
} PrioQueue;
/* Definisi PrioQueue kosong: HEAD=Nil; TAIL=Nil. */

/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah MAKANAN dan Q adalah PrioQueue, maka akses elemen : */
#define TimeFull(e) (e).exp
#define Time(e) TIMEToMin((e).exp)
#define Makanan(e) (e)
#define NamaMakanan(e) (e).Nama
#define Info(e) (e).id
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl
#define Elmt(Q, i) (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsEmptyPQ(PrioQueue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullPQ(PrioQueue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
boolean isThereExp(PrioQueue Q);
/* Mengirim true jika dalam queue ada yang expired */
boolean searchMkn(PrioQueue Q, MAKANAN m);
/* Mengirimkan true jika makanan terdapat dalam queue */

int NBElmt(PrioQueue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty(PrioQueue *Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueue *Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue(PrioQueue *Q, MAKANAN X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */

void Dequeue(PrioQueue *Q, MAKANAN *X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

void DequeueExp(PrioQueue *Q, MAKANAN *X);
/* Proses: Menghapus X pada Q dengan aturan FIFO Jika ada yang exp dalam queue */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

void removeFromInventory(PrioQueue *Q, int ID);
/* Proses: Menghapus makanan dengan id ID pada Q dengan aturan yang paling mendekati expired dimulai dari head 
hingga menemukan m lalu dihapus */
/* I.S. Q tidak mungkin kosong */
/* F.S. makanan dengan id ID ter-dequeue (hapus) dari Q dan Q tetap teratur dengan mekanisme circular buffer
        Q mungkin menjadi kosong */


/* Operasi Tambahan */
void PrintPrioQueue(PrioQueue Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/

// 	List Makanan di Inventory
// (nama - waktu sisa kedaluwarsa)
// Ayam Goreng - 2 jam
// Ayam Goreng - 5 jam
// Cabai - 3 jam
// Bawang - 1 jam

void Min1Minute(PrioQueue *Q, boolean *Flag, ListMakanan *LMakana);
/* I.S. q terdefinisi */
/* F.S. Semnua elemen makanan  dalam q berkurang 1 menit dan DequeueExp  */

void MinNTime(PrioQueue *Q, boolean *Flag, ListMakanan *LMakana, int h, int m);
/* I.S. q terdefinisi */
/* F.S. Semnua elemen makanan  dalam q berkurang h jam dan m menit dan DequeueExp  */

#endif
