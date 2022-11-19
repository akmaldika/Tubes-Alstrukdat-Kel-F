#include "boolean.h"
#include "Multiset.h"

#include <stdio.h>

/* gcc -lm -o a Driver_MultiSet.c MultiSet.c ..\ADT_ListStatik\ListResep.c ..\ADT_Tree\NTree.c ..\ADT_MesinKata\mesinkata.c  ..\ADT_MesinKata\string.c ..\ADT_MesinKata\mesinkarakter.c ; ./a */

int main() {
    // KAMUS
    MultiSet m, m1, m2, m3;
    int i, j, k, n1, n2, n3, n4, n5;

    // ALGOTITMA
    printf("Buat MultiSet baru l\n");
    CreateMS(&m);

    addMS(&m, 1, 10);
    addMS(&m, 1, 10);
    addMS(&m, 2, 8);
    addMS(&m, 3, 7);
    addMS(&m, 4, 6);

    printMS(m);

    removeMS(&m, 4, 5);
    removeMS(&m, 2, 8);
    deleteAtMS(&m, 0);


    printMS(m);

    CreateMS(&m);
    addMS(&m, 2, 2);
    addMS(&m, 21, 1);
    addMS(&m, 10, 1);
    addMS(&m, 15, 1);
    // addMS(&m, 123, 1);

    printMS(m);
    

    // printf("Ambil indeks pertama:\n%d\n", getFirstIdxMS(m));

    // printf("Ambil indeks terakhir:\n%d\n", getLastIdxMS(m));
    
    // printf("Cek apakah kosong:\n%d\n", isEmptyMS(m));

    // printf("Cek apakah full:\n%d\n", isFullMS(m));


}