/* File : Stack.c */
/* implementasi Stack.h */

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "../ADT_Simulator/simulator.h"


/* ********** SELEKTOR ********** */
// #define Top(S) (S).TOP
// #define LStack(S) (S).Container
// #define InfoTop(S) (S).Container[(S).TOP]
// #define InfoTopSim(S) (S).Container[(S).TOP].Sim
// #define InfoTopN(S) (S).Container[(S).TOP].N
// #define CapStack(S) (S).Capacity

/* *** KONSTRUKTOR *** */
ElStackURType MakeElStack(SIMULATOR S, Notifikasi N)
{
    /* Mengirimkan tipe element stack daari S dan N */
    /* precond : S dan N terdefinisi dan valid */
    ElStackURType e;
    Sim(e) = S;
    Nof(e) = N;
    return e;
}

void CreateEmptyStack(Stack *S)
{
    /* I.S. sembarang; */
    /* F.S. Sebuah stack S kosong terbentuk dengan kapasitas initial initCap*/
    LStack(*S) = (ElStackURType *) malloc(initCap * sizeof(ElStackURType));
    Top(*S) = IDX_UNDEF_STACK;
    CapStack(*S) = initCap;
}

/* ************ Predikat Untuk test keadaan Stack ************ */
boolean IsEmptyStack(Stack S)
{
    /* Mengirim true jika Stack kosong */
    return (Top(S) == IDX_UNDEF_STACK);
}

boolean IsFullStack(Stack S)
{
    /* Mengirim true jika Stack penuh */
    return (Top(S) == CapStack(S) - 1);
}

boolean IsSparseStack(Stack S)
{
    /* Mengirimkan true jika S adalah matrix sepi */
    return (CapStack(S) >= 40 && Top(S) < CapStack(S) - 20);
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, ElStackURType X)
{
    /* Menambahkan X sebagai elemen Stack S. */
    /* I.S. S mungkin kosong, mungkin penuh */
    /* F.S. Jika Stack tidak penuh maka Top bertambah 1 */
    /* Jika stack penuh akan mengalokasi memori tambahan dengan fungsi IncearseSize */
    if(IsFullStack(*S))
    {
        IncreaseSize(S);
    }

    Top(*S)++;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, ElStackURType *X)
{
    /* Menghapus X dari Stack S. */
    /* I.S. S  tidak mungkin kosong, mungkin mendekati keadaan sepi */
    /* F.S. X adalah IDX_UNDEF_STACKai elemen TOP yang lama, TOP berkurang 1 */
    /* Jika stack sepi akan di-dealokasi dengan fungsi DecreaseSize */
    *X = InfoTop(*S);
    Top(*S)--;

    if(IsSparseStack(*S))
    {
        DecreaseSize(S);
    }
    else if (IsEmptyStack(*S))
    {
        resetStack(S);
    }
}

void IncreaseSize(Stack *S)
{
    /* I.S. Stack terdefinisi, Stack penuh */
    /* F.S. Capacity stack bertambah sebanyak addCap */
    /* Mengalokasikan memori tambahan untuk stack sebanyak addCap dengan realloc*/
    LStack(*S) = (ElStackURType *) realloc(LStack(*S), (CapStack(*S) + addCap) * sizeof(ElStackURType));
    CapStack(*S) += addCap;
}

void DecreaseSize(Stack *S)
{
    /* I.S. Stack terdefinisi, Stack sepi */
    /* F.S. Capacity stack berkurang sebanyak minCap*/
    /* Men-dealokasi memori berbelih stack sebanyak minCap dengan realloc */
    LStack(*S) = (ElStackURType *) realloc(LStack(*S), (CapStack(*S) - minCap) * sizeof(ElStackURType));
    CapStack(*S) -= minCap;
}

void resetStack(Stack *S)
{
    /* I.S. Stack  terdefinisi, sembarang */
    /* F.S. Capacity Stack dikembalikan initCap; Top Stack = IDX_UNDEF_STACK; Container menampung initCap memori */
    LStack(*S) = (ElStackURType *) realloc(LStack(*S), (initCap) * sizeof(ElStackURType));
    Top(*S) = IDX_UNDEF_STACK;
    CapStack(*S) = initCap;
}

void delAllStack(Stack *S)
{
    /* I.S. Stack  terdefinisi, sembarang */
    /* F.S. Stack dikembalikan ke sistem seluruhnya */
    free(LStack(*S));
    Top(*S) = IDX_UNDEF_STACK;
    CapStack(*S) = initCap;
}