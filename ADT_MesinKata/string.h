#ifndef __STRING_H_
#define __STRING_H_

#include <stdio.h>
#include <math.h>
#include "boolean.h"

typedef char str[100];

boolean isStrSame (str str1, str str2) {
    int i = 0;
    boolean same = true;

    while ((str1[i] != '\0' || str2[i] != '\0') && same) {
        if (str1[i] != str2[i]) {
            same = false;
        }
        i++;
    }
    return same;
}

int wordToInt (str word, int length) {
	int i;
	int num = 0;
	int power = length - 1;

	for (i = 0; i < length; i++) {
		num += ((int) word[i] - 48) * pow(10, power);
		power--;
	}

	return num;
}

#endif