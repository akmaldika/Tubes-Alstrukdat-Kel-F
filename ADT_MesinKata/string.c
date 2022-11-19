/* File: string.h */
/* Implementasi ADT String */


#include "string.h"

boolean isWordSame (Word str1, char str2[]) {
    /* Mengembalikan true jika kedua kata sama dan false bila tidak */

    /* KAMUS */
    int i = 0;
    boolean same = (str1.Length != 0);

    /* ALGORITMA */
    while ((str1.String[i] != ENDSTRING || str2[i] != ENDSTRING) && same) {
        if (str1.String[i] != str2[i]) {
            same = false;
        }
        else {
            i++;
        }
    }
    return same && str2[i] == ENDSTRING;

}

boolean isLineSame (Line l, char str2[]) {
    /* Mengembalikan true jika kedua kalimat sama dan false jika tidak (kalimat di sini berarti satu baris dengan spasi) */

    /* KAMUS */
    int i = 0;
    boolean same = (l.Length != 0);

    /* ALGORITMA */
    while ((l.Tabword[i] != ENDSTRING || str2[i] != ENDSTRING) && same) {
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
    /* Mengembalikan integer dari suatu word */

    /* KAMUS */
	int i;
	int num = 0;
	int power = cc.Length - 1;

    /* ALGORTIMA */
	for (i = 0; i < cc.Length; i++) {
		num += ((int) cc.String[i] - 48) * pow(10, power);
		power--;
	}
	return num;
}

boolean isWordInt (Word cc) {
    /* Mengembalikan true jika word merupakan integer dan false jika tidak */

    /* ALGORITMA */
    int i = 0;
    boolean isInt = true;
    while (cc.String[i] != '\0')
    {
        if (cc.String[i] < '0' || cc.String[i] > '9')
        {
            isInt = false;
        }
        i++;
    }
    return isInt;
}