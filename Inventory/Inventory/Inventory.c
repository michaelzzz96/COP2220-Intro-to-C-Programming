/*
 * File name:	 Inventory.c
 * Name:		 Michael Zulfekar
 * Course:		 COP 2220C at Valencia College
 * Instructor:	 David Stendel
 * Description:	 Display the inventory by letting the user enter the the name of the product, 
 *				 the number of the products, the availability of the product, the whole sale of the 
 *				 product, and the retail of the product.
 * Team Members: N/A
 * Date:		 7/6/17 
 * 
*/

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures and Unions
typedef struct 
{
    char name[40];
    short int number;
    double wholesale;
    double retail;
    short int onHand;
} Product;

// Prototypes
void fillInProduct(Product[], int* pSize);
void reportInventory(Product[], int*);

/* 
 * Name:			main()
 * Parameters:		None.
 * Processes:		Display the inventory by letting the user enter the the name of the product, 
 *					the number of the products, the availability of the product, the whole sale of the 
 *					product, and the retail of the product.
 * Return Value:	An integer representing an error code; if the program ends without error, zero 
 *					will be returned to the calling program or operating system. 
 */

int main()
{
	// Variables
    int effectiveSize = 0;
    char choice;
    Product inventory[500];

    do 
	{
    fillInProduct(inventory, &effectiveSize);
	// Input
    printf("Process to next inventory [Y/N]: ");
    scanf(" %c", &choice);
    } 
	while (tolower(choice) == 'y');
	// Output
    printf("Thank you for using my program. Goodbye!\n");

    reportInventory(inventory, &effectiveSize);

    system("pause");
    return 0;
}

 /* 
  * Name:			reportInventory()
  * Parameters:		Product inventory	Array of the number of the inventory.
  *					pEffectiveSize	    Address of a variable for the number of inventory in the array.
  *					size				Size of the arrays; Range: > 0.
  * Processes:		Determine the inventory item name, number, availabiltiy, wholesale
  *					and retail of the inventory product based on the user.
  * Return Value:	data Array of the inventory from the user.
 */

void reportInventory(Product inventory[], int *pSize)
{
	// Variables
	int i = 0;
	char stuff[21] = "====================";

	// Output
	printf("  Inventory Report  \n");
	printf("  ================  \n");
	printf(" %-20.20s %-20.20s %-20.20s %-20.20s %-20.20s\n", "Name", "Product Number", "On Hand", "Wholesale", "Retail");
	printf(" %20.20s %20.20s %20.20s %20.20s %20.20s\n", stuff, stuff, stuff, stuff, stuff);

	for (int i = 0; i < *pSize; i++)
	{
		// Output
		printf("%20.20s %20i %20i %20lf %20lf\n", inventory[i].name, inventory[i].number,
			inventory[i].onHand, inventory[i].wholesale, inventory[i].retail);
	}
	if (inventory[i].onHand > 5)
	{
		printf("User must enter 5 items");
	}
}

 /* 
  * Name:			fillInProduct()
  * Parameters:		Product inventory	Array of the number of the inventory.
  *					pEffectiveSize	    Address of a variable for the number of inventory in the array.
  *					size				Size of the arrays; Range: > 0.
  * Processes:		Let the user enter the inventory item name, number, availabiltiy, wholesale
  *					and retail of the inventory and display it to the list.
  * Return Value:	The "Name", "Product Number", "On Hand", "Wholesale", "Retail" entered by the user.
 */
void fillInProduct(Product inventory[], int *pSize) 
{
		// Input
        char string[40];
        printf("Enter the name of the product: ");
        scanf(" %39s", &string);
        strcpy(inventory[*pSize].name, string);
        printf("Enter the number of the product: ");
        scanf("%d", &inventory[*pSize].number);
        printf("Enter the availability of the product: ");
        scanf("%d", &inventory[*pSize].onHand);
        printf("Enter the whole sale of the product: ");
        scanf("%lf", &inventory[*pSize].wholesale);
        printf("Enter the retail of the product: ");
        scanf("%lf", &inventory[*pSize].retail);
        (*pSize)++;
}



