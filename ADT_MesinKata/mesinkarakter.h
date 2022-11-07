/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "boolean.h"

typedef char str[100];

/* State Mesin */
extern char currentChar;
extern boolean EOL;
extern boolean EOP;

void START(str fileName);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          jika currentChar == '\n', EOL menyala */

#endif
