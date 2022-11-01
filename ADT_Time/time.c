/* File: time.c */

#include <stdio.h>
#include "time.h"
#include "boolean.h"

/* ***************************************************************** */
/* KELOMPOK SETTER DAN GETTER */
/* ***************************************************************** */
int getD(TIME T)
{
    return Day(T);
}
int getH(TIME T)
{
    return Hour(T);
}
int getM(TIME T)
{
    return Minute(T);
}
void setD(TIME *T, int n)
{
    Day(*T) = n;
}
void setH(TIME *T, int n)
{
    Hour(*T) = n;
}
void setM(TIME *T, int n)
{
    Minute(*T) = n;
}

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid(int D, int H, int M)
{
    /* Mengirim true jika D, H, M, S dapat membentuk T yang valid */
    /* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
    // KAMUS LOKAL
    // ALGORITMA
    return (D >= 0 && H >= 0 && H < 24 && M >= 0 && M < 60); // && D <= 7
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime(TIME *T, int D, int H, int M)
{
    /* Membentuk sebuah TIME dari komponen-komponennya yang valid */
    /* Prekondisi : D, H, M, S valid untuk membentuk TIME */
    // KAMUS LOKAL
    // ALGORITMA
    Day(*T) = D;
    Hour(*T) = H;
    Minute(*T) = M;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void ReadTIME(TIME *T)
{
    /* I.S. : T tidak terdefinisi */
    /* F.S. : T terdefinisi dan merupakan jam yang valid */
    /* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
    /* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
    /* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
    dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
    /* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
    diulangi hingga didapatkan jam yang valid. */
    /* Contoh:
    60 3 4
    Jam tidak valid
    1 3 4
    --> akan terbentuk TIME <1,3,4> */
    // KAMUS LOKAL
    int d, h, m;
    // ALGORITMA

    // scanf("%d %d %d", &h, &m, &s);
    // while (!(IsTIMEValid(h, m, s)))
    // {
    //     printf("Jam tidak valid\n");
    //     scanf("%d %d %d", &h, &m, &s);
    // }

    CreateTime(T, d, h, m);
}

void DisplayTIME(TIME T)
{
    /* I.S. : T sembarang */
    /* F.S. : Nilai T ditulis dg format D:H:M */
    /* Proses : menulis nilai setiap komponen T ke layar dalam format D:H:M
    tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
    // KAMUS LOKAL
    // ALGORITMA
    printf("%d:%d:%d", Day(T), Hour(T), Minute(T));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToSec(TIME T)
{
    /* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
    /* Rumus : detik = 3600*HH + 60*MM + SS */
    /* Nilai maksimum = 3600*23+59*60+59 */
    // KAMUS LOKAL
    // ALGORITMA
    return (Day(T) * 86400 + 3600 * Hour(T) + 60 * Minute(T));
}
long TIMEToMin(TIME T)
{
    /* Mengirimkan besar dari time dalam satuan menit */
    return (Day(T) * 1440 + Hour(T) * 60 + Minute(T));
}
TIME MinToTIME(long N)
{
    /* Mengirimkan bentuk konversi dari menit menjadi TIME yang valid*/
    // KAMUS LOKAL
    TIME T;
    // ALGORITMA
    CreateTime(&T, N / 1440, ((N % 1440) / 60), ((N % 1440) % 60));
    return T;
}
TIME DetikToTIME(int d, long N)
{
    /* Mengirim  konversi detik ke TIME */
    /* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
    mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
    N1 = N mod 86400, baru N1 dikonversi menjadi TIME */
    // KAMUS LOKAL
    TIME T;
    // ALGORITMA
    d = N / 86400;
    N = (N % 86400);
    CreateTime(&T, d, (N / 3600), (N % 3600) / 60);
    return T;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1=T2, false jika tidak */
    // return (Hour(T1)==Hour(T2) && Minute(T1)==Minute(T2) && Second(T1)==Second(T2));
    // KAMUS LOKAL
    // ALGORITMA
    return (TIMEToMin(T1) == TIMEToMin(T2));
}
boolean TNEQ(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1 tidak sama dengan T2 */
    // KAMUS LOKAL
    // ALGORITMA
    return (TIMEToMin(T1) != TIMEToMin(T2));
}
boolean TLT(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1<T2, false jika tidak */
    // KAMUS LOKAL
    // ALGORITMA
    return (TIMEToMin(T1) < TIMEToMin(T2));
}
boolean TGT(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1>T2, false jika tidak */
    // KAMUS LOKAL
    // ALGORITMA
    return (TIMEToMin(T1) > TIMEToMin(T2)); //
}

TIME TNextNMin(TIME T, int N)
{
    // Mengirimkan time batu dengan penambahan N menit
    return MinToTIME(TIMEToMin(T) + N);
}

TIME TPrevNMin(TIME T, int N)
{
    // Mengirimkan time batu dengan pengurangan N menit
    return MinToTIME(TIMEToMin(T) - N);
}

TIME TNextMin(TIME T)
{
    // Mengirimkan time batu dengan Penambahan 1 menit
    return MinToTIME(TIMEToMin(T) + 1);
}
TIME TPrevMin(TIME T)
{
    // Mengirimkan time batu dengan Pengurangan 1 menit
    return MinToTIME(TIMEToMin(T) - 1);
}

void NextMin(TIME *T)
{
    /* I.S. Time terdefinisi */
    /* F.S. Time menjadi Time baru yang sudah ditambahkan 1 menit */
    /* Proses : Mengubah Time ke dalam bentuk menit lalu  ditambahkan 1 menit */
    *T = MinToTIME(TIMEToMin(*T) + 1);
}
void PrevMin(TIME *T)
{
    /* I.S. Time terdefinisi */
    /* F.S. Time menjadi Time baru yang sudah dikurangkan 1 menit */
    /* Proses : Mengubah Time ke dalam bentuk menit lalu dikurang 1 menit */
    *T = MinToTIME(TIMEToMin(*T) - 1);
}
void NextNMin(TIME *T, int N)
{
    /* I.S. Time terdefinisi */
    /* F.S. Time menjadi Time baru yang sudah ditambahkan N menit */
    /* Proses : Mengubah Time ke dalam bentuk menit lalu ditambahkan N */

    // int d = Day(*T);
    // if (m > 1440)
    // {
    //     d = (d + (m / 1440)) % 7;
    // }
    *T = MinToTIME(TIMEToMin(*T) + N);
}
void PrevNMin(TIME *T, int N)
{
    /* I.S. Time terdefinisi dan Time dikurang N valid membentuk Time (N < TIME yang sudah dijadikan menit)*/
    /* F.S. Time menjadi Time baru yang sudah dikurangkan N menit */
    /* Proses : Mengubah Time ke dalam bentuk menit lalu dikurangkan N */
    *T = MinToTIME(TIMEToMin(*T) - N);
}

/* *** Kelompok Operator Aritmetika *** */
long Durasi(TIME TAw, TIME TAkh)
{
    /* Mengirim TAkh-TAw dlm menit, dengan kalkulasi */
    // KAMUS LOKAL
    long d;
    // ALGORITMA
    d = TIMEToMin(TAkh) - TIMEToMin(TAw);
    if (d < 0)
    {
        d *= -1;
    }
    return d;
}
