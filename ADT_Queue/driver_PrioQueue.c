#include <stdio.h>
#include "PrioQueue.h"
// #include "../ADT_ListStatik/ListMakanan.h"

void assignWord(Word *w, char str[])
{
    int i = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        w->String[i] = str[i];
    }
    w->Length = i;
    w->String[i] = '\0';
}
void assignLine(Line *w, char str[])
{
    int i = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        w->Tabword[i] = str[i];
    }
    w->Length = i;
    w->Tabword[i] = '\0';
}

int main()
{
    MAKANAN m1, m2, m3, m4, m5, m6, m7, m8, temp, mExp;
    Line w1, w2, w3, w4, w5, w6, w7;
    Word wd;
    ListMakanan ListMakananExp;
    ListMakanan ListDelivDone;
    CreateListMakanan(&ListMakananExp);
    CreateListMakanan(&ListDelivDone);
    boolean Flag = false;
    boolean FlagDeliv = false;
    assignWord(&wd, "Dapur");
    assignLine(&w1, "Ayam goreng");
    assignLine(&w2, "Kangkung");
    assignLine(&w3, "Iga sapi");
    assignLine(&w4, "Bayam");
    assignLine(&w5, "Kentang");
    assignLine(&w6, "Ikan asin");
    assignLine(&w7, "Ubi");
    // printf("\nkata word: %s, n : %d\n", w1.Tabword, w1.Length);
    // printf("kata line: %s, n : %d\n\n", wd.String, wd.Length);

    TIME t1, t2, t3, t4, t5, t6, t7;
    printf("Test PrioQueue \n\n");
    CreateTime(&t1, 0, 0, 7);
    CreateTime(&t2, 0, 0, 2);
    CreateTime(&t3, 0, 0, 6);
    CreateTime(&t4, 0, 0, 3);
    CreateTime(&t5, 0, 0, 2);
    CreateTime(&t6, 0, 0, 8);
    CreateTime(&t7, 0, 0, 3);
    CreateMakanan(&m1, 12, w1, t1, t7, wd);
    CreateMakanan(&m2, 13, w2, t2, t7, wd);
    CreateMakanan(&m3, 14, w3, t3, t4, wd);
    CreateMakanan(&m4, 15, w4, t4, t2, wd);
    CreateMakanan(&m5, 16, w5, t5, t1, wd);
    CreateMakanan(&m6, 18, w6, t6, t4, wd);
    CreateMakanan(&m7, 19, w7, t7, t2, wd);
    // CreateMakanan(&m1, 12, "ayam goreng", t1, t1, 1);
    // CreateMakanan(&m2, 13, "manisan", t2, t2, 2);
    // CreateMakanan(&m3, 14, "kangkung", t3, t3, 3);
    // CreateMakanan(&m4, 15, "nasi goreng", t4, t4, 4);
    // Makanan(a) = m1;
    PrioQueue InventoryPQ;
    MakeEmpty(&InventoryPQ, 4); // 4 dan 5 // MaxEl
    printf("max : %d \n", MaxEl(InventoryPQ));
    Enqueue(&InventoryPQ, m1);
    Enqueue(&InventoryPQ, m2);
    Enqueue(&InventoryPQ, m3);
    Enqueue(&InventoryPQ, m4);
    // Enqueue(&InventoryPQ, m5);
    // Enqueue(&InventoryPQ, m7);
    PrintPrioQueue(InventoryPQ);
    // printf("h t%d %d\n", Head(InventoryPQ), Tail(InventoryPQ));
    // printf("is full %d \n",IsFull(InventoryPQ) );

    Dequeue(&InventoryPQ, &temp);
    Dequeue(&InventoryPQ, &temp);
    Dequeue(&InventoryPQ, &temp);

    PrintPrioQueue(InventoryPQ);
    // printf("h t%d %d\n", Head(InventoryPQ), Tail(InventoryPQ));
    Enqueue(&InventoryPQ, m5);
    // PrintPrioQueue(InventoryPQ);

    // printf("h t%d %d\n", Head(InventoryPQ), Tail(InventoryPQ));
    Enqueue(&InventoryPQ, m6);
    // PrintPrioQueue(InventoryPQ);

    // printf("h t%d %d\n", Head(InventoryPQ), Tail(InventoryPQ));
    Enqueue(&InventoryPQ, m7);
    // PrintPrioQueue(InventoryPQ);

    DequeueExp(&InventoryPQ, &temp);
    // printf("h t%d %d\n", Head(InventoryPQ), Tail(InventoryPQ));
    // printf("id nihh %d\n", Info((InventoryPQ).T[Head(InventoryPQ)]));  enque yg dah exp

    printf("\n\n1. Pengurangan 1 menit dalam PrioQueue \n");
    PrintPrioQueue(InventoryPQ);
    Min1Minute(&InventoryPQ, &Flag, &ListMakananExp);
    PrintPrioQueue(InventoryPQ);
    if (Flag)
    {
        printf("\nFlag truee \n");
        printf("Makanan yg sudah Exp adalah %s\n\n", ListMakananExp.Lmakanan[ListMakananExp.NElmt - 1].Nama);
    }
    else
    {
        printf("\nFlag false, belum ada yg expired \n");
    }

    printf("\n2. Pengurangan 1 menit dalam PrioQueue \n");
    PrintPrioQueue(InventoryPQ);
    Min1Minute(&InventoryPQ, &Flag, &ListMakananExp);
    PrintPrioQueue(InventoryPQ);
    if (Flag)
    {
        printf("\nFlag truee \n");
        printf("Makanan yg sudah Exp adalah %s\n\n", ListMakananExp.Lmakanan[ListMakananExp.NElmt - 1].Nama);
    }
    else
    {
        printf("\nFlag false, belum ada yg expired \n\n");
    }

    printf("\n3. Pengurangan 1 menit dalam PrioQueue \n");
    PrintPrioQueue(InventoryPQ);
    Min1Minute(&InventoryPQ, &Flag, &ListMakananExp);
    PrintPrioQueue(InventoryPQ);
    if (Flag)
    {
        printf("\nFlag truee \n");
        printf("Makanan yg sudah Exp adalah %s\n\n", ListMakananExp.Lmakanan[ListMakananExp.NElmt - 1].Nama);
    }
    else
    {
        printf("\nFlag false, belum ada yg expired \n\n");
    }

    int i = 0;
    // ListMakananExp.Lmakanan[0] = mExp;
    printf("list makanan basi : \n");
    while (i < ListMakananExp.NElmt)
    {
        printf("   %d. %s\n", i + 1, ListMakananExp.Lmakanan[i].Nama);
        i++;
    }
    PrintPrioQueue(InventoryPQ);
    printf("m3 id : %d\n", m1.id);
    printf("ada ayam goreng : %d", searchMkn(InventoryPQ, m1));
    boolean flag = 0;

    printf("\n\n4. Pengurangan 3 menit dalam PrioQueue \n");
    PrintPrioQueue(InventoryPQ);
    MinNTime(&InventoryPQ, &flag, &ListMakananExp, 0, 3);
    PrintPrioQueue(InventoryPQ);
    if (Flag)
    {
        printf("\nFlag truee \n");
        printf("Makanan yg sudah Exp adalah %s\n\n", ListMakananExp.Lmakanan[ListMakananExp.NElmt - 1].Nama);
    }
    else
    {
        printf("\nFlag false, belum ada yg expired \n\n");
    }
    printf("list makanan basi : \n");

    i = 0;
    while (i < ListMakananExp.NElmt)
    {
        printf("   %d. %s\n", i + 1, ListMakananExp.Lmakanan[i].Nama);
        i++;
    }

    Enqueue(&InventoryPQ, m2);
    Enqueue(&InventoryPQ, m3);
    printf("\n");
    PrintPrioQueue(InventoryPQ);
    // printf("h t%d %d\n", Head(InventoryPQ), Tail(InventoryPQ));
    printf("\nremove ikan asin \n");
    removeFromInventory(&InventoryPQ, 18);
    // printf("h t%d %d\n", Head(InventoryPQ), Tail(InventoryPQ));
    PrintPrioQueue(InventoryPQ);

    // Delivery m5  m4
    PrioQueue DeliveryPQ, Qcopy;
    MakeEmpty(&DeliveryPQ, 20);
    DelivMakanan(&DeliveryPQ, m4);
    DelivMakanan(&DeliveryPQ, m4);
    DelivMakanan(&DeliveryPQ, m4);
    DelivMakanan(&DeliveryPQ, m4);
    DelivMakanan(&DeliveryPQ, m4);
    DelivMakanan(&DeliveryPQ, m4);
    PrintDelivery(DeliveryPQ); // delivv
    waitCommand(&DeliveryPQ, &InventoryPQ, &FlagDeliv, &Flag, &ListMakananExp, &ListDelivDone, 0, 2);
    PrintDelivery(DeliveryPQ); // delivv
    min1menitAll(&DeliveryPQ, &InventoryPQ, &FlagDeliv, &Flag, &ListMakananExp, &ListDelivDone);
    // min1menitAll(&DeliveryPQ, &InventoryPQ, &FlagDeliv, &Flag, &ListMakananExp, &ListDelivDone);
    // min1menitAll(&DeliveryPQ, &InventoryPQ, &FlagDeliv, &Flag, &ListMakananExp, &ListDelivDone);

    PrintPrioQueue(InventoryPQ);
    printf("\n");
    copyPQ(InventoryPQ, &Qcopy);
    PrintPrioQueue(Qcopy);
    printf("\n");
    PrintDelivery(DeliveryPQ); // delivv
    printf("\n");
    PrintPrioQueue(Qcopy);
    printf("maxBefore %d\n", MaxEl(Qcopy));
    // expandPQ(&Qcopy, 10);
    shrinkPQ(&Qcopy, 2);
    printf("maxAfter shrink  %d\n", MaxEl(Qcopy));

    printf("\nUntuk mencoba shrink/expand (ketika enqueue atau dequeue) harus di set MaxElPQ di PrioQueue.h menjadi 2\n\n");
    if (MaxElPQ == 2)
    {
        Enqueue(&Qcopy, m7);
        Enqueue(&Qcopy, m1);
        Enqueue(&Qcopy, m2);
        PrintPrioQueue(Qcopy);
        printf("maxAfter enqueue -> expand  %d\n", MaxEl(Qcopy));

        Dequeue(&Qcopy, &temp);
        Dequeue(&Qcopy, &temp);
        Dequeue(&Qcopy, &temp);
        Dequeue(&Qcopy, &temp);
        printf("maxAfter dequeue -> shrink  %d\n", MaxEl(Qcopy));
        PrintPrioQueue(Qcopy);
        printf("\n");
    }


    // printf("test\n");
    // STARTWORD();
    // STARTCOMMAND();
    // checkWait();


    return 0;
}