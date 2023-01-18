/*
*	File name:		FunctionCalculator.c
*	Name:			Michael Zulfekar
*	Course:			COP 2220C at Valencia College
*	Instructor:		David Stendel
*	Description:	This program is uses functions to call an operation to get 	
					valid numbers, add, subtract, multiply, Divide, Calculate the 
					Average, Find the largest and smallest numbers a user enters. 
					It will display the value of the result depending on what the number the user 
					selects, and will display the result.
*	Team Members:	N/A
*	Date:			6/8/17
*/

/*
*	Name:			main()
*	Parameters:		(double number[], int size)
*	Processes:		This program is uses functions to call an operation to get 	
					valid numbers, add, subtract, multiply, Divide, Calculate the 
					Average, Find the largest and smallest numbers a user enters. 
					It will display the value of the result depending on what the number the user 
					selects, and will display the result.
*	Return Value:	An integer representing an error code; if the program ends without error,
					zero will be returned to the calling program or operating system.
*/

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>


// Constants
#define SIZE 3

// Welcome Message Menu
void welcomeMessage() 
{
	printf("\t Array Calculator\n");
printf("(G)et 3 numbers.\n");
printf("(A)dd.\n");
printf("(S)Subtract.\n");
printf("(M)ultiply.\n");
printf("(D)ivide.\n");
printf("(C)alculate the average.\n");
printf("Find the (L)argest.\n");
printf("(F)ind the smallest.\n");
printf("E(X)it.\n");
}

double getValidNumber()
{
		double result;

		printf("Enter a number:  ");
		scanf_s("%lf", &result);

		return result;
}

// Sum Function
double calculateTotal(double number[], int size)
{
		double result = 0.0;
		int i;
		for (i = 0; i < SIZE; i++)
		{
				result += number[i];
		}
		return result;
}

// Largest Number Function
double findLargest(double number[], int size)
{
		double result = 0.0;
		int i;
		for (i = 0; i < size; i++)
		{
		if (number[i] > result)
		result = number[i];
		}
		return result;
}

// Smallest Number Function
double findSmallest(double number[], int size)
{
		double result = number[0];
		int i;
		for (i = 0; i < size; i++)
		{
		if (number[i] < result)
		result = number[i];
		}	
		return result;
}

// Multiply Function
double findProduct(double number[], int size)
{
		double multiply = 0.0;
		double result = number[0];
		int i;
		for (i = 0; i < size; i++)
		{
		result = result * number[i];
		}
		return result;
}

// Find Difference Function
double findSubtraction(double number[], int size)
{
		double subtraction = 0.0;
		double result = number[0];
		int i;
		for (i = 0; i < size; i++)
		{
		result = result - number[i];
		}
		return result;
}

// Find Divide Function
double findDivide(double number[], int size)
{
		double divide = 0.0;
		double result = 0.0;
		int i;
		for (i = 0; i < size; i++)
		{
		result = result / number[i];
		}
		return result;
}

// Main Function
int main(void)
{
	double number[SIZE], totalNumber, averageNumber,
	largestNumber, smallestNumber, productNumber, subtractNumber, division;
	char choice = 0;
	int i = 0, sum = 0, subtraction = 0, multiply = 0, largest = 0, num = 0, smallest = 0;

	while (choice != 'X')
	{
		welcomeMessage();
		scanf_s(" %c", &choice);

		switch (choice)
		{
			case 'G':
				for (i = 0; i < SIZE; i++)
					number[i] = getValidNumber();
				break;
			case 'g':
				for (i = 0; i < SIZE; i++)
					number[i] = getValidNumber();
				break;
			case 'A':
				sum = calculateTotal(number, SIZE);
				printf("Sum equals %d\n", sum);
				break;
			case 'a':
				sum = calculateTotal(number, SIZE);
				printf("Sum equals %d\n", sum);
				break;
			case 'S':
				subtraction = findSubtraction(number, SIZE);
				printf("Difference equals %d\n", subtraction);
				break;
			case 's':
				subtraction = findSubtraction(number, SIZE);
				printf("Difference equals %d\n", subtraction);
				break;
			case 'M':
				multiply = findProduct(number, SIZE);
				printf("Product equals %d\n", multiply);
				break;
			case 'm':
				multiply = findProduct(number, SIZE);
				printf("Product equals %d\n", multiply);
				break;
			case 'D':
				division = findDivide(number, SIZE);
				printf("Quotient equals %d\n", division);
				break;
            case 'd':
				division = findDivide(number, SIZE);
				printf("Quotient equals %d\n", division);
				break;
			case 'C':
				sum = calculateTotal(number, SIZE); 
				averageNumber = sum / SIZE;
				printf("Average equals %lf\n", averageNumber);
				break;
			case 'c':
				sum = calculateTotal(number, SIZE); 
				averageNumber = sum / SIZE;
				printf("Average equals %lf\n", averageNumber);
				break;
			case 'L':
				largest = findLargest(number, SIZE);
				printf("Largest number equals %d\n", largest);
				break;
			case 'l':
				largest = findLargest(number, SIZE);
				printf("Largest number equals %d\n", largest);
				break;
			case 'F':
				smallest = findSmallest(number, SIZE);
				printf("Smallest number equals %d\n", smallest);
				break;
			case 'f':
				smallest = findSmallest(number, SIZE);
				printf("Smallest number equals %d\n", smallest);
				break;
			case 'X':
				printf("Thank you for using the program! Goodbye!\n");
				break;
			case 'x':
				printf("Thank you for using the program! Goodbye!\n");
				break;
		}
	}
	system("pause");
	return 0;
}
