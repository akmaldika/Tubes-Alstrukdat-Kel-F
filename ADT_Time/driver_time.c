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

    printf("\n a : ");
    NextMin(&a);
    DisplayTIME(a);
    printf("\n");
    PrevMin(&a);
    DisplayTIME(a);
    printf("\n");
    PrevNMin(&a, 5);
    DisplayTIME(a);
    printf("\n");
    NextNMin(&a, 5);
    DisplayTIME(a);
    printf("\n");
    setD(&a, 10);
    DisplayTIME(a);
    printf("\n");

    NextMin(&a);
    printf("Next a: ");
    DisplayTIME(a);
    printf("\n");
    PrevMin(&b);
    printf("Prev b: ");
    DisplayTIME(b);
    printf("\n");

    return 0;
}