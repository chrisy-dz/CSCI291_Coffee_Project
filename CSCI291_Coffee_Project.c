// Including library headers needed for the working of the code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

// Defining given constants for coffee beans, water, milk, and chocolate syrup individually for each coffee type.
#define coffee_beans 8              
#define water_for_espresso 30

#define water_for_cappucino 30
#define milk_for_cappucino 70

#define water_for_mocha 39
#define milk_for_mocha 160
#define chocolate_syrup_for_mocha 30

// Defining admin password
#define admin_password "admin"

// Defining threshold for each ingredient
#define threshold_for_coffee_beans 24
#define threshold_for_water 150
#define threshold_for_milk 230
#define threshold_for_chocolate_syrup 60

double price_for_espresso = 3.5;
double price_for_cappucino = 4.5;
double price_for_mocha = 5.5;

// Assigning threshold values to integers so that we can call and alter during the execution of the code 
int beans = threshold_for_coffee_beans;
int water = threshold_for_water;
int milk = threshold_for_milk;
int chocolate_syrup = threshold_for_chocolate_syrup;

int main()
{
    int input; // User input to display the menu-driven interface to the user
    double total_amount = 0; // Initializing a double variable to store total sales and the current order total
    do {
        // Using printf to display the menu-driven interface
        printf("\n.........................................\n");
        printf("Welcome to CAFEine Coffee Vending Machine\n");
        printf(".........................................\n");
        printf("Select 1 to Order Coffee\n");
        printf("Select 2 to go to Admin Mode\n");
        printf("Select 0 to Exit\n");
        printf("Select an option: "); // Prompting the user to input 
        scanf("%d", &input); // Reading user input for the menu-driven interface

        if (input == 1) // User chooses to order coffee
        {
            int coffeeType, order; // Adding order to allow multiple orders
            double cart = 0; // To track the order added to the cart

            do {
                // Using printf to display the options along with the price in AED 
                printf("\n..........................................\n");
                printf("         Welcome to Coffee Menu\n");
                printf("..........................................\n");
                printf("Select 1 for Espresso (AED %.2f)\n", price_for_espresso);
                printf("Select 2 for Cappuccino (AED %.2f)\n", price_for_cappucino);
                printf("Select 3 for Mocha (AED %.2f)\n", price_for_mocha);
                printf("Select 0 to Finish Ordering\n");
                printf("Select a coffee type: ");
                scanf("%d", &coffeeType); // Reading user input for coffeeType

                if (coffeeType == 0) 
                break; // Exiting the menu if 0 is selected to finish ordering

                // Checks if the ingredients are enough to brew the selected coffee using if condition and logical AND 
                if ((coffeeType == 1 && beans >= coffee_beans && water >= water_for_espresso) ||
                    (coffeeType == 2 && beans >= coffee_beans && water >= water_for_cappucino && milk >= milk_for_cappucino) ||
                    (coffeeType == 3 && beans >= coffee_beans && water >= water_for_mocha && milk >= milk_for_mocha && chocolate_syrup >= chocolate_syrup_for_mocha))
                {
                    int confirm; // To confirm the order selected by the user
                    if (coffeeType == 1) // If Espresso is chosen
                    {
                        printf("Do you confirm to buy an Espresso for AED %.2f?\n", price_for_espresso);
                        printf("Select 1 for YES and 0 for NO: "); // Confirmation for Espresso
                    }
                    else if (coffeeType == 2) // If Cappuccino is chosen
                    {
                        printf("Do you confirm to buy a Cappuccino for AED %.2f?\n", price_for_cappucino);
                        printf("Select 1 for YES and 0 for NO: "); // Confirmation for Cappuccino
                    } 
                    else if (coffeeType == 3) // If Mocha is chosen
                    {
                        printf("Do you confirm to buy a Mocha for AED %.2f?\n", price_for_mocha);
                        printf("Select 1 for YES and 0 for NO: "); // Confirmation for Mocha
                    }

                    scanf(" %d", &confirm); // Reading the confirmation input from the user
                    if(confirm == 1){
                        // Proceed with subtracting ingredients and adding to the cart
                        if (coffeeType == 1) // If Espresso is confirmed
                        {
                            beans -= coffee_beans; // Subtracts coffee beans used to make a cup of Espresso
                            water -= water_for_espresso; // Subtracts water used to make a cup of Espresso
                            cart += price_for_espresso; // Adds price of Espresso to cart
                            printf("An Espresso is added to your cart. Cart: AED %.2f\n", cart);
                        }
                        else if (coffeeType == 2) // If Cappuccino is confirmed
                        {
                            beans -= coffee_beans; // Subtracts coffee beans used to make a cup of Cappuccino
                            water -= water_for_cappucino; // Subtracts water used to make a cup of Cappuccino
                            milk -= milk_for_cappucino; // Subtracts milk used to make a cup of Cappuccino
                            cart += price_for_cappucino; // Adds price of Cappuccino to cart
                            printf("A Cappuccino is added to your cart. Cart: AED %.2f\n", cart);
                        }
                        else if (coffeeType == 3) // If Mocha is confirmed
                        {
                            beans -= coffee_beans; // Subtracts coffee beans used to make a cup of Mocha
                            water -= water_for_mocha; // Subtracts water used to make a cup of Mocha
                            milk -= milk_for_mocha; // Subtracts milk used to make a cup of Mocha
                            chocolate_syrup -= chocolate_syrup_for_mocha; // Subtracts chocolate syrup used to make a cup of Mocha
                            cart += price_for_mocha; // Adds price of Mocha to cart
                            printf("A Mocha is added to your cart. Cart: AED %.2f\n", cart);
                        }
                    }    
                    else 
                    {
                        printf("Order cancelled. Returning to the coffee menu.\n"); // Cancels order if an invalid input is entered
                    }

                }
                else
                {
                    // Message to display unavailability due to insufficiency of ingredients. Also requests the user to order a different coffee
                    printf("Unavailable to serve due to temporarily insufficient ingredients. Please order a different coffee or try again later.\n");
                }

                // Asks user if they want to order another coffee
                printf("Do you want to order another coffee?\n");
                printf("Select 1 for YES and 0 for NO: ");
                scanf("%d", &order); // Reads the input of the user 

            } while (order == 1); // Continue ordering until the user decides to stop

            if (cart > 0) {
                total_amount += cart; // Add the cart total to total sales
                double payment = 0, coin;
                // Prompting the user to insert coins of AED 1 & AED 0.5
                printf("Your total is AED %.2f. Please insert coins of 1 AED or 0.5 AED: \n", cart);
                while (payment < cart)
                {
                    scanf("%lf", &coin); // Reading inserted coin 
                    if (coin == 1 || coin == 0.5) // Checking if the coin inserted is valid
                    {
                        payment += coin; // Adding coin counter to payment
                        printf("You have paid AED %.2f.\n", payment); // Displaying total paid so far
                    }
                    else
                    {
                        printf("Invalid coin. Please insert AED 1 or AED 0.50. Collect your invalid coin!\n"); // Printing invalid coin entry
                    }
                }
                printf("Your coffee is coming right up. Visit again :)\n");
            }
        }
        else if (input == 2) // Admin Mode
        {
            char password[20]; // Admin password input for security
            printf("Enter admin password: ");
            scanf("%s", password);// Reading admin password

            if (strcmp(password, admin_password) == 0) // Verifying Admin password for authentication using string comparison function
            {
                int AdminMode; // Initialising an integer variable for Admin Mode
                do {
                    // Displaying Admin menu
                    printf("\n..........................................\n");
                    printf("         Welcome to Admin Mode\n");
                    printf("..........................................\n");
                    printf("Select 1 to View ingredients\n");
                    printf("Select 2 to Replenish ingredients\n");
                    printf("Select 3 to Change coffee prices\n");
                    printf("Select 4 to Reset Total Sales To Zero\n");
                    printf("Select 0 to Exit Admin Mode\n");
                    printf("Select an option: ");
                    scanf("%d", &AdminMode); // Reading Admin operator input

                    if (AdminMode == 1) // Option to view remaining ingredients
                    {
                        // Displaying the quantity of each ingredient in the machine and the total sale amount
                        printf("\nIngredients Left:\n");
                        printf("Coffee Beans: %d grams\n", beans);
                        printf("Water: %d ml\n", water);
                        printf("Milk: %d ml\n", milk);
                        printf("Chocolate Syrup: %d ml\n", chocolate_syrup);
                        printf("Total Sales: AED %.2f\n", total_amount);
                  
                        // Displaying warning if any ingredient is running low on ingredients. Here I used ingredients of Mocha as it has the highest ingredient value
                        if (beans <= coffee_beans)
                            printf("Warning: Low Coffee Beans. Kindly refill.\n");
                        if (water <= water_for_mocha)
                            printf("Warning: Low Water. Kindly refill.\n");
                        if (milk <= milk_for_mocha)
                            printf("Warning: Low Milk. Kindly refill.\n");
                        if (chocolate_syrup <= chocolate_syrup_for_mocha)
                            printf("Warning: Low Chocolate Syrup. Kindly refill.\n");
                    }
                    else if (AdminMode == 2) // Option to replenish ingredients
                    {
                        // Randomly replenishing ingredients within a range using rand function
                        printf("\nReplenishing Ingredients...\n");
                        beans = rand() % 100 + 40;
                        water = rand() % 450 + 30;
                        milk = rand() % 280 + 15;
                        chocolate_syrup = rand() % 90 + 12;
                        printf("Coffee Beans: %d grams\n", beans);
                        printf("Water: %d ml\n", water);
                        printf("Milk: %d ml\n", milk);
                        printf("Chocolate Syrup: %d ml\n", chocolate_syrup);
                        printf("\nIngredients have been replenished successfully\n");
                    }
                    else if (AdminMode == 3) // Option to change coffee prices
                    {
                        int change; // Initialising an integer to store change in coffee price
                        printf("Select 1 to change Espresso price\n");
                        printf("Select 2 to change Cappuccino price\n");
                        printf("Select 3 to change Mocha price\n");
                        printf("Select your option: ");
                        scanf("%d", &change); // Reading Admin operator's input

                        // Allowing the admin operator to change coffee price
                        if (change == 1) // For Espresso
                        {
                            printf("Enter the new price for Espresso: ");
                            scanf("%lf", &price_for_espresso); // Reading new price for Espresso
                            printf("The updated price for Espresso is AED %.2f \n", price_for_espresso); // Prints new price for Espresso
                        }
                        else if (change == 2) // For Cappuccino
                        {
                            printf("Enter the new price for Cappuccino: ");
                            scanf("%lf", &price_for_cappucino); // Reading new price for Cappuccino
                            printf("The updated price for Cappuccino is AED %.2f \n", price_for_cappucino); // Prints new price for Cappuccino
                        }
                        else if (change == 3) // For Mocha
                        {
                            printf("Enter the new price for Mocha: ");
                            scanf("%lf", &price_for_mocha); // Reading new price for Mocha
                            printf("The updated price for Mocha is AED %.2f \n", price_for_mocha); // Prints new price for Mocha
                        }
                        else
                        {
                            printf("Invalid input.\n"); // Displaying invalid input
                        }
                    }
                    else if(AdminMode == 4) // Option to reset total sales to zero
                    {
                        int reset; // Initialising an integer variable to store resetting mechanism
                        printf("Total Sales: AED %.2f\n", total_amount);
                        printf("Do you want to reset total sales?\n");
                        printf("Press 1 for YES and 0 for NO: ");
                        scanf("%d", &reset); // Reading the Admin operator's input 
                        if(reset == 1)
                        {
                           total_amount = 0.0; // Resets total sales to zero 
                           // Reminds the Admin operator to collect money from the machine
                           printf("Total Sales have been resetted to zero.\n");
                           printf("Please collect the money from the machine.\n");
                        }
                        else if(reset == 0)
                        {
                           printf("Total Sales: AED %.2f", total_amount); // Displays total sales if the Admin chooses not to reset
                        }
                    }
                } while (AdminMode != 0); // Closing AdminMode do while loop
            }
            else 
            {
                printf("Invalid password.\n"); // Displays incorrect password for accessing Admin Mode
            }
        }
    } while (input != 0); // Closing menu driven interface do while loop

    return 0; // Exiting the program
}