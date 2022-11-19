#include <stdio.h>
#include "makanan.h"

/* ***** SELEKTOR ***** */
// #define IDs(m) (m).id
// #define Judul(m) (m).JudulMakanan
// #define Exp(m) (m).exp
// #define Deliv(m) (m).deliv
// #define Locate(m) (m).loc

/* **** KONSTRUKTOR **** */
void CreateMakanan(MAKANAN *m, IDEM id, NamaMakanan namaMakanan, TIME exp, TIME deliv, LokasiAksi loc)
{
        ID(*m) = id;
        Judul(*m) = namaMakanan;
        Exp(*m) = exp;
        Deliv(*m) = deliv;
        Locate(*m) = loc;
}

boolean isMakananSame(MAKANAN m1, MAKANAN m2)
{
        return ID(m1) == ID(m2);
}