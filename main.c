#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "Command/CommandGame.h"

int main()
{
    /* KAMUS */
    ListResep ListRsp;
    ListMakanan ListMkn;
    ListMakanan ListMakananEXP;
    ListMakanan ListDeliveryDone;
    SIMULATOR BMO;
    Stack Undo, Redo;
    Notifikasi Notif;
    boolean FlagDelivDone;
    boolean FlagMakananEXP;
    boolean isActionSucces;
    boolean isStartGame;

    /* ALGORITMA */
    /* Inisiasi program */
    SetUpListMakanan(&ListMkn, "Config/Config_Makanan.txt");
    readListLR(&ListRsp, "Confg/Config_Resep.txt");

    CreateSim(&BMO, "Config/Config_Peta.txt");
    const SIMULATOR InitSim = BMO;

    CreateNotifikasi(&Notif);
    CreateEmptyStack(&Undo);
    CreateEmptyStack(&Redo);
    CreateListMakanan(&ListMakananEXP);
    CreateListMakanan(&ListDeliveryDone);

    splashInitGame();
    printf("\nMasukkan command: ");
    STARTCOMMAND();
    STARTWORD();
    // Cek Start command error mcna nerima START sam EXIT, loop sampai benar
    commandStartError();
    isStartGame = isLineSame(currentLine, "START");

    // while loop
    while (isStartGame)
    {   
        displayNotifikasi(&Notif);
        DisplayTIME(WAKTU(BMO));
        displayMap(MAP(BMO));
        // STARTCOMMAND semua yang diterima kecuali START
        printf("\nMasukkan command: ");
        STARTCOMMAND();
        STARTWORD();

        // cek benar salah, loop sampai benar
        commandInGameError();

        if (isWordSame(currentWord, "HELP"))
        {
            helpInGame();
        }
        else if (isWordSame(currentWord, "BUY"))
        {
            BuyFood(&BMO, ListMkn, &isActionSucces);
            if (isActionSucces)
            {
                min1menitAll(&DELIV(BMO), &INVENTORY(BMO), &FlagDelivDone, &FlagMakananEXP, &ListMakananEXP, &ListDeliveryDone);
                setExpDelivNotif(&Notif, ListMakananEXP, ListDeliveryDone);
                NextMin(&WAKTU(BMO));
            }
        }
        else if (isWordSame(currentWord, "MIX"))
        {
            if (isAdjacent(BMO, 'M')) {
                COOKFOOD(&BMO, ListMkn, ListRsp, &Notif, "Mix");
            } else {
                printf("BNMO tidak berada di area Mix!!\n ");
            }
        }
        else if (isWordSame(currentWord, "CHOP"))
        {
            if (isAdjacent(BMO, 'C')) {
                COOKFOOD(&BMO, ListMkn, ListRsp, &Notif, "Chop");
            } else {
                printf("BNMO tidak berada di area Chop!!\n ");
            }
        }
        else if (isWordSame(currentWord, "FRY"))
        {
            if (isAdjacent(BMO, 'F')) {
                COOKFOOD(&BMO, ListMkn, ListRsp, &Notif, "Fry");
            } else {
                printf("BNMO tidak berada di area Fry!!\n ");
            }
        }
        else if (isWordSame(currentWord, "BOIL"))
        {
            if (isAdjacent(BMO, 'B')) {
                COOKFOOD(&BMO, ListMkn, ListRsp, &Notif, "Boil");
            } else {
                printf("BNMO tidak berada di area Boil!!\n ");
            }
        }
        else if (isWordSame(currentWord, "MOVE"))
        {
            ADVWORD();
            Move(&BMO,currentWord, &isActionSucces);
            if (isActionSucces){
                min1menitAll(&DELIV(BMO),&INVENTORY(BMO),&FlagDelivDone,&FlagMakananEXP,&ListMakananEXP,&ListDeliveryDone);
                setExpDelivNotif(&Notif, ListMakananEXP, ListDeliveryDone);
                NextMin(&WAKTU(BMO));
            }
        }
        else if (isWordSame(currentWord, "WAIT"))
        {
            WAIT(&BMO, &FlagDelivDone, &FlagMakananEXP, &ListMakananEXP, &ListDeliveryDone);
            setExpDelivNotif(&Notif, ListMakananEXP, ListDeliveryDone);
        }
        else if (isWordSame(currentWord, "DELIVERY"))
        {
            DELIVERY(BMO);
        }
        else if (isWordSame(currentWord, "INVENTORY"))
        {
            INVENTORYMakanan(BMO);
        }
        else if (isWordSame(currentWord, "CATALOG"))
        {
            Catalogue(ListMkn);
        }
        else if (isWordSame(currentWord, "COOKBOOK"))
        {
            COOKBOOKFOOD(ListRsp, ListMkn);
        }
        else if (isWordSame(currentWord, "RECOMMENDATION"))
        {
            RECOMMENDATION(BMO, ListRsp, ListMkn);
        }
        else if (isWordSame(currentWord, "UNDO"))
        {
            undoGame(&BMO, InitSim, &Notif, &Undo, &Redo);
        }
        else if (isWordSame(currentWord, "REDO"))
        {
            redoGame(&BMO, &Notif, &Undo, &Redo);
        }
        else if (isWordSame(currentWord, "EXIT"))
        {
            isStartGame = false;
        }

        saveUndoRedoGame(BMO, InitSim, Notif, &Undo, &Redo);
        // Atur Notif
    }
    // until command/currentLine = exit

    // splash exit
    splashExitGame();
    // -program selesai-

    return 0;
}