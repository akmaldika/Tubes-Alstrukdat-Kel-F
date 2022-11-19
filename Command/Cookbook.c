// #include "../ADT_Simulator/simulator.h"
#include "../library.h"

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

void RECOMMENDATION(SIMULATOR s, ListResep lr, ListMakanan lm) {
    // KAMUS
    MultiSet multiSetInventory, makeableFood;
    int i, currentId;
    // ALGORITMA
    for (i = 0; i < NBElmt(INVENTORY(s)); i++) {
        addMS(&multiSetInventory, Info(Elmt(INVENTORY(s), i)), 1); 
    }

    makeableFood = getMakableResep(multiSetInventory, lr);

    if (!isEmptyMS(makeableFood)) {
        printf("Tidak ada makanan yang dapat direkomendasikan\n\n");

    } else {
        printf("Berikut daftar makanan yang direkomendasikan\n");
        while (!isEmptyMS(makeableFood)) {
            currentId = ELMTMS(makeableFood, 0);
            printf(" - %s\n", NamaMknId(lm, currentId).Tabword);
            removeMS(&makeableFood, currentId, 1);
        }
    }
}