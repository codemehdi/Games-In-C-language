#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "TicTacToe.h"
#include "WordleHangman.h"
#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"

/* ====================================================================================== */
/* ====================================================================================== */
/* ====================================================================================== */

int main(){
    int Game;
    /* the "\xB2" is made to draw the interface surrounding the menu when we execute the code */
    printf("========================================================================================================================\n");
    printf("\n\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 GAMES EMULATOR \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\t\t  |----------------Menu----------------|\n");
    printf("\t\t\t  |1.Tic tac toe                       |\n");
    printf("\t\t\t  |2.Wordle                            |\n");
    printf("\t\t\t  |3.Hangman                           |\n");
    printf("\t\t\t  |------------------------------------|\n");
    printf("\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n Made by ELMehdi ELOuasbi                                                 \n");
    printf("========================================================================================================================\n");
    printf("Enter the number of what game you want to play:");
    scanf("%d", &Game);

    while(Game<1 || Game>3){
        printf("Please follow the instructions above:");
        scanf("%d", &Game);
    }
    switch (Game){
        case 1:{
            M_Tictactoe();
        }
        case 2:{
            Loading1();
            Wordle();
        }
        case 3:{
            Loading1();
            Hangman();
        }
    }
    return 0;
}
