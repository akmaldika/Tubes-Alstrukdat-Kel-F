
#include "boolean.h"
#include "Multiset.h"
#include "../ADT_Tree/NTree.h"
#include <stdio.h>

// #define CAPACITY_MULTISET CONFIG_SIZELM

// typedef struct {
//     int Elmt;
//     int Multiplicty;
// } ElMultiSetType;

// typedef struct {
//     ElMultiSetType Buffer[CAPACITY_MULTISET];
//     int NEffMultiSet;
// } MultiSet;

// /* Selektor */
// #define NEFFMS(m) (m).NEffMultiSet
// #define ELMTMS(m, i) (m).buffer[i].Elmt
// #define MULTMS(m, k) (i).buffer[i].Mult

/* Konstruktor */

/* I.S. Sembarang */
/* F.S. MultiSet m terdefinisi dan kosong*/
void CreateMS(MultiSet *m) {
    NEFFMS(*m) = 0;
}

/* Banyak elemen */

/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
int lengthMS(MultiSet m) {
    return NEFFMS(m);
}

/* Selektor Indeks */

/* Prekondisi : m tidak kosong */
/* Mengirimkan indeks elemen m pertama */
int getFirstIdxMS(MultiSet m) {
    return 0;
}

/* Prekondisi : m tidak kosong */
/* Mengirimkan indeks elemen m pertama */
int getLastIdxMS(MultiSet m) {
    return (NEFFMS(m) - 1); 
}

/* Mengembalikan indeks dengan i sehinggak ELMTMS(m, i) == x */
/* Jika tidak ditemukan, kembalikan IDX_UNDEF_MS */
int getElmtIdxMS(MultiSet m, int x) {
    // KAMUS
    boolean isFound;
    int i;
    // ALGORITMA
    if (isEmptyMS(m)) {
        return IDX_UNDEF_MS;
    } else {
        isFound = false;
        i = 0;
        while (isIdxEffMS(m, i) && !isFound) {
            if (ELMTMS(m, i) == x) {
                isFound = true;
            } else {
                i++;
            }
        }
        if (isFound) {
            return i;
        } else {
            return IDX_UNDEF_MS;
        }
    }
}

/* ********** Test Indeks yang valid ********** */

/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas m */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxValidMS(MultiSet m, int i){
    return ((0 <= i) && (i <= CAPACITY_MULTISET));
}

/* Mengirimkan true jika i adalah indeks yang terdefinisi utk m */
/* yaitu antara 0..lengthMS(m)-1 */
boolean isIdxEffMS(MultiSet m, int i) {
    return ((getFirstIdxMS(m) <= i) && (i <= getLastIdxMS(m)));
}

/* *** Test MultiSet kosong *** */

/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
boolean isEmptyMS(MultiSet m) {
    return NEFFMS(m) == 0;
}


/* *** Test MultiSet penuh *** */

/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
boolean isFullMS(MultiSet m) {
    return NEFFMS(m) == CAPACITY_MULTISET;
}

/* Output */

/* I.S. m terdefinisi */
/* F.S. Nilai dan multipl;icity dari elemen-elemen dari m tercetak di layar */
void printMS(MultiSet m) {
    // KAMUS
    int i;
    // ALGORITMA
    if (isEmptyMS(m)) {
        printf("[]\n");
    } else {
        printf("[(%d, %d)", ELMTMS(m, 0), MULTMS(m, 0));
        for (i = 1; isIdxEffMS(m, i); i++) {
            printf(", (%d, %d)", ELMTMS(m, i), MULTMS(m, i));
        } 
        printf("]\n");
    }
}

/* Searching */

/* Mengecek apakah terdapat elemen dengan nilai x sebanyak k di m */
boolean isInMS(MultiSet m, int x, int k) {
    // KAMUS
    boolean isFound;
    int i;
    // ALGORITMA
    if (isEmptyMS(m)) {
        return false;
    } else {
        isFound = false;
        i = 0;
        while (isIdxEffMS(m, i) && !isFound) {
            if ((ELMTMS(m, i) == x) && (MULTMS(m, i) >= k)) {
                isFound = true;
            } else {
                i++;
            }
        } return isFound;
    }
}

/* Mengecek apakah m2 merupakan subset dari m1 */
boolean subsetMS(MultiSet m1, MultiSet m2) {
    // KAMUS
    boolean isSubset;
    int i;
    int j;
    // ALGORITMA
    if (isEmptyMS(m2)) {
        return true;
    } else {
        i = 0;
        isSubset = true;
        while (isIdxEffMS(m1, i) && isSubset) {
            if (!isInMS(m1, ELMTMS(m2, i), MULTMS(m2, i))) {
                isSubset = false;
            } else {
                i++;
            }
        } return isSubset;
    }

}

/* Menambah dan Mengurangi Elemen */

/* Menambah kan elemen dengan nilai x dan multipilicty k ke m*/
void addMS(MultiSet *m, int x, int k) {
    // KAMUS
    int i;
    // ALGORITMA
    i = getElmtIdxMS(*m, x);
    if (i == IDX_UNDEF_MS) {
        i = getLastIdxMS(*m) + 1;
        ELMTMS(*m, i) = x;
        MULTMS(*m, i) = k;
        NEFFMS(*m) = NEFFMS(*m) + 1; 
    } else {
        MULTMS(*m, i) = MULTMS(*m, i) + k;
    }
}

/* Prekondisi: isInMS(m, x, k) == true */
/* Menghilangkan elemen dengan nilai x sebanyak k */
void removeMS(MultiSet *m, int x, int k) {
    // KAMUS
    int i;
    // ALGORITMA
    i = getElmtIdxMS(*m, x);
    MULTMS(*m, i) = MULTMS(*m, i) - k;
    if (MULTMS(*m, i) == 0) {
        deleteAtMS(m, i);
    } 

}

/* I.S. m terdefinisi, m tidak kosong, i merupakan index valid dari m*/
/* F.S. Semua elemen dari m mulai dari index i tergeser ke kiri sekali */
void deleteAtMS(MultiSet *m, int i) {
    // KAMUS
    // ALGORITMA
    while (i < NEFFMS(*m) - 1) {
        ELMTMS(*m, i) = ELMTMS(*m, i+1);
        MULTMS(*m, i) = MULTMS(*m, i+1);
        i++;
    }
    NEFFMS(*m) = NEFFMS(*m) - 1;
}



