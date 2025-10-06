// ------------- FILE HEADER -------------
// Author ✅: Wyatt Hart
// Assignment ✅: Assignment 2
// Date ✅: 10/1/2025
// Citations:

// ------------- ZYBOOKS SCORES -------------
// Chapter ✅: 10
// Participation ✅: 100
// Challenge ✅: 100
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
#include <cstring>
#include <string>
using namespace std;

//constants
const int MAXCHAR = 51;

// Function prototypes (if any)
void welcome();
void displayMenu();
void readOption(char& option);
void encode(char encodeFileName[]);
void toLower (char string[]);
void readInput(char fName[], char lName[], bool& lateFlag); //  - overloaded function
void readInput(char parsedID[], char fileName[]); // class - overloaded function
void readTime(char strTime[]);

// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
int main(int argc, char *argv[]) {
  // Declare appropriate local variables.
  char option = ' ';
  char encodeFileName[MAXCHAR] = "";

    welcome();
  // In an appropriate loop call the functions and output the encoded file name.
  do {
    displayMenu();
    readOption(option);

    if(option == 'e' || option == 'E'){
      encode(encodeFileName);
      cout << "Your encoded file name is: " << encodeFileName << endl;
      strcpy(encodeFileName, "\0");
    }
  // Repeat the menu in the loop until the user chooses to quit.
  } while(option != 'q' && option != 'Q');

  cout << "Thank you for using my fileName generator!" << endl;
  return 0;
}

// Function implementations (if any)
void welcome() { // This function prints a welcome message to the user.
    cout << "Welcome to my fileName encoding program!!" << std::endl;
}

void displayMenu(){
    // This function prints the menu to the user. Your menu
    // must have 2 items - Encode file name and quit. Here is
    cout << "Please pick an option below:" << std::endl;
    
    // (E)ncode a file name
    cout << "(e) Encode a file name" << std::endl;
    // (Q)uit
    cout << "(q) Quit" << std::endl;
}

void readOption(char &option){
    // This function will read an option and return to the called function
    // through the reference parameter.

    do{
      cout << ">> ";
      cin >> option;

      // You must do validation to make sure that the character is E/e or Q/q and
      // nothing other than that. Use a while loop to do this.

      //data validation loop
      if (!cin || (option != 'q' && option != 'Q' && option != 'e' && option != 'E'))
      {
          cout << "\nInvalid input! Please try again!!" << endl;
          cin.clear();
          cin.ignore(100, '\n');
          displayMenu();
      }
    } while (option != 'q' && option != 'Q' && option != 'e' && option != 'E');
}

 void encode(char encodeFileName[]){

    //  This should be a void function that takes 1 char array encodeFileName.

    // Declare appropriate local variables.
    char fName[MAXCHAR] = "";
    char lName[MAXCHAR] = "";
    bool lateFlag;

    char parsedID[MAXCHAR] = "";
    char fileName[MAXCHAR] = "";

    char strTime[MAXCHAR] = "";

    cout << "This program will ask you a few questions and generate an encoded fileName" << endl;

    // Call the readInput() function to read student’s names and lateFlag - void readInput(char fName[], char lName[], bool& lateFlag)
    readInput(fName, lName, lateFlag);

    // Call the readInput() function to read Student ID and filename. - void readInput(char parsedID[], char fileName[])
    readInput(parsedID, fileName);

    // Call the readTime() function to read the submitted time. - void readTime(char strTime[])
    readTime(strTime);

    // Fill the encodeFileName array based on the six pieces of information
    // adding underscores between.
    // Start with the student’s names, if the assignment is late, put LATE in
    // the filename and nothing otherwise, add the parsed Student ID, add the
    // time, without the colon, and then finally add the filename.
    strcat(encodeFileName, strcat(lName, "_"));
    strcat(encodeFileName, strcat(fName, "_"));
    if(lateFlag){
      strcat(encodeFileName, "LATE_");
    }
    strcat(encodeFileName, strcat(parsedID, "_"));
    strcat(encodeFileName, strcat(strTime, "_"));
    strcat(encodeFileName, fileName);
}

void toLower (char string[]){
  for (int i = 0; string[i] != '\0'; i++){
    string[i] = tolower(string[i]);
  }
};

void readInput(char fName[], char lName[], bool &lateFlag) { //  - overloaded function

    // This void function should take 2 char arrays and 1 bool variable by
    // reference.

    char setLate;
    // It reads the student’s first name, last name and if the assignment is
    // late or not. Student last name (e.g. Smith) (char array). Student first
    // name (e.g. Sue) (char array)
    cout << "Enter your last name: ";
    cin >> lName;

    cout << "Enter your first name: ";
    cin >> fName;

    cout << "Was your assignment late (y/n)? ";
    cin >> setLate;

    // Make sure all character data for the student’s name is lowercase - you
    // may write a function to convert a cstring to all lowercase.
    toLower(fName);
    toLower(lName);

    // If the assignment was late or not (e.g., Y or N) (bool var). Must do data
    // validation for this.
    do{
      if (setLate == 'y' || setLate == 'Y'){
        lateFlag = true;
      } else if(setLate == 'n' || setLate == 'N'){
        lateFlag = false;
      } else{
          cout << "\nInvalid input! Please try again!!" << endl;
          cin.clear();
          cin.ignore(100, '\n');
          cout << "Was your assignment late (y/n)? ";
          cin >> setLate;
      }
    } while (setLate == '\0');

    // Hint: Remember an overloaded function has the same function name but
    // different types of parameters or the number of parameters are different.
}

void readInput(char parsedID[], char fileName[]) { // class - overloaded function

    // This void function should take 1 char array for the parsed 4 digit
    // Student ID that will be returned and another char array for the filename.
    char studentID[MAXCHAR] = "";
    bool validID = false;


    do{
      cout << "Enter your Student-ID (format: 222-22-2222): ";
      cin >> studentID;

      if(strlen(studentID) != 11 ){
        cout << "\nInvalid input! Please try again!!" << endl;
        cin.clear();
        cin.ignore(100, '\n');
      } else{
        validID = true;
      }
    } while(!validID);
    // The Student ID (e.g., 977-15-5587) (char array) is a local variable. Use
    // the strncpy() function to copy from position 7 till the end of the
    // string. strncpy(parsedID, stdID + 7, 4) will copy 4 characters from the
    // 7th position in the stdID string to the parsedID string.
    strncpy(parsedID, studentID + 7, 4);

    // The name of the file (e.g., prog2.cpp) (char array)
    cout << "Enter the file name: ";
    cin >> fileName;
}

void readTime(char strTime[]) {

    // This is a void function that should read the time from the user as 2
    // integers and return one char array by reference (that is the strTime
    // array).
    int hour = 0, min = 0;
    char discard;

    cout << "Enter the time submitted (military time - ex: 18:24 for 6:24pm): ";
    cin >> hour >> discard >> min;
    //while the numbers are not good or the character is not a :
    //error and stay in the loop.
    while(!cin || discard != ':' || !(hour >= 0 && hour < 24 && min >= 0 and min < 60))
    {
      cout << "Invalid input! Please try again!!" << endl;
      cin.clear();
      cin.ignore(100, '\n');
      cin >> hour >> discard >> min;
    }   

    cin.ignore(100,'\n');
    strncpy(strTime, to_string(hour).c_str(),10);
    strcat(strTime, to_string(min).c_str());

    // You must do data validation by
    // checking the hours are between 0 and 24 and the minutes are between 0
    // and 60.

    // This function must do data validation for the numbers and the HH:MM
    // format. Make sure the colon : is used to separate the mins and hours.
}

    // ------------- DESIGN -------------
    /*
    Program Name:

    Program Description:

    Design:
    A. INPUT
    Define the input variables including name data type.
    char option
    char fName[MAXCHAR]
    char lName[MAXCHAR]
    bool lateFlat
    char parsedID[MAXCHAR]
    char strTime[MAXCHAR]
    char fileName[MAXCHAR]


    B. OUTPUT
    Define the output variables including data types.
    char encodedFileName[MAXCHAR]

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

    DECLARE char option = ' '
    DECLARE char encodeFileName[MAXCHAR] = ""

    // welcome()
    DISPLAY "Welcome to my fileName encoding program!!"

    // displayMenu()
    DISPLAY "Please pick an option below:"
    DISPLAY "(e) Encode a file name"
    DISPLAY << "(q) Quit"
      
    // readOption()
    do {
      displayMenu();
      do{
        DISPLAY ">> "
        INPUT option

        if (!cin || (option != 'q' && option != 'Q' && option != 'e' && option != 'E'))
        {
            DISPLAY "\nInvalid input! Please try again!!"
            displayMenu();
        }
      } while (option != 'q' && option != 'Q' && option != 'e' && option != 'E');

      if(option == 'e' || option == 'E'){
        // encode();
        DECLARE char fName[MAXCHAR] = "";
        DECLARE char lName[MAXCHAR] = "";
        DECLARE bool lateFlag;

        DECLARE char parsedID[MAXCHAR] = "";
        DECLARE char fileName[MAXCHAR] = "";

        DECLARE char strTime[MAXCHAR] = "";

        DISPLAY "This program will ask you a few questions and generate an encoded fileName"

        // readInput()
        char setLate;
        DISPLAY "Enter your last name: "
        INPUT lName

        DISPLAY "Enter your first name: "
        INPUT fName

        DISPLAY "Was your assignment late (y/n)? "
        INPUT setLate

        do{
          if (setLate == 'y' || setLate == 'Y'){
            lateFlag = true;
          } else if(setLate == 'n' || setLate == 'N'){
            lateFlag = false;
          } else{
              DISPLAY "\nInvalid input! Please try again!!"
              DISPLAY "Was your assignment late (y/n)? "
              INPUT setLate
          }
        } while (setLate == '\0');

        // readInput(parsedID, fileName);
        char studentID[MAXCHAR] = "";
        DECLARE bool validID = false;

        do{
          DISPLAY "Enter your Student-ID (format: 222-22-2222): "
          INPUT studentID

          if(strlen(studentID) != 11 ){
            DISPLAY "\nInvalid input! Please try again!!"
          } else{
            validID = true;
          }
        } while(!validID);
        strncpy(parsedID, studentID + 7, 4);
        DISPLAY "Enter the file name: "
        INPUT fileName

        // readTime(strTime);
        DECLARE int hour = 0, min = 0;
        DECLARE char discard;

        DISPLAY "Enter the time submitted (military time - ex: 18:24 for 6:24pm): "
        INPUT hour >> discard >> min
        while(!cin || discard != ':' || !(hour >= 0 && hour < 24 && min >= 0 and min < 60))
        {
          DISPLAY "Invalid input! Please try again!!" << endl
          INPUT hour >> discard >> min
        }   

        strncpy(strTime, to_string(hour).c_str(),10);
        strcat(strTime, to_string(min).c_str());

        strcat(encodeFileName, strcat(lName, "_"));
        strcat(encodeFileName, strcat(fName, "_"));
        if(lateFlag){
          strcat(encodeFileName, "LATE_");
        }
        strcat(encodeFileName, strcat(parsedID, "_"));
        strcat(encodeFileName, strcat(strTime, "_"));
        strcat(encodeFileName, fileName);

        DISPLAY "Your encoded file name is: " << encodeFileName
        strcpy(encodeFileName, "\0");
      }
    } while(option != 'q' && option != 'Q');

    DISPLAY "Thank you for using my fileName generator!"

    SAMPLE RUNS
    Copy from assignment document.

    //////////////////Sample Run 1//////////////////
    Welcome to my fileName encoding program!!
    Please pick an option below:
    (e)Encode a file name
    (q)quit
    >>e
    This program will ask you a few questions and generate an encoded fileName based on your answers.
    Enter your last name: Iyer
    Enter your first name: GD
    Was your assignment Late (y/n)? Y
    Enter your Student-ID (format: 222-22-2222): 234-05-4556
    Enter the file name: a05.cpp
    Enter the time submitted (military time - ex: 18:24 for 6:24pm): 13:45
    Your encoded file name is: iyer_gd_LATE_4556_1345_a05.cpp
    Please pick an option below:
    (e)Encode a file name
    (q)quit
    >>b
    Invalid option! Please try again!!
    Please pick an option below:
    (e)Encode a file name
    (q)quit
    >>q
    Thank you for using my fileName generator!
    ////////////////////////////////////////////////

    */
