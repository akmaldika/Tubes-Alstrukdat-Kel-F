#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "Command/splash.c"
#include "Command/help.c"
#include "Command/Exit.c"
#include "Command/commandError.c"
#include "Command/Cookbook.c"
#include "Command/Move.c"
#include "Command/Fryfood.c"
#include "Command/wait.c"
#include "Command/buy.c"
#include "Command/UndoRedo.c"

int main()
{
    /* KAMUS */
    ListResep ListRsp;
    ListMakanan ListMkn, LM;
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
                min1menitAll(&DELIV(BMO), &INVENTORY(BMO), &FlagDelivDone, &FlagMakananEXP, &LM, &ListDeliveryDone);
            }
        }
        else if (isWordSame(currentWord, "MIX"))
        {
            // MIX
        }
        else if (isWordSame(currentWord, "CHOP"))
        {
            // CHOP
        }
        else if (isWordSame(currentWord, "FRY"))
        {
            // FRYFOOD(&BMO, ListMkn, ListRsp, ) //************* KURANG FALG
        }
        else if (isWordSame(currentWord, "BOIL"))
        {
            // BOIL
        }
        else if (isWordSame(currentWord, "MOVE"))
        {
            ADVWORD();
            Move(&BMO, currentWord, &isActionSucces);
            if (isActionSucces)
            {
                min1menitAll(&DELIV(BMO), &INVENTORY(BMO), &FlagDelivDone, &FlagMakananEXP, &LM, &ListDeliveryDone);
            }
        }
        else if (isWordSame(currentWord, "WAIT"))
        {
            // WAIT
            WAIT(&BMO, &FlagDelivDone, &FlagMakananEXP, &ListMakananEXP, &ListDeliveryDone);
        }
        else if (isWordSame(currentWord, "DELIVERY"))
        {
            // DELIVERY
            DELIVERY(BMO);
        }
        else if (isWordSame(currentWord, "INVENTORY"))
        {
            // INVENTORY
            INVENTORYMakanan(BMO);
        }
        else if (isWordSame(currentWord, "CATALOG"))
        {
            DisplayCatalog(ListMkn);
        }
        else if (isWordSame(currentWord, "COOKBOOK"))
        {
            // COOKBOOK
        }
        else if (isWordSame(currentWord, "RECOMMENDATION"))
        {
            // RECOMMENDATION
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