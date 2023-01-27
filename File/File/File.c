/*
* File name:       File.c
* Name:            Michael Zulfekar
* Course:          COP 2220C at Valencia College
* Instructor:      David Stendel
* Description:     This program ask the user to input the customer name, ID, and amount owing
*                  from the user's inputand output the records of the customer info as a table.
* Team Members:    N/A
* Date:            7/15/17
*/

//  Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structures and Unions
typedef struct
{
    char name[40];
    int customerID;
    double amountOwing;
}
Customer;

// Prototypes
void displayCustomers(Customer **customer, int numCustomers);
void getCustomerInfo(Customer *customer);
void saveFile(Customer** allCustomers, int size);
Customer** loadFile(int *size);
Customer *makeACustomer();


/*
* Name:            main()
* Parameters:      None.
* Processes:       This program ask the user to input the customer name, ID, and amount owing
*                  from the user's inputand output the records of the customer info as a table.
* Return Value:    An integer representing an error code; if the program ends without error, zero
*                  will be returned to the calling program or operating system.
*/
int main()
{
    // Variables
    int i, loadedFile = 1, size = 0;
    char choice = 0;

    Customer **myIndividualCustomers = NULL;

    myIndividualCustomers = loadFile(&size);

    for (i = size; i < (size + 10) && choice != 'n'; i++)
    {
        myIndividualCustomers[i] = makeACustomer();
        getCustomerInfo(myIndividualCustomers[i]);

        // Input
        printf("\nDo you wish to enter another Customer? [Y/N]");
        scanf_s(" %c", &choice);
        choice = tolower(choice);
    }

    displayCustomers(myIndividualCustomers, i);

    saveFile(myIndividualCustomers, i);
    system("pause");
    return 0;
}

/*
* Name:           displayCustomers()
* Parameters:     customer      Address of a variable for the resulting info of Customr.
*                 numCustomers  Total number of customer; Range: any.
* Processes:      Display customer's information by the user's input as a table.
* Return Value:   Customer name, ID, and owing.
*/
void displayCustomers(Customer **customer, int numCustomers)
{
    // Variables
    int i = 0;
    FILE* customers = NULL;

    customers = fopen("Deadbeats.txt", "w+");

    if (customers == NULL)
    {
        printf_s("Unable to open Deadbeats.txt.\n");
        return;
    }

    // Header
    printf("\t\t\tCustomers\n");
    fprintf(customers, "\t\t\tCustomers\n");

    printf("Name          ID               Owed\n");
    fprintf(customers, "Name          ID               Owed\n");

    for (i = 0; i < numCustomers; i++)
    {

        // Output
        if (customer[i]->amountOwing > 500)
        {
            printf_s("%5.20s %10i %19lf\n", customer[i]->name, customer[i]->customerID,
                customer[i]->amountOwing);
            fprintf_s(customers, "%5.20s %10i %19lf\n", customer[i]->name, customer[i]->customerID,
                customer[i]->amountOwing);
        }
    }

    fclose(customers);
}


/*
* Name:           getCustomerInfo()
* Parameters:     customer    Address of a variable for the resulting info of Customr.
* Processes:      Get the customer's information by the user's input.
* Return Value:   None.
*/
void getCustomerInfo(Customer *customer)
{
    // Input 
    printf("Enter the customer name: ");
    scanf_s("%s", customer->name, 40);
    printf("\nEnter the customer ID: ");
    scanf_s("%i", &customer->customerID);
    printf("\nEnter amount owing: ");
    scanf_s("%lf", &customer->amountOwing);
}

void saveFile(Customer** allCustomers, int size)
{
    FILE* customers = fopen("Customers.dat", "wb");
    int i = 0;

    if (customers == NULL) {
        printf("Customers files failed to open!\n");
        return;
    }

    fwrite(&size, sizeof(int), 1, customers);
    for (i = 0; i < size; i++)
        fwrite(allCustomers[i], sizeof(Customer), 1, customers);

    fclose(customers);
}


Customer** loadFile(int *size) {
    FILE* customers = fopen("Customers.dat", "rb");
    Customer** allCustomers = NULL;
    int i = 0;

    if (customers == NULL) {
        allCustomers = calloc(10, sizeof(Customer *));
        return allCustomers;
    }

    fread(size, sizeof(int), 1, customers);

    allCustomers = calloc(*size + 1, sizeof(Customer *));

    for (i = 0; i < *size; i++) {
        allCustomers[i] = makeACustomer();
        fread(allCustomers[i], sizeof(Customer), 1, customers);
    }

    fclose(customers);

    return allCustomers;
}



/*
* Name:           *makeACustomer()
* Parameters:     None
* Processes:      result  Address of a variable for the resulting info of Customr.
* Return Value:   None
*/
Customer *makeACustomer()
{
    Customer *result;

    result = malloc(sizeof(Customer));

    return result;
}
