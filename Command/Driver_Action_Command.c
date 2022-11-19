#include <stdio.h>
#include "../library.h"
// #include "../ADT_MesinKata/mesinkarakter.c"
// #include "../ADT_MesinKata/mesinkata.c"
#include "../ADT_MesinKata/string.h"
#include "../ADT_Notifikasi/Notifikasi.h"
#include "Fryfood.c"

int main() {
    SIMULATOR s;
    CreateSim(&s, "Driver_Config/Peta.txt");
    

    ListMakanan lm, lb;
    SetUpListMakanan(&lm, "Driver_Config/Makanan.txt");
    
    ListResep lr;
    readListLR(&lr, "Driver_Config/Resep.txt");

    Enqueue(&INVENTORY(s), MknId(lm, 2));
    Enqueue(&INVENTORY(s), MknId(lm, 24));
    Enqueue(&INVENTORY(s), MknId(lm, 2));
    Enqueue(&INVENTORY(s), MknId(lm, 24));
    Enqueue(&INVENTORY(s), MknId(lm, 2));
    Enqueue(&INVENTORY(s), MknId(lm, 24));
    Enqueue(&INVENTORY(s), MknId(lm, 2));
    Enqueue(&INVENTORY(s), MknId(lm, 24));
    Enqueue(&INVENTORY(s), MknId(lm, 2));
    Enqueue(&INVENTORY(s), MknId(lm, 24));
    Enqueue(&INVENTORY(s), MknId(lm, 2));
    Enqueue(&INVENTORY(s), MknId(lm, 24));
    Enqueue(&INVENTORY(s), MknId(lm, 2));
    Enqueue(&INVENTORY(s), MknId(lm, 24));
    Enqueue(&INVENTORY(s), MknId(lm, 2));
    Enqueue(&INVENTORY(s), MknId(lm, 24));
    Enqueue(&INVENTORY(s), MknId(lm, 2));
    Enqueue(&INVENTORY(s), MknId(lm, 24));
    Enqueue(&INVENTORY(s), MknId(lm, 2));
    Enqueue(&INVENTORY(s), MknId(lm, 24));
    Enqueue(&INVENTORY(s), MknId(lm, 2));
    Enqueue(&INVENTORY(s), MknId(lm, 24));
    

    Notifikasi notif;
    CreateNotifikasi(&notif);

    COOKFOOD(&s, lm, lr, &notif, "Fry");

    printLR(lr);
    displayNotifikasi(&notif);


    return 0;
    // FRYFOOD(&s, lm, lr, &isSuccess);

    
}
/*
gcc -lm  ..\ADT_Tree\NTree.c ..\ADT_MesinKata\mesinkata.c  ..\ADT_MesinKata\string.c ..\ADT_MesinKata\mesinkarakter.c ..\ADT_MultiSet\MultiSet.c ..\ADT_Makanan\makanan.c ..\ADT_ListStatik\ListMakanan.c ..\ADT_Time\time.c ..\ADT_ListStatik\ListResep.c ..\ADT_Matriks\matrix.c ..\ADT_Simulator\simulator.c ..\ADT_Queue\PrioQueue.c ..\ADT_Point\point.c ..\ADT_Notifikasi\Notifikasi.c Driver_Action_Command.c  -o a ; ./a
*/