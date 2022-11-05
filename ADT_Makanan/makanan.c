#include <stdio.h>
#include "boolean.h"
#include "makanan.h"

void CreateMakanan(MAKANAN *m, int id, char judul, TIME exp, TIME durasi, int loc)
{
        ID(*m) = id;
        judul(*m) = judul;
        exp(*m) = exp;
}

int getId(MAKANAN m)
{
        return ID(m);
}

char getJudul(MAKANAN m)
{
        return Judul(m);
}

TIME getExp(MAKANAN m)
{
        return exp(m);
}

TIME getDurasi(MAKANAN m)
{
        return durasi(m);
}
int getLoc(MAKANAN *m)
{
        return loc(*m);
}