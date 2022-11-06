#ifndef __STRING_H_
#define __STRING_H_

#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "mesinkata.h"


boolean isWordSame (str str1, str str2);
/* Mengembalikan true jika kedua kata sama dan false bila tidak */

int wordToInt (Word cc);
/* Mengembalikan integer dari suatu word */

#endif