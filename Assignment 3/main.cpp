// ------------- FILE HEADER -------------
// Author ✅: Wyatt Hart
// Assignment ✅: Assignment 3
// Date ✅: 10/12/2025
// Citations: 


// ------------- ZYBOOKS SCORES -------------
// Chapter ✅: 11
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
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Constants
const int MAX_SCORES = 20;

// Function prototypes (if any)
void welcome();
void readScores(double scores[], int &count);
void readDouble(string prompt, double &num);
void calcGrade(double scores[], char grades[], int count);
void printList(double scores[], char grades[], int count);
void sort(double scores[], char grades[], int count);
double median(double scores[], int count);

// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
int main(int argc, char* argv[]) {
    // Declare all variables needed.
    // The 2 arrays (double scores[], and char grades[]) must be declared in main().
    double scores[MAX_SCORES];
    char grades[MAX_SCORES];
    int count = 0;

    welcome();

    // Call readScores() and send scores and count to it.
    // This will fill the scores array from the user.
    // You should call the readDouble() function to read
    // and validate the scores before adding them to the scores array.
    readScores(scores, count);

    // count will have the number of values read.

    // Call **calcGrade()**function that takes the scores
    // array and an empty grades array and fills the grades
    // array with letter grades.
    calcGrade(scores, grades, count);

    cout << fixed << setprecision(1);
    cout << "\nYour stats are as below: " << endl;

    // Call the printList function to print the lists.
    cout << "\nThe list of scores and their grades are:" << endl;
    printList(scores, grades, count);

    // Call the sort function to sort the list based on scores.
    sort(scores, grades, count);

    // Call the printList function to print the lists.
    cout << "\nThe list sorted by scores in ascending order:" << endl;
    printList(scores, grades, count);

    // Call the median function to find the median and print it in main().
    cout << fixed << setprecision(2);
    cout << "\nThe median score is " << median(scores, count) << endl;


    cout << "\nThank you for using my Parallel Arrays program!!" << endl;
    
  return 0;
}


// Function implementations (if any)

// This function prints a welcome message to the user.
void welcome() {
    cout << "Welcome to my Parallel Arrays program!" << endl;
}


// Reads a list of scores from the user. A -1 indicates the end of the input and is not stored in the array. (Use an appropriate loop!! Check out this example code - a for loop is count controlled, and a while loop is condition based.)
// Call the readDouble function to do this. You must catch all invalid data such as characters, negative numbers other than -1 etc.
// The variable count keeps track of the number of scores entered.
// You must also do validation to make sure that the number is between 0 and 4 inclusive and nothing other than that. Use a while loop to do this.
void readScores(double scores[], int &count){
    double num;
    cout << "Please enter the list of scores (-1 to end input:)" << endl;
    cout << "Valid scores are between 0 and 4 inclusive." << endl;
    
    do{
        readDouble(">> ", num);
        if(0 <= num && num <= 4){
            scores[count] = num;
            count++;
        }else if(num != -1){
            cout << "Invalid score! Please try again!!" << endl;
        }
    }while(num != -1);

}



// This function should be used any time you read any floats or doubles from the user. Use this function to read the numerical scores from the user.
// It takes a string prompt, outputs it, reads a number from the user, validates and returns the num by reference.
// Write it exactly like the readInt from assignment 1 but declare a double or float instead of an int. See Samplea01.cpp for the readInt function.
// You must catch all invalid data such as characters, negative numbers etc.
void readDouble(string prompt, double &num){
    cout << prompt;
    cin >> num;
    while (!cin)
    {
        cout << "Invalid score! Please try again!!" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cout << prompt;
        cin >> num;
    }
    cin.ignore(10, '\n');
}


// Use the table below to assign grades A to F to the corresponding numerical score.

// Letter Grade	4.0 Score	Level
// A	>3.3 <= 4.0	Exceeds
// B	>2.7 <= 3.3	Meets
// C	>1.9 <= 2.7	Approaching
// D	>1.1 <= 1.9	Not Yet
// F	>0.0 <= 1.1	No Evidence
// Use a loop to process each array element and calculate the letter grade for each score.
void calcGrade(double scores[], char grades[], int count){
    for(int i = 0; i < count; i++){
        if(3.3 < scores[i] && scores[i] <= 4.0){
            grades[i] = 'A';
        } else if(2.7 < scores[i] && scores[i] <= 3.3){
            grades[i] = 'B';
        } else if(1.9 < scores[i] && scores[i] <= 2.7){
            grades[i] = 'C';
        } else if(1.1 < scores[i] && scores[i] <= 1.9){
            grades[i] = 'D';
        } else if(0.0 <= scores[i] && scores[i] <= 1.1){
            grades[i] = 'F';
        } else {
            cout << "ERROR!! INVALID SCORE ENTERED!"; // ERROR HANDLING
        }
    }
}

// Go through a for loop and print the scores and the corresponding grades for each item.
void printList(double scores[], char grades[], int count){
    for(int i = 0; i < count; i++){
        cout << scores[i] << " " << grades[i] << endl;
    }

}

// Sort the arrays using the given sorting algorithm. This is called Selection Sort. Use only this algorithm to sort your list. To see how the Selection Card Sort Algorithm works, watch this video from Virginia Tech.
// Be careful and make sure you sort based on the scores array and swap the corresponding element in the grade array to maintain the correspondence between the two arrays. Meaning if you swap the scores in index 0 and 5, you must also swap the corresponding grades in index 0 and 5.
void sort(double scores[], char grades[], int count){
    for(int i = 0; i < count; i++){
        int min = i;
        for(int j = i + 1; j < count; j++){
            if(scores[j] < scores[min]){
                min = j;
            }
        }
        if(min != i){
            double tempScore = scores[i];
            scores[i] = scores[min];
            scores[min] = tempScore;

            char tempGrade = grades[i];
            grades[i] = grades[min];
            grades[min] = tempGrade;
        }
    }
}

// After sorting, write this function to identify the median score.    
// The median is located in the middle of the array if the array’s size is odd. Otherwise, the median is the average of the middle two values.
// Return the median to main() and output in main() with two decimal places.
double median(double scores[], int count){
    if(count % 2 == 0){
        return (scores[(count / 2 - 1)] + scores[(count / 2)]) / 2;
    } else {
        int medIndex = ceil(count / 2.0 - 1);
        return scores[medIndex];
    }
    
}


// ------------- DESIGN -------------
/* 
Program Name: Parallel Arrays

Program Description:
In this assignment, you will be writing a program that stores a list of scores and the corresponding letter grades in two parallel arrays. The scores will be double data type and the letter grade will be a char data type.

Design:
A. INPUT
Define the input variables including name data type. 
double scores;

B. OUTPUT
Define the output variables including data types. 
double scores;
char grades;

C. CALCULATIONS
Describe calculations used by algorithms in step D.  
List all formulas. 
If there are no calculations needed, state there are no calculations.
there are no calculations

D. LOGIC and ALGORITHMS
Design the logic of your program using pseudocode or flowcharts. 
Use conditionals, loops, functions or array constructs.
List the steps in transforming inputs into outputs. 
https://github.com/Glen-Sasek-PCC-Instructor/2025-06-22/blob/main/Pseudocode-Reference.txt

DECLARE double scores[MAX_SCORES];
DECLARE char grades[MAX_SCORES];
DECLARE int count = 0;

// welcome()
DISPLAY "Welcome to my Parallel Arrays program!"


// readScores(scores, count);
DECLARE double num;
DISPLAY "Please enter the list of scores (-1 to end input:)""
DISPLAY "Valid scores are between 0 and 4 inclusive."

do{
    DISPLAY ">> "
    INPUT num
    while (!cin)
    {
        DISPLAY "Invalid score! Please try again!!"
        DISPLAY ">> "
        INPUT num
    if(0 <= num && num <= 4){
        SET scores[count] = num
        count++
    }else if(num != -1){
        DISPLAY "Invalid score! Please try again!!"
    }
}while(num != -1);

// calcGrade(scores, grades, count)
for(int i = 0; i < count; i++){
    if(3.3 < scores[i] && scores[i] <= 4.0){
        SET grades[i] = 'A'
    } else if(2.7 < scores[i] && scores[i] <= 3.3){
        SET grades[i] = 'B'
    } else if(1.9 < scores[i] && scores[i] <= 2.7){
        SET grades[i] = 'C'
    } else if(1.1 < scores[i] && scores[i] <= 1.9){
        SET grades[i] = 'D'
    } else if(0.0 <= scores[i] && scores[i] <= 1.1){
        SETgrades[i] = 'F'
    }
}

DISPLAY "\nYour stats are as below: "

DISPLAY "\nThe list of scores and their grades are:"
// printList(scores, grades, count);
for(int i = 0; i < count; i++){
    DISPLAY scores[i] << " " << grades[i]
}

// sort(scores, grades, count);
for(int i = 0; i < count; i++){
    DECLARE int min = i
    for(int j = i + 1; j < count; j++){
        if(scores[j] < scores[min]){
            SET min = j;
        }
    }
    if(min != i){
        DECLARE double tempScore = scores[i];
        SET scores[i] = scores[min];
        SET scores[min] = tempScore;

        DECLARE char tempGrade = grades[i];
        SET grades[i] = grades[min];
        SET grades[min] = tempGrade;
    }
}

DISPLAY "\nThe list sorted by scores in ascending order:"
// printList(scores, grades, count);
for(int i = 0; i < count; i++){
    DISPLAY scores[i] << " " << grades[i]
}

DISPLAY "\nThe median score is " << median(scores, count)


DISPLAY "\nThank you for using my Parallel Arrays program!!"


SAMPLE RUNS
Copy from assignment document.
//////////////////Sample Run 1//////////////////
Welcome to my Parallel Arrays program!
Please enter the list of scores (-1 to end input:)
Valid scores are between 0 and 4 inclusive.
>> 3.5
>> 2.7
>> 3.3
>> 2.5
>> 3.2
>> 1.5
>> 4.0
>> 3.7
>> -1

Your stats are as below: 

The list of scores and their grades are:
3.5 A
2.7 C
3.3 B
2.5 C
3.2 B
1.5 D
4.0 A
3.7 A

The list sorted by scores in ascending order:
1.5 D
2.5 C
2.7 C
3.2 B
3.3 B
3.5 A
3.7 A
4.0 A

The median score is 3.25

Thank you for using my Parallel Arrays program!!
////////////////////////////////////////////////
//////////////////Sample Run 2//////////////////
Welcome to my Parallel Arrays program!
Please enter the list of scores (-1 to end input:)
Valid scores are between 0 and 4 inclusive.
>> 3.5
>> 2.7
>> 3.3
>> 4.5
Invalid score! Please try again!!
>> abc
Invalid score! Please try again!!
>> 3.2
>> 1.5
>> 4.0
>> 3.7
>> 4.0
>> -1

Your stats are as below: 

The list of scores and their grades are:
3.5 A
2.7 C
3.3 B
3.2 B
1.5 D
4.0 A
3.7 A
4.0 A

The list sorted by scores in ascending order:
1.5 D
2.7 C
3.2 B
3.3 B
3.5 A
3.7 A
4.0 A
4.0 A

The median score is 3.40

Thank you for using my Parallel Arrays program!!
////////////////////////////////////////////////

*/