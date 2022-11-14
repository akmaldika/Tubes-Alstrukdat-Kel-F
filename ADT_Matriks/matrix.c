#include "boolean.h"
#include <stdio.h>
#include "matrix.h"
#include <math.h>
#include "mesinkata.h"
#include "string.h"
#include "mesinkata.c"
#include "mesinkarakter.c"
#include "mesinkarakter.h"
#include "string.c"

//Muhammad Zaydan A
//13521104


/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m){
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atawords terbentuk */

   // ALGORITMA
   ROW_EFF(*m) = nRows;
   COL_EFF(*m) = nCols;
}

Matrix MapMatrix(){
    /* Membuat MATRIKS Map berukuran N x M dengan */
    /* sisi terluarnya adalah # yaitu pagar, sisi dalamnya adalah . yaitu lahan */
    Matrix Map;
    Matrix RetMap;
    str f;
    int row, col, N, M;
    boolean first = true;
    int i;
    int j = 0;
    int cnt = 0;
    scanf("%s", &f);
        
        
        STARTLINE(f);
        STARTWORD();
        row = wordToInt(currentWord);
        printf(" ");
        ADVWORD();
        col = wordToInt(currentWord);
        printf("\n"); 
        createMatrix(row,col,&Map);
        i=0;
        j=0;       
        while (!EOP) {
          ADVLINE();
          for (j=0;j<col;j++){
            ELMT(Map,i,j)=currentLine.Tabword[j];
          }
            i++;
            printf("\n");
        }
      createMatrix(row+2,col+2,&RetMap);
      for (int i = brsmin; i <= getLastIdxRow(RetMap); i++){
         for (int j = kolmin; j <= getLastIdxCol(RetMap); j++){
            ELMT(RetMap, i, j) = (i == brsmin || i == getLastIdxRow(RetMap) || j == kolmin || j == getLastIdxCol(RetMap) ) 
                ? '*'
                : ELMT(Map,i-1,j-1);
        }
      }


      return RetMap;
}


void displayMap(Matrix m){
   int i;
   int j;
      for (int i = brsmin; i <= getLastIdxRow(m); i++){
         for (int j = kolmin; j <= getLastIdxCol(m); j++){
            if (ELMT(m,i,j)=='#'){
               ELMT(m,i,j)=' ';
            }

        }
      }

   displayMatrix(m);

}  






void MoveEast(Matrix *m){
   int x,y;
   Matrix idx;
   idx=getidx(*m,'S');
   y=ELMT(idx,0,0);
   x=ELMT(idx,0,1);
   // printf("%d\n",y+1);
   // printf("%d\n",x+1);

   if (ELMT(*m,y,x+1)=='#'){
      ElType temp=ELMT(*m,y,x+1);
      
      ELMT(*m,y,x+1)=ELMT(*m,y,x);
      ELMT(*m,y,x)=temp;

   }else{
      printf("gakbisa");
   }


   

}

void MoveWest(Matrix *m){
   int x,y;
   Matrix idx;
   idx=getidx(*m,'S');
   y=ELMT(idx,0,0);
   x=ELMT(idx,0,1);
   // printf("%d\n",y+1);
   // printf("%d\n",x+1);

   if (ELMT(*m,y,x-1)=='#'){
      ElType temp=ELMT(*m,y,x-1);
      
      ELMT(*m,y,x-1)=ELMT(*m,y,x);
      ELMT(*m,y,x)=temp;

   }else{
      printf("gakbisa");
   }

}

void MoveNorth(Matrix *m){
   int x,y;
   Matrix idx;
   idx=getidx(*m,'S');
   y=ELMT(idx,0,0);
   x=ELMT(idx,0,1);
   // printf("%d\n",y+1);
   // printf("%d\n",x+1);

   if (ELMT(*m,y-1,x)=='#'){
      ElType temp=ELMT(*m,y-1,x);
      
      ELMT(*m,y-1,x)=ELMT(*m,y,x);
      ELMT(*m,y,x)=temp;

      
   }else{
      printf("gakbisa");
   }

}

void MoveSouth(Matrix *m){
   int x,y;
   Matrix idx;
   idx=getidx(*m,'S');
   y=ELMT(idx,0,0);
   x=ELMT(idx,0,1);
   // printf("%d\n",y+1);
   // printf("%d\n",x+1);

   // if (ELMT(*m,y+1,x)=='*'||ELMT(*m,y+1,x)=='M'||ELMT(*m,y+1,x)=='T'||ELMT(*m,y+1,x)=='C'||ELMT(*m,y+1,x)=='F'||ELMT(*m,y+1,x)=='B'||ELMT(*m,y+1,x)=='X'){
   //    printf("South MENTOK\n");
   // }
   if (ELMT(*m,y+1,x)=='#'){
      ElType temp=ELMT(*m,y+1,x);
      
      ELMT(*m,y+1,x)=ELMT(*m,y,x);
      ELMT(*m,y,x)=temp;

   }else{
      printf("gakbisa");
   }

}

Matrix getidx(Matrix m, ElType val){
   Matrix temp;
   createMatrix(1,2,&temp);

    // Rows
    for (int i = 0; i < getLastIdxRow(m); i++) {
 
        // Columns
        for (int j = 0; j < getLastIdxCol(m); j++) {
 
            // If keyString is found
            if (ELMT(m,i,j) == val) {
               ELMT(temp,0,0)=i;
               ELMT(temp,0,1)=j;
            }
        }
    }
 
    // If keyString is not found
    // then -1 is returned
    return temp;
}   



/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j){
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

   // ALGORITMA
   return (0 <= i && i < ROW_CAP) && (0 <= j && j < COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m){
/* Mengirimkan Index baris terbesar m */

   // ALGORITMA
   return (ROW_EFF(m) - 1);
}

IdxType getLastIdxCol(Matrix m){
/* Mengirimkan Index kolom terbesar m */

   // ALGORITMA
   return (COL_EFF(m) - 1);
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j){
/* Mengirimkan true jika i, j adalah Index efektif bagi m */

   // ALGORITMA
   return (0 <= i && i < ROW_EFF(m)) && (0 <= j && j < COL_EFF(m));
}

ElType getElmtDiagonal(Matrix m, IdxType i){
/* Mengirimkan elemen m(i,i) */

   // AGORITMA
   return (ELMT(m, i, i));  
}


void copyMatrix(Matrix mIn, Matrix *mOut){
/* Melakukan assignment mOut <- mIn */

   // ALGORITMA
   *mOut = mIn;
}


void readMatrix(Matrix *m, int nRow, int nCol){
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/

   // KAMUS LOKAL
   int i, j;

   // ALGORITMA
   createMatrix(nRow, nCol, m);
   for (i = 0; i < nRow; i ++) {
      for (j = 0; j < nCol; j ++) {
         scanf("%d", &ELMT(*m, i, j));
      }
   }
}

void displayMatrix(Matrix m){
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

   // KAMUS LOKAL
   int i, j;

   // ALGORITMA
   for (i = 0; i < ROW_EFF(m); i ++) {
      for (j = 0; j < COL_EFF(m); j ++) {
         if (j == 0) {
            printf("%c", ELMT(m, i, j));
         } else {
            printf("  %c", ELMT(m, i, j));
         }
      }
      printf("\n");
   }
}






int countElmt(Matrix m){
/* Mengirimkan banyaknya elemen m */

   // ALGORITMA
   return (ROW_EFF(m) * COL_EFF(m));
}



