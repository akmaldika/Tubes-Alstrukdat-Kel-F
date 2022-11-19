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

    // cek predikat keadaan
    printf("isEmpty(Undo) = %s\n", IsEmptyStack(Undo) ? "true" : "false");
    printf("isFUll(Undo) = %s\n", IsFullStack(Undo) ? "true" : "false");

    // coba penuhin -> cek auto increase
    while (!IsFullStack(Undo))
    {
        setNamaSim(&BNMO, Nama1);
        valStack = MakeElStack(BNMO, Notif);
        Push(&Undo, valStack);
    }
    printf("Capacity Full = %d\n", CapStack(Undo));
    setNamaSim(&BNMO, Nama2);
    valStack = MakeElStack(BNMO, Notif);
    Push(&Undo, valStack);
    printf("Capacity Upgrade after add= %d\n", CapStack(Undo));
    while (!IsFullStack(Undo))
    {
        setNamaSim(&BNMO, Nama1);
        valStack = MakeElStack(BNMO, Notif);
        Push(&Undo, valStack);
    }
    printf("Capacity Full = %d\n", CapStack(Undo));
    setNamaSim(&BNMO, Nama2);
    valStack = MakeElStack(BNMO, Notif);
    Push(&Undo, valStack);
    printf("Capacity Upgrade after add= %d\n", CapStack(Undo));
    
    // coba pop
    memocap = CapStack(Undo);
    while (!IsEmptyStack(Undo))
    {
        Pop(&Undo, &valStack);
        if(memocap != CapStack(Undo))
        {
            printf("Capacity shrink after pop = %d\nand idx Top is at = %d", Capstack(Undo)), Top(Undo);
            memocap = CapStack(Undo);
        }
    }
    printf("Capacity reset = %d\n", CapStack(Undo));

    return 0;
}