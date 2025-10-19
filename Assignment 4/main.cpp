// ------------- FILE HEADER -------------
// Author ✅: Wyatt Hart
// Assignment ✅: Assignment 4
// Date ✅: 10/18/2025
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
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

// Constants
const int MAXCHAR = 51;
const int MAXLENGTH = 20;

// Function prototypes (if any)
void welcome();
void readInput(char courseNums[][MAXCHAR], int students[], int &count);
void readInt(string prompt, int &num);
void printList(char courseNums[][MAXCHAR], int students[], int count);
void cancelCourses(char courseNums[][MAXCHAR], int students[], int &count);

// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
int main(int argc, char *argv[]) {
  // Declare the arrays for course numbers and students.
  char courseNums[MAXLENGTH][MAXCHAR];
  int students[MAXLENGTH];
  int count = 0;

  welcome();


  // Call the readInput() function and get the arrays filled. The list must be ordered by the course numbers. This is important for this grade level.
  readInput(courseNums, students, count);

  // Call the printList() function and print the course numbers and students neatly formatted.
  cout << "\nList of courses and students:" << endl;
  printList(courseNums, students, count);

  // Call the cancelCourses() function and cancel the courses with less than10 students in them.
  cancelCourses(courseNums, students, count);

  // Call the printList() function again and print the course numbers and students neatly formatted.
  cout << "\nList after cancellations:" << endl;
  printList(courseNums, students, count);

  cout << "\nThank you for checking out my Course Rosters program!" << endl;

  return 0;
}

// Function implementations (if any)

void welcome() { cout << "Welcome to my Course Rosters program!!" << endl; }

void readInput(char courseNums[][MAXCHAR], int students[], int &count) {
  char input[MAXCHAR] = "";
  bool quitting = false;
  int num;
  cout << "Enter course number and students enrolled when prompted." << endl;
  cout << "Enter Quit or quit for course number when you are done." << endl;

  do {
      int i = 0;
      cout << "Enter a course number: ";
      cin.getline(input, MAXCHAR);
      if(count == MAXLENGTH) {
          cout << "Array full!" << endl;
          quitting = true;
      } else if(strcmp(input, "QUIT") == 0 || strcmp(input, "Quit") == 0 || strcmp(input, "quit") == 0){
        quitting = true;
      } else if(!count) {
          strcpy(courseNums[count], input);
      } else {
        while(strcmp(courseNums[i], input) < 0 && i < count) {
          i++;
        }
        for(int j = count; j > i; j--) {
          strcpy(courseNums[j], courseNums[j-1]);
          students[j] = students[j-1];
        }
        strcpy(courseNums[i], input);
      }
      
      if(!quitting){
        readInt("Number of students enrolled: ", num);
        students[i] = num;

        count++;
      }

  } while (!quitting);
}

void readInt(string prompt, int &num) {
  cout << prompt;
  cin >> num;
  while (!cin || !(0 <= num && num <= 25) ) {
    cout << "Invalid number!! Please enter a number between 0 and 25" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cout << prompt;
    cin >> num;
  }
  cin.ignore(10, '\n');
}

void printList(char courseNums[][MAXCHAR], int students[], int count) {
  for (int i = 0; i < count; i++) {
    cout << setw(20) << left << courseNums[i] << right << students[i] << endl;
  }
}

void cancelCourses(char courseNums[][MAXCHAR], int students[], int &count){
  for (int i = 0; i < count; i++){
    if(students[i] < 10){
      for (int j = i; j < count - 1; j++){
            strcpy(courseNums[j], courseNums[j+1]);
            students[j] = students[j + 1];
      }
      count--;  // decrement the number of elements in the array
      students[count] = 0; // reset the value at end of array
      strcpy(courseNums[count], "");
    }
  }
}



// ------------- DESIGN -------------
/*
Program Name: Course Rosters program

Program Description:
In this assignment, you will write a program that uses arrays to represent a list of courses and students enrolled in them and manipulate those arrays.


Design:
A. INPUT
Define the input variables including name data type.
courseNums[MAXLENGTH][MAXCHAR]
students[MAXLENGTH]

B. OUTPUT
Define the output variables including data types.
courseNums[MAXLENGTH][MAXCHAR]
students[MAXLENGTH]


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

DECLARE char courseNums[MAXLENGTH][MAXCHAR];
DECLARE int students[MAXLENGTH];
DECLARE int count = 0;

// welcome();
DISPLAY "Welcome to my Course Rosters program!!"

// readInput(courseNums, students, count);
DECLARE char input[MAXCHAR] = "";
DECLARE bool quitting = false;
DECLARE int num;
DISPLAY "Enter course number and students enrolled when prompted." << endl;
DISPLAY "Enter Quit or quit for course number when you are done." << endl;

do {
    DECLARE int i = 0
    DISPLAY "Enter a course number: "
    INPUT input
    if(count == MAXLENGTH) {
        DISPLAY "Array full!" << endl;
        SET quitting = true;
    } else if(strcmp(input, "QUIT") == 0 || strcmp(input, "Quit") == 0 || strcmp(input, "quit") == 0){
      SET quitting = true;
    } else if(!count) {
        SET courseNums[count] = input
    } else {
      while(strcmp(courseNums[i], input) < 0 && i < count) {
        i++
      }
      for(int j = count; j > i; j--) {
        SET courseNums[j] = courseNums[j-1])
        SET students[j] = students[j-1]
      }
      SET courseNums[i] = input
    }
    
    if(!quitting){
      // readInt("Number of students enrolled: ", num);
      DISPLAY "Number of students enrolled: "
      INPUT num
      while (!cin || !(0 <= num && num <= 25) ) {
        DISPLAY "Invalid number!! Please enter a number between 0 and 25"
        DISPLAY "Number of students enrolled: "
        INPUT num
      }

      SET students[i] = num

      count++
    }

} while (!quitting);


DISPLAY "List of courses and students:"
// printList(courseNums, students, count);
for (int i = 0; i < count; i++) {
  DISPLAY courseNums[i] + students[i]
}

// cancelCourses(courseNums, students, count);
for (int i = 0; i < count; i++){
    if(students[i] < 10){
      for (int j = i; j < count - 1; j++){
            SET courseNums[j] = courseNums[j+1]
            SET students[j] = students[j + 1]
      }
      count--
      SET students[count] = 0
      SET courseNums[count] = ""
    }
  }

DISPLAY "List after cancellations:"

// printList(courseNums, students, count);
for (int i = 0; i < count; i++) {
  DISPLAY courseNums[i] + students[i]
}

DISPLAY "Thank you for checking out my Course Rosters program!"


SAMPLE RUNS
Copy from assignment document.
//////////////////Sample Run 1//////////////////
Welcome to my Course Rosters program!!
Enter course number and students enrolled when prompted. Enter Quit or quit for course number when you are done.
Enter course number: CS133G
Number of students enrolled: 7
Enter course number: CS160
Number of students enrolled: 15
Enter course number: CS161A
Number of students enrolled: 21
Enter course number: CS161B
Number of students enrolled: 23
Enter course number: CS162
Number of students enrolled: 30
Invalid number!! Please enter a number between 0 and 25
Number of students enrolled: 25
Enter course number: CS260
Number of students enrolled: 5
Enter course number: Quit

List of courses and students:
CS133G          7
CS160           15
CS161A          21
CS161B          23
CS162           25
CS260           5

List after cancellations:
CS160           15
CS162A          21
CS161B          23
CS162           25

Thank you for checking out my Course Rosters program!

////////////////////////////////////////////////
//////////////////Sample Run 2//////////////////
Welcome to my Course Rosters program!!
Enter course number and students enrolled when prompted. Enter Quit or quit for course number when you are done.
Enter course number: CS133G
Number of students enrolled: 7
Enter course number: CS160_1
Number of students enrolled: 15
Enter course number: CS161A_1
Number of students enrolled: 21
Enter course number: CS161B
Number of students enrolled: 23
Enter course number: CS162
Number of students enrolled: 30
Invalid number!! Please enter a number between 0 and 25
Number of students enrolled: 25
Enter course number: CS260
Number of students enrolled: 5
Enter course number: CS160_2
Number of students enrolled: 7
Enter course number: CS161A_2
Number of students enrolled: 25
Enter course number: quit

List of courses and students:
CS133G          7
CS160_1         15
CS160_2         7
CS161A_1        21
CS161A_2        25
CS161B          23
CS162           25
CS260           5

List after cancellations:
CS160_1         15
CS161A_1        21
CS161A_2        25
CS161B          23
CS162           25

Thank you for checking out my Course Rosters program!
////////////////////////////////////////////////

*/
