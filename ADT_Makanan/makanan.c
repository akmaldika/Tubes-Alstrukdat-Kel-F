#include <stdio.h>
#include "makanan.h"

/* ***** SELEKTOR ***** */
// #define IDs(m) (m).id
// #define Judul(m) (m).JudulMakanan
// #define Exp(m) (m).exp
// #define TimeAct(m) (m).TAction
// #define Locate(m) (m).loc

/* **** KONSTRUKTOR **** */
void CreateMakanan(MAKANAN *m, IDEM id, NamaMakanan namaMakanan, TIME exp, TIME TAction, LokasiAksi loc)
{
        ID(*m) = id;
        Judul(*m) = namaMakanan;
        Exp(*m) = exp;
        TimeAct(*m) = TAction;
        Locate(*m) = loc;
}

boolean isMakananSame(MAKANAN m1, MAKANAN m2)
{
        return ID(m1) == ID(m2);
}