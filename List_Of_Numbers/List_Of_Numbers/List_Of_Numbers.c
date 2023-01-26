/*
 * File name:		ListOfNumbers.c
 * Name:			Michael Zulfekar
 * Course:			COP 2220C at Valencia College
 * Instructor:		David Stendel 
 * Description:		Creates a list of numbers by adding one number to it at a time, and then,
 *					displays the list. Maximum of 100 numbers.
 * Team Members:	N/A
 * Date:			6/29/17
 */

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>

// Prototypes
double getAValue(double data[], int *pEffectiveSize);
void outputArray(double data[], int effectiveSize);

/*
 * Name:			main()
 * Parameters:		None.
 * Processes:		Creates a list of numbers by adding one number to it at a time, and then,
 *					displays the list. Maximum of 100 numbers.
 * Return Value:	An integer representing an error code; if the program ends without error, zero 
 *					will be returned to the calling program or operating system. 
 */
int main()
{
	// Variables
	double big[100], entered;
	int effectiveSize = 0;

	// List Creation
	entered = getAValue(big, &effectiveSize);
	entered = getAValue(big, &effectiveSize);
	entered = getAValue(big, &effectiveSize);

	// Output
	outputArray(big, effectiveSize);

	system("pause");
	return 0;
}

 /* 
  * Name:			getAValue()
  * Parameters:		Data Array of doubles.
  *					pEffectiveSize Address of a variable for the number of entries in the array.
  * Processes:		Get a number from the user, and add it to the list.
  * Return Value:	The number entered by the user.
 */
double getAValue(double data[], int *pEffectiveSize)
{
	// Input
	printf("Enter a double: ");
	scanf_s("%lf", &data[*pEffectiveSize]);
	(*pEffectiveSize)++;
	return data[*pEffectiveSize - 1];
}

 /* 
  * Name:			outputArray()
  * Parameters:		data Array of doubles
  *					effectiveSize The number of entries in the array.
  * Processes:		Display the entries in the list.
  * Return Value:	None.
 */
void outputArray(double data[], int effectiveSize)
{
	// Variables
	int i;
	
	for (i = 0; i < effectiveSize; i++)
		printf("%lf\n", data[i]);
}
