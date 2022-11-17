// #include "../ADT_Simulator/simulator.h"
#include "../ADT_ListStatik/ListMakanan.h"
#include "../ADT_ListStatik/ListResep.h"
#include "../ADT_Makanan/makanan.h"
#include "../ADT_Matriks/matrix.h"
#include "../ADT_MesinKata/mesinkarakter.h"
#include "../ADT_MesinKata/mesinkata.h"
#include "../ADT_MesinKata/string.h"
#include "../ADT_MultiSet/MultiSet.h"
// #include "../ADT_Point/point.h"
#include "../ADT_Queue/PrioQueue.h"
#include "../ADT_Time/time.h"
#include "../ADT_Tree/NTree.h"

void COOKBOOKFOOD(ListResep lr, ListMakanan lm) {
    // KAMUS
    MultiSet ListBahan;
    int currentId, i, currBahanId;
    // ALGORITMA
    printf("List Resep\n");
    for (i = 0; isIdxEffLR(lr, i); i++) {
        printf("%d. ", i+1);
        currentId = INFONTREE(ELMTLR(lr, i));
        printf("%s\n", NamaMknId(lm, currentId).Tabword);
        printf("%s", ActionLocId(lm, currentId).String);
        ListBahan = getListBahan(lr, currentId);

        while (!isEmptyMS(ListBahan)) {
            currBahanId = ELMTMS(ListBahan, 0);
            printf(" - %s", NamaMknId(lm, currBahanId).Tabword);
            removeMS(&ListBahan, currBahanId, 1);
        }
        
        printf("\n");
    } 

}