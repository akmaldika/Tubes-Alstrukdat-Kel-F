#include "string.h"

boolean isWordSame (str str1, str str2) {
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

int wordToInt (Word cc) {
	int i;
	int num = 0;
	int power = cc.Length - 1;

	for (i = 0; i < cc.Length; i++) {
		num += ((int) cc.String[i] - 48) * pow(10, power);
		power--;
	}

	return num;
}