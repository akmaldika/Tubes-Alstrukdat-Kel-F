#include <stdio.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "string.h"


int main() {
    printf("Masukkan Command = ");
    STARTCOMMAND();
    STARTWORD();

    if (isWordSame(currentWord,"MAKANAN")) {
        STARTLINE("ConfigMakanan.txt");
        printf("%s\n", currentLine.Tabword);
        while (!EOP) {
            ADVLINE();
            printf("%s\n", currentLine.Tabword);
        }
    }
    else if (isWordSame(currentWord,"RESEP")) {
        STARTLINE("ConfigResep.txt");
        printf("%s\n", currentLine.Tabword);       
        while (!EOP) {
            ADVLINE();
            printf("%s\n", currentLine.Tabword);
        }      
    }
    else if (isWordSame(currentWord,"PETA")) {
        STARTLINE("ConfigPeta.txt");
        STARTWORD();
        printf("%s ", currentWord.String);
        ADVWORD();
        printf("%s\n", currentWord.String);       
        while (!EOP) {
            ADVLINE();
            printf("%s\n", currentLine.Tabword);
        }        
    }
    else {
        printf("False\n");
    }
    return 0;
}