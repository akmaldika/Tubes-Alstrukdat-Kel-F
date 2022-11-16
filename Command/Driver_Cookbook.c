#include "Cookbook.c"

/*
gcc -lm -o a Driver_ListResep.c ListResep.c ..\ADT_Tree\NTree.c ..\ADT_MesinKata\mesinkata.c  ..\ADT_MesinKata\string.c ..\ADT_MesinKata\mesinkarakter.c ; ./a
*/
int main() {
    ListMakanan lm;
    ListResep lr;
    SetUpListMakanan("Driver_Config/Makanan.txt");
    readListLR(&lr, "Driver_Config/Resep.txt");
    
    // printLR(lr);
    
    lm = DisplayActionAbleLM(ListMkn, "Fry");
    DisplayCatalog(lm);
    // COOKBOOKFOOD(lr, ListMkn);

    return 0;
}
/*gcc -lm -o a Driver_Cookbook.c  ..\ADT_Tree\NTree.c ..\ADT_MesinKata\mesinkata.c  ..\ADT_MesinKata\string.c ..\ADT_MesinKata\mesinkarakter.c ..\ADT_MultiSet\MultiSet.c ..\ADT_Makanan\makanan.c ..\ADT_ListStatik\ListMakanan.c ..\ADT_Time\time.c ..\ADT_ListStatik\ListResep.c ; ./a*/