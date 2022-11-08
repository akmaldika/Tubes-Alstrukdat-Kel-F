#include <stdio.h>
#include "mesinkata.h"

boolean endWord;
Line currentLine;
Word currentWord;
int currentLength;
static FILE *pita;
static int retval;


void STARTLINE(str fileName) {
    /* I.S. : currentChar sembarang, input nama file valid
       F.S. : currentChar = kata pertama dari baris berikutnya dan currentLine berisikan baris pertama yang telah diakuisisi */
    START(fileName);
    CopyLine();
    currentLength = 0;
    ADV();
}

void ADVLINE() {
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentChar = kata pertama dari baris berikutnya dan currentLine berisikan baris yang telah diakuisi.
       Proses : Akuisisi baris menggunakan procedure CopyLine */
    CopyLine();
    ADV();
    currentLength = 0;
}

void CopyLine() {
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentChar = kata pertama dari baris berikutnya dan currentLine berisikan baris yang telah diakuisi */
    currentLine.Length = 0;
    while (!EOP && !EOL) {
        currentLine.Tabword[currentLine.Length++] = currentChar;
        ADV();
    }
}

void ADVWORD() {
    /* I.S. : CurrentLine terdefinisi
       F.S. : currentWord adalah kata yang telah diakusisi dari currentLength sampai endWord*/
    CopyWord();
    currentLength++;
}

void CopyWord() {
    /* I.S. : CurrentLine terdefinisi
       F.S. : currentWord berisi word mulai dari currentLine.Tabword[currentLength]  sampai endWord */
    currentWord.Length = 0;

    while (currentLine.Tabword[currentLength] != BLANK && currentLength < currentLine.Length) {
        currentWord.String[currentWord.Length] = currentLine.Tabword[currentLength];
        currentWord.Length++;
        currentLength = currentLength + 1;
    }
}

void displayWord () {
    /* Menampilkan currentWord ke layar */
    int i;

    for (i = 0; i < currentWord.Length; i++) {
        printf("%c", currentWord.String[i]);
    }
}

void STARTCOMMAND() {
    /* I.S. : Sembarang
       F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar != '\n' maka EOL akan padam (false).
              Jika currentChar = '\n' maka EOL akan menyala (true)*/
    pita = stdin;
    ADV();
    CopyLine();
    currentLength = 0;
}

void ADVCOMMAND() {
    /* Pita dimajukan satu karakter.
        I.S. : Karakter pada jendela = currentChar
        F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama.
               Jika  currentChar = '\n' maka EOL akan menyala (true) dan pita akan ditutup */
    ADV();
}