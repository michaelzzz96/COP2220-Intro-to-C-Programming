 /*
 * File name:		ShippingCalculator.c
 * Name:			Michael Zulfekar
 * Course:			COP 2220C at Valencia College
 * Instructor: 		David Stendel 
 * Description:		User must enter the height, length, width and miles used
 *					to calculate the dimentional weight using miles segments.
 *					Each segment is 500 miles. The rates are based on the 
 *   				dimensional weight as weight greater than zero to two 
 *     				pounds is $1.50. Two pounds to six pounds is $3.25, and 
 *					greater than six pounds to ten pounds is $5.00.
 *    				If the user enters the height, length, width, or miles 
 *					as zero, an error message will show up and asked to redo
 *					the input. If user enters the weight that is 20,	
 *					an error message will display to redo that value. The 
 *					calculator cost is display with the tax based on a rate of
 *   				6.5% and the total. The user will be asked to continue
 *					with the next customer or exit.
 *
 * Team Members:	N/A.
 * Date:			5/30/17.
 */

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>

// Constants
#define MILES_SEGMENTS 500
#define TAX_RATE 0.065

/*
 * Name:			int main()
 * Parameters:		None.
 * Processes:		User must enter the height, length, width and miles used
 *					to calculate the dimentional weight using miles segments.
 *					Each segment is 500 miles. The rates are based on the 
 *   				dimensional weight as weight greater than zero to two 
 *     				pounds is $1.50. Two pounds to six pounds is $3.25, and 
 *					greater than six pounds to ten pounds is $5.00.
 *    				If the user enters the height, length, width, or miles 
 *					as zero, an error message will show up and asked to redo
 *					the input. If user enters the weight that is 20,	
 *					an error message will display to redo that value. The 
 *					calculator cost is display with the tax based on a rate of
 *   				6.5% and the total. The user will be asked to continue
 *					with the next customer or exit.            
 * Return Value:	An integer representing an error code; if the program ends without       
 */

int main()
{
	// Variables
	int miles = 0, segments = 0;
	double height = 0.0, length = 0.0, width = 0.0, weight = 0.0, price = 0.0;
	double tax = 0.0, total = 0.0, subtotal = 0.0;
	char choice;

	do
	{
	// Input - Miles
	printf("Enter the number of miles in whole numbers: ");
	scanf_s("%i", &miles);

	// Valadation - Miles
	while (miles <= 0)
	{
		printf("\t Miles must be greater than zero.\n");
		printf("Enter the number of miles in whole numbers: ");
		scanf_s("%i", &miles);
	}

	if (miles % MILES_SEGMENTS) {
		segments = (miles / MILES_SEGMENTS + 1);
	}
	else {
		segments = miles / MILES_SEGMENTS;
	}

	// Input - Height
	printf("Enter the height of the package in inches: ");
	scanf_s("%lf", &height);

	// Valadation - Height
	while (height <= 0)
	{
		printf("\t Height must be greater than zero.\n");
		printf("Enter the height of the package in inches: ");
		scanf_s("%lf", &height);
	}

	// Input - length
	printf("Enter the length of the package in inches: ");
	scanf_s("%lf", &length);

	// Valadation - Height
	while (length <= 0)
	{
		printf("\t length must be greater than zero.\n");
		printf("Enter the length of the package in inches: ");
		scanf_s("%lf", &length);
	}

	// Input - Width
	printf("Enter the width of the package in inches: ");
	scanf_s("%lf", &width);

	// Valadation - Width
	while (width <= 0)
	{
		printf("\t Width must be greater than zero.\n");
		printf("Enter the width of the package in inches: ");
		scanf_s("%lf", &width);
	}

	// Calculation Dementional weight
	weight = (length * height * width) / 166;
	if (weight <= 2)
	{
		price = 1.50;
	}
	else if (weight > 2 && weight <= 6)
	{
		price = 3.25;
	}
	else if (weight > 6 && weight <= 20)
	{
		price = 5.00;
	}

	// Calculations -Mile Segment, Subtotal, Tax, and Total
	subtotal = segments * price;
	tax = subtotal * TAX_RATE;
	total = subtotal + tax;

	// Output 
	printf("\nSubtotal:\t$%5.2f\n", subtotal);
	printf("Tax:\t\t$%5.2f\n", tax);
	printf("Total:\t\t$%5.2f\n\n", total);

	// Repeat to Another Customer?
	printf("Process to next customer [Y/N]:");
	scanf_s(" %c", &choice);


	// Reset the Valid Calculation
	} while (choice == 'Y' || choice == 'y');

	printf("Thank you for using my program. Goodbye!\n");

	system("pause");
	return 0;
}