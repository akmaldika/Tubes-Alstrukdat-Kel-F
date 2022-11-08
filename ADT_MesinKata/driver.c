#include <stdio.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "mesinkarakter.c"
#include "mesinkata.c"
#include "string.c"


int main () {
    STARTCOMMAND();
    while (!EOL) {
        ADVCOMMAND();
    }
    CopyWord();

    if (isWordSame(currentWord,"MAKANAN")) {
        STARTLINE("ConfigMakanan.txt");
        ADVWORD();
        displayWord();
        printf("\n");
        while (!EOP) {
            ADVLINE();
            while (currentLength < currentLine.Length) {
                ADVWORD();
                displayWord();
                printf(" ");
            }
            printf("\n");
        }
    }
    else if (isWordSame(currentWord,"RESEP")) {
        STARTLINE("ConfigResep.txt");
        ADVWORD();
        displayWord();
        printf("\n");        
        while (!EOP) {
            ADVLINE();
            while (currentLength < currentLine.Length) {
                ADVWORD();
                displayWord();
                printf(" ");
            }
            printf("\n");
        }      
    }
    else if (isWordSame(currentWord,"PETA")) {
        STARTLINE("ConfigPeta.txt");
        ADVWORD();
        displayWord();
        printf(" ");
        ADVWORD();
        displayWord();
        printf("\n");        
        while (!EOP) {
            ADVLINE();
            while (currentLength < currentLine.Length) {
                ADVWORD();
                displayWord();
                printf(" ");
            }
            printf("\n");
        }        
    }
    else {
        printf("False\n");
    }
    return 0;
}