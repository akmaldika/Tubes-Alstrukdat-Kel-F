#include <stdio.h>
#include "makanan.h"

<<<<<<< HEAD
void CreateMakanan(MAKANAN *m, int id, char judul, __TIME__ exp,__TIME__ durasi,int loc){
        ID(*m)= id;
        judul(*m)= judul;
        exp(*m)= exp;
=======
/* ***** SELEKTOR ***** */
// #define IDs(m) (m).id
// #define Judul(m) (m).JudulMakanan
// #define Exp(m) (m).exp
// #define Deliv(m) (m).deliv
// #define Locate(m) (m).loc
>>>>>>> 7def3875f18419c7c2c8f6be366e66beef125527

/* **** KONSTRUKTOR **** */
void CreateMakanan(MAKANAN *m, IDEM id, NamaMakanan namaMakanan, TIME exp, TIME deliv, LokasiAksi loc)
{
        ID(*m) = id;
        Judul(*m) = namaMakanan;
        Exp(*m) = exp;
        Deliv(*m) = deliv;
        Locate(*m) = loc;
}