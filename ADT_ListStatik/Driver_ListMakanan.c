#include "ListMakanan.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    SetUpListMakanan();

    DisplayCatalog(ListMkn);
    printf("Banyak Makanan = %d (Gak masuk display)\n", LengthLM(ListMkn));
    printf("\n");
    printf("\nMisal User : BUY saat adjecent\n");
    DisplayBuyAbleLM(ListMkn);
    printf("\nMisal diketikan command FRY saat adjecent\n");
    DisplayActionAbleLM(ListMkn, "Fry");

}