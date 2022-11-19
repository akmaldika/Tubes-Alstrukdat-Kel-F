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

int main()
{
    /* KAMUS */
    ListResep ListRsp;
    ListMakanan ListMkn;
    ListMakanan ListMakananEXP;
    ListMakanan ListDeliveryDone;
    boolean FlagDelivDone;
    boolean FlagMakananEXP;
    boolean isStartGame;
    boolean MoveSucces;
    SIMULATOR BMO, InitSim;
    Stack Undo, Redo;
    boolean isBuydone;

    /* ALGORITMA */
    /* Inisiasi program */
    SetUpListMakanan(&ListMkn, "Config/Config_Makanan.txt");
    readListLR(&ListRsp, "Confg/Config_Resep.txt");
    CreateEmptyStack(&Undo);
    CreateEmptyStack(&Redo);

    CreateSim(&BMO, "Config/Config_Peta.txt");
    InitSim = BMO;
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
            BuyFood(&BMO, ListMkn, &isBuydone);
        }
        else if (isWordSame(currentWord, "MIX"))
        {
            //MIX
        }
        else if (isWordSame(currentWord, "CHOP"))
        {
            //CHOP
        }
        else if (isWordSame(currentWord, "FRY"))
        {
            // FRYFOOD(&BMO, ListMkn, ListRsp, ) //************* KURANG FALG
        }
        else if (isWordSame(currentWord, "BOIL"))
        {
            //BOIL
        }
        else if (isWordSame(currentWord, "MOVE"))
        {
            ADVWORD();
            Move(&BMO,currentWord,&MoveSucces);
            if (MoveSucces){
                min1menitAll(&DELIV(BMO),&INVENTORY(BMO),&FlagDelivDone,&FlagMakananEXP,&ListMkn,&ListDeliveryDone);
            }
        }
        else if (isWordSame(currentWord, "WAIT"))
        {
            //WAIT
            WAIT(&BMO, &FlagDelivDone, &FlagMakananEXP, &ListMakananEXP, &ListDeliveryDone);
        }
        else if (isWordSame(currentWord, "DELIVERY"))
        {
            //DELIVERY
            DELIVERY(BMO);
            min1menitAll(&DELIV(BMO),&INVENTORY(BMO),&FlagDelivDone,&FlagMakananEXP,&ListMkn,&ListDeliveryDone);
        }
        else if (isWordSame(currentWord, "INVENTORY"))
        {
            //INVENTORY
            INVENTORYMakanan(BMO);
            min1menitAll(&DELIV(BMO),&INVENTORY(BMO),&FlagDelivDone,&FlagMakananEXP,&ListMkn,&ListDeliveryDone);
        }
        else if (isWordSame(currentWord, "CATALOG"))
        {
            DisplayCatalog(ListMkn);
        }
        else if (isWordSame(currentWord, "COOKBOOK"))
        {
            //COOKBOOK
        }
        else if (isWordSame(currentWord, "RECOMMENDATION"))
        {
            //RECOMMENDATION
        }
        else if (isWordSame(currentWord, "UNDO"))
        {
            //UNDO
        }
        else if (isWordSame(currentWord, "REDO"))
        {
            //REDO
        }
        else if (isWordSame(currentWord, "EXIT"))
        {
            isStartGame = false;
        }

        // State baru masuk stak undo
        // Atur Notif
    }
    // until command/currentLine = exit

    // splash exit
    splashExitGame();
    // -program selesai-

    return 0;
}