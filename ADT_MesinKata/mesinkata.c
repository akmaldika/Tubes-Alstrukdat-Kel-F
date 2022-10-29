#include <stdio.h>
#include "mesinkata.h"

boolean endWord;
Line currentLine;
Word currentWord;


void STARTLINE(str fileName) {
    /* I.S. : currentChar sembarang, input nama file valid
       F.S. : currentChar == '\n' dan currentLine berisikan baris pertama yang telah diakuisisi */
    START(fileName);
    CopyLine();
}

void ADVLINE() {
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentChar == '\n' dan currentLine berisikan baris yang telah diakuisi.
       Proses : Akuisisi baris menggunakan procedure CopyLine */
    CopyLine();
}

void CopyLine() {
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentChar == '\n' dan currentLine berisikan baris yang telah diakuisi */
    currentLine.Length = 0;
    while (!EOL) {
        if (currentLine.Length < NMax) { 
            // jika lebih akan terpotong
            currentLine.Tabword[currentLine.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

void CopyWord(int *currentLength) {
    /* I.S. : CurrentLine terdefinisi
       F.S. : currentWord berisi word mulai dari currentLine.Tabword[currentLength]  sampai endWord */
    currentWord.Length = 0;

    while (currentLine.Tabword[*currentLength] != BLANK && *currentLength < currentLine.Length) {
        currentWord.String[currentWord.Length] = currentLine.Tabword[*currentLength];
        currentWord.Length++;
        *currentLength = *currentLength + 1;
    }
}

void displayString () {
    /* Menampilkan currentWord ke layar */
    int i;

    for (i = 0; i < currentWord.Length; i++) {
        printf("%c", currentWord.String[i]);
    }
}