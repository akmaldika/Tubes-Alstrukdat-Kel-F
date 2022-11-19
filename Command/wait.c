#include "../ADT_Queue/PrioQueue.h"
#include <stdio.h>


void WAIT(SIMULATOR *S, boolean *FlagDeliv, boolean *FlagExp, ListMakanan *LMakananEXP, ListMakanan *ListDelivDone)
{
    int hour, minute;
    ADVWORD();
    hour = isWordInt(currentWord);
    ADVWORD();
    minute = isWordInt(currentWord);
    waitCommand(&DELIV(*S), &INVENTORY(*S), FlagDeliv, FlagExp, LMakananEXP, ListDelivDone, hour, minute);
    // printf("menunggu %d  %d\n", hour, minute);
    NextNMin(&WAKTU(*S), (60*hour)+minute);
}

void DELIVERY(SIMULATOR S)
{
    PrintDelivery(DELIV(S));
}

void INVENTORYMakanan(SIMULATOR S){
    PrintPrioQueue(INVENTORY(S));
}
