#include "../ADT_Queue/PrioQueue.h"
#include <stdio.h>

int hour, minute;

void WAIT(PrioQueue *Qdeliv, PrioQueue *Q, boolean *FlagDeliv, boolean *FlagExp, ListMakanan *LMakananEXP, ListMakanan *ListDelivDone)
{
    ADVWORD();
    hour = isWordInt(currentWord);
    ADVWORD();
    minute = isWordInt(currentWord);
    waitCommand(Qdeliv, Q, FlagDeliv, FlagExp, LMakananEXP, ListDelivDone, hour, minute);
    printf("menunggu %d  %d\n", hour, minute);
    ADVLINE();
}

void DELIVERY(PrioQueue Q)
{
    PrintDelivery(Q);
    ADVLINE();
}

void INVENTORYMakanan(PrioQueue Q){
    PrintPrioQueue(Q);
    ADVLINE();
}
