#include "../ADT_Simulator/simulator.h"

void FRYFOOD(SIMULATOR *s, ListMakanan lm, ListResep lr, boolean *flag) {
    // KAMUS
    MultiSet listBahan;
    PrioQueue tempInventory;
    ListMakanan actionableFood;
    boolean isSuccess;
    int n, id, currIdBahan, failureId;

    // ALGORITMA
    *flag = false;
    if (isAdjacent(*s,'F')) {
        actionableFood = DisplayActionAbleLM(lm, "Fry");
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
                // Inisialisasi untuk memilih
                id = GetIdMkn(actionableFood, n-1);
                listBahan = getListBahan(lr, id);
                isSuccess = true;
                tempInventory = INVENTORY(*s);

                while ((!isEmptyMS(listBahan)) && (isSuccess)) {
                    currIdBahan = ELMTMS(listBahan, 0);
                    if (searchMkn(tempInventory, MknId(lm, currIdBahan))) {
                        removeFromInventory(&tempInventory, currIdBahan);
                        removeMS(&listBahan, currIdBahan, 1);
                    } else {
                        isSuccess = false;
                        failureId = currIdBahan;
                    }
                }

                if (isSuccess) {
                    *flag = true;
                    printf("%s telah berhasil dibuat dan masuk ke dalam inventory\n\n", NamaMknId(lm, id).Tabword);

                    Enqueue(&tempInventory, MknId(lm, id));
                    INVENTORY(*s) = tempInventory;
                } else {
                    printf("Gagal membuat %s karena kamu tidak memiliki bahan berikut: \n", NamaMknId(lm, id).Tabword);
                    printf("- %d\n\n", NamaMknId(lm, failureId).Tabword);
                }

            }
            STARTCOMMAND();
            STARTWORD();
            printf("Kirim 0 untuk exit.\n\n");
            printf("Command = ");
            n = wordToInt(currentWord);

        }
    }
}