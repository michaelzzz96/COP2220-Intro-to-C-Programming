/*
 * File name:		Grades.c
 * Name:			Michael Zulfekar
 * Course:			COP 2220C at Valencia College
 * Instructor:		David Stendel 
 * Description:		Ask the user to enter 10 test scores.
					The pass mark is 70%.
					Calculate the average score, and count how many
					of the students have passed the test.
 * Team Members:	N/A
 * Date:			6/1/16
 */

//Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>


/*
 * Name:			main()
 * Parameters:		None.
 * Processes:		User enters grades 10 times for passing score of 70.
 * Return Value:	An integer representing an error code; if the program ends without error, zero 
 *					will be returned to the calling program or operating system. 
 */

//Constants
#define SCORES_COUNT 10
#define PASSING_SCORE 70


int main()
	{
	int scores[SCORES_COUNT];
	int total = 0, i, passingScores = 0;
	double average;

	for (i = 0; i < SCORES_COUNT; i++)
	{
		printf("Enter score for student %i:\t", i + 1);
		
		scanf("%i", &scores[i]);
	}
	for (i = 0; i < SCORES_COUNT; i++)
	{
		total += scores[i];

	if (scores[i]>= PASSING_SCORE) 
	{
		passingScores++;
	}
}
	//Calculation
	average = (double) total / SCORES_COUNT;

	// Output
	printf("The class average is %.2lf\n", average);
	printf("%i students passed.\n", passingScores);	
	system("pause");
	return 0;
}
