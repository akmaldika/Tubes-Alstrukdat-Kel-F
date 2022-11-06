#include "ListResep.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    /* KAMUS */
    ListResep l;
    NTree t1, t2, t3;
    Address a1, a2, a3;

    /* ALGORITMA */

    // Buat list baru
    printf("Buat list baru l\n");
    CreateLR(&l);

    printf("Ambil indeks pertama:\n%d\n", getFirstIdxLR(l));

    printf("Ambil indeks terakhir:\n%d\n", getLastIdxLR(l));
    
    printf("Cek apakah kosong:\n%d\n", isEmptyLR(l));

    printf("Cek apakah full:\n%d\n", isFullLR(l));

    CreateNTree(&t1);
    t1 = newNode(10);
    addChildInfo(&t1, 2);
    addChildInfo(&t1, 5);

    CreateNTree(&t2);
    t2 = newNode(21);
    addChildInfo(&t2, 3);
    addChildInfo(&t2, 7);

    insertLastLR(&l, t1);
    insertLastLR(&l, t2);

    printListLR(l);

    printf("\n");
    // readListLR(&l);

    return 0;


}
//