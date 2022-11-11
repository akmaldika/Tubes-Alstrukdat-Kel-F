

/* ADT N-Ary Tree */
/* Implementasi dengan menggunakan pointer */

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
/* NTree T kosong ketika T = NULL*/
// typedef Address NTree;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define INFONTREE(P) (P)->info
#define CHILD(P) (P)->child
#define SIBLING(P) (P)->sibling
#define COUNTCHILD(P) (P)->countChild

/* *** Konstruktor *** */

/* I.S. Sembarang */
/* F.S. Ntree t kosong terdefinisi*/
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

/* I.S. t terdefinisi */
/* F.S. t dan semua sub elemen nya dikembalikan ke sistem */
/* Melakukan dealokasi NTree t*/
// TODO
void deallocateNTree(NTree t) {
    // KAMUS
    Address p;
    // ALGORITMA
    if (!isNTreeEmpty(t)) {
        p = t;
        if (isHaveChild(t)) {
            deallocateNTree(CHILD(t));
        } if (isHaveSibling(t)) {
            deallocateNTree(SIBLING(t));
        } free(p);
        // deallocateNode(p);
    }
}

/* *** Predikat-Predikat Penting *** */

/* Mengembalikan true jika NTree t kosong */
boolean isNTreeEmpty(NTree t) {
    return (t == NULL);
}

/* Membalikan true jika NTree t punya sibling*/
/* Pointer harus menunjuk pada sebuah node */
boolean isHaveSibling(NTree t) {
    return !(SIBLING(t) == NULL);
}

/* Mengembalikan true jika NTree t punya child*/
/* Pointer harus menunjuk pada sebuah node */
boolean isHaveChild(NTree t) {
    return !(CHILD(t) == NULL);
}

/* *** Traversal *** */

/* Mengembalikan true jika terdapat address p di node NTree t sehingga INFONTREE(p) == val */
boolean isContainInfo(NTree t, int val) {
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
            isFound = isContainInfo(CHILD(t), val);
        } if (isHaveSibling(t) && !isFound) {
            isFound = isContainInfo(SIBLING(t), val);
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
        printf("Tree Kosong\n");
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

/* *** Fungsi-Fungsi Lain *** */

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

void copyNTreePrt(NTree prt, NTree *newPrt) {
    // KAMUS
    NTree newChd;
    // ALGORITMA
    if (isNTreeEmpty(prt)) {
        *newPrt = NULL;
    } else {
        *newPrt = newNode(INFONTREE(prt));
        if (isHaveChild(prt)) {
            CreateNTree(&newChd);
            newChd = newNode(INFONTREE(CHILD(prt)));
            CHILD(*newPrt) = newChd;
            copyNTreeChd(CHILD(prt), &newChd);
        } 
    } 
}

void copyNTreeChd(NTree chd, NTree *newChd) {
    // KAMUS
    Address newChdOfChd;
    Address newSibOfChd;
    // ALGORITMA
    if (isNTreeEmpty(chd)) {
        *newChd = NULL;
    } else {
        if (isHaveChild(chd)) {
            CreateNTree(&newChdOfChd);
            newChdOfChd = newNode(INFONTREE(CHILD(chd)));
            CHILD(*newChd) = newChdOfChd;
            copyNTreeChd(CHILD(chd), &newChdOfChd);
        } if (isHaveSibling(chd)) {
            CreateNTree(&newSibOfChd);
            newSibOfChd = newNode(INFONTREE(SIBLING(chd)));
            SIBLING(*newChd) = newSibOfChd;
            copyNTreeChd(SIBLING(chd), &newSibOfChd);
        } 
    } 
}
/* I.S. prt terdefinisi, chd terdefinisi */
/* F.S. setiap bagian cabang dari prt yang memiliki info sama dengan INFO(chd)
        akan diganti dengan address copian NTree chd*/
void addChildBySpecificInfo(NTree *prt, NTree chd) {
    // KAMUS
    NTree newChdOfChd;
    Address p, temp;
    int info;
    // ALGORITMA
    if (isHaveChild(chd)) {
        if (isNTreeEmpty(*prt)) {
            printf("Parent tree kosong\n");
        } else {
            /* Bagian rekursi */
            if (isHaveChild(*prt)) {
                addChildBySpecificInfo(&CHILD(*prt), chd);
            } if (isHaveSibling(*prt)) {
                addChildBySpecificInfo(&SIBLING(*prt), chd);
            }
            
            info = INFONTREE(chd);
            if (INFONTREE(*prt) == info)  {
                CreateNTree(&newChdOfChd);
                newChdOfChd = newNode(INFONTREE(CHILD(chd)));
                CHILD(*prt) = newChdOfChd;
                copyNTreeChd(CHILD(chd), &newChdOfChd);
            }
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


