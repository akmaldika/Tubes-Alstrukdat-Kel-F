#include <stdio.h>
#include "../library.h"
#include "../ADT_MesinKata/mesinkarakter.c"
#include "../ADT_MesinKata/mesinkata.c"
#include "../ADT_MesinKata/string.h"

int main() {
    SIMULATOR s;
    CreateSim(&s);
    
    Matrix peta;
    // peta = MapMatrix("Driver_Config/Peta.txt");

    ListMakanan lm, lb;
    SetUpListMakanan(&lm, "Driver_Config/Makanan.txt");
    
    ListResep lr;
    readListLR(&lr, "Driver_Config/Resep.txt");

    Enqueue(&INVENTORY(s), MknId(lm, 2));
    Enqueue(&INVENTORY(s), MknId(lm, 24));

    // FRYFOOD(&s, lm, lr, &isSuccess);
    MultiSet listBahan;
    PrioQueue tempInventory;
    ListMakanan actionableFood;
    boolean isSuccess;
    int n, id, currIdBahan, failureId;

    // ALGORITMA
    boolean flag = false;
    // if (isAdjacent(s, MAP(*s), 'F')) {
    actionableFood = DisplayActionAbleLM(lm, "Fry");
    printf("Kirim 0 untuk exit.\n\n");
    printf("Command = ");
    STARTCOMMAND();
    STARTWORD();

    // Nanti tambahin pengecekan currentWORD integer bukan
    n = wordToInt(currentWord);
    while (n != 0) {
        // Jika n diluar opsi pilihan
        if ((n < 0) || (n > LengthLM(actionableFood))) {
            printf("Masukan command yang susuai\n\n");

        // Jija n sesuai 0 <= n <= Length(actionableFood)
        } else {
            
            // Inisialisasi untuk memilih
            id = GetIdMkn(actionableFood, n-1);
            listBahan = getListBahan(lr, id);
            isSuccess = true;
            tempInventory = INVENTORY(s);

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
                flag = true;
                printf("%s telah berhasil dibuat dan masuk ke dalam inventory\n\n", NamaMknId(lm, id).Tabword);

                Enqueue(&tempInventory, MknId(lm, id));
                INVENTORY(s) = tempInventory;
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

/*
gcc -lm  ..\ADT_Tree\NTree.c ..\ADT_MesinKata\mesinkata.c  ..\ADT_MesinKata\string.c ..\ADT_MesinKata\mesinkarakter.c ..\ADT_MultiSet\MultiSet.c ..\ADT_Makanan\makanan.c ..\ADT_ListStatik\ListMakanan.c ..\ADT_Time\time.c ..\ADT_ListStatik\ListResep.c ..\ADT_Matriks\matrix.c ..\ADT_Simulator\simulator.c ..\ADT_Queue\PrioQueue.c ..\ADT_Point\point.c Driver_Action_Command.c -o a ; ./a
*/

/*
gcc -lm  ..\ADT_MesinKata\mesinkata.c  ..\ADT_MesinKata\string.c ..\ADT_MesinKata\mesinkarakter.c  Driver_Action_Command.c -o a ; ./a
*/