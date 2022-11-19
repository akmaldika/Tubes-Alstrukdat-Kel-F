#include "../ADT_Simulator/simulator.h"
#include "../ADT_Notifikasi/Notifikasi.h"
#include "../config_main.h"

void COOKFOOD(SIMULATOR *s, ListMakanan lm, ListResep lr, Notifikasi *notif, char *action) {
    // KAMUS
    MultiSet listBahan;
    PrioQueue tempInventory;
    ListMakanan actionableFood, expFood, delivFood, newFood, tempUsedFood, usedFood;
    boolean isSuccess, flagDeliv, flagExp;
    int n, id, currIdBahan, failureId;

    // ALGORITMA
    // Inisialisasi awal
    CreateListMakanan(&expFood);
    CreateListMakanan(&delivFood);
    CreateListMakanan(&newFood);
    CreateListMakanan(&usedFood);

    actionableFood = DisplayActionAbleLM(lm, action);
    printf("Kirim 0 untuk exit.\n\n");
    printf("Command = ");
    STARTCOMMAND();
    STARTWORD();
    

    // Nanti tambahin pengecekan currentWORD integer bukan
    n = wordToInt(currentWord);
    while (n != 0) {

        // Jika n diluar opsi pilihan
        if ((n < 0) || (n > LengthLM(actionableFood)) || (!isWordInt(currentWord))) {
            printf("Masukan command yang sesuai\n\n");

        // Jija n sesuai 0 <= n <= Length(actionableFood)
        } else {

            // Inisialisasi 
            // Nomor id pilihan pengguna
            id = GetIdMkn(actionableFood, n-1);
            listBahan = getListBahan(lr, id);
            isSuccess = true;
            tempInventory = INVENTORY(*s);
            CreateListMakanan(&tempUsedFood);

            // Loop untuk tes apakah terdapat bahan yang cukup dari inventory
            while ((!isEmptyMS(listBahan)) && (isSuccess)) {
                currIdBahan = ELMTMS(listBahan, 0);
                if (searchMkn(tempInventory, MknId(lm, currIdBahan))) {
                    removeFromInventory(&tempInventory, currIdBahan);
                    insertLM(&tempUsedFood, MknId(lm, currIdBahan));
                    removeMS(&listBahan, currIdBahan, 1);
                } else {
                    isSuccess = false;
                    failureId = currIdBahan;
                }
            }

            if (isSuccess) {
                printf("%s telah berhasil dibuat dan masuk ke dalam inventory\n\n", NamaMknId(lm, id).Tabword);
                
                Enqueue(&tempInventory, MknId(lm, id));
                INVENTORY(*s) = tempInventory;

                insertLM(&newFood, MknId(lm, id));
                accumLM(&usedFood, tempUsedFood);

                waitCommand(&DELIV(*s), &INVENTORY(*s), &flagDeliv, &flagExp, &expFood, &delivFood, 0, FRY_TIME);
                setAllNotif(notif, expFood, delivFood, usedFood, newFood);


            } else {
                printf("Gagal membuat %s karena kamu tidak memiliki bahan berikut: \n", NamaMknId(lm, id).Tabword);
                printf("- %s\n\n", NamaMknId(lm, failureId).Tabword);
            }

        }
        printf("Kirim 0 untuk exit.\n\n");
        printf("Command = ");
        STARTCOMMAND();
        STARTWORD();
        n = wordToInt(currentWord);

    }
}
