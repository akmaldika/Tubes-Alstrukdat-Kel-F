#include <stdio.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "mesinkarakter.c"
#include "mesinkata.c"
#include "string.c"


int main () {
    str t;
    int cnt = 0;
    scanf("%s", &t);

    if (isWordSame(t,"MAKANAN")) {
        STARTLINE("ConfigMakanan.txt");
        CopyWord();
        int N = ((wordToInt(currentWord)) * 5);
        printf("%s\n", currentWord.String);
        while (cnt < N) {
            ADVLINE();
            while (currentLength < currentLine.Length) {
                ADVWORD();
                displayString();
                printf(" ");
            }
            printf("\n");
            cnt++;
        }
    }
    else if (isWordSame(t,"RESEP")) {
        STARTLINE("ConfigResep.txt");
        CopyWord();
        int N = (wordToInt(currentWord));
        printf("%s\n", currentWord.String);
        while (cnt < N) {
            ADVLINE();
            while (currentLength < currentLine.Length) {
                ADVWORD();
                displayString();
                printf(" ");
            }
            printf("\n");
            cnt++;
        }      
    }
    else if (isWordSame(t,"PETA")) {
        STARTLINE("ConfigPeta.txt");
        CopyWord();
        int N = (wordToInt(currentWord));
        printf("%s\n", currentLine.Tabword);
        while (cnt < N) {
            ADVLINE();
            while (currentLength < currentLine.Length) {
                ADVWORD();
                displayString();
                printf(" ");
            }
            printf("\n");
            cnt++;
        }        
    }
    else {
        printf("False\n");
    }
    return 0;
}