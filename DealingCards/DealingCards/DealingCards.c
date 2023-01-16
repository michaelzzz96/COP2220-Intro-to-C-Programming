/*
 * File name:		DealingCards.c	
 * Name:			Michael Zulfekar
 * Course:			COP 2220C at Valencia College
 * Instructor:		David Stendel 
 * Description:		Display the random selection of 5 cards out of a deck of 52 cards by letting 
 *					the user enter the the number of players between 2-10 and output the result by
 *					displaying the player number with the number of cards selected towards them. 
 * Team Members:	N/A
 * Date:			7/1/17
 */

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define SIZE 5
#define SUITS 4
#define FACES 13
#define AVAILABLE 0
#define TAKEN 1

// Prototypes
void dealACard(char *suits[], char *faces[], int deck[][FACES]);
void dealAHand(char *suits[], char *faces[], int deck[][FACES]);

/* 
 * Name:			main()
 * Parameters:		None.
 * Processes:		Display the random selection of 5 cards out of a deck of 52 cards by letting 
 *					the user enter the the number of players between 2-10 and output the result by
 *					displaying the player number with the number of cards selected towards them. 
 * Return Value:	An integer representing an error code; if the program ends without error, zero 
 *					will be returned to the calling program or operating system. 
 */
 int main() 
 {
	 // Variables 
	 char *suits[SUITS] = { "Hearts", "Diamonds", "Spades", "Clubs" };
	 char *faces[FACES] = { "Two", "Three", "Four", "Five", "Six", "Seven",
		 "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };
	 int deck[SUITS][FACES] = { AVAILABLE };
	 int choice = 0, i = 0;

	// Input
	printf("Enter the number of players: ");
	scanf_s("%i", &choice);

	while (choice <= 1 || choice >= 11)
		{
			printf("\t There must be between 2 - 10 players.\n");
			printf("Enter the number of players: ");
			scanf_s("%i", &choice);
		}
	
	// Seed the random number generator.
	srand(time(NULL));

	for (i = 0; i < choice; i++)
	{ 
		// Ourput 
		printf("Player #%i's cards are: \n", i + 1);
		dealAHand(suits, faces, deck);
	}
	system("pause");
	return 0;
}

 /* 
  * Name:			dealAHand()
  * Parameters:		suits	Array of the number of suits in a deck
  *					faces	Array deck Array of corresponding to the number of faces cards in a deck.
  *					size	Size of the arrays; Range: > 0.
  *					deck	The address of the variable for the number of cards in a deck of 52 card.
  * Processes:		Determine and count the 5 random cards based on the deck.
  * Return Value:	None.
 */
void dealAHand(char *suits[], char *faces[], int deck[][FACES])
{
	// Variables
	int i = 0;
	for (i = 0; i < SIZE; i++)
		dealACard(suits, faces, deck);
	// Output
	printf("\n");
}

 /* 
  * Name:			dealACard()
  * Parameters:		suits	Array of the number of suits in a deck
  *					faces	Array deck Array of corresponding to the number of faces cards in a deck.
  *					size	Size of the arrays; Range: > 0.
  *					deck	The address of the variable for the number of cards in a deck of 52 card.
  * Processes:		Determine and count the 5 random cards based on the deck.
  * Return Value:	A randon
  card displayed with a random face and suit.
 */
void dealACard(char *suits[], char *faces[],int deck[][FACES ]) 
{
	// Variables
	int suitIndex = 0, faceIndex = 0;

	suitIndex = rand() % SUITS;
	faceIndex = rand() % 13;
	while (deck[suitIndex][faceIndex] == TAKEN)
	{
		suitIndex = rand() % SUITS;
		faceIndex = rand() % FACES;
	}
	deck[suitIndex][faceIndex] = TAKEN;
	
	// Output 
	printf("%s of %s \n", faces[faceIndex], suits[suitIndex]);
}
