/*
 * File name:		Make_Change.c
 * Name:			Michael Zulfekar
 * Course:			COP 2220C at Valencia College
 * Instructor:		David Stendel 
 * Description:		Convert change input from the user using quarters, dimes, and nickles
					and to display the results.
 * Team Members:	N/A
 * Date:			6/24/17
 */

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>

// Constants
#define QUARTER_DIVISOR 25
#define DIME_DIVISOR 10
#define NICKLES_DIVISOR 5

// Prototypes
void makeChange(double change, int *pQuaters, int *pDimes, int *pNickles, int *pPennies);


/*
 * Name:			main()
 * Parameters:		None.
 * Processes:		Convert change input from the user using quarters, dimes, and nickles
					and to display the results.
 * Return Value:	An integer representing an error code; if the program ends without error, zero 
 *					will be returned to the calling program or operating system. 
 */
int main()
{
	// Variables
	double change;
	int quarters, dimes, nickles, pennies;


	// Input
	printf("Enter the change amount: ");
	scanf_s("%lf", &change);

	// Conversion
	makeChange(change, &quarters, &dimes, &nickles, &pennies);

	// Output
	printf("\nExpected Results:\n");
	printf("Quarters: %d\n", quarters);
	printf("Dimes: %d\n", dimes);
	printf("Nickles: %d\n", nickles);
	printf("Pennies: %d\n\n", pennies);
	printf("Thank you for using the progrm. Goodbye!\n");

	system("pause");
	return 0;
}

 /* 
  * Name:			makeChange()
  * Parameters:		change,  *pQuarters,  *pDimes,  *pNickles,  *pPennies
  *
  * Processes:		Convert change input from the user using quarters, dimes, and nickles
					and to display the results.
  * Return Value:	None.
  * Note:			The following constants must be defined:
  *					QUARTER 25
  *					DIME 10
  *					NICKLES 5
 */

	void makeChange(double change, int *pQuarters, int *pDimes, int *pNickles, int *pPennies)
	{
	 
		int remainingAmount = (int)(change * 100);


        // Find the number of quarters in the remaining amount
        *pQuarters = remainingAmount / QUARTER_DIVISOR;
        remainingAmount = remainingAmount % QUARTER_DIVISOR;

        // Find the number of dimes  in the remaining amount
         *pDimes = remainingAmount / DIME_DIVISOR;
        remainingAmount = remainingAmount % DIME_DIVISOR;

        // Find the number of nickels in the remaining amount
         *pNickles = remainingAmount / NICKLES_DIVISOR;
        remainingAmount = remainingAmount % NICKLES_DIVISOR;

        // Find the number of pennies in the remaining amount
         *pPennies = remainingAmount ;

	}
