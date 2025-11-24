// ------------- FILE HEADER -------------
// Author ✅: Wyatt Hart
// Assignment ✅: Assignment 7
// Date ✅: 11/23/2025
// Citations:

// ------------- ZYBOOKS SCORES -------------
// Chapter ✅: 14
// Participation ✅: 100
// Challenge ✅:100
// Labs ✅: 100

// ------------- DISCORD POSTS -------------
// https://discord.com/invite/URYKKf8YHm
// Count ✅: 2
// Links (Optional):

// ------------- DESIGN DOCUMENT -------------
// A. INPUT ✅: yes
// B. OUTPUT ✅: yes
// C. CALCULATIONS ✅: yes
// D. LOGIC and ALGORITHMS ✅: yes
//    (Optional) flow chart link or file name:

// ------------- TESTING -------------
// PASS ALL GIVEN SAMPLE RUN TESTS ✅: yes
// (Optional) Additional tests count:

// ------------- CODE -------------
#include <iomanip>
#include <iostream>

using namespace std;

// Function prototypes (if any)
// 
// function that takes 2 pointers to integers and swaps the integers read in main().
void swapArgs(int* numA, int* numB);

// function that takes 2 pointers to integers and stores the integer quotient in the first pointer parameter and the remainder in the second pointer parameter.
void divideArgs(int* numA, int* numB);

// function that takes 2 pointers to integers, raises the first integer to the power of the second integer, and stores the result in the first integer.You may NOT use the pow() function to do this, you must use a loop to calculate the result.Recall, any number raised to the 0 power is 1. If the power is a negative number, do not calculate any result.See sample runs below.
void powerArgs(int* numA, int* numB);


// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
int main(int argc, char* argv[]) {
    int numA, numB;
    int* num_ptrA;
    int* num_ptrB;

    cout << "Enter integer 1: ";
    cin >> numA;
    num_ptrA = &numA;

    cout << "Enter integer 2: ";
    cin >> numB;
    num_ptrB = &numB;

    if (numA == 0 && numB == 0) {
        cout << "No operations performed!";
        return 0;
    }

    cout << "\nBefore call to swapArgs a : " << numA << " b : " << numB << endl;
    
    swapArgs(num_ptrA, num_ptrB);
    cout << "After call to swapArgs a : " << numA << " b : " << numB << endl;
    
    divideArgs(num_ptrA, num_ptrB);
    cout << "After call to divideArgs a : " << numA << " b : " << numB << endl;
    
    powerArgs(num_ptrA, num_ptrB);
    cout << "After call to powerArgs a : " << numA << " b : " << numB << endl;

    cout << "\nGoodbye!" << endl;

    return 0;
}




void swapArgs(int* numA, int* numB)
{
    int temp = 0;

    temp = *numA;

    *numA = *numB;
    *numB = temp;

    return;
}

void divideArgs(int* numA, int* numB)
{
    int quotiant, remainder = 0;

    quotiant = *numA / *numB;
    remainder = *numA % *numB;

    *numA = quotiant;
    *numB = remainder;

    return;
}

void powerArgs(int* numA, int* numB)
{
    if (*numB == 0) {
        *numA = 1;
        return;
    } else if (*numB < 0){
        return;
    } else {
        for (int i = 1; i < *numB; i++) {
            *numA *= *numA;
        }
    }

    return;
}

// ------------- DESIGN -------------
/*
Program Name: Pointers are Fun!

Program Description: This program takes 2 integer values and manipulates their values using pointers.



Design:
A. INPUT
Define the input variables including name data type.
int numA
int numB

B. OUTPUT
Define the output variables including data types.
int numA
int numB

C. CALCULATIONS
Describe calculations used by algorithms in step D.
List all formulas.
If there are no calculations needed, state there are no calculations.
int quotiant = *numA / *numB;
int remainder = *numA % *numB;

for (int i = 1; i < *numB; i++) {
    *numA *= *numA;
}

D. LOGIC and ALGORITHMS
Design the logic of your program using pseudocode or flowcharts.
Use conditionals, loops, functions or array constructs.
List the steps in transforming inputs into outputs.
https://github.com/Glen-Sasek-PCC-Instructor/2025-06-22/blob/main/Pseudocode-Reference.txt


DECLARE int numA, numB
DECLARE int* num_ptrA
DECLARE int* num_ptrB

DISPLAY "Enter integer 1: "
INPUT numA
SET num_ptrA = &numA

DISPLAY "Enter integer 2: "
INPUT numB
SET num_ptrB = &numB

if (numA == 0 && numB == 0) {
    DISPLAY "No operations performed!"
    QUIT
}

DISLPAY "\nBefore call to swapArgs a : " + numA + " b : " + numB

// swapArgs(num_ptrA, num_ptrB)
{
    DECLARE int temp = 0

    SET temp = *numA

    SET *numA = *numB
    SET *numB = temp
}
DISPLAY "After call to swapArgs a : " + numA + " b : " + numB

// divideArgs(num_ptrA, num_ptrB);
{
    DECLARE int quotiant, remainder = 0

    SET quotiant = *numA / *numB
    SET remainder = *numA % *numB

    SET *numA = quotiant
    SET *numB = remainder
}
DISPLAY "After call to divideArgs a : " + numA + " b : " + numB

// powerArgs(num_ptrA, num_ptrB);
{
    if (*numB == 0) {
        SET *numA = 1
        return
    } else if (*numB < 0){
        return
    } else {
        for (int i = 1; i < *numB; i++) {
            SET *numA *= *numA
        }
    }
}
DISPLAY "After call to powerArgs a : " + numA + " b : " + numB

DISLPAY "\nGoodbye!"

SAMPLE RUNS
Copy from assignment document.
//////////////////Sample Run 1//////////////////
Enter integer 1: 3
Enter integer 2: 17

Before call to swapArgs a: 3 b: 17
After call to swapArgs a: 17 b: 3
After call to divideArgs a: 5 b: 2
After call to powerArgs a: 25 b: 2

Goodbye!
////////////////////////////////////////////////
//////////////////Sample Run 2//////////////////
Enter integer 1: 2
Enter integer 2: 10

Before call to swapArgs a: 2 b: 10
After call to swapArgs a: 10 b: 2
After call to divideArgs a: 5 b: 0
After call to powerArgs a: 1 b: 0

Goodbye!
////////////////////////////////////////////////
//////////////////Sample Run 3//////////////////
Enter integer 1: -10
Enter integer 2: 3

Before call to swapArgs a: -10 b: 3
After call to swapArgs a: 3 b: -10
After call to divideArgs a: 0 b: 3
After call to powerArgs a: 0 b: 3

Goodbye!
////////////////////////////////////////////////
//////////////////Sample Run 4//////////////////
Enter integer 1: 0
Enter integer 2: 0

No operations performed!
////////////////////////////////////////////////
//////////////////Sample Run 5//////////////////
Enter integer 1: -2
Enter integer 2: -9

Before call to swapArgs a: -2 b: -9
After call to swapArgs a: -9 b: -2
After call to divideArgs a: 4 b: -1
After call to powerArgs a: 4 b: -1

Goodbye!
////////////////////////////////////////////////

*/
