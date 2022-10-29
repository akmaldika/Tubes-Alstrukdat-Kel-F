/* File: mesinkata.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkarakter.h"
#include "string.h"

#define NMax 100
#define BLANK ' '

typedef struct
{
   str Tabword;
   int Length;
} Line;

typedef struct mesinkata
{
   str String;
   int Length; 
} Word;


/* State Mesin Word */
extern boolean endWord;
extern Word currentWord;
extern Line currentLine;


void STARTLINE();
    /* I.S. : currentChar sembarang, input nama file valid
       F.S. : currentChar == '\n' dan currentLine berisikan baris pertama yang telah diakuisisi */

void ADVLINE();
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentChar == '\n' dan currentLine berisikan baris yang telah diakuisi.
       Proses : Akuisisi baris menggunakan procedure CopyLine */

void CopyLine();
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentChar == '\n' dan currentLine berisikan baris yang telah diakuisi */

void CopyWord(int *currentLength);
    /* I.S. : CurrentLine terdefinisi
       F.S. : currentWord berisi word mulai dari currentLine.Tabword[currentLength] sampai endWord */

#endif
