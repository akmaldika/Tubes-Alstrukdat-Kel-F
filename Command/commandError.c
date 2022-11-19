#ifndef CommandError_h
#define CommandError_h

#include <stdlib.h>
#include <stdio.h>
#include "../ADT_MesinKata/mesinkata.h"
#include "../ADT_MesinKata/mesinkarakter.h"
#include "../ADT_MesinKata/string.h"
// #include "../ADT_MesinKata/mesinkata.c"
// #include "../ADT_MesinKata/mesinkarakter.c"
// #include "../ADT_MesinKata/string.c"
#include "help.c"
#include "boolean.h"


void commandStartError();
/* I.S. : currrentLine dan currentWord sudah didapatkan */
/* F.S. : currentWord / currentLine untuk command yang benar didapatkan */
/* currentWord adalah kata pertama dari currentLine */
/* ketika currentLine/currentWord tidak dikenali untuk start game */
/* memunculkan pesna error dan meminta input kembali sesuai kondisi */

boolean isDigit(char *str);
/* precond : str terdefinisi */
/* mengecek apakah string yang dimasukkan merupakan digit */

void commandInGameError();
/* I.S. : currrentLine dan currentWord sudah didapatkan */
/* F.S. : currentWord / currentLine untuk command yang benar didapatkan*/
/* currentWord adalah kata pertama dari currentLine */
/* currentLine/currentWord tidak dikenali untuk start game*/
/* memunculkan pesna error dan meminta input kembali sesuai kondisi */

// void IgnoreBlankcurLine();
/* I.S. sembarang untuk suatu kata/kalimat dalam currentLine dan currentLine terdefinisi */
/* F.S. currentLine.Tabword[currentLength] != BLANK atau endWord*/

#endif

void commandStartError()
{
    if (isLineSame(currentLine, "START") || isLineSame(currentLine, "EXIT"))
    {/* Do Nothing */}
    else
    {
        if(!endWord)
        {
            printf("Jangan gunakan spasi di awal atau diakhir command!\n");
        }
        printf("Command tidak dikenali. Silahkan masukkan command yang benar\n");
        printf("Ketik 'HELP' untuk melihat daftar command yang tersedia\n");
        printf("Masukkan command: ");
        STARTCOMMAND();
        STARTWORD();
    
        while (isWordSame(currentWord, "HELP"))
        {    
            helpStartGame();
            printf("Masukkan command: ");
            STARTCOMMAND();
            STARTWORD();
        }   
        commandStartError();
    }
}

void commandInGameError()
{
    if(isLineSame(currentLine, "HELP") || isLineSame(currentLine, "BUY") || isLineSame(currentLine, "MIX") || isLineSame(currentLine, "CHOP") || isLineSame(currentLine, "FRY") || isLineSame(currentLine, "BOIL") || isLineSame(currentLine, "DELIVERY") || isLineSame(currentLine, "INVENTORY") || isLineSame(currentLine, "CATALOG") || isLineSame(currentLine, "COOKBOOK") || isLineSame(currentLine, "RECOMMENDATION") || isLineSame(currentLine, "UNDO") || isLineSame(currentLine, "REDO") || isLineSame(currentLine, "EXIT"))
    {/* Do Nothing */}
    else if (isWordSame(currentWord, "WAIT"))
    {
        if(endWord)
        {
            printf("Anda tidak memasukkan parameter X jam Y menit dengan benar!\n");
            printf("WAIT X Y\n");
            printf("Masukkan command: ");
            STARTCOMMAND();
            STARTWORD();
            commandInGameError();
        }
        else
        {
            ADVWORD();
            if(isWordInt(currentWord))
            {
                if(!endWord)
                {
                    ADVWORD();
                    if(isWordInt(currentWord))
                    {
                        if(endWord)
                        {
                            STARTWORD();
                        }
                        else
                        {
                            printf("Jangan tambahkan karakter lain!\n");
                            printf("Gunakan Format: WAIT X Y\nX untuk jam dan Y untuk menit\n");
                            printf("Masukkan command: ");
                            STARTCOMMAND();
                            STARTWORD();
                            commandInGameError(); 
                        }
                    }
                    else
                    {
                        printf("Y harus berupa angka!\n");
                        printf("Gunakan Format: WAIT X Y\nX untuk jam dan Y untuk menit\n");
                        printf("Masukkan command: ");
                        STARTCOMMAND();
                        STARTWORD();
                        commandInGameError(); 
                    }
                }
                else
                {
                    printf("Masukkan parameter Y dengan benar!\n");
                    printf("Gunakan Format: WAIT X Y\nX untuk jam dan Y untuk menit\n");
                    printf("Masukkan command: ");
                    STARTCOMMAND();
                    STARTWORD();
                    commandInGameError();
                }
            }
            else
            {
                printf("X harus berupa angka!\n");
                printf("Gunakan Format: WAIT X Y\nX untuk jam dan Y untuk menit\n");
                printf("Masukkan command: ");
                STARTCOMMAND();
                STARTWORD();
                commandInGameError();
            }
        
        }
    }
    else if(isWordSame(currentWord, "MOVE"))
    {
        if(endWord)
        {
            printf("Anda tidak memasukkan X dengan benar!\n");
            printf("Gunakan Format: MOVE X\n");
            printf("X = {NORTH, SOUTH, EAST, WEST}\n");
            printf("Masukkan command: ");
            STARTCOMMAND();
            STARTWORD();

            commandInGameError();
        }
        else
        {
            ADVWORD();
            if(isWordSame(currentWord, "NORTH") || isWordSame(currentWord, "SOUTH") || isWordSame(currentWord, "EAST") || isWordSame(currentWord, "WEST"))
            {
                if(endWord)
                {
                    STARTWORD();
                }
                else
                {
                    printf("Jangan tambahkan karakter lain!\n");
                    printf("Gunakan Format: MOVE X\n");
                    printf("X = {NORTH, SOUTH, EAST, WEST}\n");
                    printf("Masukkan command: ");
                    STARTCOMMAND();
                    STARTWORD();
                    commandInGameError();
                }
            }
            else
            {
                printf("X harus berupa NORTH, SOUTH, EAST, atau WEST!\n");
                printf("Gunakan Format: MOVE X\n");
                printf("X = {NORTH, SOUTH, EAST, WEST}\n");
                printf("Masukkan command: ");
                STARTCOMMAND();
                STARTWORD();

                commandInGameError();
            }
        }
    }
    else
    {
        if (isWordSame(currentWord, "START"))
        {
            printf("Game sudah dimulai!\n");
            printf("Silakan masukkan commmand 'EXIT' untuk keluar game dan memulai ulang game\n");
            printf("Ketik 'HELP' untuk melihat daftar command yang tersedia\n");
            printf("Masukkan command: ");
            STARTCOMMAND();
            STARTWORD();
        }
        else
        {
            if(!endWord)
            {
                printf("Jangan gunakan spasi di awal atau diakhir command!\n");
            }
            printf("Command tidak dikenali. Silahkan masukkan command yang benar\n");
            printf("Ketik 'HELP' untuk melihat daftar command yang tersedia\n");
            printf("Masukkan command: ");
            STARTCOMMAND();
            STARTWORD();
        }
        commandInGameError();
    }
}