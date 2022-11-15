/* File MultiSet.h*/

#ifndef _MULTISET_h
#define _MULTISET_h

#include "boolean.h"
#include "..\config_main.h"
#include "..\ADT_Tree\NTree.h"
#include "..\ADT_ListStatik\ListResep.h"
#include "..\ADT_MesinKata\mesinkata.h"
#include "..\ADT_MesinKata\mesinkarakter.h"
#include "..\ADT_MesinKata\string.h"

#define CAPACITY_MULTISET CONFIG_SIZELM
#define IDX_UNDEF_MS -1

typedef struct {
    int Elmt;
    int Multiplicty;
} ElMultiSetType;

typedef struct {
    ElMultiSetType Buffer[CAPACITY_MULTISET];
    int NEffMultiSet;
} MultiSet;

/* Selektor */
#define NEFFMS(m) (m).NEffMultiSet
#define ELMTMS(m, i) (m).Buffer[i].Elmt
#define MULTMS(m, i) (m).Buffer[i].Multiplicty

/* Konstruktor */

/* I.S. Sembarang */
/* F.S. MultiSet m terdefinisi dan kosong*/
void CreateMS(MultiSet *m);

/* Banyak elemen */

/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
int lengthMS(MultiSet m);

/* Selektor Indeks */

/* Prekondisi : m tidak kosong */
/* Mengirimkan indeks elemen m pertama */
int getFirstIdxMS(MultiSet m);

/* Prekondisi : m tidak kosong */
/* Mengirimkan indeks elemen m pertama */
int getLastIdxMS(MultiSet m);

/* Mengembalikan indeks dengan i sehinggak ELMTMS(m, i) == val */
/* Jika tidak ditemukan, kembalikan IDX_UNDEF_MS */
int getElmtIdxMS(MultiSet m, int x);

/* ********** Test Indeks yang valid ********** */

/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas m */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxValidMS(MultiSet m, int i);

/* Mengirimkan true jika i adalah indeks yang terdefinisi utk m */
/* yaitu antara 0..lengthMS(m)-1 */
boolean isIdxEffMS(MultiSet m, int i);

/* *** Test MultiSet kosong *** */

/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
boolean isEmptyMS(MultiSet m);


/* *** Test MultiSet penuh *** */

/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
boolean isFullMS(MultiSet m);

/* Output */

/* I.S. m terdefinisi */
/* F.S. Nilai dan multipl;icity dari elemen-elemen dari m tercetak di layar */
void printMS(MultiSet m);

/* Searching */

/* Mengecek apakah terdapat elemen dengan nilai x sebanyak k di m */
boolean isInMS(MultiSet m, int x, int k);

/* Mengecek apakah m2 merupakan subset dari m1 */
boolean subsetMS(MultiSet m1, MultiSet m2);

/* Menambah dan Mengurangi Elemen */

/* Menambah kan elemen dengan nilai x dan multipilicty k ke m*/
void addMS(MultiSet *m, int x, int k);

/* Menghilangkan elemen dengan nilai x sebanyak k */
void removeMS(MultiSet *m, int x, int k);

/* I.S. m terdefinisi, m tidak kosong, i merupakan index valid dari m*/
/* F.S. Semua elemen dari m mulai dari index i tergeser ke kiri sekali */
void deleteAtMS(MultiSet *m, int i);

/* Bonus 3*/
/* Recomendation */

/* Mengembalikan true jika resep bisa dibuat dengan inventory m*/
boolean isResepMakeable(MultiSet *m, NTree resep);

/* Mengembalikan id dari resep yang bisa dibuat dari inventory m */
MultiSet getMakableResep(MultiSet m, ListResep l);
#endif