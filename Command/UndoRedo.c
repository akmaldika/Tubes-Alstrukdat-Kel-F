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

void undoGame(SIMULATOR *S, SIMULATOR InitSim, Notifikasi *Notif, Stack *Undo, Stack *Redo);
/* I.S. : S, Undo, Notif, dan redo terdefinisi, InitSim adalah keadaan simulator paling awal dalam game */
/* Notif datang ke Undo dalam keadaan kosong */
/* F.S. : jika stack Undo kosong, tampilkan pesan */
/* Stack undo menjadi kosong artinya S = InitSim  dan Notif kosong */
/* Jika tidak, Notifikasi pada InfoTopN(Undo) akan dikirimkan ke Notif */
/* Stack Undo akan dipop dan dimasukkan ke dalam Stack Redo */
/* InfoTopSim(Undo) yang baru akan menjadi S, dan visualnya */
/* misal A, B, C adalah keadaan untuk SIMULATOR S dan Notifikasi N 
    C     SD=C                               SD=B
    B                   -undoGame->     B               -> Notif = InfoTopN(Undo) di C
    A                                   A           C
    Undo        Redo                    Undo        Redo
    -------Jika Stack Undo menjadi kosong
          SN=A                             SN=InitSim A
                B       -undoGame->                   B -> Notif = InfoTopN(Undo) di A
    A           C                                     C
    Undo        Redo                    Undo        Redo
 */

void redoGame(SIMULATOR *S, Notifikasi *Notif, Stack *Undo, Stack *Redo);
/* I.S. : S, Undo, dan Redo terdefinisi */
/* Notif datang ke redoGame dalam keadaan kosong */
/* F.S. : Jika Stack Redo kosong, tampilkan pesan */
/* Stack redo kosong artinya S dan Notif sedang pada keadaan paling baru*/
/* Jika tidak kosong Stack Redo akan dipop dan di masukkan ke dalam Stack Redo*/
/* InfoTopSim(Undo) yang baru akan menjadi S, visualnya: */
/* misal A, B, C adalah type SIMULATOR dan S adalah kondisi S
          SN=B                          C    SN=C
    B                   -redoGame->     B               -> Notif = InfoTopN(Undo) di C 
    A           C                       A           
    Undo        Redo                    Undo        Redo
    -------Jika Stack kosong
    C      SN=C                         C      SN=C 
    B                    -redoGame->    B               -> Notif = kosong
    A                    {pesan}        A           
    Undo        Redo                    Undo        Redo
 */

void saveUndoRedoGame(SIMULATOR S, SIMULATOR InitSim, Notifikasi Notif, Stack *Undo, Stack *Redo);
/* I.S. : S, Undo, dan Redo terdefinisi, InitSim adalah keadaan simulator paling awal, 
    currentWord terdefinisi dan valid sebagai command */
/* Notif terdefinisi baik kosong mapun berisi */
/* F.S. : jika keadaan S berubah, S dimasukkan ke dalam Stack Undo */
/* S disamakan dengan Top(Undo) -> F.S. */
/* Stack Redo akan kosong menyesuaikan kondisi logic undo-redo, 
    yaitu ketika user menginput command baru dan S berubah setelah melakukan beberapa Undo  */

#endif

void undoGame(SIMULATOR *S, SIMULATOR InitSim, Notifikasi *Notif, Stack *Undo, Stack *Redo)
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

        *Notif = Nof(valOut);

        if (IsEmptyStack(*Undo))
        {
            *S = InitSim;
        }
        else
        {
            *S = InfoTopSim(*Undo);
        }
    }
}

void redoGame(SIMULATOR *S, Notifikasi *Notif, Stack *Undo, Stack *Redo)
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
        *S = Sim(valOut);
        *Notif = Nof(valOut);
    }
}

void saveUndoRedoGame(SIMULATOR S, SIMULATOR InitSim, Notifikasi Notif, Stack *Undo, Stack *Redo)
{
    ElStackURType valIn;
    if (!(isTimeSame(WAKTU(S), WAKTU(InitSim))))
    {
        // Handle kejadian pertama kali keadaan sim berubah
        if (IsEmptyStack(*Undo))
        {
            Sim(valIn) = S;
            Nof(valIn) = Notif;
            Push(Undo, valIn);
        }
        else
        {
            if (isTimeSame(WAKTU(S), WAKTU(InfoTopSim(*Undo))))
            {
                // Do Nothing 
            }
            else
            {
                Sim(valIn) = S;
                Nof(valIn) = Notif;
                Push(Undo, valIn);
                resetStack(Redo);
            }
        }
    }
}

// isWordSame(currentWord, "HELP") || isWordSame(currentWord, "UNDO") || isWordSame(currentWord, "REDO") || isWordSame(currentWord, "EXIT") || isWordSame(currentWord, "DELIVERY") || isWordSame(currentWord, "INVENTORY") || isWordSame(currentWord, "CATALOG") || isWordSame(currentWord, "COOKBOOK") || isWordSame(currentWord, "RECOMMENDATION")
// isPointSame(TITIK(S), TITIK(InfoTop(*Undo))) && isPrioqueSame(INVENTORY(S), INVENTORY(InfoTop(*Undo))) && isPrioqueSame(DELIV(S), DELIV(InfoTop(*Undo))) && isTimeSame(WAKTU(S), WAKTU(InfoTop(*Undo)))