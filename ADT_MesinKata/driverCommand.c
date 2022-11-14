#include <stdio.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "mesinkarakter.c"
#include "mesinkata.c"
#include "string.c"

int main () {
    /* Beda isWordSame buat 1 kata, sedangkan isLineSame buat 1 baris (ada spasinya) */
    STARTCOMMAND();
    STARTWORD();
    printf("Command = %s\n", currentWord.String);
    if (isWordSame(currentWord, "WAIT")) {
        printf("benul\n");
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