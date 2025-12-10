// ------------- FILE HEADER -------------
// Author ✅: Wyatt Hart
// Assignment ✅: Final Project
// Date ✅: 12/7/2025
// Citations:

// ------------- ZYBOOKS SCORES -------------
// Chapter ✅: 16
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
#include <fstream>
#include <cstring>

using namespace std;

// Constants
const int GAMES = 10;
const int MAXCHAR = 51;

// Structs
struct Games {
	char Name[MAXCHAR];
	char Platform[MAXCHAR];
	char Genre[MAXCHAR];
    double NA_Sales;
};

// Function prototypes (if any)
void welcome();
void displayMenu();
void readOption(char& option);
bool openFile(ifstream &inFile);
void loadData(ifstream &inFile, Games games[GAMES], int &count);
void addEntry(Games games[GAMES], int &count);
void removeEntry(Games games[GAMES], int &count);
void editEntry(Games games[GAMES], int count);
void printList(Games games[GAMES], int count);
void showData(Games games[GAMES], int count);


// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
int main(int argc, char *argv[]) {
  // Declare the arrays for course numbers and students.
  ifstream inFile;
  int count = 0;
  char option = ' ';
  Games games[GAMES];

  if(!openFile(inFile)) {
    cout << "File did not open! Program terminating!" << endl;
    exit(0);
  }
  
  loadData(inFile, games, count);

  welcome();
  
  do{
    displayMenu();
    readOption(option);

    switch(option){
        case 'a':
        case 'A':
            if(count >= GAMES){
                cout << "\nList already full! Can not add another entry" << endl;
                printList(games, count);
            } else{
                addEntry(games, count);
            }
            break;
        case 'r':
        case 'R':
            removeEntry(games, count);
            break;
        case 'e':
        case 'E':
            editEntry(games, count);
            break;
        case 'p':
        case 'P':
            printList(games, count);
            break;
        case 's':
        case 'S':
            showData(games, count);
            break;
    }


  } while(option != 'q' && option != 'Q');

  cout << "\nThank you for using my program!" << endl;

  inFile.close();

  return 0;
}

// Function implementations (if any)
void welcome(){
    cout << "Welcome!" << endl;
    cout << "This program analyzes video game sales and provides insight into popular game genres by console. You can Add, Remove, and Edit entries as well as Print the dataset and see which genre was the most popular, or quit the program." << endl;
}

void displayMenu(){
    cout << "\nPlease pick an option below:" << std::endl;
    
    cout << "\n(A)dd entry" << endl;
    cout << "(R)emove entry" << endl;
    cout << "(E)dit entry" << endl;
    cout << "(P)rint data" << endl;
    cout << "(S)how most popular" << endl;
    cout << "(Q)uit" << endl;
}

void readOption(char &option){
    do{
      cout << "\n>> ";
      cin >> option;

      //data validation loop
      if (!cin || (
                    option != 'q' && option != 'Q' &&
                    option != 'a' && option != 'A' &&
                    option != 'r' && option != 'R' &&
                    option != 'e' && option != 'E' &&
                    option != 's' && option != 'S' &&
                    option != 'p' && option != 'P'))
      {
          cout << "\nInvalid input! Please try again!!" << endl;
          cin.clear();
          cin.ignore(100, '\n');
          displayMenu();
      }
    } while (option != 'q' && option != 'Q' &&
                    option != 'a' && option != 'A' &&
                    option != 'r' && option != 'R' &&
                    option != 'e' && option != 'E' &&
                    option != 's' && option != 'S' &&
                    option != 'p' && option != 'P');
}

bool openFile(ifstream &inFile) {
	inFile.open("vgsales.csv");
	if(!inFile) {
		return false;
	}
	return true;
}

void loadData(ifstream &inFile, Games games[GAMES], int &count) {

    // Skip header line
    char temp[512];
    inFile.getline(temp, 512, '\n');

    while (!inFile.eof() && count < GAMES) {
        // Skip Rank
        inFile.ignore(MAXCHAR, ',');
        
        // Read Name
        inFile.getline(games[count].Name, MAXCHAR, ',');

        // Read Platform
        inFile.getline(games[count].Platform, MAXCHAR, ',');

        // Skip Year
        inFile.ignore(MAXCHAR, ',');

        // Read Genre
        inFile.getline(games[count].Genre, MAXCHAR, ',');

        // Skip Publisher
        inFile.ignore(MAXCHAR, ',');

        // Read NA_Sales
        inFile >> games[count].NA_Sales;
        inFile.ignore(MAXCHAR, ',');  // skip comma

        // Skip rest
        inFile.ignore(MAXCHAR, ',');
        inFile.ignore(MAXCHAR, ',');
        inFile.ignore(MAXCHAR, ',');
        inFile.ignore(MAXCHAR, '\n');

        // Increment count
        count++;

    }

}


void addEntry(Games games[GAMES], int &count){
    Games temp;

    cin.clear();
    cin.ignore(100, '\n');
    cout << "Please enter the name of the game (30 characters or less): ";
    cin.getline(temp.Name, MAXCHAR);

    cout << "Enter the genre : ";
    cin.getline(temp.Genre, MAXCHAR);

    cout << "Enter the platform : ";
    cin.getline(temp.Platform, MAXCHAR);

    cout << "Enter the NA_Sales (in millions) : ";
    cin >> temp.NA_Sales;

    games[count] = temp;
    count++;

    printList(games, count);

    return;
}

void removeEntry(Games games[GAMES], int &count){
    int option = 0;

    cout << "Which entry would you like to remove?" << endl;
    
    printList(games, count);
    cin >> option;
    if(0 <= option && option <= count){
        for(int i = option - 1; i < count - 1; i++){
            games[i] = games[i+1];
        }
        count--;

        cout << "Entry removed. Here is your new list:" << endl;
    }else{
        cout << "Invalid option!" << endl;
    }

    printList(games, count);

    return;
}

void editEntry(Games games[GAMES], int count){
    int index = 0;
    int option = 0;
    char temp[MAXCHAR];
    
    cout << "\nWhich entry would you like to edit?" << endl;
    printList(games, count);
    cin >> index;
    index--;

    if(0 <= index && index < count){
        cout << "Which field would you like to edit?" << endl;
    
        cout << "1.) Name" << endl;
        cout << "2.) Platform" << endl;
        cout << "3.) Genre" << endl;
        cout << "4.) NA Sales" << endl;

        cin >> option;
        if(option == 1){
            cout << "Please enter the new Name:";
            cin.clear();
            cin.ignore(100, '\n');
            cin.getline(games[index].Name, MAXCHAR);
        } else if(option == 2){
            cout << "Please enter the new Platform:";
            cin.clear();
            cin.ignore(100, '\n');
            cin.getline(games[index].Platform, MAXCHAR);
        } else if(option == 3){
            cout << "Please enter the new Genre:";
            cin.clear();
            cin.ignore(100, '\n');
            cin.getline(games[index].Genre, MAXCHAR);
        } else if(option == 4){
            cout << "Please enter the new NA_Sales (in millions):";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> games[index].NA_Sales;
        }
    }else{
        cout << "Invalid option!" << endl;
    }
    
    cout << "Entry edited. Here is your new list:" << endl;
    printList(games, count);
    
    return;
}

void printList(Games games[GAMES], int count) {
    cout << "\nName;Console;Genre;NA Sales" << endl;

    for (int i = 0; i < count; i++) {
        cout << (i + 1) << ".) " << games[i].Name << ";" << games[i].Genre << ";" << games[i].Platform << ";" << games[i].NA_Sales << endl;
    }

}

void showData(Games games[GAMES], int count){
    char mostPopularGenre[MAXCHAR];
    char leastPopularGenre[MAXCHAR];
    double mostPopularTotalSales;
    double leastPopularTotalSales;
    int num = 1;
    int maxNum = 0;
    int minNum = count;

    for(int i = 0; i < count; i++){
        for(int j = i + 1; j < count; j++){
            if(strcmp(games[i].Genre, games[j].Genre) == 0){
                num++;
            }
        }
        if(num > maxNum){
            strcpy(mostPopularGenre, games[i].Genre);
            maxNum = num;
        } else if (num < minNum){
            strcpy(leastPopularGenre, games[i].Genre);
            minNum = num;
        }
    }
    for(int i = 0; i < count; i++){
        if(strcmp(games[i].Genre, mostPopularGenre) == 0){
            mostPopularTotalSales += games[i].NA_Sales;
        }
    }
    for(int i = 0; i < count; i++){
        if(strcmp(games[i].Genre, leastPopularGenre) == 0){
            leastPopularTotalSales += games[i].NA_Sales;
        }
    }

    cout << "\nThe most popular genre was " << mostPopularGenre << endl;
    cout << "Total Sales: " << mostPopularTotalSales << endl;

    cout << "\nThe least popular genre was " << leastPopularGenre << endl;
    cout << "Total Sales: " << leastPopularTotalSales << endl;
    return;
}


// ------------- DESIGN -------------
/*
Program Name: Final Exam

Program Description:
This program analyzes video game sales and provides insight into popular game genres by console.
You can Add, Remove, and Edit entries as well as Print the dataset and see which genre was the
most popular, or quit the program.



Design:
A. INPUT
Define the input variables including name data type.
char option
char temp[MAXCHAR]

B. OUTPUT
Define the output variables including data types.
Games games[GAMES]
char mostPopularGenre[MAXCHAR]
char leastPopularGenre[MAXCHAR]
double mostPopularTotalSales
double leastPopularTotalSales

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


Int main(){
DECLARE Game games[];
DISPLAY “Welcome!”
DISPLAY “This program analyzes video game sales and provides insight into popular game genres by console. You can Add, Remove, and Edit entries as well as Print the dataset and see which genre was the most popular and on what console, or quit the program.”
do{
    displayMenu();
    switch(option){
    }
} while (option != ‘Q’ && option != ‘q’);
DISPLAY “Thank you for using my program!”;
FUNCTION displayMenu
DISPLAY “Pick an option from below:”
DISPLAY “(A)dd entry”
DISPLAY “(R)emove entry”
DISPLAY “(E)dit entry”
DISPLAY “(P)rint data”
DISPLAY “(S)how most popular”
DISPLAY “(Q)uit”
FUNCTION addEntry
DISPLAY “Please enter the name of the game (30 characters or less):”
SET games[count].Name = INPUT;
DISPLAY “Enter the genre :”
SET games[count].Genre = INPUT;
DISPLAY “Enter the NA_Sales (in millions) :”
SET games[count].naSales = INPUT
count++;
FUNCTION removeEntry
DECLARE num
DISPLAY “Which entry would you like to remove?”
printData(games)
INPUT num
SET num -= 1;
    for(int i = num; i < count << i++){
    games[i] = games[i + 1];
}
count --;
FUNCTION editEntry
DECLARE int num, index
DISPLAY “Which entry would you like to edit?”
printData(games)
INPUT index
SET num -=1;
DISPLAY “Which field would you like to edit?”
DISPLAY “Name;Console;Genre;NA Sales”
DISPLAY “1.) Name”
DISPLAY “2.) Console”
DISPLAY “3.) Genre”
DISPLAY “4.) NA Sales”
INPUT num;
DISPLAY “Please enter the new {ValueToBeUpdated}”
SET games[index].SelectedValueToBeUpdated = cin
DISPLAY “Entry edited. Here is your new list:”
printData(games);
FUNCTION printData
DISPLAY “Name;Console;Genre;NA Sales”;
for(int i = 0; i < count; i++){
    DISPLAY games[i].Name + “;”
    DISPLAY games[i].Console + “;”
    DISPLAY games[i].Genre + “;”
    DISPLAY games[i].naSales + “\n”
}
FUNCTION analyzeData
DECLARE Double mostPopularSales, leastPopularSales
DECLARE char mostPopularGenre[], leastPopularGenre[], mostPopularConsole[], leastPopularConsole[]
Char genres[];
Int count[];
For (int i = 0; i < count; i++)
    For (int j = 0; j < sizeof(genres); j++)
        if(games[i].Genre = games[j].Genre)
            Count[j] += 1;
        Else
            Count[j] = 1;
    For (int i = 0; i < sizeof(genres); i++){
        For (int j = i + 1; j < sizeof(genres); j++)
            if(count[j] > count[i])
            mostPopularGenre = genre[j]
SET Double mostPopularSales = sum of all naSales of games with genre = mostPopularGenre;
SET Double leastPopularSales = sum of all naSales of games with genre = leastPopularGenre;
DISPLAY “The most popular genre was “ + mostPopularGenre + “ on the “ + mostPopularConsole + “.”
DISPLAY “Total Sales: “ + mostPopularSales;
DISPLAY “The least popular genre was “ + leastPopularGenre + “ on the “ + leastPopularConsole + “.”
DISPLAY “Total Sales: “ + leastPopularSales;

SAMPLE RUNS
Copy from assignment document.
//////////////////Sample Run 1//////////////////
Welcome!
This program analyzes video game sales and provides insight into popular game genres by console. You can Add, Remove, and Edit entries as well as Print the dataset and see which genre was the most popular and on what console, or quit the program.
Pick an option from below:
The most popular genre was Sports on the Wii.
Total Sales: 57.24
The least popular genre was Racing on the Wii.
Total Sales: 15.85

Pick an option from below:
(A)dd entry
(R)emove entry
(E)dit entry
(P)rint data
(S)how most popular
(Q)uit

g

Invalid option!

Pick an option from below:
(A)dd entry
(R)emove entry
(E)dit entry
(P)rint data
(S)how most popular
(Q)uit

R

Which entry would you like to remove?

Name;Console;Genre;NA Sales
1.) Wii sports;Wii;Sports;41.49
2.) Super Mario Bros.;NES;Platform;29.08
3.) Mario Kart Wii;Wii;Racing;15.85
4.) Wii Sports Resort;Wii;Sports;15.75
5.) Elden Ring;PC;RPG,30.00

3

Entry removed. Here is your new list:

Name;Console;Genre;NA Sales
1.) Wii sports;Wii;Sports;41.49
2.) Super Mario Bros.;NES;Platform;29.08
3.) Wii Sports Resort;Wii;Sports;15.75
4.) Elden Ring;PC;RPG,30.00

Pick an option from below:
(A)dd entry
(R)emove entry
(E)dit entry
(P)rint data
(S)how most popular
(Q)uit

e

Which entry would you like to edit?
Name;Console;Genre;NA Sales
1.) Wii sports;Wii;Sports;41.49
2.) Super Mario Bros.;NES;Platform;29.08
3.) Wii Sports Resort;Wii;Sports;15.75
4.) Elden Ring;PC;RPG,30.00

1

Which field would you like to edit?
Name;Console;Genre;NA Sales
1.) Name
2.) Console
3.) Genre
4.) NA Sales

4

Please enter the new NA_Sales (in millions): 43.3

Entry edited. Here is your new list:

Name;Console;Genre;NA Sales
1.) Wii sports;Wii;Sports;43.30
2.) Super Mario Bros.;NES;Platform;29.08
3.) Wii Sports Resort;Wii;Sports;15.75
4.) Elden Ring;PC;RPG,30.00

Pick an option from below:

(A)dd entry
(R)emove entry
(E)dit entry
(P)rint data
(S)how most popular
(Q)uit

Q

Thank you for using my program!
////////////////////////////////////////////////

*/
