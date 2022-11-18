#ifndef _Exit_h_
#define _Exit_h_

#include <stdlib.h>
#include <stdio.h>
#include "../ADT_Stack/Stack.h"
#include "../ADT_Queue/PrioQueue.h"

void exitGame(PrioQueue *inventory, PrioQueue *delivery, Stack *undo, Stack *redo);
/* I.S. inventori, delivery, undo, dan redo terdefinisi */
/* F.S. semua dikembalikan ke sistem */

#endif

void exitGame(PrioQueue *inventory, PrioQueue *delivery, Stack *undo, Stack *redo)
{
    delAllPriqueue(delivery);
    delAllPriqueue(inventory);
    delAllStack(undo);
    delAllStack(redo);
}