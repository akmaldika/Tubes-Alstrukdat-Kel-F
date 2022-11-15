#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main()
{
    /* KAMUS */
    ListResep ListRsp;

    /* ALGORITMA */
    /* Inisiasi program */
    SetUpListMakanan(); // variabel ListMkn as "Global Variable"
    readListLR(&ListRsp);

    // muncul splash

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