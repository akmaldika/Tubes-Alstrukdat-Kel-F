/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotype, type addrNode, dan beberapa fungsi disesuikan 
   karena melibatkan modul list rekursif. */

#ifndef _NTREE_H_
#define _NTREE_H_

/* Modul lain yang digunakan : */
#include "boolean.h"

/* *** Definisi Type N-Tree dengan left child right sibling interpretation *** */
typedef int ElNTreeType;
typedef struct node* Address;
typedef struct node {
    ElNTreeType info;
    Address child;
    Address sibling; 
    int countChild; 
} Node;

/* Definisi N-ary Tree*/
/* N-ary Tree kosong ketika T = NULL*/
typedef Address NTree;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define INFONTREE(P) (P)->info
#define CHILD(P) (P)->child
#define SIBLING(P) (P)->sibling
#define COUNTCHILD(P) (P)->countChild

/* *** Konstruktor *** */

/* I.S. t merupakan NTree sembarang*/
/* F.S  t merupakan NTree yang kosong*/
void CreateNTree(NTree *t);

/* Manajemen Memory */

/* Mengembalikan Address hasil alokasi ElNTreeType */
/* Jika alokasi berhasil maka Address tidak NULL misal p, maka
   INFONTREE(P) = val, CHILD(P) = NULL, SIBLING(P) = NULL*/
/* Jika alokasi gagal, mengirimkan NULL */
Address newNode (ElNTreeType val);

/* I.S. p terdefinisi */
/* F.S. p dikembalikan ke sistem */
/* Melakukan dealokasi Address p */
void deallocateNode(Address p);

/* I.S. t terdefinisi */
/* F.S. t dan semua sub elemen nya dikembalikan ke sistem */
/* Melakukan dealokasi NTree t*/
void deallocateNTree(NTree t);

/* *** Predikat-Predikat Penting *** */

/* Mengembalikan true jika NTree t kosong dan sebaliknya */
boolean isNTreeEmpty(NTree t);

/* Membalikan true jika NTree t punya sibling dan sebaliknya */
boolean isHaveSibling(NTree t);

/* Mengembalikan true jika NTree t punya child dan sebaliknya */
boolean isHaveChild(NTree t);

/* *** Traversal *** */

/* Mengembalikan true jika terdapat address p di node NTree t 
   sehingga INFONTREE(p) == val, dan sebaliknya */
boolean isContainInfo(NTree t, int val);

/* Mengembalikan address p sehingga INFONTREE(p) adalah anak ke-n dari parent t */
Address traverseChild(NTree t, int n);

/* I.S. t terdefinisi, offset merupakan banyak spasi pada antara parent dengan anak*/
/* F.S. Tecetak NTree pada layar*/
void printNTree(NTree t, int offset);

/* *** Fungsi-Fungsi Lain *** */

/* Menambahkan prt dengan child, misal t, sehingga INFO(t) = val*/
void addChildInfo(NTree *prt, int val);

/* Mengembalikan adress tree dengan hasil salinan prt */
void copyNTreePrt(NTree prt, NTree *newPrt);

/* Mengembalikan adress tree dengan hasil salinan chd */
void copyNTreeChd(NTree chd, NTree *newChd);

/* I.S. prt terdefinisi, chd terdefinisi */
/* F.S. setiap bagian cabang dari prt yang memiliki info sama dengan INFO(chd)
        akan diganti dengan address copian NTree chd*/
void addChildBySpecificInfo(NTree *prt, NTree chd);

/* I.S. N terdefinisi */
/* F.S. Tercetak spasi sebanyak N dilayar */
void printNSpace(int N);


#endif