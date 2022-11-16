#include "../ADT_Simulator/simulator.h"

void FRYFOOD(SIMULATOR *s, ListMakanan lm, ListResep lr, boolean *flag) {
    // KAMUS
    SIMULATOR tempS;
    ListMakanan actionableFood;
    int n, id;

    // ALGORITMA

    tempS = *s;
    if (isAdjacent(s, MAP(*s), 'f')) {
        actionableFood = DisplayActionAbleLM(lm, 'f');
        STARTCOMMAND();
        STARTWORD();
        printf("Kirim 0 untuk exit.\n\n");
        printf("Command = ");

        // Nanti tambahin pengecekan currentWORD integer bukan
        n = wordToInt(currentWord);
        while (n != 0) {
            // Jika n diluar opsi pilihan
            if ((n < 0) && (n > LengthLM(actionableFood))) {
                printf("Masukan command yang susuai\n\n");

            // Jija n sesuai 0 <= n <= Length(actionableFood)
            } else {
                id = GetIdMkn(actionableFood, n-1);

            }
        }
    }