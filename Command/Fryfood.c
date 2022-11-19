#include "../ADT_Simulator/simulator.h"
#include "../ADT_Notifikasi/Notifikasi.h"
#include "../config_main.h"

void FRYFOOD(SIMULATOR *s, ListMakanan lm, ListResep lr, Notifikasi *notif) {
    // KAMUS
    MultiSet listBahan, accumBahan, accumHasil;
    PrioQueue tempInventory;
    ListMakanan actionableFood, expFood, delivFood, accumNewFood, accumUsedFood;
    boolean isSuccess, flagDeliv, flagExp;
    int n, id, currIdBahan, failureId;

    // ALGORITMA
    // Inisialisasi awal
    actionableFood = DisplayActionAbleLM(lm, "Fry");
    STARTCOMMAND();
    STARTWORD();
    printf("Kirim 0 untuk exit.\n\n");
    printf("Command = ");

    // Nanti tambahin pengecekan currentWORD integer bukan
    n = wordToInt(currentWord);
    while (n != 0) {

        // Jika n diluar opsi pilihan
        if ((n < 0) || (n > LengthLM(actionableFood)) || (!isWordInt(currentWord))) {
            printf("Masukan command yang susuai\n\n");

        // Jija n sesuai 0 <= n <= Length(actionableFood)
        } else {
            CreateMS(&accumBahan);
            CreateMS(&accumHasil);
            // Inisialisasi untuk memilih
            id = GetIdMkn(actionableFood, n-1);
            listBahan = getListBahan(lr, id);
            isSuccess = true;
            tempInventory = INVENTORY(*s);

            // 
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
                listBahan = getListBahan(lr, id);
                CreateListMakanan(&expFood);
                CreateListMakanan(&delivFood);

                printf("%s telah berhasil dibuat dan masuk ke dalam inventory\n\n", NamaMknId(lm, id).Tabword);
                Enqueue(&tempInventory, MknId(lm, id));
                INVENTORY(*s) = tempInventory;
                waitCommand(&DELIV(*s), &INVENTORY(*s), &flagDeliv, &flagExp, &expFood, &delivFood, 0, FRY_TIME);
                setAllNotif(notif, expFood, delivFood, newFood, usedFood);


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
