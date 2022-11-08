#ifndef __STRING_H_
#define __STRING_H_

#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "mesinkata.h"


boolean isWordSame (Word str1, str str2);
/* Mengembalikan true jika kedua kata sama dan false bila tidak */

boolean isLineSame (Line l, str str2);
/* Mengembalikan true jika kedua kalimat sama dan false jika tidak (kalimat di sini berarti satu baris dengan spasi) */

int wordToInt (Word cc);
/* Mengembalikan integer dari suatu word */

#endif