/* Driver untuk ADT time */

#include <stdio.h>
#include "time.h" //

int main()
{
    TIME a, b;
    CreateTime(&a, 1, 5, 30);
    CreateTime(&b, 0, 0, 5);
    printf("a : ");
    DisplayTIME(a);
    printf("\n");
    printf("b : ");
    DisplayTIME(b);
    printf("\n");

    printf("\nNext min a : ");
    NextMin(&a);
    DisplayTIME(a);

    printf("\n");
    printf("\nPrev min a : ");
    PrevMin(&a);
    DisplayTIME(a);

    printf("\n");
    printf("\nPrev 5 min a : ");
    PrevNMin(&a, 5);
    DisplayTIME(a);

    printf("\n");
    printf("\nNext 5 min a : ");
    NextNMin(&a, 5);
    DisplayTIME(a);

    printf("\n");
    printf("\nSet D 10 a : ");
    setD(&a, 10);
    DisplayTIMEk(a);

    printf("\n\n");
    printf("a : ");
    DisplayTIME(a);
    printf("\n");
    printf("b : ");
    DisplayTIME(b);
    printf("\n");
    if (TGT(a, b))
    {
        printf("a is greater than b");
    }
    else
    {
        printf("a is not greater than b");
    }

    printf("\n\n");

    return 0;
}