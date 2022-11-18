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
// #define CapStack(S) (S).Capacity

/* *** KONSTRUKTOR *** */
void CreateEmptyStack(Stack *S)
{
    /* I.S. sembarang; */
    /* F.S. Sebuah stack S kosong terbentuk dengan kapasitas initial initCap*/
    LStack(*S) = (SIMULATOR *) malloc(initCap * sizeof(SIMULATOR));
    Top(*S) = Nil;
    CapStack(*S) = initCap;
}

/* ************ Predikat Untuk test keadaan Stack ************ */
boolean IsEmptyStack(Stack S)
{
    /* Mengirim true jika Stack kosong */
    return (Top(S) == Nil);
}

boolean IsFullStack(Stack S)
{
    /* Mengirim true jika Stack penuh */
    return (Top(S) == CapStack(S) - 1);
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
    /* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    /* Jika stack sepi akan di-dealokasi dengan fungsi DecreaseSize */
    InfoTop(*S) = *X;
    Top(*S)--;

    if(CapStack(*S) >= 40 && Top(*S) < CapStack(*S) - 20)
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
    LStack(*S) = (SIMULATOR *) realloc(LStack(*S), (CapStack(*S) + addCap) * sizeof(SIMULATOR));
    CapStack(*S) += addCap;
}

void DecreaseSize(Stack *S)
{
    /* I.S. Stack terdefinisi, Stack sepi */
    /* F.S. Capacity stack berkurang sebanyak minCap*/
    /* Men-dealokasi memori berbelih stack sebanyak minCap dengan realloc */
    LStack(*S) = (SIMULATOR *) realloc(LStack(*S), (CapStack(*S) - minCap) * sizeof(SIMULATOR));
    CapStack(*S) -= minCap;
}

void resetStack(Stack *S)
{
    /* I.S. Stack  terdefinisi, sembarang */
    /* F.S. Capacity Stack dikembalikan initCap; Top Stack = Nil; Container menampung initCap memori */
    LStack(*S) = (SIMULATOR *) realloc(LStack(*S), (initCap) * sizeof(SIMULATOR));
    Top(*S) = Nil;
    CapStack(*S) = initCap;
}

void delAllStack(Stack *S)
{
    /* I.S. Stack  terdefinisi, sembarang */
    /* F.S. Stack dikembalikan ke sistem seluruhnya */
    free(LStack(*S));
    Top(*S) = Nil;
    CapStack(*S) = initCap;
}