// ------------- FILE HEADER -------------
// Author ✅: Wyatt Hart
// Assignment ✅: Assignment 1
// Date ✅: 9/28/2025
// Citations: 


// ------------- ZYBOOKS SCORES -------------
// Chapter ✅: 8 & 9
// Participation ✅: 100
// Challenge ✅: 100
// Labs ✅: 100


// ------------- DISCORD POSTS -------------
// https://discord.com/invite/URYKKf8YHm
// Count ✅: 1
// Links (Optional): 


// ------------- DESIGN DOCUMENT -------------
// A. INPUT ✅: Yes
// B. OUTPUT ✅: Yes
// C. CALCULATIONS ✅: Yes
// D. LOGIC and ALGORITHMS ✅: Yes
//    (Optional) flow chart link or file name: 


// ------------- TESTING -------------
// PASS ALL GIVEN SAMPLE RUN TESTS ✅: Yes
// (Optional) Additional tests count:   


// ------------- CODE -------------
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function prototypes (if any)
void welcome();
void displayMenu();
void readOption(int& option);
void readInt(string prompt, int& num);
void readDouble(string prompt, double& num);
void placeOrder(double& cost);
double tipDiscount(double& tip, double& discount, double cost);

// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
int main() {
    // Declare all variables needed.
    int userSelection;
    double cost = 0;
    double tip, discountedTotal;

    // Some discounts may apply for larger orders.If the total(including the tip) is greater than $50, they get a 10 % discount, and if the total is greater than $35 and less than $50, they get a 5 % discount.
    double discount;

    welcome();

    // There must be a do - while loop in main that will keep repeating the menu until the user enters 2.
    do {
        // Call the displayMenu function.
        displayMenu();

        // Call the readOption function.
        readOption(userSelection);

        // When the user enters 1, call the placeOrder function.
        if (userSelection == 1) {
            placeOrder(cost);
            cout << fixed << setprecision(2) << "\nYour order is: $" << cost << endl;
            // Then call the tipDiscount function that will calculate the final total and return the value.It will also receive the tip and discount amount byreference.
            discountedTotal = tipDiscount(tip, discount, cost);
            // Print the tip, discount and final total when it comes back.Repeat the menu and continue until the user enters option 2.
            // Print dollar amounts with a $ sign and output to 2 decimal places.
            cout << "Your order with tip is: $" << cost + tip << endl;
            cout << fixed << setprecision(0) << (discount * 100) << "% discount: $" << fixed << setprecision(2) << ceil(((cost + tip) - discountedTotal) * 100.00) / 100.00 << endl;
            cout << "Total: " << discountedTotal << endl;
            cost = 0.00;
            tip = 0.00;
        }
        else if (userSelection == 2) {
            cout << "\nThank you for using my program!" << endl;
        }

        // When the user enters 2, quit the program after printing a thank you message.
    } while (userSelection != 2);
    

	return 0;
}

// Function implementations (if any)
// This function prints a welcome message to the user.
void welcome() {
    cout << "🍇 🍈 🍉   🍋 🍌 🥭   🍎 🍏 🍑   🍒 🫐" << endl;
    cout << "🍅         🫒    🥥   🥑    🥔   🥕   🥓" << endl;
    cout << "🌽 🫑      🥬    🥦   🧄    🧅   🥜    🫘" << endl;
    cout << "🌰         🫚    🫛   🫜    🍞   🥐    🥖 " << endl;
    cout << "🫓         🥨 🍗 🥩   🥯 🥞 🧇   🧀 🍖 " << endl;

    cout << "Welcome to my Food Cart Program!" << endl;
}

// This function prints the menu to the user.Your menu must have 2 items - Place an order and quit.
void displayMenu() {
    cout << "\nPick an option:" << endl;
    cout << "\t1. Place an Order" << endl;
    cout << "\t2. Quit" << endl;
}

// This function will read an option and return to the called function through the reference parameter.
void readOption(int& option) {
    // Call the readInt function to do this.You must catch all invalid data such as characters, negative numbers etc.
    readInt(">> ", option);

    // You must also do validation to make sure that the number is 1 or 2 and nothing other than that.Use a while loop to do this.

    //data validation loop
    while (option < 1 || option > 2)
    {
        cout << "Invalid Option!" << endl;
        displayMenu();
        readInt(">> ", option);
    }
}

// This function should be used any time you read any integers from the user.Use this function to read the menu option from the user.
// It takes a string prompt, outputs it, reads a number from the user, validates and returns the num by reference.
void readInt(string prompt, int& num) {

    // You must catch all invalid data such as characters, negative numbers etc.
    cout << prompt;
    cin >> num;
    while (!cin)
    {
        cout << "\nInvalid input! Please try again!!" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> num;
    }
    cin.ignore(10, '\n');
}

// This function should be used any time you read any floats or doubles from the user.Use this function to read the cost of the item, tip, etc from the user.
// It takes a string prompt, outputs it, reads a number from the user, validates and returns the num by reference.
void readDouble(string prompt, double& num) {

    // Write it exactly like the readInt but declare a double or float instead of an int.

    // You must catch all invalid data such as characters, negative numbers etc.
    cout << prompt;
    cin >> num;
    while (!cin)
    {
        cout << "\nInvalid input! Please try again!!" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> num;
    }
    cin.ignore(10, '\n');
}

// Call this function if the user selects 1 from the menu.
// This function will go through a loop and ask the user to enter item names and their cost until the user answers ‘n’ to the question - Do you want another item ? (y / n) : You must validate to make sure the user enters y / n for this question(it should not be case sensitive - must accept both uppercase and lowercase).Use a while loop to do this.
void placeOrder(double& cost) {
    char enteringMoreItems = 'y';
    string menuItem = "";
    // The total cost must be returned through the reference parameter and be printed in main().
    double input;
    do {
        cout << "\nEnter the name of your item: ";
        getline(cin, menuItem);

        // Call the readDouble function to do this.You must catch all invalid data such as characters, negative numbers etc.
        readDouble("Enter the cost of your item: $", input);
        cost += input;
        do {
            cout << "Do you want another item? (y/n): ";
            cin >> enteringMoreItems;
            if (enteringMoreItems != 'y' && enteringMoreItems != 'Y' && enteringMoreItems != 'n' && enteringMoreItems != 'N') {
                cout << "Invalid Option!" << endl;
            }
        } while (enteringMoreItems != 'y' && enteringMoreItems != 'Y' && enteringMoreItems != 'n' && enteringMoreItems != 'N');

        cin.ignore(100, '\n');
    } while (enteringMoreItems == 'y' || enteringMoreItems == 'Y');
    // Do not print anything in this function.The tip, discount, and final total must be printed in main().
}

// This function takes the cost by value, and the tip and discount by reference.
// The function prompts the user to enter a tip amount, and reads into the tip parameter.This will be used to calculate the total, and it will also go back to main() so it can be printed in main().
double tipDiscount(double& tip, double& discount, double cost) {

    // Call the readDouble function to do this.You must catch all invalid data such as characters, negative numbers etc.
    readDouble("Enter tip $: ", tip);
    // It then calculates the discount based on the total(including the tip), and returns the final total to main().The discount amount goes back by reference to be printed in main().See sample run."
    if (cost + tip > 50.0) {
        discount = 0.10;
    }
    else if (35 < cost + tip && cost + tip < 50) {
        discount = 0.05;
    }
    else {
        discount = 0.00;
    }

    return ((cost + tip) - ((cost + tip) * discount));
    // Do not print anything inside the function.
}

// ------------- DESIGN -------------
/*
Program Name: Food Cart Ordering

Program Description:
In this assignment, you will be writing a menu-driven program to calculate
how much a customer will pay once they are done ordering food at a food cart.
You will give the user a menu with some choices, and let them pick a choice.
Based on the choice they pick, you will ask them some questions and give them
results. This process will repeat until they choose to quit the program. The
purpose of this assignment is to modularize your program.

Design:
A. INPUT
Define the input variables including name data type.
int userSelection
double cost = 0
double tip, discountedTotal
double discount

B. OUTPUT
Define the output variables including data types.
double discountedTotal


C. CALCULATIONS
Describe calculations used by algorithms in step D.
List all formulas.
If there are no calculations needed, state there are no calculations.
Discount Amount = ceil(((cost + tip) - discountedTotal) * 100.00) / 100.00
discountedTotal = ((cost + tip) - ((cost + tip) * discount))

D. LOGIC and ALGORITHMS
Design the logic of your program using pseudocode or flowcharts.
Use conditionals, loops, functions or array constructs.
List the steps in transforming inputs into outputs.
https://github.com/Glen-Sasek-PCC-Instructor/2025-06-22/blob/main/Pseudocode-Reference.txt


DECLARE int userSelection;
DECLARE double cost = 0;
DECLARE double tip, discountedTotal;
DECLARE double discount;

DISPLAY "🍇 🍈 🍉   🍋 🍌 🥭   🍎 🍏 🍑   🍒 🫐" 
DISPLAY "🍅         🫒    🥥   🥑    🥔   🥕   🥓"
DISPLAY "🌽 🫑      🥬    🥦   🧄    🧅   🥜    🫘"
DISPLAY "🌰         🫚    🫛   🫜    🍞   🥐    🥖 "
DISPLAY "🫓         🥨 🍗 🥩   🥯 🥞 🧇   🧀 🍖 "

DISPLAY "Welcome to my Food Cart Program!"

WHILE userselection != 2 {

    // displayMenu();
    DISPLAY "\nPick an option:"
    DISPLAY "\t1. Place an Order"
    DISAPLY "\t2. Quit"

    // readInt();
    DISPLAY ">> "
    INPUT num
    while (!cin)
    {
        DISPLAY "\nInvalid input! Please try again!!"
    while (option < 1 || option > 2)
    {
        DISPLAY "Invalid Option!"
        displayMenu()
        readInt(">> ", option)
    }

    // When the user enters 1, call the placeOrder function.
    if (userSelection == 1) {
        DECLARE char enteringMoreItems = 'y'
        DECLARE string menuItem = ""
        DECLARE double input;
        do {
            DISPLAY "\nEnter the name of your item: "
            INPUT menuItem

            // readDouble("Enter the cost of your item: $", input);
            DISPLAY "Enter the cost of your item: $" 
            INPUT num
            while (!cin)
            {
                DISPLAY "\nInvalid input! Please try again!!"
                INPUT num
            }
            SET cost += input;
            do {
                DISPLAY "Do you want another item? (y/n): "
                INPUT enteringMoreItems
                if (enteringMoreItems != 'y' && enteringMoreItems != 'Y' && enteringMoreItems != 'n' && enteringMoreItems != 'N') {
                    DISPLAY "Invalid Option!"
                }
            } while (enteringMoreItems != 'y' && enteringMoreItems != 'Y' && enteringMoreItems != 'n' && enteringMoreItems != 'N');

        } while (enteringMoreItems == 'y' || enteringMoreItems == 'Y');

        DISLAY "\nYour order is: $" + cost

        // readDouble("Enter tip $: ", tip);
        DISPLAY "Enter tip $: "
        INPUT num;
        while (!cin)
        {
            DISPLAY "\nInvalid input! Please try again!!"
            INPUT num;
        }

        if (cost + tip > 50.0) {
            SET discount = 0.10;
        }
        else if (35 < cost + tip && cost + tip < 50) {
            SET discount = 0.05;
        }
        else {
            SET discount = 0.00;
        }

        SET discountedTotal = ((cost + tip) - ((cost + tip) * discount));
        
        DISPLAY "Your order with tip is: $" + cost + tip
        DISPLAY (discount * 100) + "% discount: $" + ceil(((cost + tip) - discountedTotal) * 100.00) / 100.00
        DISPLAY "Total: " + discountedTotal
        SET cost = 0.00;
        SET tip = 0.00;
    }
    else if (userSelection == 2) {
        DISPLAY "Thank you for using my program!" << endl;
    }

SAMPLE RUNS
Copy from assignment document.
//////////////////Sample Run 1//////////////////
🍇 🍈 🍉   🍋 🍌 🥭   🍎 🍏 🍑   🍒 🫐
🍅         🫒    🥥   🥑    🥔    🥕   🥓
🌽 🫑      🥬    🥦   🧄    🧅   🥜    🫘
🌰         🫚    🫛   🫜    🍞   🥐    🥖
🫓         🥨 🍗 🥩   🥯 🥞 🧇   🧀 🍖

Welcome to my Food Cart Program!

Pick an option:
    1. Place an order
    2. Quit
>> 9
Invalid Option!

Pick an option:
    1. Place an order
    2. Quit
>> 1

Enter the name of your item: Pasta
Enter the cost of your item $: 15.75
Do you want another item? (y/n): y

Enter the name of your item: Bowl
Enter the cost of your item $: 12.75
Do you want another item? (y/n): y

Enter the name of your item: Soda
Enter the cost of your item $: 3.50
Do you want another item? (y/n): x
Invalid Option!
Do you want another item? (y/n): n

Your order is: $32.00
Enter tip $: 3.50
Your order with tip is: $35.50
5% discount: $1.78
Total: $33.73

Pick an option:
    1. Place an order
    2. Quit
>> 1

Enter the name of your item: Fajita Bowl
Enter the cost of your item $: 20.75
Do you want another item? (y/n): y

Enter the name of your item: Vietnamese plate
Enter the cost of your item $: 22.75
Do you want another item? (y/n): y

Enter the name of your item: Soda
Enter the cost of your item $: 3.50
Do you want another item? (y/n): x
Invalid Option!
Do you want another item? (y/n): n

Your order is: $47.00
Enter tip $: 3.50
Your order with tip is: $50.50
10% discount: $5.05
Total: $45.45

Pick an option:
    1. Place an order
    2. Quit
>> 2

Thank you for using my program!
////////////////////////////////////////////////
*/