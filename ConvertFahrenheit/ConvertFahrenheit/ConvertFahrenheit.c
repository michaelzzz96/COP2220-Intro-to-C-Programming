/*
 * File name:		ConvertFahrenheit.c
 * Name:			Michael Zulfekar
 * Course:			COP 2220C at Valencia College
 * Instructor:		David Stendel 
 * Description:		Convert 0 to 300 Fahrenheit to Celsius and Kelvin in steps of 10 with 2 places
 *					of precision, and output as a table.
 * Team Members:	N/A
 * Date:			6/22/17
 */

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>

// Constants
#define MAX_DEGREE 300
#define STEP 10
#define FAHRENHEIT_CELSIUS_RATIO 5.0 / 9.0
#define FAHRENHEIT_CELSIUS_DIFF 32
#define KELVIN_CELSIUS_DIFF 273.15

// Prototypes
void convertTemperature(int fahrenheit, double *pCelsius, double *pKelvin);

/*
 * Name:			main()
 * Parameters:		None.
 * Processes:		Convert 0 to 300 Fahrenheit to Celsius and Kelvin in steps of 10 with 2 places
 *					of precision, and output as a table.
 * Return Value:	An integer representing an error code; if the program ends without error, zero 
 *					will be returned to the calling program or operating system. 
 */
int main()
{
	// Variables
	int fahrenheit;
	double celsius = 0.0, kelvin = 0.0;

	// Headers
	printf("Fahrenheit   Celsius    Kelvin\n");
	printf("==========   =======    ======\n");

	for (fahrenheit = 0; fahrenheit <= MAX_DEGREE; fahrenheit += STEP)
	{
		 // Conversion
		convertTemperature(fahrenheit, &celsius, &kelvin);
		// Output
		printf("%10i%10.2lf%10.2lf\n", fahrenheit, celsius, kelvin);
	}

	system("pause");
	return 0;
}

 /* 
  * Name:			convertTemperature()
  * Parameters:		fahrenheit Total number of Fahrenheit degrees to convert; Range: any.
  *					pCelsius Address of a variable for the resulting degrees of Celsius.
  * Processes:		Convert Fahrenheit to Celsius and Kelvin.
  * Return Value:	None.
  * Note:			The following constants must be defined:
  *					FAHRENHEIT_CELSIUS_RATIO 5.0 / 9.0
  *					FAHRENHEIT_CELSIUS_DIFF 32
  *					KELVIN_CELSIUS_DIFF 273.15
 */

void convertTemperature(int fahrenheit, double *pCelsius, double *pKelvin) 
	{
		// Calculations
		*pCelsius = FAHRENHEIT_CELSIUS_RATIO * (fahrenheit - FAHRENHEIT_CELSIUS_DIFF);
		*pKelvin = *pCelsius + KELVIN_CELSIUS_DIFF;
	}

