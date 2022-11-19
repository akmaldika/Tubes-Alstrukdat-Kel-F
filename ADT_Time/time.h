/* File: time.h */

#ifndef TIME_H
#define TIME_H

#include "boolean.h"

/* *** Definisi TYPE TIME <H:M:S> *** */
typedef struct
{
   int D; /* integer [1..]  */
   int H; /* integer [0..23] */
   int M; /* integer [0..59] */
} TIME;

/* *** Notasi Akses: selektor TIME *** */
#define Day(T) (T).D
#define Hour(T) (T).H
#define Minute(T) (T).M

/* ***************************************************************** */
/* KELOMPOK SETTER DAN GETTER */
/* ***************************************************************** */
int getD(TIME T);
int getH(TIME T);
int getM(TIME T);

void setD(TIME *T, int n);
void setH(TIME *T, int n);
void setM(TIME *T, int n);

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */

boolean IsTIMEValid(int D, int H, int M);
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime(TIME *T, int D, int H, int M);
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : H, M, S valid untuk membentuk TIME */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */

void DisplayTIMEFull(TIME T);
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format D:H:M */
/* Proses : menulis nilai setiap komponen T ke layar dalam format D:H:M
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/

void DisplayTIME(TIME T);
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format D:H:M */
/* Proses : menulis nilai setiap komponen T ke layar dalam format D.H.M
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/

void DisplayTIMEk(TIME T);
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format D,H,M dengan tambahan "jam menit detik" */
/* Proses : menulis nilai setiap komponen T ke layar dalam format D, H, M dengan tambahan keterangan satuannya yaitu jam, menit, dan detik */

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */

long TIMEToMin(TIME T);
/* Mengirimkan besar dari time dalam satuan menit */
TIME MinToTIME(long N);
/* Mengirimkan bentuk konversi dari menit menjadi TIME yang valid*/

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ(TIME T1, TIME T2);
/* Mengirimkan true jika T1=T2, false jika tidak */
boolean TNEQ(TIME T1, TIME T2);
/* Mengirimkan true jika T1 tidak sama dengan T2 */
boolean TLT(TIME T1, TIME T2);
/* Mengirimkan true jika T1<T2, false jika tidak */
boolean TGT(TIME T1, TIME T2);
/* Mengirimkan true jika T1>T2, false jika tidak */

/* *** Operator aritmatika TIME *** */
// TIME NextDetik(TIME T);
// /* Mengirim 1 detik setelah T dalam bentuk TIME */
// TIME NextNDetik(TIME T, int N);
// /* Mengirim N detik setelah T dalam bentuk TIME */
// TIME PrevDetik(TIME T);
// /* Mengirim 1 detik sebelum T dalam bentuk TIME */
// TIME PrevNDetik(TIME T, int N);
// /* Mengirim N detik sebelum T dalam bentuk TIME */
TIME TNextNMin(TIME T, int N);
// Mengirimkan time batu dengan Penambahan N menit
TIME TPrevNMin(TIME T, int N);
// Mengirimkan time batu dengan pengurangan N menit
TIME TNextMin(TIME T);
// Mengirimkan time batu dengan Penambahan 1 menit
TIME TPrevMin(TIME T);
// Mengirimkan time batu dengan Pengurangan 1 menit

void NextMin(TIME *T);
/* I.S. Time terdefinisi */
/* F.S. Time menjadi Time baru yang sudah ditambahkan 1 menit */
/* Proses : Mengubah Time ke dalam bentuk menit lalu  ditambahkan 1 menit */

void PrevMin(TIME *T);
/* I.S. Time terdefinisi */
/* F.S. Time menjadi Time baru yang sudah dikurangkan 1 menit */
/* Proses : Mengubah Time ke dalam bentuk menit lalu dikurang 1 menit */

void NextNMin(TIME *T, int N);
/* I.S. Time terdefinisi */
/* F.S. Time menjadi Time baru yang sudah ditambahkan N menit */
/* Proses : Mengubah Time ke dalam bentuk menit lalu ditambahkan N */
void PrevNMin(TIME *T, int N);
/* I.S. Time terdefinisi dan Time dikurang N valid membentuk Time (N < TIME yang sudah dijadikan menit)*/
/* F.S. Time menjadi Time baru yang sudah dikurangkan N menit */
/* Proses : Mengubah Time ke dalam bentuk menit lalu dikurangkan N */

/* *** Kelompok Operator Aritmetika *** */
long Duration(TIME TAw, TIME TAkh);
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */

boolean isTimeSame(TIME T1, TIME T2);
/* Mengirimkan true jika t1 dan t2 meemiliki waktu yang sama */

#endif