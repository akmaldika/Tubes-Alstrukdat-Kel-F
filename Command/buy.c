#ifndef BUY_h
#define BUY_h

#include "../ADT_Simulator/simulator.h"
#include <stdio.h>
#include <stdlib.h>

void BuyFood(SIMULATOR *s, ListMakanan lm, boolean *flag);
/* I.S. : S terdefinisi, lm berisi hasil konfigurasi program, flag sembarang */
/* F.S. : S selesai melakukan pembelian dengan menginput 0 atau S tidak berada di dekat telepon */
/* Meminta input angka kepada user, jika berhasil maka makanan akan disimpan pada deliv queue S */
/* Mengecek apakah S adjecent dengan 'B' */
/* Pengecakan dan pengulangan input terjadi */

#endif

void BuyFood(SIMULATOR *s, ListMakanan lm, boolean *flag)
{
    /* KAMUS LOKAL */
    ListMakanan buyAbleFood;
    boolean isSuccess;
    int inputUser;
    IDEM id;

    /* ALGORITMA */
    *flag = false;

    if (isAdjacent(*s, 'T'))
    {
        buyAbleFood = DisplayBuyAbleLM(lm);
        printf("\nKirim 0 untuk exit.\n\n");
        printf("Masukkan command = ");
        STARTCOMMAND();
        STARTWORD();

        while (!isWordInt(currentWord))
        {
            printf("'%s' Bukan angka!\n", currentWord.String);
            printf("Masukan command yang susuai\n");
            printf("Masukkan command = ");
            STARTCOMMAND();
            STARTWORD();
        }
        inputUser = wordToInt(currentWord);
        while (inputUser != 0)
        {
            if (inputUser < 0 || inputUser > LengthLM(buyAbleFood))
            {
                printf("'%d' tidak valid!\n", inputUser);
                printf("Pilih angka 0 - %d\n", LengthLM(buyAbleFood));
                printf("Masukkan command = ");
                STARTCOMMAND();
                STARTWORD();
            }
            else
            {
                isSuccess = true;
                *flag = true;
                while(isSuccess && !endWord)
                {
                    Enqueue(&DELIV(*s), ElmtLM(buyAbleFood, inputUser - 1));
                    printf("%s Berhasil dipesan! Mohon tunggu selama ", GetNamaMkn(buyAbleFood, inputUser - 1));
                    DisplayTIMEk(GetDeliverTimeMkn(buyAbleFood, inputUser - 1));
                    printf("\n");

                    ADVWORD();
                    if (isWordInt(currentWord))
                    {
                        inputUser = wordToInt(currentWord);
                        isSuccess = (inputUser >= 0 && inputUser <= LengthLM(buyAbleFood));
                        
                        if (!isSuccess)
                        {
                            printf("'%d' tidak valid!\n", inputUser);
                            printf("Pilih angka 0 - %d\n", LengthLM(buyAbleFood));
                        }
                    }
                    else
                    {
                        isSuccess = false;
                        printf("'%s' Bukan angka!\n", currentWord.String);
                    }
                }

                // last angka jika sudah endWord, tetapi masih success
                if(isSuccess)
                {
                    Enqueue(&DELIV(*s), ElmtLM(buyAbleFood, inputUser -1));
                    printf("%s Berhasil dipesan! Mohon tunggu selama ", GetNamaMkn(buyAbleFood, inputUser - 1));
                    DisplayTIMEk(GetDeliverTimeMkn(buyAbleFood, inputUser - 1));
                    printf("\n");
                }

                NextMin(&WAKTU(*s));

                printf("Ingin memesan lagi?\n");
                printf("Masukkan command = ");
                STARTCOMMAND();
                STARTWORD();
            }
        }
    }
    else
    {
        printf("BNMO tidak berada di area Telepon!!\n");
    }
}
