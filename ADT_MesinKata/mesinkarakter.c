/* File: mesinkarakter.c */
/* Implementasi Mesin Karakter */

#include "mesinkarakter.h"
#include <stdio.h>

char currentChar;
boolean EOL;

static FILE *pita;
static int retval;

void START(str fileName)
{
       /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
          Karakter pertama yang ada pada pita posisinya adalah pada jendela.
          I.S. : sembarang
          F.S. : currentChar adalah karakter pertama pada pita. */

       /* Algoritma */
       pita = fopen(fileName, "r");
       ADV();
}

void ADV()
{
       /* Pita dimajukan satu karakter.
          I.S. : Karakter pada jendela = currentChar
          F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama.
                 Jika  currentChar = '\n' maka EOL akan menyala (true) */

       /* Algoritma */
       retval = fscanf(pita, "%c", &currentChar);
       EOL = (currentChar == '\n');
}
