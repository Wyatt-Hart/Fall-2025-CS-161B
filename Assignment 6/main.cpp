// ------------- FILE HEADER -------------
// Author ✅: Wyatt Hart
// Assignment ✅: Assignment 6
// Date ✅: 11/16/2025
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
//The client file or the driver file
//This file has the main() function
//Add header comments here.
#include <iostream>
#include <cstring>

#include "Student.h"
#include "Course.h"

using namespace std;

int main() {
    Course course = initCourse();
    ifstream inFile;
    cout << "Welcome to my Course Roster Program\n" << endl;
    inFile.open("students.txt");
    if(!inFile)
    {
    cout << "File did not open! Program Exiting!!" << endl;
    return 0;
    }
    //calls readStudent to read from the file
    readStudent(inFile, course);
    //calls printRoster to print the roster
    cout << "\nHere is the course roster: " << endl;
    printRoster(course);

    //call the appropriate functions based on the grade level you are choosing.
    //calls dropStudent to drop a student from the roster.
    //read a last name into a char array and pass to function.
    //declare variables if needed
    char lastname[51];
    cout << "\nEnter the last name of the student to drop: ";
    cin.getline(lastname, 51);
    dropStudent(lastname, course);

    /*Add code here to call function*/
  
    //calls printRoster to print the roster after the student drop.
    //Uncomment the next 2 lines once you have dropped a student
    cout << "\nHere is the course roster: " << endl;
    printRoster(course);
  
    //calls findStudentHighestGPA to get Student with highest GPA
    //declare variables if needed

    /*Add code here to call function*/
    Student studentHighestGPA = findStudentHighestGPA(course);
  
    //calls printStd to print the student with the highest GPA
    cout << "\nStudent with the highest GPA: " << endl;
    printStd(studentHighestGPA);

    /*Add code here to call function*/

    cout << "\nThank you for using my Student Roster program!!" << endl;
    return 0;
}



// ------------- DESIGN -------------
/*
Program Name: Student Roster program

Program Description:


Design:
A. INPUT
Define the input variables including name data type.
char[51] lastname

B. OUTPUT
Define the output variables including data types.
course.roster[].first
course.roster[].last
course.roster[].gpa
Student studentHighestGPA

C. CALCULATIONS
Describe calculations used by algorithms in step D.
List all formulas.
If there are no calculations needed, state there are no calculations.
there are no calculations needed

D. LOGIC and ALGORITHMS
Design the logic of your program using pseudocode or flowcharts.
Use conditionals, loops, functions or array constructs.
List the steps in transforming inputs into outputs.
https://github.com/Glen-Sasek-PCC-Instructor/2025-06-22/blob/main/Pseudocode-Reference.txt

DECLARE
DISPLAY
INPUT
SET



DECLARE Course course = initCourse()
DECLARE ifstream inFile;

DISPLAY "Welcome to my Course Roster Program\n"

inFile.open("students.txt");

// readStudent(inFile, course);
while (!inFile.eof()) {
    DECLARE char first[51];
    DECLARE char last[51];
    DECLARE double gpa;

    SET inFile.getline(first, 50, ';');
    SET inFile.getline(last, 50, ';');
    SET inFile >> gpa;
    SET inFile.ignore(1, '\n');

    DECLARE Student student = initStudent(first, last, gpa);
    
    // addStudent(student, course);
    if (course.numStudents != 0) {
        for (int i = 0; i <= course.numStudents; i++) {
            if (strcmp(student.last, course.roster[i].last) < 0) {
                for (int j = course.numStudents; j >= i; j--) {
                    SET course.roster[j + 1] = course.roster[j];
                }
                SET course.roster[i] = student;
                SET course.numStudents++;
                SET return;
            }
        }
    }
    else {
        SET course.roster[course.numStudents].gpa = student.gpa;
        SET strcpy(course.roster[course.numStudents].last, student.last);
        SET strcpy(course.roster[course.numStudents].first, student.first);
        SET course.numStudents++;
    }
    return;
}

DISPLAY "\nHere is the course roster: "
// printRoster(course);
for (int i = 0; i < course.numStudents; i++) {
    // printStd(course.roster[i]);
    DISPLAY student.first + ";" + student.last + ";" + student.gpa
}

SET char lastname[51];
DISPLAY "\nEnter the last name of the student to drop: ";

cin.getline(lastname, 51);
// dropStudent(lastname, course);
for (int i = 0; i < course.numStudents; i++) {
    if (strcmp(course.roster[i].last, lastname) == 0) {
        for (int j = i; j < course.numStudents - 1; j++) {
            SET course.roster[j] = course.roster[j + 1];
        }
        SET course.numStudents--;
        return;
    }
}
DISPLAY "That name does not exist in the roster"


DISPLAY "\nHere is the course roster: "
// printRoster(course);


SET Student studentHighestGPA = findStudentHighestGPA(course);

DISLAY "\nStudent with the highest GPA: "
// printStd(studentHighestGPA)

DISPLAY "\nThank you for using my Student Roster program!!"

SAMPLE RUNS
Copy from assignment document.
//////////////////Sample Run 1//////////////////
Welcome to my Course Roster Program

Here is the course roster:
Henry;Nguyen;3.5
Brenda;Stern;2
Lynda;Robison;3.2
Sonya;King;3.9
Gayathri;Iyer;3.5
Glen;Sasek;3.7
Priya;Goel;3.8

Enter the last name of the student to drop: King

Here is the course roster:
Henry;Nguyen;3.5
Brenda;Stern;2
Lynda;Robison;3.2
Gayathri;Iyer;3.5
Glen;Sasek;3.7
Priya;Goel;3.8

The student with the highest GPA:
Priya;Goel;3.8

Thank you for using my Student Roster program!!

////////////////////////////////////////////////
//////////////////Sample Run 2//////////////////
Welcome to my Course Roster Program

Here is the course roster:
Priya;Goel;3.8
Gayathri;Iyer;3.5
Sonya;King;3.9
Henry;Nguyen;3.5
Lynda;Robison;3.2
Glen;Sasek;3.7
Brenda;Stern;2

Enter the last name of the student to drop: Iyer

Here is the course roster:
Priya;Goel;3.8
Sonya;King;3.9
Henry;Nguyen;3.5
Lynda;Robison;3.2
Glen;Sasek;3.7
Brenda;Stern;2

The student with the highest GPA:
Sonya;King;3.9

Thank you for using my Student Roster program!!

////////////////////////////////////////////////

*/
