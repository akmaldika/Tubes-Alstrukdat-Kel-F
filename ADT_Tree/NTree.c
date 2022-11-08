

/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotype, type addrNode, dan beberapa fungsi disesuikan 
   karena melibatkan modul list rekursif. */


/* Modul lain yang digunakan : */
#include <stdio.h>
#include <stdlib.h>
#include "..\ADT_Tree\boolean.h"
#include "..\ADT_Tree\NTree.h"

/* *** Definisi Type N-Tree dengan left child right sibling interpretation *** */
// typedef int ElNTreeType;
// typedef struct node* Address;
// typedef struct node {
//     ElNTreeType info;
//     Address child;
//     Address sibling; 
//     int countChild; } Node;

/* Definisi N-ary Tree*/
/* N-ary Tree kosong ketika T = NULL*/
// typedef Address NTree;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define INFONTREE(P) (P)->info
#define CHILD(P) (P)->child
#define SIBLING(P) (P)->sibling
#define COUNTCHILD(P) (P)->countChild

/* *** Konstruktor *** */

void CreateNTree(NTree *t) {
    *t = NULL;
}

/* Manajemen Memory */

/* Mengembalikan Address hasil ealokasi ElNTreeType */
/* Jika alokasi berhasil maka Address tidak NULL misal p, maka
   INFONTREE(P) = val, CHILD(P) = NULL, SIBLING(P) = NULL*/
/* Jika alokasi gagal, mengirimkan NULL */
Address newNode (ElNTreeType val) {
    Address  p = (Address)malloc(sizeof(Node));
    if (p !=NULL) {
        INFONTREE(p) = val;
        CHILD(p) = NULL;
        SIBLING(p) = NULL;
        COUNTCHILD(p) = 0;
    } return p;
}

/* I.S. p terdefinisi */
/* F.S. p dikembalikan ke sistem */
/* Melakukan dealokasi Address p */
void deallocateNode(Address p) {
    free(p);
}

/* *** Predikat-Predikat Penting *** */

/* Mengembalikan true jika NTree t kosong*/
boolean isNTreeEmpty(NTree t) {
    return (t == NULL);
}

/* Membalikan true jika NTree t punya sibling*/
boolean isHaveSibling(NTree t) {
    return !(SIBLING(t) == NULL);
}

/* Mengembalikan true jika NTree t punya child*/
boolean isHaveChild(NTree t) {
    return !(CHILD(t) == NULL);
}

/* *** Traversal *** */

/* Mengembalikan true jika terdapat address p di node NTree t sehingga INFONTREE(p) == val */
boolean isContainAddress(NTree t, int val) {
    // KAMUS
    boolean isFound;
    // ALGORITMA
    if (isNTreeEmpty(t)) {
        return false;
    } else if (INFONTREE(t) == val) {
        return true;
    } else {
        isFound = false;
        if (isHaveChild(t) && !isFound) {
            isFound = isContainAddress(CHILD(t), val);
        } if (isHaveSibling(t) && !isFound) {
            isFound = isContainAddress(SIBLING(t), val);
        } return isFound;
    }
} 

/* Mengembalikan address p sehingga INFONTREE(p) adalah anak ke-n dari parent t */
Address traverseChild(NTree t, int n) {
    // KAMUS
    Address p;
    int i;
    // ALGORITMA
    p = t;
    p = CHILD(p);
    for (i = 2; i <= n; i++) {
        p = (SIBLING(p));
    }
    return p;
}

void printNTree(NTree t, int offset) {
    if (isNTreeEmpty(t)) {
        printf("Tree Kosong");
        printf("\n");
    } else {
        printNSpace(offset);
        printf("%d\n", INFONTREE(t));

        if (isHaveChild(t)) {
            printNTree(CHILD(t), offset + 1);
        } if (isHaveSibling(t)) {
            printNTree(SIBLING(t), offset);
        }
    }

}

/* Mengirimkan true jika ada node dari t sehingga INFONTREE(t) == val */
boolean searchNTree(NTree t, ElNTreeType val)
{
    //KAMUS
    Address p;
    boolean isFound;
    int i;
    // ALGORITMA
    p = t;
    isFound = (INFONTREE(p) == val);

    if (!isFound && isHaveChild(p)) {
        isFound = searchNTree(CHILD(p), val);
    }
    if (!isFound && isHaveSibling(p)) {
        isFound = searchNTree(SIBLING(p), val);
    }

    return isFound;
}


/* *** Fungsi-Fungsi Lain *** */

/* Menambahkan NTree dengan alamat chd kepada suatu parent*/
void addChildAddress(NTree *prt, NTree chd) {
    // KAMUS
    Address p;
    // ALGORITMA
    if (isNTreeEmpty(*prt)) {
        printf("Parent tree kosong\n");
    } else {
        if (!isHaveChild(*prt)) {
            CHILD(*prt) = chd;
        } else {
            p = traverseChild(*prt, COUNTCHILD(*prt));
            SIBLING(p) = chd;
        } COUNTCHILD(*prt)++;
    }
}

/* Menambahkan prt dengan child, misal t, sehingga INFO(t) = val*/
void addChildInfo(NTree *prt, int val) {
    // KAMUS
    Address p;
    // ALGORITMA
    if (isNTreeEmpty(*prt)) {
        printf("Parent tree kosong\n");
    } else {
        if (!isHaveChild(*prt)) {
            CHILD(*prt) = newNode(val);
        } else {
            p = traverseChild(*prt, COUNTCHILD(*prt));
            SIBLING(p) = newNode(val);
        } COUNTCHILD(*prt)++;
    }
}

Address copyNTree(NTree prt) {
    // KAMUS
    Address newPrt;
    // ALGORITMA
    if (isNTreeEmpty(prt)) {
        printf("Parent tree kosong\n");
        return NULL;
    } else {
        CreateNTree(&newPrt);
        newPrt = newNode(INFONTREE(prt));
        if (isHaveChild(prt)) {
            CHILD(newPrt) = CHILD(prt);
        } 
        return newPrt;
    } 
}
/* I.S. prt terdefinisi, chd terdefinisi */
/* F.S. setiap bagian cabang dari prt yang memiliki info sama dengan INFO(chd)
        akan diganti dengan address copian NTree chd*/
void addChildBySpecificInfo(NTree *prt, NTree chd) {
    // KAMUS
    Address p, temp;
    int info;
    // ALGORITMA
    if (isNTreeEmpty(*prt)) {
        printf("Parent tree kosong\n");
    } else {
        info = INFONTREE(chd);
        if (INFONTREE(*prt) == info) {
            temp = SIBLING(*prt);
            *prt = copyNTree(chd);
            SIBLING(*prt) = temp;
        }
        /* Bagian rekursi */
        if (isHaveChild(*prt)) {
            addChildBySpecificInfo(&CHILD(*prt), chd);
        } if (isHaveSibling(*prt)) {
            addChildBySpecificInfo(&SIBLING(*prt), chd);
        }
    }
}

void printNSpace(int N) {
    // KAMUS
    int i;
    // ALGORITMA
    for (i = 0; i < N; i++) {
        printf("   ");
    }
}


