#include <stdio.h>
#include <stdlib.h>

//Prototypes
void gameMenu();
void multiplayer();
void singleplayer();

/*
Input : none
Function : main entry point of the programm
Output : integer (0 if execution went correctly or 1 if it didn't)
*/
int main() {

  gameMenu();

  return 0;
}

/*
Input : none
Function : Displays the menu and redirects the player
according to their choice.
Output : none
*/
void gameMenu() {
  int gameRunning = 1;

  while (gameRunning) {
    //Display the whole menu
    printf("Welcome to Rock Paper scissors\n");
    printf("What would you like to do ?\n");

    //Skip a line
    printf("\n");

    //Give the choices to the player
    printf("Press 1 to play multiplayer\n");
    printf("Press 2 to play singleplayer\n");
    printf("Press 3 to suit\n");

    //Get the input from the user
    char input[] = "";
    gets(input);

    //Compare the input
    if(input == "1") multiplayer();
    if(input == "2") singleplayer();
    if(input == "3") gameRunning = 0;
  }
}

/*
Input : none
Function : This is the multiplayer part of the gameplay
Output : none
*/
void multiplayer() {
  //Player strings
  char player1[] = "";
  char player2[] = "";

  //Rock = 1
  //Paper = 2
  //scissors = 3

  //Input string
  char input[] = "";

  //Enunciate the different options to both players and get their input
  printf("Player 1:\n");
  printf("Enter 1 for rock, 2 for paper and 3 for scissors\n");

  gets(input);
  player1 = input;

  printf("Player 2:\n");
  printf("Enter 1 for rock, 2 for paper and 3 for scissors\n");

  gets(input);
  player2 = input;

  //Check for the different win possibilities and announce the winner
  char result[] = "";
  result = checkWin(player1, player2);

  printf("Player " + result + " wins !\n");

  //Skip a line before returning into the menu loop
  printf("\n");
}
