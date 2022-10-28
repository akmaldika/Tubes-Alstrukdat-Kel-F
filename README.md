# Tubes-Alstrukdat-Kel-F
Tugas Besar IF2110 Algoritma &amp; Struktur Data

## Struktur folder pada repo tugas besar
<p>Setiap ADT memiliki 1 folder yang berisi file *.c *.h *.exe.
Satu folder dapat memuat lebih dari 1 file h asalkan masih berada pada topik ADT yang sama</p>

## Cara Compiling C program dengan bat (batch) file
<p>
Penggunaan beberapa header file pada "driverUji.c" mempersulit pengetikan pada C. Oleh karena itu, proses compile dapat menggunakan file .bat (batch) :
1. buat file {namaProgram}.bat, contoh : main.bat
2. Isi file tersebut dengan format :
    gcc {namaProgram.c} -o {namaprogram} {implementasiHeader}.c  && {namaProgram}
    contoh :
    gcc main.c -o main Tree.c List.c && main
3. Untuk meng-compile cukup ketik ./{filebat}, contoh : ./main.bat
4. Setiap penambahan header (yang ada implementasinya) dengan include tambahkan juga implementasi pada file bat
5. boolean.h tidak memiliki implementasi .c sehingga tidak perlu ditambah pada bat
</p>