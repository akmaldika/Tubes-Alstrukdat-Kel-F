#include "string.h"

boolean isWordSame (Word str1, char str2[]) {
    int i = 0;
    boolean same = true;

    while (i < str1.Length && same) {
        if (str1.String[i] != str2[i]) {
            same = false;
        }
        else {
            i++;
        }
    }
    return same;
}

boolean isLineSame (Line l, char str2[]) {
    int i = 0;
    boolean same = true;

    while (i < l.Length && same) {
        if (l.Tabword[i] != str2[i]) {
            same = false;
        }
        else {
            i++;
        }
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