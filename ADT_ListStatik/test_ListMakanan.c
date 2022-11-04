#include "ListMakanan.h"

/// @brief 
/// @return 
int main()
{
    ListMakanan lm;
    int i, j, k;

    CreateListMakanan(&lm);

    SetUpListMakanan(&lm,"../Config/Config_Makanan.txt");

    for(i = 0; i < LengthLM(lm); i++)
    {
        printf("ID\t\t = %d\n", GetIdMkn(lm, i));
        printf("Nama\t\t = %s\n", GetNamaMkn(lm, i));
        printf("Kedaluarsa\t = %s\n", GetKadaluarsaMkn(lm, i));
        printf("Action\t\t = %s\n", GetActionLocMkn(lm, i));
        printf("DelivTime\t = %s\n", GetDeliverTimeMkn(lm, i));
    }

    // Asumsi Simulator adjecent dengan B : tempat BUY
    // input user : BUY
    DisplayBuyAbleLM(lm);

    // Asumsi Simulator adjecent dengan F : tempat FRY
    // input user : FRY
    DisplayActionAbleLM(lm, "FRY");

    // Asumsi input user : CATALOG
    DisplayCatalog(lm);
}