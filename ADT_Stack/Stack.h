/* File : Stack.h */
/* Stack dengan elemen kontigu dan alokasi memori dinamk*/
/* TOP adalah alamat elemen puncak */


#ifndef StackUndoRedo_h
#define StackUndoRedo_h

#include "boolean.h"
#include "..\ADT_Makanan\makanan.h"
#include "..\ADT_Time\time.h"
#include "..\ADT_Simulator\simulator.h"
// #include "..\ADT_Point\"
#include "..\ADT_Matriks\matrix.h"

#define Nil -1
#define initCap 20
#define addCap 10
#define minCap 10


typedef int address;   /* indeks tabel */
typedef SIMULATOR ElStackURType; /* Type List Makanan */

typedef struct { 
  ElStackURType *Container; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
  int Capacity; /* kapasitas yang sedang ditampung */
} Stack;
/* indeks stack [0..Capacity-1] */
/* Stack kosong adalah stack dengan Top == Nil */
/* Stack penuh adalah stack dengan Top == Capacity - 1 */
/* Stack sepi adalah stack dengan Top < Capacity - 20 dan Capacity >= 40 */


/* ********** SELEKTOR ********** */
#define Top(S) (S).TOP
#define LStack(S) (S).Container
#define InfoTop(S) (S).Container[(S).TOP]
#define CapStack(S) (S).Capacity

/* *** KONSTRUKTOR *** */
void CreateEmpty(Stack *S);
/* I.S. sembarang; */
/* F.S. Sebuah stack S kosong terbentuk dengan kapasitas initial initCap*/

/* ************ Predikat Untuk test keadaan Stack ************ */
boolean IsEmpty(Stack S);
/* Mengirim true jika Stack kosong */

boolean IsFull(Stack S);
/* Mengirim true jika Stack penuh */

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
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
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
/* F.S. Capacity Stack dikembalikan initCap; Top Stack = Nil; Container menampung initCap memori */
/* menggunakan fungsi realloc untuk container */

#endif