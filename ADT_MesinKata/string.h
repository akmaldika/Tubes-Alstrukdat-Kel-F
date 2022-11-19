/* File: string.h */
/* Definisi String */


#ifndef __STRING_H_
#define __STRING_H_

#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "mesinkata.h"


boolean isWordSame (Word str1, char str2[]);
/* Mengembalikan true jika kedua kata sama dan false bila tidak */

boolean isLineSame (Line l, char str2[]);
/* Mengembalikan true jika kedua kalimat sama dan false jika tidak (kalimat di sini berarti satu baris dengan spasi) */

int wordToInt (Word cc);
/* Mengembalikan integer dari suatu word */

boolean isWordInt (Word cc);
/* Mengembalikan true jika word merupakan integer dan false jika tidak */

#endif