#include <stdio.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "string.h"


int main() {
    /* Beda isWordSame buat 1 kata, sedangkan isLineSame buat 1 baris (ada spasinya) */
    STARTCOMMAND();
    STARTWORD();
    printf("Command = %s\n", currentWord.String);
    if (isWordSame(currentWord, "WAIT")) {
        printf("benul\n");
        ADVWORD();
        if (isWordInt(currentWord)) {
            printf("%s\n", currentWord.String);
        }
    }
    else {
        printf("salah\n");
    }

    STARTCOMMAND();
    printf("Command = %s\n", currentLine.Tabword);
    if (isLineSame(currentLine,"MOVE NORTH")) {
        printf("Mendaki guuunung, melewati sungai.\n");
    }
    else {
        printf("meng-turu\n");
    }
}