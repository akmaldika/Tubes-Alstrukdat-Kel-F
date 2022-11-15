#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* KAMUS LOKAL */
    Stack Undo, Redo;
    ElStackURType valIn, valOut;

    CreateEmpty(&Undo);
    CreateEmpty(&Redo);
    
    // initial cek
    printf("Capacity = %d\n", CapStack(Undo));

    // cek predikat keadaan
    printf("isEmpty(Undo) = %s\n", IsEmpty(Undo) ? "true" : "false");
    printf("isFUll(Undo) = %s\n", IsFull(Undo) ? "true" : "false");

    Push(&Undo, );
    printf("\n");
    Pop(&Undo, );
    Push(&Redo, );
    printf("\n");



    return 0;
}