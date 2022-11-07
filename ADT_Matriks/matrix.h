/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef MATRIX_H
#define MATRIX_H

#include "boolean.h"

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


Matrix MapMatrix();

void displayMap(Matrix m);
/* Merubah '#' dalam matrix menjadi ' ' kemudian menampilkan matrix */

void MoveEast(Matrix *m);

void MoveWest(Matrix *m);

void MoveNorth(Matrix *m);

void MoveSouth(Matrix *m);


/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j);
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
Matrix getidx(Matrix m, ElType val);
/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m);
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxCol(Matrix m);
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, IdxType i, IdxType j);
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, IdxType i);
/* Mengirimkan elemen m(i,i) */
IdxType GetFirstIdxBrs (Matrix M);
    /* Mengirimkan indeks baris terkecil M */

IdxType GetFirstIdxKol (Matrix M);
    /* Mengirimkan indeks kolom terkecil M */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut);
/* Melakukan assignment mOut <- mIn */


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




/* ********** Operasi lain ********** */
int countElmt(Matrix m);
/* Mengirimkan banyaknya elemen m */




#endif