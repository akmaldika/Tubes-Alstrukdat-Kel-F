/* File: mesinkata.c */
/* Implementasi ADT Mesin Kata */

#include <stdio.h>
#include "mesinkata.h"

boolean endWord;
Line currentLine;
Word currentWord;
int currentLength;
static FILE *pita;
static int retval;


void STARTLINE(char fileName[]) {
    /* I.S. : currentChar sembarang, input nama file valid
       F.S. : currentChar = kata pertama dari baris berikutnya dan currentLine berisikan baris pertama yang telah diakuisisi */

    /* ALGORITMA */
    START(fileName);
    CopyLine();
    ADV();
}

void ADVLINE() {
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentChar = kata pertama dari baris berikutnya dan currentLine berisikan baris yang telah diakuisi.
       Proses : Akuisisi baris menggunakan procedure CopyLine */

    /* ALGORITMA */
    CopyLine();
    ADV();
}

void CopyLine() {
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentChar = kata pertama dari baris berikutnya dan currentLine berisikan baris yang telah diakuisi */

    /* ALGORITMA */
    currentLine.Length = 0;
    while (!EOP && !EOL) {
        currentLine.Tabword[currentLine.Length++] = currentChar;
        ADV();
    }
    currentLine.Tabword[currentLine.Length] = ENDSTRING;
}

void STARTWORD() {
    /* I.S. : CurrentLine terdefinisi
       F.S. : currentWord adalah kata pertama yang telah diakusisi */

    /* ALGORITMA */
    currentLength = 0;
    CopyWord();
    currentLength++;
}

void ADVWORD() {
    /* I.S. : CurrentLine terdefinisi
       F.S. : currentWord adalah kata yang telah diakusisi dari currentLength sampai akhir kata (sebelum spasi atau akhir baris) */

    /* ALGORITMA */
    CopyWord();
    currentLength++;
}

void CopyWord() {
    /* I.S. : CurrentLine terdefinisi
       F.S. : currentWord berisi word mulai dari currentLength sampai akhir kata */

    /* ALGORITMA */
    currentWord.Length = 0;

    while (currentLine.Tabword[currentLength] != BLANK && currentLength < currentLine.Length) {
        currentWord.String[currentWord.Length] = currentLine.Tabword[currentLength];
        currentWord.Length++;
        currentLength++;
    }
    currentWord.String[currentWord.Length] = ENDSTRING;
    endWord = (currentLength == currentLine.Length);
}

void STARTCOMMAND() {
    /* I.S. : Sembarang
       F.S. : currentLine berisi masukan command dari user sampai sebelum new line (currentChar = '\n') */

    /* ALGORITMA */
    pita = stdin;
    ADVCOMMAND();
    CopyCommand();
}

void ADVCOMMAND() {
    /* I.S. : Sembarang
       F.S  : karakter pada input command telah dimajukan satu karakter */

    /* ALGORITMA */
    fscanf(pita, "%c", &currentChar);
    EOL = (currentChar == NEWLINE);
}

void CopyCommand() {
    /* I.S. : Sembarang
       F.S. : Satu line/baris input command telah diakuisisi dan disimpan pada currentLine, currentChar == '\n' */

    /* ALGORITMA */
    currentLine.Length = 0;
    while (!EOL) {
        currentLine.Tabword[currentLine.Length++] = currentChar;
        ADVCOMMAND();
    }
    currentLine.Tabword[currentLine.Length] = ENDSTRING;    
}