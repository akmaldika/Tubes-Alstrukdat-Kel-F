#include <stdio.h>
#include "PrioQueue.h"
#include "../ADT_ListStatik/ListMakanan.h" 
#include <string.h>

int main()
{
    MAKANAN m1, m2, m3, m4, m5, m6, m7, m8, temp, mExp;
    Word w1, w2, w3, w4, w5, w6, w7, wd;
    ListMakanan ListMakananExp;
    CreateListMakanan(&ListMakananExp);
    boolean Flag = false;
    strcpy(wd.String, "Dapur");
    strcpy(w1.String, "Ayam goreng");
    strcpy(w2.String, "Kangkung");
    strcpy(w3.String, "Iga sapi");
    strcpy(w4.String, "Bayam");
    strcpy(w5.String, "Kentang");
    strcpy(w6.String, "Ikan asin");
    strcpy(w7.String, "Ubi");

    TIME t1, t2, t3, t4, t5, t6, t7;
    printf("\nTest PrioQueue \n\n");
    CreateTime(&t1, 0, 0, 7);
    CreateTime(&t2, 0, 0, 2);
    CreateTime(&t3, 0, 0, 6);
    CreateTime(&t4, 0, 0, 3);
    CreateTime(&t5, 0, 0, 2);
    CreateTime(&t6, 0, 0, 8);
    CreateTime(&t7, 0, 0, 3);
    CreateMakanan(&m1, 12, w1, t1, t1, wd);
    CreateMakanan(&m2, 13, w2, t2, t2, wd);
    CreateMakanan(&m3, 14, w3, t3, t3, wd);
    CreateMakanan(&m4, 15, w4, t4, t4, wd);
    CreateMakanan(&m5, 16, w5, t5, t5, wd);
    CreateMakanan(&m6, 18, w6, t6, t6, wd);
    CreateMakanan(&m7, 19, w7, t7, t7, wd);
    // CreateMakanan(&m1, 12, "ayam goreng", t1, t1, 1);
    // CreateMakanan(&m2, 13, "manisan", t2, t2, 2);
    // CreateMakanan(&m3, 14, "kangkung", t3, t3, 3);
    // CreateMakanan(&m4, 15, "nasi goreng", t4, t4, 4);
    // Makanan(a) = m1;
    PrioQueue q;
    MakeEmpty(&q, 4);
    Enqueue(&q, m1);
    Enqueue(&q, m2);
    Enqueue(&q, m3);
    Enqueue(&q, m4);
    PrintPrioQueue(q);
    // printf("h t%d %d\n", Head(q), Tail(q));

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
    Min1Minute(&q,&Flag, &ListMakananExp,&mExp);
    PrintPrioQueue(q);
    if(Flag){
        printf("\nFlag truee \n");
        printf("Makanan yg sudah Exp adalah %s\n\n",mExp.Nama );
    }
    else{
        printf("\nFlag false, belum ada yg expired \n");
    }

    printf("\n2. Pengurangan 1 menit dalam PrioQueue \n");
    PrintPrioQueue(q);
    Min1Minute(&q,&Flag, &ListMakananExp,&mExp);
    PrintPrioQueue(q);
    if(Flag){
        printf("\nFlag truee \n");
        printf("Makanan yg sudah Exp adalah %s\n\n",mExp.Nama );
    }
    else{
        printf("\nFlag false, belum ada yg expired \n\n");
    }
    return 0;
}