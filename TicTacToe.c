#include "TicTacToe.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <string.h>
#include <windows.h>
#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"

/* the 'color_red' 'color_blue' are to make the text colored while the 'color_white' is to put it back to default */
/* I used char and not int when declaring square because we need to replace them later with X or O which are char's
and not int's */
/*i called the variables outside the functions because they will be used in different functions at the same time */
char square[10] = {'0','1','2','3','4','5','6','7','8','9'};
int player = 1;
int z = 0;
int move=0;
int i = 2;

void color_red(){
     printf("\033[0;31m");
}

void color_blue(){
    printf("\033[0;34m");
}

void color_white(){
  printf("\033[0m");
}

/* ====================================================================================== */
/* this function shows the user the interface for the tic tac toe gamemode */
void M_Tictactoe(){
    Loading();
    int mode;
    int diff;
    system("cls");
    printf("Welcome to");
    color_red();
    printf("%s Tic ", BOLD);
    color_blue();
    printf("%sTac ", BOLD);
    color_red();
    printf("%sToe V1.0 :%s\n\n",BOLD, RESET);
    printf("\t\tChoose your mode:\n");
    printf("%s1. vs Player\n", BOLD);
    printf("%s2. vs Computer\n", BOLD);
    printf("%s3. Capture the flag\n", BOLD);
    printf("%s4. Gravity mode\n", BOLD);
    printf("%s5. How to play\n", BOLD);
    printf("%s6. Exit", BOLD);
    printf("\n\nChoose your mode:");
    scanf("%d", &mode);
    while(mode<1 || mode>6){
        printf("Please Enter a valid mode (1 or 2 or 3 or 4 or 5 or 6):");
        scanf("%d", &mode);
    }
    if(mode == 1){
        Loading();
        TTT_player();
    }
    else if(mode == 2){
        Loading();
        TTT_Computer();
    }
    else if(mode == 3){
        Loading();
        TTT_CTF();
    }
    else if(mode == 4){
        Loading();
        TTT_CNT();
    }
    else if(mode == 5){
        Loading();
        Tutorial(); }
    else if(mode == 6){
        system("cls");
        main();
    }
}

/* ====================================================================================== */
void tableaux(){
    /* this function is the one able to draw the table for tic tac toe */
    printf("\n\n\n\n\t\t\t%c | %c | %c \n", square[1],square[2],square[3]);
    printf("\t\t\t-----------\n");
    printf("\t\t\t%c | %c | %c \n",square[4],square[5],square[6]);
    printf("\t\t\t-----------\n");
    printf("\t\t\t%c | %c | %c \n",square[7],square[8],square[9]);
}
/* ====================================================================================== */

void Table(){
    /* this one is used to make the intro saying the line "Welcome to Tic Tac Toe" in colors and all after you choose what mode you want to play inside tic tac toe */
    Loading();
    char welcome[] = "Welcome to";
    char name[] = "Tic Tac Toe";
    int i,j;
    system("cls");
    for(i=0;i<strlen(welcome);i++){
            _sleep(70);
            printf("%c", welcome[i]);
        }
    printf(" ");
    color_red();
    for(j=0;j<=3;j++){
        _sleep(70);
        printf("%s%c",BOLD, name[j]);
    }
    color_blue();
    for(j=4;j<=6;j++){
        _sleep(70);
        printf("%s%c",BOLD, name[j]);
    }
    color_red();
    for(j=7;j<=10;j++){
        _sleep(70);
        printf("%s%c",BOLD, name[j]);
    }
    color_white();
    tableaux();

}

/* ====================================================================================== */

void reset_board(){
    /* reset_board is used to reset all the squares so when a play chooses to play again the squares wont be filled */
    player = 1;
    square[0] = '0';
    square[1] = '1';
    square[2] = '2';
    square[3] = '3';
    square[4] = '4';
    square[5] = '5';
    square[6] = '6';
    square[7] = '7';
    square[8] = '8';
    square[9] = '9';
    i = 2;
    move = 0;
}

/* ====================================================================================== */

void Tutorial(){
    /*function used to show the tutorial */
    Loading();
    int menu,temp;
    /* system("cls"); is used to clear the screen */
    system("cls");
    printf("What mode do you want to learn about :\n");
    printf("1. Normal mode (vs player // vs computer)\n");
    printf("2.Capture the flag\n");
    printf("3.Gravity mode\n");
    scanf("%d", &temp);
    while(temp != 1 && temp != 2 && temp != 3){
        system("cls");
        printf("1.Normal mode (vs player // vs computer)\n");
        printf("2.Capture the flag\n");
        printf("3.Gravity mode\n");
        printf("Please enter a valid number (1 or 2 or 3) :");
        scanf("%d", &temp);
    }
    if(temp == 1){
        system("cls");
        printf("%s1.Your symbol (x or o) is said below the board.%s\n",BOLD,RESET);
        printf("%s2.Enter the number showing the square you want to put your symbol in.%s\n",BOLD,RESET);
        printf("%s3.The first player to get 3 of their marks in a row (up, down, or diagonally) is the winner.%s\n",BOLD,RESET);
        printf("%s4.When all 9 squares are full the game is over If no player has 3 marks in a row the game ends in a tie.%s\n",BOLD,RESET);
        printf("Enter '0' to go back to the menu : ");
        scanf("%d", &menu);
    while(menu != 0){
        printf("Please follow the instructions :");
        scanf("%d", &menu);
    }
    }
    else if(temp == 2){
        system("cls");
        printf("Players get to choose the square of their flag at the start of the game\n");
        printf("After choosing the position of the flag Players try to capture the opposite player flag by putting a mark on their flag\n");
        printf("Rules of normal tic tac toe still applies\n");
        printf("\t\t\tEnter '0' to go back to the menu : ");
        scanf("%d", &menu);
        while(menu != 0){
            printf("Please follow the instructions :");
            scanf("%d", &menu);
    }
    }
    else if(temp == 3){
        system("cls");
        printf("Players will have to win according to the same rules of normal tic tac toe\n");
        printf("Instead of choosing your exact square you'll have to rely on gravity\n");
        printf("squares(1 4 and 7) can be accessed by typing 1\n");
        printf("squares(2 5 and 8) can be accessed by typing 2\n");
        printf("squares(3 6 and 9) can be accessed by typing 3\n");
        printf("In the end its basically connect 4 but its connect 3\n");
        printf("\t\t\tEnter '0' to go back to the menu : ");
        scanf("%d", &menu);
        while(menu != 0){
            printf("Please follow the instructions :");
            scanf("%d", &menu);
    }
    }
    M_Tictactoe();

}

/* ====================================================================================== */


void Loading(){
    int a;
    /*this function is the one used for the loading screen*/
    /* we use the _sleep(number) to delay the passage from a line to another */
    for(a=0;a<=1;a++){
        printf("\n\n\n\n\n\n\n\n\t\t\t\t | Loading.");
        _sleep(20);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\t\t\t\t / Loading..");
        _sleep(20);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\t\t\t\t - Loading...");
        _sleep(20);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\t\t\t\t \\ Loading");
        _sleep(20);
        system("cls");
    }
}

/* ====================================================================================== */

int win(){
    /* this one basically checks for all the possibilies where a game can be won */
    /* if it finds that the game is won it returns a 1*/
    /* if the board is still not filled it returns a 2*/
    /* if the board is full and there isnt a winner it returns a 0*/
    if (square[1] == square[2] && square[2] == square[3]){
        return 1;
    }
    else if (square[1] == square[4] && square[4] == square[7]){
        return 1;
    }
    else if (square[1] == square[5] && square[5] == square[9]){
        return 1;
    }
    else if(square[2] == square[5] && square[5] == square[8]){
        return 1;
    }
    else if(square[3] == square[6] && square[6] == square[9]){
        return 1;
    }
    else if(square[3] == square[5] && square[5] == square[7]){
        return 1;
    }
    else if(square[4] == square[5] && square[5] == square[6]){
        return 1;
    }
    else if(square[7] == square[8] && square[8] == square[9]){
        return 1;
    }
    else if(square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9'){
        return 0;
    }
    else {return 2;}
}

/* ====================================================================================== */

    void win1_screen(){
    /*this function is just there to show a "Player 1 won" */
    int a,k;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t %sPlayer 1 won!!!%s", BOLD, RESET);
    printf("\n\n\n press 0 to go back to menu and 1 to play again : ");
    scanf("%d", &k);
    while(k != 0 && k != 1){
        printf("please enter a valid number : ");
        scanf("%d", &k);
    }
    if(k == 0){
        reset_board();
        system("cls");
        main();
    }
    else if(k == 1){
        reset_board();
        TTT_player();
    }
    }
/* ====================================================================================== */

    void win2_screen(){
        /*this function is just there to show a "Player 2 won" */
    int k;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t %sPlayer 2 won!!!%s\n", BOLD, RESET);
    printf("press 0 to go back to menu and 1 to play again : ");
    scanf("%d", &k);
    while(k != 0 && k != 1){
        printf("please enter a valid number : ");
        scanf("%d", &k);
    }
    if(k == 0){
        system("cls");
        main();
    }
    else if(k == 1){
        reset_board();
        TTT_player();
    }
    }

/* ====================================================================================== */

    void CTFW1_screen(){
    /*this function is just there to show a "Player 1 won" */
    int a,k;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t %sPlayer 1 won!!!%s", BOLD, RESET);
    printf("\n\n\n press 0 to go back to menu and 1 to play again : ");
    scanf("%d", &k);
    while(k != 0 && k != 1){
        printf("please enter a valid number : ");
        scanf("%d", &k);
    }
    if(k == 0){
        reset_board();
        system("cls");
        main();
    }
    else if(k == 1){
        reset_board();
        TTT_CTF();
    }
    }
/* ====================================================================================== */

    void CTFW2_screen(){
        /*this function is just there to show a "Player 2 won" */
    int k;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t %sPlayer 2 won!!!%s\n", BOLD, RESET);
    printf("press 0 to go back to menu and 1 to play again : ");
    scanf("%d", &k);
    while(k != 0 && k != 1){
        printf("please enter a valid number : ");
        scanf("%d", &k);
    }
    if(k == 0){
        system("cls");
        main();
    }
    else if(k == 1){
        reset_board();
        TTT_CTF();
    }
    }

/* ====================================================================================== */
void CTF_draw(){
    int k;
    /*this function is just there to show a "Game ended in a draw D:" */
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t %sGame ended in a draw D:%s\n", BOLD, RESET);
    printf("\n\npress 0 to go back to menu and 1 to play again : ");
    scanf("%d", &k);
    while(k != 0 && k != 1){
        printf("please enter a valid number : ");
        scanf("%d", &k);
    }
    if(k == 0){
        system("cls");
        M_Tictactoe();
    }
    else if(k == 1){
        square[0] = '0';
        square[1] = '1';
        square[2] = '2';
        square[3] = '3';
        square[4] = '4';
        square[5] = '5';
        square[6] = '6';
        square[7] = '7';
        square[8] = '8';
        square[9] = '9';
        TTT_CTF();
    }

}

/* ====================================================================================== */

    void CNTW1_screen(){
    /*this function is just there to show a "Player 1 won" */
    int a,k;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t %sPlayer 1 won!!!%s", BOLD, RESET);
    printf("\n\n\n press 0 to go back to menu and 1 to play again : ");
    scanf("%d", &k);
    while(k != 0 && k != 1){
        printf("please enter a valid number : ");
        scanf("%d", &k);
    }
    if(k == 0){
        reset_board();
        system("cls");
        main();
    }
    else if(k == 1){
        reset_board();
        TTT_CNT();
    }
    }
/* ====================================================================================== */

    void CNTW2_screen(){
        /*this function is just there to show a "Player 2 won" */
    int k;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t %sPlayer 2 won!!!%s\n", BOLD, RESET);
    printf("press 0 to go back to menu and 1 to play again : ");
    scanf("%d", &k);
    while(k != 0 && k != 1){
        printf("please enter a valid number : ");
        scanf("%d", &k);
    }
    if(k == 0){
        system("cls");
        main();
    }
    else if(k == 1){
        reset_board();
        TTT_CNT();
    }
    }

/* ====================================================================================== */
void CNT_draw(){
    int k;
    /*this function is just there to show a "Game ended in a draw D:" */
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t %sGame ended in a draw D:%s\n", BOLD, RESET);
    printf("\n\npress 0 to go back to menu and 1 to play again : ");
    scanf("%d", &k);
    while(k != 0 && k != 1){
        printf("please enter a valid number : ");
        scanf("%d", &k);
    }
    if(k == 0){
        system("cls");
        M_Tictactoe();
    }
    else if(k == 1){
        square[0] = '0';
        square[1] = '1';
        square[2] = '2';
        square[3] = '3';
        square[4] = '4';
        square[5] = '5';
        square[6] = '6';
        square[7] = '7';
        square[8] = '8';
        square[9] = '9';
        TTT_CNT();
    }

}

/* ====================================================================================== */


    void bot_screen(){
        /*this function is just there to show a "Computer won" */
    int k;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t %sComputer won!!!%s\n", BOLD, RESET);
    printf("press 0 to go back to menu and 1 to play again : ");
    scanf("%d", &k);
    while(k != 0 && k != 1){
        printf("please enter a valid number : ");
        scanf("%d", &k);
    }
    if(k == 0){
        system("cls");
        main();
    }
    else if(k == 1){
        reset_board();
        TTT_Computer();
    }
    }

/* ====================================================================================== */

    void botwin1_screen(){
    /*this function is just there to show a "Player 1 won" */
    int a,k;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t %sPlayer 1 won!!!%s", BOLD, RESET);
    printf("\n\n\n press 0 to go back to menu and 1 to play again : ");
    scanf("%d", &k);
    while(k != 0 && k != 1){
        printf("please enter a valid number : ");
        scanf("%d", &k);
    }
    if(k == 0){
        reset_board();
        system("cls");
        main();
    }
    else if(k == 1){
        reset_board();
        TTT_Computer();
    }
    }
/* ====================================================================================== */

void draw(){
    int k;
    /*this function is just there to show a "Game ended in a draw D:" */
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t %sGame ended in a draw D:%s\n", BOLD, RESET);
    printf("\n\npress 0 to go back to menu and 1 to play again : ");
    scanf("%d", &k);
    while(k != 0 && k != 1){
        printf("please enter a valid number : ");
        scanf("%d", &k);
    }
    if(k == 0){
        system("cls");
        M_Tictactoe();
    }
    else if(k == 1){
        square[0] = '0';
        square[1] = '1';
        square[2] = '2';
        square[3] = '3';
        square[4] = '4';
        square[5] = '5';
        square[6] = '6';
        square[7] = '7';
        square[8] = '8';
        square[9] = '9';
        TTT_player();
    }

}

/* ====================================================================================== */

void bot_draw(){
    int k;
    /*this function is just there to show a "Game ended in a draw D:" */
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t %sGame ended in a draw D:%s\n", BOLD, RESET);
    printf("\n\npress 0 to go back to menu and 1 to play again : ");
    scanf("%d", &k);
    while(k != 0 && k != 1){
        printf("please enter a valid number : ");
        scanf("%d", &k);
    }
    if(k == 0){
        system("cls");
        M_Tictactoe();
    }
    else if(k == 1){
        square[0] = '0';
        square[1] = '1';
        square[2] = '2';
        square[3] = '3';
        square[4] = '4';
        square[5] = '5';
        square[6] = '6';
        square[7] = '7';
        square[8] = '8';
        square[9] = '9';
        TTT_Computer();
    }

}

/* ====================================================================================== */

void TTT_player(){
    reset_board();
    Table();
    int pos;
    char mark;
    player = 1;
    do{
    /* player initially equals 1 so when the computer checks player % 2 if is an even number the result will be '0'
    if it's an odd number the result will be '1' and after adding a player++ at the end of the loop it makes this
    line capable of switching roles between player 1 and 2*/
    player = (player % 2) ? 1 : 2;
    printf("\n Player %d please enter your position : ", player);
    scanf("%d", &pos);
    /* mark will equal to X when its player 1 turn and will equal to O when its player 2 turn (player 1 and 2 is chosen
    from the line "player = (player % 2) ? 1 : 2;" */
    mark = (player == 1) ? 'X' : 'O';
    while(pos>9 || pos<1){
        printf("the move you entered is invalid or occupied please use a different square");
        scanf("%d", &pos);
    }
    /* the if and else if lines are to check if the square chosen is available if it is then it will be replaced with a
    mark if not it will show that its an invalid move and it will execute the line player-- which while added to player++
    at the end of the loop will keep the same player turn */
    if (pos == 1 && square[1] == '1'){
            square[1] = mark;}

    else if (pos == 2 && square[2] == '2'){
            square[2] = mark;}

    else if (pos == 3 && square[3] == '3'){
            square[3] = mark;}

    else if (pos == 4 && square[4] == '4'){
            square[4] = mark;}

    else if (pos == 5 && square[5] == '5'){
            square[5] = mark;}

    else if (pos == 6 && square[6] == '6'){
            square[6] = mark;}

    else if (pos == 7 && square[7] == '7'){
            square[7] = mark;}

    else if (pos == 8 && square[8] == '8'){
            square[8] = mark;}

    else if (pos == 9 && square[9] == '9'){
            square[9] = mark;}
    else{
        printf("invalid move!!!");
        player--;
    }
    /* i initially equals to 2 so when we give it the value of "win()" if the win() returns a 1 that means there
    is a winner if it returns 2 it means the game is still going if it returns a 0 that means all the spots are filled
    and the game ended in a draw */
    i = win();
    pos = 0;
    player++;
    system("cls");
    tableaux();
    }while(i == 2);
    /* the loop do while keeps working until the board is full or the bot found a winner */
    if(i == 1 && --player == 1){
        win1_screen();
        reset_board();
    }
    else if(i==1){
        win2_screen();
        reset_board();
    }
    else if(i==0){
        draw();
        reset_board();
    }
}

/* ====================================================================================== */

void TTT_Computer(){
    reset_board();
    Table();
    int pos;
    int k=0;
    char mark = 'X';
    do{
    printf("\n Player %d please enter your position : ", player);
    scanf("%d", &pos);
    while(pos>9 || pos<1){
        printf("the move you entered is invalid or occupied please use a different square");
        scanf("%d", &pos);
    }
    if (pos == 1 && square[1] == '1'){
            square[1] = mark;
            move++;
            }

    else if (pos == 2 && square[2] == '2'){
            square[2] = mark;
            move++;}

    else if (pos == 3 && square[3] == '3'){
            square[3] = mark;
            move++;}

    else if (pos == 4 && square[4] == '4'){
            square[4] = mark;
            move++;}

    else if (pos == 5 && square[5] == '5'){
            square[5] = mark;
            move++;}

    else if (pos == 6 && square[6] == '6'){
            square[6] = mark;
            move++;}

    else if (pos == 7 && square[7] == '7'){
            square[7] = mark;
            move++;}

    else if (pos == 8 && square[8] == '8'){
            square[8] = mark;
            move++;}

    else if (pos == 9 && square[9] == '9'){
            square[9] = mark;
            move++;}
    else{
        printf("invalid move!!!");
        k = 1;
    }
    i = win();
    if(i == 2){
    if(move == 1 && pos%2 != 0 && pos != 5 && k == 0){
        square[5] = 'O';
    }
    else if(move == 1 && pos == 2 && k == 0){
        square[1] = 'O';
    }
    else if(move == 1 && pos == 4 && k == 0){
        square[7] = 'O';
    }
    else if(move == 1 && pos == 6 && k == 0){
        square[3] = 'O';
    }
    else if(move == 1 && pos == 8 && k == 0){
        square[7] = 'O';
    }
    else if(move == 1 && pos == 5 && k ==0){
        square[1] = 'O';
    }

    /* ================================================================================================================*/
    /* check for possibilities where computer might win */
    if(move == 2 || move >2){
    if(square[1] == 'O' && square[2] == 'O' && square[3] == '3'){
        square[3] = 'O';
    }
    else if(square[1] == 'O' && square[3] == 'O' && square[2] == '2'){
        square[2] = 'O';
    }
    else if(square[2] == 'O' && square[3] == 'O' && square[1] == '1'){
        square[1] = 'O';
    }
    else if(square[1] == 'O' && square[4] == 'O' && square[7] == '7'){
        square[7] = 'O';
    }
    else if(square[4] == 'O' && square[7] == 'O' && square[1] == '1'){
        square[1] = 'O';
    }
    else if(square[1] == 'O' && square[7] == 'O' && square[4] == '4'){
        square[4] = 'O';
    }
    else if(square[1] == 'O' && square[5] == 'O' && square[9] == '9'){
        square[9] = 'O';
    }
    else if(square[5] == 'O' && square[9] == 'O' && square[1] == '1'){
        square[1] = 'O';
    }
    else if(square[1] == 'O' && square[9] == 'O' && square[5] == '5'){
        square[5] = 'O';
    }
    else if(square[2] == 'O' && square[5] == 'O' && square[8] == '8'){
        square[8] = 'O';
    }
    else if(square[2] == 'O' && square[8] == 'O' && square[5] == '5'){
        square[5] = 'O';
    }
    else if(square[5] == 'O' && square[8] == 'O' && square[2] == '2'){
        square[2] = 'O';
    }
    else if(square[3] == 'O' && square[6] == 'O' && square[9] == '9'){
        square[9] = 'O';
    }
    else if(square[3] == 'O' && square[9] == 'O' && square[6] == '6'){
        square[6] = 'O';
    }
    else if(square[6] == 'O' && square[9] == 'O' && square[3] == '3'){
        square[3] = 'O';
    }
    else if(square[3] == 'O' && square[5] == 'O' && square[7] == '7'){
        square[7] = 'O';
    }
    else if(square[3] == 'O' && square[7] == 'O' && square[5] == '5'){
        square[5] = 'O';
    }
    else if(square[5] == 'O' && square[7] == 'O' && square[3] == '3'){
        square[3] = 'O';
    }
    else if(square[4] == 'O' && square[5] == 'O' && square[6] == '6'){
        square[6] = 'O';
    }
    else if(square[4] == 'O' && square[6] == 'O' && square[5] == '5'){
        square[5] = 'O';
    }
    else if(square[5] == 'O' && square[6] == 'O' && square[4] == '4'){
        square[4] = 'O';
    }
    else if(square[7] == 'O' && square[8] == 'O' && square[9] == '9'){
        square[9] = 'O';
    }
    else if(square[7] == 'O' && square[9] == 'O' && square[8] == '8'){
        square[8] = 'O';
    }
    else if(square[8] == 'O' && square[9] == 'O' && square[7] == '8'){
        square[7] = 'O';
    }

    /* ===================================================================================================== */
    /* check for moves where user might win */
    else if(square[1] == 'X' && square[2] == 'X' && square[3] == '3'){
        square[3] = 'O';
    }
    else if(square[1] == 'X' && square[3] == 'X' && square[2] == '2'){
        square[2] = 'O';
    }
    else if(square[2] == 'X' && square[3] == 'X' && square[1] == '1'){
        square[1] = 'O';
    }
    else if(square[1] == 'X' && square[4] == 'X' && square[7] == '7'){
        square[7] = 'O';
    }
    else if(square[4] == 'X' && square[7] == 'X' && square[1] == '1'){
        square[1] = 'O';
    }
    else if(square[1] == 'X' && square[7] == 'X' && square[4] == '4'){
        square[4] = 'O';
    }
    else if(square[1] == 'X' && square[5] == 'X' && square[9] == '9'){
        square[9] = 'O';
    }
    else if(square[5] == 'X' && square[9] == 'X' && square[1] == '1'){
        square[1] = 'O';
    }
    else if(square[1] == 'X' && square[9] == 'X' && square[5] == '5'){
        square[5] = 'O';
    }
    else if(square[2] == 'X' && square[5] == 'X' && square[8] == '8'){
        square[8] = 'O';
    }
    else if(square[2] == 'X' && square[8] == 'X' && square[5] == '5'){
        square[5] = 'O';
    }
    else if(square[5] == 'X' && square[8] == 'X' && square[2] == '2'){
        square[2] = 'O';
    }
    else if(square[3] == 'X' && square[6] == 'X' && square[9] == '9'){
        square[9] = 'O';
    }
    else if(square[3] == 'X' && square[9] == 'X' && square[6] == '6'){
        square[6] = 'O';
    }
    else if(square[6] == 'X' && square[9] == 'X' && square[3] == '3'){
        square[3] = 'O';
    }
    else if(square[3] == 'X' && square[5] == 'X' && square[7] == '7'){
        square[7] = 'O';
    }
    else if(square[3] == 'X' && square[7] == 'X' && square[5] == '5'){
        square[5] = 'O';
    }
    else if(square[5] == 'X' && square[7] == 'X' && square[3] == '3'){
        square[3] = 'O';
    }
    else if(square[4] == 'X' && square[5] == 'X' && square[6] == '6'){
        square[6] = 'O';
    }
    else if(square[4] == 'X' && square[6] == 'X' && square[5] == '5'){
        square[5] = 'O';
    }
    else if(square[5] == 'X' && square[6] == 'X' && square[4] == '4'){
        square[4] = 'O';
    }
    else if(square[7] == 'X' && square[8] == 'X' && square[9] == '9'){
        square[9] = 'O';
    }
    else if(square[7] == 'X' && square[9] == 'X' && square[8] == '8'){
        square[8] = 'O';
    }
    else if(square[8] == 'X' && square[9] == 'X' && square[7] == '8'){
        square[7] = 'O';
    }

    /* ===================================================================================================== */
    /* check if center '5' is empty */
    else if(square[5] == '5'){
        square[5] = 'O';
    }
    /* ===================================================================================================== */
    /*check if user wants to use the combination 3(5) 9(corner) "auto win" */

    else if(square[1] == 'X' && square[9] == 'X'){
        if(square[2] == '2'){
            square[2] = 'O';
        }
        else if(square[4] == '4'){
            square[4] = 'O';
        }
        else if(square[6] == '6'){
            square[6] = 'O';
        }
        else if(square[8] == '8'){
            square[8] = 'O';
        }
    }
    else if(square[3] == 'X' && square[7] == 'X'){
        if(square[2] == '2'){
            square[2] = 'O';
        }
        else if(square[4] == '4'){
            square[4] = 'O';
        }
        else if(square[6] == '6'){
            square[6] = 'O';
        }
        else if(square[8] == '8'){
            square[8] = 'O';
        }
    }
    /* ===================================================================================================== */
    /* check for adjacent corner moves */
    else if(square[1] == 'X' && square[9] == '9'){
        square[9] = 'O';
    }
    else if(square[9] == 'X' && square[1] == '1'){
        square[1] = 'O';
    }
    else if(square[7] == 'X' && square[3] == '3'){
        square[3] = 'O';
    }
    else if(square[3] == 'X' && square[7] == '7'){
        square[7] = 'O';
    }
    /* ===================================================================================================== */
    /* available corner moves */
    else if(square[1] == '1'){
        square[1] = 'O';
    }
    else if(square[3] == '3'){
        square[3] = 'O';
    }
    else if(square[7] == '7'){
        square[7] = 'O';
    }
    else if(square[9] == '9'){
        square[9] = 'O';
    }
    /* ===================================================================================================== */
    /* check for any available move */
    else if(square[2] == '2'){
        square[2] = 'O';
    }
    else if(square[4] == '4'){
        square[4] = 'O';
    }
    else if(square[6] == '6'){
        square[6] = 'O';
    }
    else if(square[8] == '8'){
        square[8] = 'O';
    }
    }
    }





    i = win();
    if(i == 1 && --player == 1){
        botwin1_screen();
        reset_board();
    }
    else if(i==1){
        bot_screen();
        reset_board();
    }
    else if(i==0){
        bot_draw();
        reset_board();
    }
    /* we used the k variable in case of (let's say player 1 chose square number 3 as first choice computer will then
    fill square 5 with 'O' now lets say as second move player chose square 5 which is already occupied without the k
    variable the computer would fill another square meaning it'll cause imbalance*/
    k = 0;
    pos = 0;
    system("cls");
    tableaux();
    }while(i == 2);

}

/* ====================================================================================== */
    /* CTF = Capture the flag */
void TTT_CTF(){
    reset_board();
    Table();
    int pos,Flag1,Flag2;
    char mark;
    int tmp;
    int p = 0;
    player = 1;
    printf("\n Player 1 Choose the position of your flag :");
    scanf("%d", &Flag1);
    while(Flag1 > 9 || Flag1 < 1){
        system("cls");
        tableaux();
        printf("\n Player 1 Please Choose a valid square :");
        scanf("%d", &Flag1);
    }
    system("cls");
    tableaux();
    printf("\n Player 2 Choose the position of your flag :");
    scanf("%d", &Flag2);
    while(Flag2 > 9 || Flag2 < 1 || Flag1 == Flag2){
        system("cls");
        tableaux();
        printf("\n Player 2 Please Choose a valid square :");
        scanf("%d", &Flag2);
    }
    system("cls");
    tableaux();
    do{
    player = (player % 2) ? 1 : 2;
    printf("\n Player %d please enter your position : ", player);
    scanf("%d", &pos);
    mark = (player == 1) ? 'X' : 'O';
    while(pos>9 || pos<1){
        printf("the move you entered is invalid or occupied please use a different square");
        scanf("%d", &pos);
    }
    if(player == 1 && pos == Flag1){
        player = 0;
    }
    else if(player == 2 && pos == Flag2){
        player = 0;
        p++;
    }
    else if (pos == 1 && square[1] == '1'){
            square[1] = mark;}

    else if (pos == 2 && square[2] == '2'){
            square[2] = mark;}

    else if (pos == 3 && square[3] == '3'){
            square[3] = mark;}

    else if (pos == 4 && square[4] == '4'){
            square[4] = mark;}

    else if (pos == 5 && square[5] == '5'){
            square[5] = mark;}

    else if (pos == 6 && square[6] == '6'){
            square[6] = mark;}

    else if (pos == 7 && square[7] == '7'){
            square[7] = mark;}

    else if (pos == 8 && square[8] == '8'){
            square[8] = mark;}

    else if (pos == 9 && square[9] == '9'){
            square[9] = mark;}
    else{
        printf("invalid move!!!");
        player--;
    }
    i = win();
    if(player == 1 && pos == Flag2){
        i = 1;
    }
    else if(player == 2 && pos == Flag1){
        i = 1;
    }
    if(p == 0){
        player++;
    }
    else{
        player = 2;
    }
    p=0;
    pos = 0;
    system("cls");
    tableaux();
    }while(i == 2);
    if(i == 1 && --player == 1){
        CTFW1_screen();
        reset_board();
    }
    else if(i==1){
        CTFW2_screen();
        reset_board();
    }
    else if(i==0){
        CTF_draw();
        reset_board();
    }

    }

/* ====================================================================================== */
    /* CNT = Connect 3 */
void TTT_CNT(){
    reset_board();
    Table();
    int pos;
    char mark;
    player = 1;
    do{
    player = (player % 2) ? 1 : 2;
    printf("\n Player %d please enter your position : ", player);
    scanf("%d", &pos);
    mark = (player == 1) ? 'X' : 'O';
    while(pos>3 || pos<1){
        printf("the move you entered is invalid or occupied please use a different square(either 1 or 2 or 3)");
        scanf("%d", &pos);
    }
    if(pos == 1 && square[7] == '7'){
        square[7] = mark;
    }
    else if(pos == 1 && square[4] == '4'){
        square[4] = mark;
    }
    else if(pos == 1 && square[1] == '1'){
        square[1] = mark;
    }
    else if(pos == 2 && square[8] == '8'){
        square[8] = mark;
    }
    else if(pos == 2 && square[5] == '5'){
        square[5] = mark;
    }
    else if(pos == 2 && square[2] == '2'){
        square[2] = mark;
    }
    else if(pos == 3 && square[9] == '9'){
        square[9] = mark;
    }
    else if(pos == 3 && square[6] == '6'){
        square[6] = mark;
    }
    else if(pos == 3 && square[3] == '3'){
        square[3] = mark;
    }
    else{
        printf("invalid move!!!");
        player--;
    }
    i = win();
    pos = 0;
    player++;
    system("cls");
    tableaux();
    }while(i == 2);
    if(i == 1 && --player == 1){
        CNTW1_screen();
        reset_board();
    }
    else if(i==1){
        CNTW2_screen();
        reset_board();
    }
    else if(i==0){
        CNT_draw();
        reset_board();
    }

}


