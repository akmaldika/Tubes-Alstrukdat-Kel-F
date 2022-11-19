/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "boolean.h"

#define NEWLINE '\n'
#define BLANK ' '
#define ENDSTRING '\0'
#define Nmax 100

typedef char str[Nmax];

/* State Mesin */
extern char currentChar;
extern boolean EOL;
extern boolean EOP;

void START(char fileName[]);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          Jika  currentChar = '\n' maka EOL true. Jika retval != 1, maka EOP menyala (true) */

#endif
