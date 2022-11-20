#ifndef CommandGame_h
#define CommandGame_h

#include "../library.h"
#include "../ADT_Stack/stack.h"

void splashInitGame();
/* I.S. Sembarang */
/* F.S. Menampilkan splash start game */

void splashExitGame();
/* I.S. Sembarang */
/* F.S. Menampilkan splash exit game */

void helpStartGame();
/* I.S. currentWord {command}= "HELP" dan belum memulai game {belum "START"} */
/* F.S. Menampilkan command yang dapat dipakai sebelum Start Game */

void helpInGame();
/* I.S. currentWord {command} = "HELP" dan user sudah masuk dalah game {sudah pernah START} */
/* F.S. menampilkan command yang dapat dipakai di dalam game */

void exitGame(PrioQueue *inventory, PrioQueue *delivery, Stack *undo, Stack *redo);
/* I.S. inventori, delivery, undo, dan redo terdefinisi */
/* F.S. semua dikembalikan ke sistem */

void commandStartError();
/* I.S. : currrentLine dan currentWord sudah didapatkan */
/* F.S. : currentWord / currentLine untuk command yang benar didapatkan */
/* currentWord adalah kata pertama dari currentLine */
/* ketika currentLine/currentWord tidak dikenali untuk start game */
/* memunculkan pesna error dan meminta input kembali sesuai kondisi */

void commandInGameError();
/* I.S. : currrentLine dan currentWord sudah didapatkan */
/* F.S. : currentWord / currentLine untuk command yang benar didapatkan*/
/* currentWord adalah kata pertama dari currentLine */
/* currentLine/currentWord tidak dikenali untuk start game*/
/* memunculkan pesna error dan meminta input kembali sesuai kondisi */

void COOKBOOKFOOD(ListResep lr, ListMakanan lm);

void RECOMMENDATION(SIMULATOR s, ListResep lr, ListMakanan lm);

void DELIVERY(SIMULATOR S);

void INVENTORYMakanan(SIMULATOR S);

void Catalogue(ListMakanan lm);
/* I.S. lm terdefinisi dan merupakan hasil baca configurasi */
/* F.S. menampilkan semua info makanan yang terdapat pada Game */

void Move(SIMULATOR *S, Word X, boolean *MoveSuccess);

void MoveS(SIMULATOR *S, boolean *MoveSuccess);
void MoveN(SIMULATOR *S, boolean *MoveSuccess);
void MoveW(SIMULATOR *S, boolean *MoveSuccess);
void MoveE(SIMULATOR *S, boolean *MoveSuccess);

void BuyFood(SIMULATOR *s, ListMakanan lm, boolean *flag);
/* I.S. : S terdefinisi, lm berisi hasil konfigurasi program, flag sembarang */
/* F.S. : S selesai melakukan pembelian dengan menginput 0 atau S tidak berada di dekat telepon */
/* Meminta input angka kepada user, jika berhasil maka makanan akan disimpan pada deliv queue S */
/* Mengecek apakah S adjecent dengan 'B' */
/* Pengecakan dan pengulangan input terjadi */

void COOKFOOD(SIMULATOR *s, ListMakanan lm, ListResep lr, Notifikasi *notif, char *action);

void WAIT(SIMULATOR *S, boolean *FlagDeliv, boolean *FlagExp, ListMakanan *LMakananEXP, ListMakanan *ListDelivDone);

void undoGame(SIMULATOR *S, SIMULATOR InitSim, Notifikasi *Notif, Stack *Undo, Stack *Redo);
/* I.S. : S, Undo, Notif, dan redo terdefinisi, InitSim adalah keadaan simulator paling awal dalam game */
/* Notif datang ke Undo dalam keadaan kosong */
/* F.S. : jika stack Undo kosong, tampilkan pesan */
/* Stack undo menjadi kosong artinya S = InitSim  dan Notif kosong */
/* Jika tidak, Notifikasi pada InfoTopN(Undo) akan dikirimkan ke Notif */
/* Stack Undo akan dipop dan dimasukkan ke dalam Stack Redo */
/* InfoTopSim(Undo) yang baru akan menjadi S, dan visualnya */
/* misal A, B, C adalah keadaan untuk SIMULATOR S dan Notifikasi N
    C     SD=C                               SD=B
    B                   -undoGame->     B               -> Notif = InfoTopN(Undo) di C
    A                                   A           C
    Undo        Redo                    Undo        Redo
    -------Jika Stack Undo menjadi kosong
          SN=A                             SN=InitSim A
                B       -undoGame->                   B -> Notif = InfoTopN(Undo) di A
    A           C                                     C
    Undo        Redo                    Undo        Redo
 */

void redoGame(SIMULATOR *S, Notifikasi *Notif, Stack *Undo, Stack *Redo);
/* I.S. : S, Undo, dan Redo terdefinisi */
/* Notif datang ke redoGame dalam keadaan kosong */
/* F.S. : Jika Stack Redo kosong, tampilkan pesan */
/* Stack redo kosong artinya S dan Notif sedang pada keadaan paling baru*/
/* Jika tidak kosong Stack Redo akan dipop dan di masukkan ke dalam Stack Redo*/
/* InfoTopSim(Undo) yang baru akan menjadi S, visualnya: */
/* misal A, B, C adalah type SIMULATOR dan S adalah kondisi S
          SN=B                          C    SN=C
    B                   -redoGame->     B               -> Notif = InfoTopN(Undo) di C
    A           C                       A
    Undo        Redo                    Undo        Redo
    -------Jika Stack kosong
    C      SN=C                         C      SN=C
    B                    -redoGame->    B               -> Notif = kosong
    A                    {pesan}        A
    Undo        Redo                    Undo        Redo
 */

void saveUndoRedoGame(SIMULATOR S, SIMULATOR InitSim, Notifikasi Notif, Stack *Undo, Stack *Redo);
/* I.S. : S, Undo, dan Redo terdefinisi, InitSim adalah keadaan simulator paling awal,
    currentWord terdefinisi dan valid sebagai command */
/* Notif terdefinisi baik kosong mapun berisi */
/* F.S. : jika keadaan S berubah, S dimasukkan ke dalam Stack Undo */
/* S disamakan dengan Top(Undo) -> F.S. */
/* Stack Redo akan kosong menyesuaikan kondisi logic undo-redo,
    yaitu ketika user menginput command baru dan S berubah setelah melakukan beberapa Undo  */

#endif

#include "../ADT_Simulator/simulator.h"
#include "../ADT_Matriks/matrix.h"
#include "../ADT_Point/point.h"
#include "../ADT_Queue/PrioQueue.h"
