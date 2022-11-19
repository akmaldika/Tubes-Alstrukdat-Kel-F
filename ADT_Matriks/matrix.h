/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef MATRIX_H
#define MATRIX_H

#include "boolean.h"
#include "../ADT_MesinKata/mesinkarakter.h"
#include "../ADT_MesinKata/mesinkata.h"
#include "../ADT_MesinKata/string.h"

/* Ukuran maksimum baris dan kolom */
#define ROW_CAP 100
#define COL_CAP 100
#define brsmin 0
#define kolmin 0

typedef int IdxType; /* Index baris, kolom */
typedef char ElType;
typedef struct
{
   ElType mem[ROW_CAP][COL_CAP];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m);
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT(M, i, j) (M).mem[(i)][(j)]


Matrix MapMatrix(char *filename);

void displayMap(Matrix m);
/* Merubah '#' dalam matrix menjadi ' ' kemudian menampilkan matrix */

void MoveNorth(Matrix *m,boolean *sukses);
/*Memindahkan 'S' sesuai arah fungsi sebanyak 1 index */
void MoveSouth(Matrix *m,boolean *sukses);
/*Memindahkan 'S' sesuai arah fungsi sebanyak 1 index */
void MoveWest(Matrix *m,boolean *sukses);
/*Memindahkan 'S' sesuai arah fungsi sebanyak 1 index */
void MoveEast(Matrix *m,boolean *sukses);
/*Memindahkan 'S' sesuai arah fungsi sebanyak 1 index */

/* *** Selektor "Dunia Matrix" *** */

Matrix getidx(Matrix m, ElType val);
/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m);
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxCol(Matrix m);
/* Mengirimkan Index kolom terbesar m */





void displayMatrix(Matrix m);
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

#endif