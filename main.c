#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Prototypes
void gameMenu();
void multiplayer();
void singleplayer();
int checkWin();

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
Function : This is the multiplayer part of the gameplay
Output : none
*/
void multiplayer() {
  printf("In multiplayer function \n"); //DEBUG

  //Player strings
  char *player1;
  char *player2;

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
  int result;
  result = checkWin(player1, player2);

  //Concatenate strings in order to announce the result
  //Find a better way later
  char *str;

  printf("Player ");
  sprintf(str, "%d", result);
  printf(" wins !\n");

  //Skip a line before returning into the menu loop
  printf("\n");
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
    printf("Press 3 to quit\n");

    //Get the input from the user
    char input[] = "poop";
    gets(input);

    //Compare the input
    if(input == "1") multiplayer();
    if(input == "2") singleplayer();
    if(input == "3") gameRunning = 0;
  }
}



/*
Input : none
Function : Conatains the singleplayer part of the gameplay with the AI
Output : none
*/
void singleplayer() {

  //Print a message and wait for input to go back to the menu
  printf("This part is currently empty");
  printf("Press any key to go back to the menu");

  char input[] = "";
  gets(input);

  return;
}
/*
Input : Player1 and Player2 entries (strings)
Function : Returns a value depending on who won
Output : Value of the winner
*/
int checkWin(char *entry1, char *entry2) {
  //Win possibilities for player 1
  char* winPlayer1[3] = {"13", "32", "21"};

  //Win possibilities for player 2
  char* winPlayer2[3] = {"31", "23", "12"};

  //Combine both entries
  char *combination;
  combination = strcat(entry1, entry2);

  //Compare the combination to all the win possibilities
  if (combination == winPlayer1[0] || combination == winPlayer1[1] || combination == winPlayer1[2]) {
    return "1";
  };

  if (combination == winPlayer2[0] || combination == winPlayer2[1] || combination == winPlayer2[2]) {
    return "2";
  } else {
    return -1;
  };
}
