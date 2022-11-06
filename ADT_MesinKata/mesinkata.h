/* File: mesinkata.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkarakter.h"

#define BLANK ' '

typedef struct line
{
   str Tabword;
   int Length;
} Line;

typedef struct word
{
   str String; 
   int Length; 
} Word;


/* State Mesin Word */
extern boolean endWord;
extern Word currentWord;
extern Line currentLine;
extern int currentLength;


void STARTLINE(str fileName);
    /* I.S. : currentChar sembarang, input nama file valid
       F.S. : currentChar = kata pertama dari baris berikutnya dan currentLine berisikan baris pertama yang telah diakuisisi */

void ADVLINE();
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentChar = kata pertama dari baris berikutnya dan currentLine berisikan baris yang telah diakuisi.
       Proses : Akuisisi baris menggunakan procedure CopyLine */

void CopyLine();
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentChar = kata pertama dari baris berikutnya dan currentLine berisikan baris yang telah diakuisi */

void ADVWORD();
    /* I.S. : CurrentLine terdefinisi
       F.S. : currentWord adalah kata yang telah diakusisi dari currentLength sampai endWord*/

void CopyWord();
    /* I.S. : CurrentLine terdefinisi
       F.S. : currentWord berisi word mulai dari currentLine.Tabword[currentLength] sampai endWord */

void displayString();
    /* Menampilkan currentWord ke layar */

#endif
