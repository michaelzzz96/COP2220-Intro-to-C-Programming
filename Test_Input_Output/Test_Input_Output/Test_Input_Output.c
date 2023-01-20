/*
 *          	    TestInputOutput.c
 * Name:			Michael Zulfekar
 * Course:			COP 2220C at Valencia College
 * Instructor:		David Stendel 
 * Description:		Displays my name, address, age, and grade.
 * Team Members:	N/A
 * Date:			5/17/17
 */

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>

/*
 * Name:			main()
 * Parameters:		None.
 * Processes:		Displays my name, address, age, and grade.
 * Return Value:	An integer representing an error code; if the program ends without error, zero 
 *					will be returned to the calling program or operating system. 
 */
int main()
{
	// Variables
	int age = 20;
	double grade = 93.20;

	// Output
	printf("Michael Zulfekar\n");
	printf("1234 Somewhere St., Orlando, FL 32825\n");
	printf("Age: %i \n", age);
	printf("Grade: %lf \n", grade);
	
	system("pause");
	return 0;
}

