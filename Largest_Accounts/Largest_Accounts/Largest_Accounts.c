/*
 * File name:		LargestAccounts.c	
 * Name:			Michael Zulfekar
 * Course:			COP 2220C at Valencia College
 * Instructor:		David Stendel 
 * Description:		Display the largest accounts and the amounts they owe.
 * Team Members:	N/A
 * Date:			6/29/17
 */

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>

// Constants
#define SIZE 6
#define THRESHOLD 40

// Prototypes
int countLargeAccounts(int account[], double balanceDue[], int size, double threshold);
void getLargestAccount(int account[], double balanceDue[], int size, int *pAccount, 
		double *pAmount);

/* 
 * Name:			main()
 * Parameters:		None.
 * Processes:		Display the largest accounts and the amounts they owe.
 * Return Value:	An integer representing an error code; if the program ends without error, zero 
 *					will be returned to the calling program or operating system. 
 */
int main()
{
	// Variables
	int account[] = {12345, 67589, 74942, 34325, 80492}, countLarge = 0, maxAccount = 0;
	double balanceDue[] = {19.95, 23.50, 0.00, 68.45, 46.89, 19.95}, maxAmount = 0.0;
	
	countLarge = countLargeAccounts(account, balanceDue, SIZE, THRESHOLD);
	getLargestAccount(account, balanceDue, SIZE, &maxAccount, &maxAmount);
	
	// Output
	printf("\nThe largest account is %i with an amount of %f \n", account, balanceDue);
	
	system("pause");
	return 0;
}

/* 
  * Name:			countLargeAccounts()
  * Parameters:		account Array of account numbers.
  *					balanceDue	Array of corresponding balances due.
  *					size		Size of the arrays; Range: > 0.
  *					threshold	The number to indicate which accounts are larger; Range: >= 0.
  * Processes:		Determine, count, and display the largest accounts based on the threshold.
  * Return Value:	The number of accounts larger than the threshold.
 */
	int countLargeAccounts(int account[], double balanceDue[], int size, double threshold) 
	{
	// Variables
	int i, countLarge = 0;

	for (i = 0; i < size; i++) 
	{
		if (balanceDue[i] > threshold)
		{
				countLarge++;
				
				// Output
				printf("Account: %i owes %.2f\n", account[i], balanceDue[i]);
		}
	}
	
	return countLarge;
}

/* 
  * Name:			getLargestAccount()
  * Parameters:		account Array of account numbers.
  *					balanceDue Array of corresponding balances due.
  *					size Size of the arrays; Range: > 0.
  *					pAccount	The address of the variable for the largest account number.
  *					pAmount		The address of the variable for the amount of the largest account.
  * Processes:		Determine the account number and amount of the largest account.
  * Return Value:	None.
 */
void getLargestAccount(int account[], double balanceDue[], int size, int *pAccount, 
		double *pAmount) 
{
	// Variables
	double largeAccount = 0.0;
	int i, location = 0;
	
	for (i = 0; i < size; i++) 
	{
		if (balanceDue[i] > largeAccount)
		{
			largeAccount = balanceDue[i];
			location = i;
		}
	}

	*pAccount = account[location];
	*pAmount = balanceDue[location];
}
