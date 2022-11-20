#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* KAMUS LOKAL */
    Stack Undo, Redo;
    ElStackURType valIn, valOut;
    ElStackURType valStack;
    Notifikasi Notif;
    SIMULATOR BNMO;
    int memocap;
    Word Nama1 = {"BMO", 3}, Nama2 = {"Adventurer", 10};


    CreateSim(&BNMO, "../Config/Config_Peta.txt");
    CreateNotifikasi(&Notif);

    valStack = MakeElStack(BNMO, Notif);

    CreateEmptyStack(&Undo);
        
    // initial cek
    printf("Capacity = %d\n", CapStack(Undo));
    printf("Top = %d\n", Top(Undo));

    // cek predikat keadaan
    printf("isEmpty(Undo) = %s\n", IsEmptyStack(Undo) ? "true" : "false");
    printf("isFull(Undo) = %s\n\n", IsFullStack(Undo) ? "true" : "false");

    // coba penuhin -> cek auto increase
    while (!IsFullStack(Undo))
    {
        setNamaSim(&BNMO, Nama1);
        valStack = MakeElStack(BNMO, Notif);
        Push(&Undo, valStack);
    }
    printf("Capacity Full = %d idx = %d\n", CapStack(Undo), Top(Undo));
    setNamaSim(&BNMO, Nama2);
    valStack = MakeElStack(BNMO, Notif);
    Push(&Undo, valStack);
    printf("Capacity Upgrade after add= %d idx = %d\n", CapStack(Undo), Top(Undo));
        while (!IsFullStack(Undo))
        {
            setNamaSim(&BNMO, Nama1);
            valStack = MakeElStack(BNMO, Notif);
            Push(&Undo, valStack);
        }
        printf("Capacity Full = %d idx = %d\n", CapStack(Undo), Top(Undo));
        setNamaSim(&BNMO, Nama2);
        valStack = MakeElStack(BNMO, Notif);
        Push(&Undo, valStack);
        printf("Capacity Upgrade after add= %d idx = %d\n\n", CapStack(Undo), Top(Undo));
    
    // coba pop
    while (!IsEmptyStack(Undo))
    {
        Pop(&Undo, &valStack);
    }
    printf("Capacity reset after empty= %d %d\n", CapStack(Undo), Top(Undo));

    return 0;
}