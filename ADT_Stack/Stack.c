/* File : Stack.c */

#include "Stack.h"

void CreateEmpty(Stack *S)
{
    Top(*S) = Nil;
}

boolean IsEmpty(Stack S)
{
    return (Top(S) == Nil);
}

boolean IsFull(Stack S)
{
    return (Top(S) == MaxElStack);
}

void Push(Stack * S, ElStackURType X)
{
    if (Top(*S) >= MaxElStack)
    {
        CreateEmpty(&STemp);
        ReqnumCopyStack(*S, STemp, MaxElStack/2);
        *S = STemp;
        Top(*S)++;
    }

    Top(*S)++;
    InfoTop(*S) = X;
}

void Pop(Stack * S, ElStackURType* X)
{
    *X = InfoTop(*S);
    Top(*S)--;
}