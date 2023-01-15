/*
* File name:	ArrayGrades.c
* Name:			Michael Zulfekar
* Course:		COP 2220
* Instructor:	David Stendel
* Description:	User enter 10 test scores. The pass mark is 70%.
*				Calculate the average score.
*				How many students passed the test by the letter grades
*				they recieved by displaying the results. 
* Team Members: N/A
* Date:			6/8/17
*/

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>

// Constants
#define SCORES_COUNT 10
#define HIGH_SCORE 100
#define A 90
#define B 80
#define C 70
#define D 60

/*
* Name:			main()
* Parameters:	None.
* Processes:	User enter 10 test scores. The pass mark is 70%. Calculate the
*				average score, and how many  students  passed the test by
*				how many A’s, B’s, C’s, and D’s as you display the results.
* Return Value: An integer representing an error code; if the program ends without error, zero
*				will be returned to the calling program or operating system.
*/
int main()
{
// Variables
int grades[HIGH_SCORE] = {0.0}, test = 0, total = 0, i = 0, passingScores = 0, a = 0, b = 0, c = 0, d = 0, f = 0;
double average = 0.0;

// Input 
for (i = 0; i < SCORES_COUNT; i++)
{
	printf("Enter score for student %i: ", i + 1);
	scanf("%i", &test);

	if (test >= 0 && test <= HIGH_SCORE)
	{
		grades[i] = test;
	}
	else
	{
		printf("Score is not valid! Try again\n");
		i--;
	}
}

// Calculation
	for (i = 0; i < SCORES_COUNT; i++)
	{
		total += grades[i];
	if (grades[i] >= A)
	{
		a++;
		passingScores++;
	}
	else
	{
		if (grades[i] >= B)
		{
			b++;
			passingScores++;
		}
		else
		{
			if (grades[i] >= C)
			{
				c++;
				passingScores++;
			}
			else
			{
				if (grades[i] >= D)
				{
					d++;
				}
				else
				{
					f++;
				}
			}
		}
	}
}

// Average Calculation
average = (double)total / SCORES_COUNT;

// Output
printf("The  average of the grades is %.2f.\n", average);
printf("There are %i students, who passed.\n", passingScores);
printf("Grade Distribution\n");
printf("A: %i\n", a);
printf("B: %i\n", b);
printf("C: %i\n", c);
printf("D: %i\n", d);
printf("F: %i\n", f);
system("pause");
return 0;
}


