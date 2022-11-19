#include "../ADT_Queue/PrioQueue.h"
#include <stdio.h>

int hour, minute;

void WAIT(SIMULATOR *S, boolean *FlagDeliv, boolean *FlagExp, ListMakanan *LMakananEXP, ListMakanan *ListDelivDone)
{
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
