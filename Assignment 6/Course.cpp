//The implementation file for Course.h
//It loads students from a text file.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "Course.h"
#include "Student.h"
using namespace std;

//initiaizes a course variable and returns it. The array is empty
//and the number of students is set to 0.
Course initCourse() {
	Course course;
	course.numStudents = 0;
	return course;
}

//reads a student from the file and calls AddStudent
void readStudent(ifstream &inFile, Course &course)
{
 /*Add code here to read from the file and call addStudent to add each student to the roster.*/ 
	// This function should take a file stream variable and Course struct by reference.
	
	// Use a while (!eof) loop to read from the file into a single Student(declare local variables for this).
	while (!inFile.eof()) {
		char first[51];
		char last[51];
		double gpa;

		inFile.getline(first, 50, ';');
		inFile.getline(last, 50, ';');
		inFile >> gpa;
		inFile.ignore(1, '\n');

		Student student = initStudent(first, last, gpa);
		// Call addStudent(Student student, Course & course); and send the Student and the course to get the student added to the course.
		addStudent(student, course);
	}
	
	// The addStudent function has already been written.Right now it adds the student to the end of the list and increments the number of students.Check it out and make sure you understand how this function works.In the next few steps, you will modify this function, so you will insert the student into the list in the right position, so the list will be sorted(no sorting algorithms needed)
	
	// Repeat this process in the while loop until all students have been added.

}

//adds a student to the roster, and increment count
//modify this function to add the student sorted by name
//do not use any sorting functions.
//See this example in zyBooks Section 14.7 [https://learn.zybooks.com/zybook/PCCCS161BSpring23/chapter/14/section/7]
/*
void addStudent(Student student, Course &course) {
	course.roster[course.numStudents].gpa = student.gpa;
	strcpy(course.roster[course.numStudents].last, student.last);
	strcpy(course.roster[course.numStudents].first, student.first);
	course.numStudents++;
}
*/


void addStudent(Student student, Course &course) { // (***new for this level***)
	// Here you will modify the existing addStudent function.Right now the function adds students to the end of the list.

	// Modify the function so it adds students sorted by lastname - you should not use any sorting algorithm.Insert the students in the right position, by finding the position and shifting the other students.Here is an example from zyBooks Section 14.7.

	if (course.numStudents != 0) {
		for (int i = 0; i <= course.numStudents; i++) {
			if (strcmp(student.last, course.roster[i].last) < 0) {
				for (int j = course.numStudents; j >= i; j--) {
					course.roster[j + 1] = course.roster[j];
				}
				course.roster[i] = student;
				course.numStudents++;
				return;
			}
		}
	}
	else {
		course.roster[course.numStudents].gpa = student.gpa;
		strcpy(course.roster[course.numStudents].last, student.last);
		strcpy(course.roster[course.numStudents].first, student.first);
		course.numStudents++;
	}
	return;
	// Once you have modified this function, rerun the program to make sure it reads from the file and inserts students in the right position.Your output should look like this:
}

//prints a whole Course roster calling student print.
//use a for loop and print all the students
//must call the printStd function in Student.h
void printRoster(Course course)
{
  /*Add your code here*/
	// This function takes the course by value(the struct variable course is just used to print the students on the roster, the course is not going to be changed - hence no need to pass by reference), and prints the list of students.
	
	// Use a for loop(remember numStudents keeps track of the number of students in the Course struct), and call the printStd function to print each student.

	for (int i = 0; i < course.numStudents; i++) {
		printStd(course.roster[i]);
	}
}

/*Based on the grade level you are doing: Please read the appropriate level assignment document.
add code and function comments for the below 2 functions.
void dropStudent(char *lastname, Course &course);
Student findStudentHighestGPA(Course course);
*/
void dropStudent(char* lastname, Course& course) {
	// This function receives the name of a student and the course and removes the student with that name from the roster.
	
	// If the name does not exist, do not do anything.
	for (int i = 0; i < course.numStudents; i++) {
		if (strcmp(course.roster[i].last, lastname) == 0) {
			for (int j = i; j < course.numStudents - 1; j++) {
				course.roster[j] = course.roster[j + 1];
			}
			course.numStudents--;
			return;
		}
	}
	cout << "That name does not exist in the roster" << endl;
	
	// Notice the lastname is received as a pointer.See section15.4 Receiving arrays as pointers in Functions in zybooks for the pointer syntax.
	
	// Course variable is received by reference since the number of students and the array will change if you remove a student from the list.
	
	// Test the function by adding code to main() - there are comments where you should add code and call the function.

}

Student findStudentHighestGPA(Course course) {
	// This function should go through the roster and return a Student with the highest gpa.The course struct has all the information you need - you can declare some local variables as needed.
	int index = 0;

	for (int i = 0; i < course.numStudents; i++) {
		if (course.roster[i].gpa > course.roster[index].gpa) {
			index = i;
		}
	}
	return course.roster[index];

	// Test the function by adding code to main() - there are comments where you should add code and call the function.

}
