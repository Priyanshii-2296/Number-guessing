#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Global balances so they are accessible inside play() */
int dp1, dp2;

/* Function declarations */
void printstar(void);
void printdollar(void);
void play(void);

/* Print stars */
void printstar(void)
{
    int i;
    for (i = 0; i < 30; i++)
        printf(" * ");
}

/* Print dollars */
void printdollar(void)
{
    int i;
    for (i = 0; i < 30; i++)
        printf(" $$ ");
}

/* ====================== PLAY FUNCTION ====================== */
void play(void)
{
    int bet1, bet2;
    int guess1, guess2;
    int computer;
    int choice;

    /* Betting amount */
    printf("\nPLAYER 1 ENTER BET AMOUNT ($): ");
    scanf("%d", &bet1);

    printf("PLAYER 2 ENTER BET AMOUNT ($): ");
    scanf("%d", &bet2);

    /* Generate winning number */
    computer = rand() % 36;   // 0 to 35

    printstar();
    printf("\nROULETTE WHEEL IS SPINNING...\n");
    printstar();

    /* Player guesses */
    do {
        printf("\nPLAYER 1 ENTER NUMBER (0-35): ");
        scanf("%d", &guess1);
    } while (guess1 < 0 || guess1 > 35);

    do {
        printf("\nPLAYER 2 ENTER NUMBER (0-35): ");
        scanf("%d", &guess2);
    } while (guess2 < 0 || guess2 > 35);

    /* Reveal result */
    printf("\n\nWINNING NUMBER IS: %d\n", computer);

    /* Player 1 result */
    if (guess1 == computer) {
        dp1 += bet1 * 36;
        printf("PLAYER 1 WON! Balance: $%d\n", dp1);
    } else {
        dp1 -= bet1;
        printf("PLAYER 1 LOST! Balance: $%d\n", dp1);
    }

    /* Player 2 result */
    if (guess2 == computer) {
        dp2 += bet2 * 36;
        printf("PLAYER 2 WON! Balance: $%d\n", dp2);
    } else {
        dp2 -= bet2;
        printf("PLAYER 2 LOST! Balance: $%d\n", dp2);
    }

    /* Play again */
    printf("\nPress 1 to play again\nPress 2 to exit\n");
    scanf("%d", &choice);

    if (choice == 1)
        play();
    else
        printf("\nTHANK YOU FOR PLAYING!\n");
}

/* ====================== MAIN FUNCTION ====================== */
int main(void)
{
    char name1[20], surname1[20];
    char name2[20], surname2[20];

    srand(time(NULL));   // Seed random number

    printdollar();
    printf("\n");
    printstar();
    printf("\n   CCCCCC           A         SSSSSSSSS      IIIIIIIIIII    NN       NN   OOOOOOOO ");
    printf("\n CC               A    A      SS                 III        NN  N    NN  OO      OO");
    printf("\nCC               A      A     SSSSSSSSS          III        NN    N  NN  OO      OO");
    printf("\n CC              AAAAAAAA            SS          III        NN     N NN  OO      OO ");
    printf("\n   CCCCCC      A          A   SSSSSSSSS      IIIIIIIIIII    NN       NN   OOOOOOOO   ");
    printf("\n");
    printstar();
    printf("\n");
    printdollar();

    /* Player details */
    printf("\n\nENTER PLAYER 1 NAME & SURNAME: ");
    scanf("%s %s", name1, surname1);

    printf("ENTER PLAYER 2 NAME & SURNAME: ");
    scanf("%s %s", name2, surname2);

    printf("\nENTER DEPOSIT FOR PLAYER 1: ");
    scanf("%d", &dp1);

    printf("ENTER DEPOSIT FOR PLAYER 2: ");
    scanf("%d", &dp2);

    printf("\nPLAYER 1 BALANCE: $%d", dp1);
    printf("\nPLAYER 2 BALANCE: $%d\n", dp2);

    printstar();

    play();

    return 0;
}
