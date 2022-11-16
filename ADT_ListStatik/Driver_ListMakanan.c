#include "ListMakanan.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    ListMakanan TEMP;

    CreateListMakanan(&TEMP);

    SetUpListMakanan(&TEMP, "../Config/Config_Makanan.txt");

    DisplayCatalog(TEMP);
    printf("Banyak Makanan = %d (Gak masuk display)\n", LengthLM(TEMP));
    printf("\n");
    printf("\nMisal User : BUY saat adjecent\n");
    DisplayBuyAbleLM(TEMP);
    printf("\nMisal diketikan command FRY saat adjecent\n");
    DisplayActionAbleLM(TEMP, "Fry");

}