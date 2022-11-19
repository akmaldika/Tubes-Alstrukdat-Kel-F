/* File : Stack.h */
/* Stack dengan elemen kontigu dan alokasi memori dinamk*/
/* TOP adalah alamat elemen puncak */


#ifndef StackUndoRedo_h
#define StackUndoRedo_h

#include "boolean.h"
#include "..\ADT_Simulator\simulator.h"
#include "..\ADT_Notif\Notifikasi.h"

#define IDX_UNDEF_STACK -1
#define initCap 20
#define addCap 10
#define minCap 10


typedef int address;   /* indeks tabel */
typedef struct {
  SIMULATOR Sim;
  Notifikasi N;
} ElStackURType; /* Type List Makanan */

typedef struct { 
  ElStackURType *Container; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
  int Capacity; /* kapasitas yang sedang ditampung */
} Stack;
/* indeks stack [0..Capacity-1] */
/* Stack kosong adalah stack dengan Top == IDX_UNDEF_STACK */
/* Stack penuh adalah stack dengan Top == Capacity - 1 */
/* Stack sepi adalah stack dengan Top < Capacity - 20 dan Capacity >= 40 */


/* ********** SELEKTOR ********** */
#define Sim(e) (e).Sim
#define Nof(e) (e).N
#define Top(S) (S).TOP
#define LStack(S) (S).Container
#define InfoTop(S) (S).Container[(S).TOP]
#define InfoTopSim(S) Sim(InfoTop(S))
#define InfoTopN(S) Nof(InfoTop(S))
#define CapStack(S) (S).Capacity

/* *** KONSTRUKTOR *** */
void CreateEmptyStack(Stack *S);
/* I.S. sembarang; */
/* F.S. Sebuah stack S kosong terbentuk dengan kapasitas initial initCap*/

/* ************ Predikat Untuk test keadaan Stack ************ */
boolean IsEmptyStack(Stack S);
/* Mengirim true jika Stack kosong */

boolean IsFullStack(Stack S);
/* Mengirim true jika Stack penuh */

boolean IsSparseStack(Stack S);
/* Mengirimkan true jika S adalah matrix sepi */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, ElStackURType X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, mungkin penuh */
/* F.S. Jika Stack tidak penuh maka Top bertambah 1 */
/* Jika stack penuh akan mengalokasi memori tambahan dengan fungsi IncearseSize */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, ElStackURType *X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong, mungkin mendekati keadaan sepi */
/* F.S. X adalah IDX_UNDEF_STACKai elemen TOP yang lama, TOP berkurang 1 */
/* Jika stack sepi akan di-dealokasi dengan fungsi DecreaseSize */

void IncreaseSize(Stack *S);
/* I.S. Stack terdefinisi, Stack penuh */
/* F.S. Capacity stack bertambah sebanyak addCap */
/* Mengalokasikan memori tambahan untuk stack sebanyak addCap dengan realloc*/

void DecreaseSize(Stack *S);
/* I.S. Stack terdefinisi, Stack sepi */
/* F.S. Capacity stack berkurang sebanyak minCap*/
/* Men-dealokasi memori berbelih stack sebanyak minCap dengan realloc */

void resetStack(Stack *S);
/* I.S. Stack  terdefinisi, sembarang */
/* F.S. Capacity Stack dikembalikan initCap; Top Stack = IDX_UNDEF_STACK; Container menampung initCap memori */
/* menggunakan fungsi realloc untuk container */

void delAllStack(Stack *S);
/* I.S. Stack terdefinisi, sembarang */
/* F.S. Stack dikembalikan ke sistem seluruhnya */

#endif