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
    printf("Command = %s\n", currentLine.Tabword);
    if (isWordSame(currentLine.Tabword, "MOVE NORTH")) {
        printf("benul\n");
    }
    else {
        printf("salah\n");
    }
}