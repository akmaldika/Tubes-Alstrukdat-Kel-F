# Tubes-Alstrukdat-Kel-F
Tugas Besar IF2110 Algoritma &amp; Struktur Data

## Struktur folder pada repo tugas besar
Setiap ADT memiliki 1 folder yang berisi file *.c *.h *.exe.
Satu folder dapat memuat lebih dari 1 file h asalkan masih berada pada topik ADT yang sama.

## Cara Compiling C program dengan bat (batch) file
Penggunaan beberapa header file pada "driverUji.c" mempersulit pengetikan pada C. 
Oleh karena itu, proses compile dapat menggunakan file (batch) :
1. Buat file .bat

contoh: 
```
Program.bat
```

2. Isi file 

Dalam bat file, isi dengan format:
```
gcc Program.c -o Program HeaderImplement1.c ... && Program
```

3. Ketik pada terminal

Ketikan pada terminal
```PowerShell
.\Program.bat
```
Jika benar terminal akan menampilkan dan automatis menjalankan program:
```PowerShell
$ .\Program.bat
$ gcc Program.c -o Program HeaderImplement1.c ... && Program
```

4. Setiap penambahan header* dengan include tambahkan juga '.c' pada file bat

**boolean.h tidak memiliki implementasi '.c' sehingga tidak perlu ditambah pada bat*


Pembagian Tugas dan Statusnya

|Fitur Utama|                                     |Sub-Fitur|                        |Nama|                                   |NIM|            |Status Pengerjaan|
| --- |                                          | --- |                   | --- |                                           | --- |                   | --- | 
|ADT Sederhana|                                  |ADT Point|               |Muhammad Zaydan Athallah|                        |13521104|                |Selesai|
||                                               |ADT Makanan|             |Muhammad Zaydan Athallah|                        |13521104|                |Selesai|
||                                               |ADT Simulator|           |Muhammad Zaydan Athallah|                        |13521104|                |Selesai|
||                                               |ADT Waktu/Time|          |Nigel Sahl|                                      |13521043|                |Selesai|
|ADT List Statik|                                |ADT List Makanan|        |Akmal Mahardika Nurwahyu P|                      |13521070|                |Selesai|
||                                               |ADT List Resep|          |Fakhri Muhammad Mahendra|                        |13521045|                |Selesai|
|ADT Matriks|                                    |ADT Map|                 |Muhammad Zaydan Athallah|                        |13521104|                |Selesai|
|ADT Mesin Karakter dan Mesin Kata|              |ADT Mesin Karakter|      |Muhammad Equilibrie Fajria|                      |13521047|                |Selesai|
||                                               |ADT Mesin Kata|          |Muhammad Equilibrie Fajria|                      |13521047|                |Selesai|
||                                               |ADT String|              |Muhammad Equilibrie Fajria|                      |13521047|                |Selesai|
|ADT Queue|                                      |ADT PrioQueue|           |Nigel Sahl|                                      |13521043|                |Selesai|
|ADT Stack|                                      |ADT Stack Undo Redo|     |Akmal Mahardika Nurwahyu P|                      |13521070|                |Selesai|
|ADT Tree|                                       |ADT Resep|               |Fakhri Muhammad Mahendra|                        |13521045|                |Selesai|
|Waktu Pengolahan Makanan|                       |         |               |Nigel Sahl & Fakhri Muhammad Mahendra|           |13521043 & 13521045|     |Selesai|
|Rekomendasi Makanan|                            |         |               |Fakhri Muhammad Mahendra|                        |13521045|                |Selesai|
