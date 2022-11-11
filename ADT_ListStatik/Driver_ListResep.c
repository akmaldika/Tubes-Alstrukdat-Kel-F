#include "ListResep.h"
#include <stdio.h>
#include <stdlib.h>

/* gcc -lm -o a Driver_ListResep.c ListResep.c ..\ADT_Tree\NTree.c ..\ADT_MesinKata\mesinkata.c  ..\ADT_MesinKata\string.c ..\ADT_MesinKata\mesinkarakter.c ; ./a
*/
int main() {
    /* KAMUS */
    ListResep l;
    NTree t1, t2, t3;
    Address a1, a2, a3;

    /* ALGORITMA */

    // Buat list baru
    
    printf("Cek apakah kosong:\n%d\n", isEmptyLR(l));

    printf("Cek apakah full:\n%d\n", isFullLR(l));

    printf("Masukan ListResep l dengan beberapa resep\n");
    CreateNTree(&t1);
    t1 = newNode(10);
    addChildInfo(&t1, 2);
    addChildInfo(&t1, 5);
    CreateNTree(&t2);
    t2 = newNode(21);
    addChildInfo(&t2, 3);
    addChildInfo(&t2, 7);
    addChildInfo(&t2, 120);
    insertLastLR(&l, t1);
    insertLastLR(&l, t2);

    printf("Print l:\n");
    printLR(l);

    printf("Apakah l memiliki resep dengan id 21:\n%d\n", isContainResep(l, 21));
    printf("Apakah l memiliki resep dengan id 20:\n%d\n", isContainResep(l, 20));

    

    printf("Buat resep baru dengan id 120 dan bahan makanan 10, 12, 1\n");
    t3 = newNode(120);
    addChildInfo(&t3, 10);
    addChildInfo(&t3, 12);
    addChildInfo(&t3, 1);
    printf("Print resep t3:\n");
    printNTree(t3, 0);

    printf("Print l:\n");
    printLR(l);
        
    printf("Masukan t3 ke ListResep l dengan skema konsolidasi\n");
    insertLastLRKonsolidasi(&l, &t3);
    printf("Print l:\n");
    printLR(l);
    


    // printf("Geser elemen di l ke kiri dari index 0\n");
    // shiftLeftLRAtIndex(&l, 0);
    // printf("Print l:\n");
    // printLR(l);
    // readListLR(&l);

    return 0;


}
//