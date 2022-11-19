#include "Cookbook.c"

int main() {
    ListMakanan lm, lb;
    ListResep lr;
    CreateListMakanan(&lm);
    SetUpListMakanan(&lm, "Driver_Config/Makanan.txt");
    readListLR(&lr, "Driver_Config/Resep.txt");
    // printf("Banyak barang di ListMakanan%d", LengthLM(lm));
    // printLR(lr);
    DisplayCatalog(lm);

    // COOKBOOKFOOD(lr, lm);    
    // lb = DisplayActionAbleLM(lm, "Fry");
    // DisplayCatalog(lb);
    // COOKBOOKFOOD(lr, ListMkn);
    // printf("Selesai");
    // printf("halo");
    return 0;
}
/*
gcc -lm -o a Driver_Action_Command.c  ..\ADT_Tree\NTree.c ..\ADT_MesinKata\mesinkata.c  ..\ADT_MesinKata\string.c ..\ADT_MesinKata\mesinkarakter.c ..\ADT_MultiSet\MultiSet.c ..\ADT_Makanan\makanan.c ..\ADT_ListStatik\ListMakanan.c ..\ADT_Time\time.c ..\ADT_ListStatik\ListResep.c ..\ADT_Matriks\matrix.c ..\ADT_Simulator\simulator.c ..\ADT_Queue\PrioQueue.c ..\ADT_Point\point.c; ./a 
*/

