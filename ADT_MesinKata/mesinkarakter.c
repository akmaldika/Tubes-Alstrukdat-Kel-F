/* File: mesinkarakter.c */
/* Implementasi ADT Mesin Karakter */

#include "mesinkarakter.h"
#include <stdio.h>

char currentChar;
boolean EOL;
boolean EOP;

static FILE *pita;
static int retval;


void START(char fileName[]) {
       /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
          Karakter pertama yang ada pada pita posisinya adalah pada jendela.
          I.S. : sembarang
          F.S. : currentChar adalah karakter pertama pada pita. */

       /* Algoritma */
       pita = fopen(fileName, "r");
       ADV();
}

void ADV() {
       /* Pita dimajukan satu karakter.
          I.S. : Karakter pada jendela = currentChar
          F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama.
                 Jika  currentChar = '\n' maka EOL true. Jika retval != 1, maka EOP menyala (true) */

       /* Algoritma */
       retval = fscanf(pita, "%c", &currentChar);
       EOL = (currentChar == NEWLINE);
       EOP = (retval != 1);
       if (EOP) {
              fclose(pita);
       }
}
