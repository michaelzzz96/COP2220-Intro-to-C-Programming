/*
 * File name:		DynamicMemory.c
 * Name:			Michael Zulfekar
 * Course:			COP 2220C at Valencia College
 * Instructor:		David Stendel 
 * Description:		Ask the user to input the customer name, ID, and amount owing from the user's input
 *					and output the customer info as a table.
 * Team Members:	N/A
 * Date:			7/15/17
 */

//  Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures and Unions
typedef struct 
{
    char name[40];
    int customerID;
    double amountOwing;
} 
Customer;

// User-Defined Types
Customer *makeACustomer() 
{
    Customer *result;

    result = malloc(sizeof(Customer));

    return result;
}

// Prototypes
void getCustomerInfo(Customer *customer);
void displayCustomers(Customer **customer, int numCustomers);

/*
 * Name:			main()
 * Parameters:		None.
 * Processes:		Ask the user to input the customer name, ID, and amount owing from the user's input
 *					and output the customer info as a table.
 * Return Value:	An integer representing an error code; if the program ends without error, zero 
 *					will be returned to the calling program or operating system. 
 */
int main() 
{
	// Variables
    int i;
    char choice = 0;

    Customer **myIndividualCustomers;

    myIndividualCustomers = calloc(10, sizeof(Customer *));

	// Calculations
    for (i = 0; i < 10 && choice != 'n'; i++) 
    {
        myIndividualCustomers[i] = makeACustomer();
        getCustomerInfo(myIndividualCustomers[i]);
        printf("\nDo you wish to enter another Customer? [Y/N]");
        scanf(" %c", &choice);
        choice = tolower(choice);
    }
    
    displayCustomers(myIndividualCustomers, i);

    system("pause");
    return 0;
}

 /* 
  * Name:			getCustomerInfo()
  * Parameters:		Customer	Structure to obtain data types of the customer info; Range: any.
  *					customer	Address of a variable for the resulting info of Customr.
  * Processes:		Get the customer's information by the user's input.
  * Return Value:	None.
 */
void getCustomerInfo(Customer *customer) 
{
    printf("Enter the customer name: ");
    scanf("%s", customer->name);
    printf("\nEnter the customer ID: ");
    scanf("%i", &customer->customerID);
    printf("\nEnter amount owing: ");
    scanf("%lf", &customer->amountOwing);
}

 /* 
  * Name:			displayCustomers()
  * Parameters:		Customer	  Structure to obtain data types of the customer info; Range: any.
  *					customer	  Address of a variable for the resulting info of Customr.
  *					numCustomers  Total number of customer; Range: any.
  * Processes:		Display customer's information by the user's input as a table.
  * Return Value:	Customer name, ID, and owing.
 */
void displayCustomers(Customer **customer, int numCustomers)
{
	// Variables
    int i = 0;
	// Header
    printf("\t\t\Customers\n");
    printf("Name          ID               Owed\n");
	// Calculations
    for (i = 0; i < numCustomers; i++) 
    {
		// Output
        printf("%5.20s %10i %19lf\n", customer[i]->name, customer[i]->customerID,
            customer[i]->amountOwing);
    }
}
