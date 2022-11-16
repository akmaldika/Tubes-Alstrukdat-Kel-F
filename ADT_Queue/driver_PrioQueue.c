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
    printf("\nkata word: %s, n : %d\n", w1.Tabword, w1.Length);
    printf("kata line: %s, n : %d\n\n", wd.String, wd.Length);

    TIME t1, t2, t3, t4, t5, t6, t7;
    printf("\nTest PrioQueue \n\n");
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
    PrioQueue q;
    MakeEmpty(&q, 4);  // 4 dan 5 
    printf("max : %d \n", MaxEl(q));
    Enqueue(&q, m1);
    Enqueue(&q, m2);
    Enqueue(&q, m3);
    Enqueue(&q, m4);
    // Enqueue(&q, m5);
    // Enqueue(&q, m7);
    PrintPrioQueue(q);
    // printf("h t%d %d\n", Head(q), Tail(q));
    // printf("is full %d \n",IsFull(q) );

    Dequeue(&q, &temp);
    Dequeue(&q, &temp);
    Dequeue(&q, &temp);

    PrintPrioQueue(q);
    // printf("h t%d %d\n", Head(q), Tail(q));
    Enqueue(&q, m5);
    // PrintPrioQueue(q);

    // printf("h t%d %d\n", Head(q), Tail(q));
    Enqueue(&q, m6);
    // PrintPrioQueue(q);

    // printf("h t%d %d\n", Head(q), Tail(q));
    Enqueue(&q, m7);
    // PrintPrioQueue(q);

    DequeueExp(&q, &temp);
    // printf("h t%d %d\n", Head(q), Tail(q));
    // printf("id nihh %d\n", Info((q).T[Head(q)]));  enque yg dah exp

    printf("\n\n1. Pengurangan 1 menit dalam PrioQueue \n");
    PrintPrioQueue(q);
    Min1Minute(&q, &Flag, &ListMakananExp);
    PrintPrioQueue(q);
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
    PrintPrioQueue(q);
    Min1Minute(&q, &Flag, &ListMakananExp);
    PrintPrioQueue(q);
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
    PrintPrioQueue(q);
    Min1Minute(&q, &Flag, &ListMakananExp);
    PrintPrioQueue(q);
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
    PrintPrioQueue(q);
    printf("m3 id : %d\n",m1.id);
    printf("ada ayam goreng : %d", searchMkn(q, m1) );
    boolean flag = 0;



    printf("\n\n4. Pengurangan 3 menit dalam PrioQueue \n");
    PrintPrioQueue(q);
    MinNTime(&q, &flag, &ListMakananExp, 0, 3);
    PrintPrioQueue(q);
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

    i=0;
    while (i < ListMakananExp.NElmt)
    {
        printf("   %d. %s\n", i + 1, ListMakananExp.Lmakanan[i].Nama);
        i++;
    }

    Enqueue(&q, m2);
    Enqueue(&q, m3);
    printf("\n");
    PrintPrioQueue(q);
    // printf("h t%d %d\n", Head(q), Tail(q));
    printf("\nremove ikan asin \n");
    removeFromInventory(&q, 18);
    // printf("h t%d %d\n", Head(q), Tail(q));
    PrintPrioQueue(q);

    // Delivery m5  m4
    PrioQueue Qdeliv;
    MakeEmpty(&Qdeliv, 3);
    DelivMakanan(&Qdeliv, m4);
    PrintPrioQueue(Qdeliv);
    waitCommand(&Qdeliv, &q, &FlagDeliv, &Flag, &ListMakananExp, &ListDelivDone, 0, 2);
    // min1menitAll(&Qdeliv, &q, &FlagDeliv, &Flag, &ListMakananExp, &ListDelivDone);
    // min1menitAll(&Qdeliv, &q, &FlagDeliv, &Flag, &ListMakananExp, &ListDelivDone);
    // min1menitAll(&Qdeliv, &q, &FlagDeliv, &Flag, &ListMakananExp, &ListDelivDone);
    PrintPrioQueue(q);
    PrintPrioQueue(Qdeliv);

    return 0;
}