#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main()
{
    /* KAMUS */
    ListResep ListRsp;
    ListMakanan ListMkn;

    /* ALGORITMA */
    /* Inisiasi program */
    SetUpListMakanan(&ListMkn, "Config/Config_Makanan.txt");
    readListLR(&ListRsp, "Confg/Config_Resep.txt");

    // splashInitGame();
    
    STARTCOMMAND(); // currentWord

    // Cek Start command error mcna nerima START sam EXIT
        // loop sampai benar

    // while bukan exit masuk loop
        // STARTCOMMAND semua yang diterima kecuali START
        // cek benar salah 
            // loop sampai benar
            // cekcommand()
        
        // if else function 
            // if command == <command>
                // fungsi/prosedur command>

            // else if
                // ...
            // ...

            // if else.
        
        // ATUR NOTIF.
    // until command = exit

    // splash exit
    // -program selesai-

    return 0;
}