#ifndef HELP_h
#define HELP_h

#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"

void helpStartGame()
{
    /* I.S. currentWord {command}= "HELP" dan belum memulai game {belum "START"} */
    /* F.S. Menampilkan command yang dapat dipakai sebelum Start Game */
    printf("Daftar command yang tersedia:\n");
    printf("HELP\t- Menampilkan daftar command yang tersedia\n");
    printf("START\t- Memulai game\n");
    printf("EXIT\t- Keluar dari game\n");
}

void helpInGame()
{
    /* I.S. currentWord {command} = "HELP" dan user sudah masuk dalah game {sudah pernah START} */
    /* F.S. menampilkan command yang dapat dipakai di dalam game */
    printf("Daftar command yang tersedia:\n");
    printf("HELP\t- Menampilkan daftar command yang tersedia\n");
    printf("\nCommand memasak:\n");
    printf("BUY\t- Membeli makanan dari toko\n");
    printf("MIX\t- Mencampurkan dua/lebih bahan makanan\n");
    printf("CHOP\t- Memotong bahan makanan menjadi potongan-potongan kecil\n");
    printf("FRY\t- Menggoreng bahan makanan\n");
    printf("BOIL\t- Merebus bahan makanan\n");
    printf("* Dekatkan Simulator ke lokasi memasak tersebut untuk melakukan aksi!\n");
    printf("\nCommand pergerakan:\n");
    printf("MOVE X\t- bergerak kearah yang dituju \n");
    printf("\t  X : NORTH, EAST, WEST, SOUTH\n");
    printf("WAIT X Y - Menunggu X jam Y menit\n");
    printf("\nCommand lain:\n");
    printf("DELIVERY- Menampilkan daftar barang yang dipesan\n");
    printf("INVENTORY - Menampilkan daftar bahan makanan yang dimiliki\n");
    printf("CATALOG\t- Menampilkan daftar makanan yang tersedia pada aplikasi\n");
    printf("COOKBOOK - Menampilkan daftar resep yang tersedia pada aplikasi\n");
    printf("RECOMMENDATION - Menampilkan resep yang dapat dibuat\n");
    printf("UNDO\t- Kembali ke kondisi sebelumnya\n");
    printf("REDO\t- Kembali ke kondisi setelah UNDO\n");
    printf("EXIT\t- Keluar dari game\n");        
}

#endif