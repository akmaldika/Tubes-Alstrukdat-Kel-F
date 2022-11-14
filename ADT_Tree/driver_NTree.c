#include <stdio.h>
#include <stdlib.h>
#include "NTree.h"

// gcc -lm -o a driver_NTree.c Ntree.c ; ./a
int main() {
    int i, k, n, val;
    NTree t, r, s, g, v, Tree, h;
    Address p;

    CreateNTree(&t);
    printf("Apakah NTree kosong: %d\n", isNTreeEmpty(t));

    printf("Assign nilai Info NTree menjadi 10\n");
    t = newNode(10);

    printf("Apakah NTree punya Sibling: %d\n", isHaveSibling(t));
    printf("Apakah NTree punya Child: %d\n", isHaveChild(t));

    printf("Print NTree:\n");
    printNTree(t, 0);

    printf("Tambahkan Child ke NTree yang bernilai 2 dan 5\n");
    addChildInfo(&t, 2);
    addChildInfo(&t, 5);
    printf("Print NTree t:\n");
    printNTree(t, 0);
    printf("Apakah NTree mendandung address yang memiliki info: 2");
    // scanf("%d", &val);
    val = 2;
    printf("Jawaban: %d\n", isContainInfo(t, val));

    printf("Tambahkan Child ke NTree yang bernilai 3 dan 7\n");
    addChildInfo(&t, 3);
    addChildInfo(&t, 7);
    printf("Print NTree t:\n");
    printNTree(t, 0);

    printf("Info dari anak ke-4 adalah: %d\n", INFONTREE(traverseChild(t, 4)));

    printf("Buat NTree g dengan info bernilai 8 dan memiliki\nanak masing-masing bernilai 1 dan 3\n");
    CreateNTree(&g);
    g = newNode(8);
    addChildInfo(&g, 1);
    addChildInfo(&g, 3);
    printf("Print NTree g:\n");
    printNTree(g, 0);

    printf("Copy tree t sebagai tree h\n");
    CreateNTree(&h);
    copyNTreePrt(t, &h);
    printf("Apakah NTree punya Child: %d\n", isHaveChild(h));
    printf("Print NTree h:\n");
    printNTree(h, 0);

    printf("Cek apakah setiap address sudah berbeda\n");
    printf("Coba dealokasi NTree h dan akses kembali t\n");
    deallocateNTree(h);
    printf("Print NTree t:\n");
    printNTree(t, 0);
    printf("Berhasil\n");


    printf("Buat NTree s dengan info bernilai 3 dan memiliki\nanak masing-masing bernilai 20 dan 50\n");
    CreateNTree(&s);
    s = newNode(3);
    addChildInfo(&s, 20);
    addChildInfo(&s, 50);
    printf("Print NTree s:\n");
    printNTree(s, 0);

    printf("Pada NTree t, untuk setiap Address yang memiliki info\nyang sama dengan INFONTREE(s) maka tambahkan\ndi Adrress tersebut anak-anak yang memiliki\nnilai yang sama dengan s\n");
    addChildBySpecificInfo(&t, s);
    printf("Print NTree t:\n");
    printNTree(t, 0);

    printf("Print NTree s:\n");
    printNTree(s, 0);
    deallocateNTree(t);
    deallocateNTree(s);
    deallocateNTree(g);
    printf("Selesai");


}