#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* KAMUS LOKAL */
    Stack Undo, Redo;
    ElStackURType valIn, valOut;
    SIMULATOR BNMO;
    Word Nama1 = {"BMO", 3}, Nama2 = {"Adventurer", 10};

    CreateSim(&BNMO);

    CreateEmpty(&Undo);
    CreateEmpty(&Redo);
    
    // initial cek
    printf("Capacity = %d\n", CapStack(Undo));

    // cek predikat keadaan
    printf("isEmpty(Undo) = %s\n", IsEmpty(Undo) ? "true" : "false");
    printf("isFUll(Undo) = %s\n", IsFull(Undo) ? "true" : "false");

    // coba penuhin -> cek auto increase
    while (!IsFullStack(Undo))
    {
        setNamaSim(&BNMO, Nama1);
        Push(&Undo, BNMO);
    }
    printf("Capacity Full = %d\n", CapStack(Undo));
    setNamaSim(&BNMO, Nama2);
    Push(&Undo, BNMO);
    printf("Capacity Upgrade after add= %d\n", CapStack(Undo));
    
    // coba pop
    while (!IsEmptyStack(Undo))
    {
        Pop(&Undo, &BNMO);
        printf("Nama = %s\n", getNamaSim(BNMO));
    }
    printf("Capacity reset = %d\n", CapStack(Undo));

    return 0;
}