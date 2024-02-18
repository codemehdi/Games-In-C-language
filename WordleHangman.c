#include "WordleHangman.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

/* ====================================================================================== */

void Hangman(){
    char words[][6] = {"gangs", "floor", "cycle", "staff", "clean"};
    char target[6];
    char guess;
    char emptyword[6] = "_____";
    int i,x,choice;
    int b=0;
    int randomnum;
    srand(time(NULL));
    randomnum = rand() % 5;
    strcpy(target, words[randomnum]);
    i = strlen(target);
    do{
    system("cls");
    x=0;
    if(b == 0){
    printf("\n\n\n\t |-------\n");
    printf("\t |\n");
    printf("\t |\n");
    printf("\t |\n");
    printf("\t |\n");
    printf("\t |\n");
    printf("\t |\t\t\t\t\t\t");}

    else if(b == 1){
    printf("\n\n\n\t |------|\n");
    printf("\t |      0\n");
    printf("\t |\n");
    printf("\t |\n");
    printf("\t |\n");
    printf("\t |\n");
    printf("\t |\t\t\t\t\t\t");}

    else if(b == 2){
    printf("\n\n\n\t |------|\n");
    printf("\t |      0\n");
    printf("\t |      |\n");
    printf("\t |      |\n");
    printf("\t |\n");
    printf("\t |\n");
    printf("\t |\t\t\t\t\t\t");}

    else if(b == 3){
    printf("\n\n\n\t |------|\n");
    printf("\t |      0\n");
    printf("\t |     /|\n");
    printf("\t |      |\n");
    printf("\t |\n");
    printf("\t |\n");
    printf("\t |\t\t\t\t\t\t");}

    else if(b == 4){
    printf("\n\n\n\t |------|\n");
    printf("\t |      0\n");
    printf("\t |     /|\\\n");
    printf("\t |      |\n");
    printf("\t |\n");
    printf("\t |\n");
    printf("\t |\t\t\t\t\t\t");}

    else if(b == 5){
    printf("\n\n\n\t |------|\n");
    printf("\t |      0\n");
    printf("\t |     /|\\\n");
    printf("\t |      |\n");
    printf("\t |     /\n");
    printf("\t |\n");
    printf("\t |\t\t\t\t\t\t");}

    for(i=0;i<= strlen(target);i++){
        printf("%c",emptyword[i]);
    }
    printf("\n\n What is your guess :");
    scanf(" %c",&guess);
    for(i=0;i<=strlen(target);i++){
        if(guess == target[i]){
            emptyword[i] = guess;
            x++;
        }
    }
    if(x==0){
        b++;
    }

    }while(strcmp(emptyword, target) != 0 && b < 6);
    system("cls");
    if(b == 5 || b == 6){
        system("cls");
        printf("You lost!!! the correct word was %s\n", target);
        printf("press any number to go back to menu:");
        scanf("%d", &choice);
        Loading1();
        main();
    }
    else if(strcmp(emptyword, target) == 0){
        system("cls");
        printf("Congratulations You won!!!\n");
        printf("press any number to go back to menu:");
        scanf("%d", &choice);
        Loading1();
        main();
    }

}

/* ====================================================================================== */


void Wordle(){
    char res[5];
    int k = 3;
    int randomnum;
    char words[][6] = {"table", "guest" , "angle", "entry", "first"};
    char target[6];
    int clp, choice;
    int cl;
    system("cls");
    srand(time(NULL)); /* set the seed for the rand() */
    randomnum = rand() % 5; /* this generates a number (0,1,2,3,4) */
    strcpy(target, words[randomnum]); /* this copies the word says we got randomnum = 0 then target will equal Table */
    do{
    printf("\t\t\t %d tries left\n", k);
    printf("Please enter your word (5 letters) :");
    scanf("%s", &res);
    if(strlen(res) > 5 || strlen(res) < 5){
        k++;
        printf("\nplease insert a word of 5 letters\n\n\n");
    }
    clp = 0;
    cl = 0;
    if(res[0] == target[0]){
            clp++;
    }
    if(res[1] == target[1]){
            clp++;
    }
    if(res[2] == target[2]){
            clp++;
    }
    if(res[3] == target[3]){
            clp++;
    }
    if(res[4] == target[4]){
            clp++;
    }
    if(res[0] == target[1] || res[0] == target[2] || res[0] == target[3] || res[0] == target[4]){
        cl++;
    }
    if(res[1] == target[0] || res[1] == target[2] || res[1] == target[3] || res[1] == target[4]){
        cl++;
    }
    if(res[2] == target[0] || res[2] == target[1] || res[2] == target[3] || res[2] == target[4]){
        cl++;
    }
    if(res[3] == target[0] || res[3] == target[1] || res[3] == target[2] || res[3] == target[4]){
        cl++;
    }
    if(res[4] == target[0] || res[4] == target[1] || res[4] == target[2] || res[4] == target[3]){
        cl++;
    }
    if(strlen(res) == 5){
    printf("\n\n\n\t\t\t %d Letters that are correct and in the right spot\n", clp);
    printf("\t\t\t %d Letters that are correct but in the wrong spot\n", cl);
    printf("\t\t\t %d Letters that are wrong\n", 5-(clp+cl));
    }
    if(clp != 5){
        k--;
    }
    }while(clp != 5 && k > 0);
    if(k <= 0){
        system("cls");
        printf("The correct word was %s \n\n", target);
        printf("press any number to go back to menu");
        scanf("%d", &choice);
        Loading1();
        main();
    }
    else if(clp == 5){
        system("cls");
        printf("Congratulations!!! You won\n\n");
        printf("\n press any number to go back to menu");
        scanf("%d", &choice);
        Loading1();
        main();
    }
}

/* ====================================================================================== */


void Loading1(){
        printf("\n\n\n\n\n\n\n \t\t\t\t Please wait a moment");
        printf("\n\t\t\t\t   Loading.");
        printf("\n\t\t\t\t\t {=            }");
        _sleep(100);
        system("cls");
        printf("\n\n\n\n\n\n\n \t\t\t\t Please wait a moment");
        printf("\n\t\t\t\t   Loading..");
        printf("\n\t\t\t\t\t {==           }");
        _sleep(100);
        system("cls");
        printf("\n\n\n\n\n\n\n \t\t\t\t Please wait a moment");
        printf("\n\t\t\t\t   Loading...");
        printf("\n\t\t\t\t\t {===          }");
        _sleep(100);
        system("cls");
        printf("\n\n\n\n\n\n\n \t\t\t\t Please wait a moment");
        printf("\n\t\t\t\t   Loading...");
        printf("\n\t\t\t\t\t {====         }");
        _sleep(100);
        system("cls");
        printf("\n\n\n\n\n\n\n \t\t\t\t Please wait a moment");
        printf("\n\t\t\t\t   Loading.");
        printf("\n\t\t\t\t\t {=====        }");
        _sleep(100);
        system("cls");
        printf("\n\n\n\n\n\n\n \t\t\t\t Please wait a moment");
        printf("\n\t\t\t\t   Loading..");
        printf("\n\t\t\t\t\t {======       }");
        _sleep(100);
        system("cls");
        printf("\n\n\n\n\n\n\n \t\t\t\t Please wait a moment");
        printf("\n\t\t\t\t   Loading..");
        printf("\n\t\t\t\t\t {=======      }");
        _sleep(100);
        system("cls");
        printf("\n\n\n\n\n\n\n \t\t\t\t Please wait a moment");
        printf("\n\t\t\t\t   Loading...");
        printf("\n\t\t\t\t\t {========     }");
        _sleep(100);
        system("cls");
        printf("\n\n\n\n\n\n\n \t\t\t\t Please wait a moment");
        printf("\n\t\t\t\t   Loading.");
        printf("\n\t\t\t\t\t {=========    }");
        _sleep(100);
        system("cls");
        printf("\n\n\n\n\n\n\n \t\t\t\t Please wait a moment");
        printf("\n\t\t\t\t   Loading.");
        printf("\n\t\t\t\t\t {===========  }");
        _sleep(100);
        system("cls");
        printf("\n\n\n\n\n\n\n \t\t\t\t Please wait a moment");
        printf("\n\t\t\t\t   Loading...");
        printf("\n\t\t\t\t\t {=============}");
        _sleep(100);
        system("cls");

}

/* ====================================================================================== */


