#ifndef UNDO_h
#define UNDO_h

#include <stdlib.h>
#include <stdio.h>
#include "../ADT_Simulator/simulator.h"
#include "../ADT_Stack/stack.h"
#include "boolean.h"
#include "../ADT_MesinKata/mesinkata.c"
#include "../ADT_MesinKata/mesinkarakter.c"
#include "../ADT_MesinKata/string.c"

void undoGame(SIMULATOR *S, SIMULATOR InitSim, Stack *Undo, Stack *Redo);
/* I.S. : S, Undo, dan redo terdefinisi, InitSim adalah keadaan simulator paling awal dalam game */
/* F.S. : jika stack Undo kosong, tampilkan pesan */
/* Stack undo menjadi kosong artinya S = InitSim  */
/* Jika tidak, Stack Undo akan dipop dan dimasukkan ke dalam Stack Redo */
/* Top(Undo) yang baru akan menjadi S, visualnya */
/* misal A, B, C adalah type SIMULATOR dan S adalah kondisi S
    C     S=C                               S=B
    B                   -undoGame->     B
    A                                   A           C
    Undo        Redo                    Undo        Redo
    -------Jika Stack menjadi kosong
          S=A                               S=InitSim
                        -undoGame->     
    A                                               A
    Undo        Redo                    Undo        Redo
 */

void redoGame(SIMULATOR *S, Stack *Undo, Stack *Redo);
/* I.S. : S, Undo, dan Redo terdefinisi */
/* F.S. : Jika Stack Redo kosong, tampilkan pesan */
/* Stack redo kosong artinya S sedang pada keadaan paling baru*/
/* Jika tidak kosong Stack Redo akan dipop dan di masukkan ke dalam Stack Redo*/
/* Top(Undo) yang baru akan menjadi S, visualnya: */
/* misal A, B, C adalah type SIMULATOR dan S adalah kondisi S
          S=B                           C    S=C
    B                   -redoGame->     B
    A           C                       A           
    Undo        Redo                    Undo        Redo
    -------Jika Stack kosong
          S=A                               S=A 
                        -redoGame->     
    A                    {pesan}        A           
    Undo        Redo                    Undo        Redo
 */

void saveUndoRedoGame(SIMULATOR S, SIMULATOR InitSim, Stack *Undo, Stack *Redo);
/* I.S. : S, Undo, dan Redo terdefinisi, InitSim adalah keadaan simulator paling awal, 
    currentWord terdefinisi dan valid sebagai command */
/* F.S. : jika keadaan S berubah, S dimasukkan ke dalam Stack Undo */
/* S disamakan dengan Top(Undo) -> F.S. */
/* Stack Redo akan kosong menyesuaikan kondisi logic undo-redo, 
    yaitu ketika user menginput command baru dan S berubah setelah melakukan beberapa Undo  */

#endif

void undoGame(SIMULATOR *S, SIMULATOR InitSim, Stack *Undo, Stack *Redo)
{
    if (IsEmptyStack(*Undo))
    {
        printf("Undo tidak bisa dilakukan\n");
        printf("Anda sudah berada di keadaan paling awal!\n");
    }
    else
    {
        ElStackURType valOut;
        Pop(Undo, &valOut);
        Push(Redo, valOut);

        if (IsEmptyStack(*Undo))
        {
            *S = InitSim;
        }
        else
        {
            *S = InfoTop(*Undo);
        }
    }
}

void redoGame(SIMULATOR *S, Stack *Undo, Stack *Redo)
{
    if (IsEmptyStack(*Redo))
    {
        printf("Redo tidak bisa dilakukan\n");
        printf("Anda sudah berada di keadaan terbaru!\n");
    }
    else
    {
        ElStackURType valOut;
        Pop(Redo, &valOut);
        Push(Undo, valOut);
        *S = valOut;
    }
}

void saveUndoRedoGame(SIMULATOR S, SIMULATOR InitSim, Stack *Undo, Stack *Redo)
{
    // Handle kejadian pertama kali keadaan sim berubah
    if (!(isTimeSame(WAKTU(S), WAKTU(InitSim))))
    {
        if (IsEmptyStack(*Undo))
        {
            Push(Undo, S);
        }
        else
        {
            if (isTimeSame(WAKTU(S), WAKTU(InfoTop(*Undo))))
            {
                // Do Nothing 
            }
            else
            {
                Push(Undo, S);
                resetStack(Redo);
            }
        }
    }
}

// isWordSame(currentWord, "HELP") || isWordSame(currentWord, "UNDO") || isWordSame(currentWord, "REDO") || isWordSame(currentWord, "EXIT") || isWordSame(currentWord, "DELIVERY") || isWordSame(currentWord, "INVENTORY") || isWordSame(currentWord, "CATALOG") || isWordSame(currentWord, "COOKBOOK") || isWordSame(currentWord, "RECOMMENDATION")
// isPointSame(TITIK(S), TITIK(InfoTop(*Undo))) && isPrioqueSame(INVENTORY(S), INVENTORY(InfoTop(*Undo))) && isPrioqueSame(DELIV(S), DELIV(InfoTop(*Undo))) && isTimeSame(WAKTU(S), WAKTU(InfoTop(*Undo)))