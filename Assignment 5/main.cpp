// ------------- FILE HEADER -------------
// Author ✅: Wyatt Hart
// Assignment ✅: Assignment 5
// Date ✅: 11/02/2025
// Citations:

// ------------- ZYBOOKS SCORES -------------
// Chapter ✅: 12
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

using namespace std;

// Constants
const int SONGS = 10;
const int MAXCHAR = 51;

// Function prototypes (if any)

// Write a function to open the text file created from your dataset and check to make sure it opens.  If it does not open, the program exits.
bool openFile(ifstream &inFile);
void loadData(ifstream &inFile, char songs[][2][MAXCHAR], int otherData[][2], int &count);

// Write a function to print the lists.
void printList(char songs[][2][MAXCHAR], int otherData[][2], int count);

void msToTime(int duration);

// Write a function to read from the arrays and do some data analysis.  This could be comparing data such as finding the highest value or lowest value for a column.
void songCompare(char songs[][2][MAXCHAR], int otherData[][2], int count);

// Write a function to read from the arrays and do some summation analysis.  Find the sum or average of a column of data, or rows of data as shown below in the second example.
void avgSongLength(char songs[][2][MAXCHAR], int otherData[][2], int count);


// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
int main(int argc, char *argv[]) {
  // Declare the arrays for course numbers and students.
  ifstream inFile;
  int count = 0;
  char songs[SONGS][2][MAXCHAR];
  int otherData[SONGS][2] = {0};
  if(!openFile(inFile)) {
    cout << "File did not open! Program terminating!" << endl;
    exit(0);
  }
  
  loadData(inFile, songs, otherData, count);

  printList(songs, otherData, count);

  songCompare(songs, otherData, count);

  avgSongLength(songs, otherData, count);

  inFile.close();

  return 0;
}

// Function implementations (if any)
bool openFile(ifstream &inFile) {
	inFile.open("spotify-world.csv");
	if(!inFile) {
		return false;
	}
	return true;
}

void loadData(ifstream &inFile, char songs[][2][MAXCHAR], int otherData[][2], int &count) {

    // Skip header line
    char temp[512];
    inFile.getline(temp, 512, '\n');

    while (!inFile.eof() && count < SONGS) {
        // Skip Date
        inFile.ignore(MAXCHAR, ',');
        
        // Read position
        inFile >> otherData[count][0];
        inFile.ignore(1, ',');  // skip comma

        // Read song
        inFile.getline(songs[count][0], MAXCHAR, ',');
        
        // Read artist
        inFile.getline(songs[count][1], MAXCHAR, ',');

        // Skip popularity
        inFile.ignore(MAXCHAR, ',');

        // Read duration_ms
        inFile >> otherData[count][1];
        inFile.ignore(1, ',');  // skip comma

        // Skip rest
        inFile.ignore(MAXCHAR, ',');
        inFile.ignore(MAXCHAR, ',');
        inFile.ignore(MAXCHAR, ',');
        inFile.ignore(MAXCHAR, ',');
        inFile.ignore(MAXCHAR, '\n');

        // Increment count
        count++;

    }

}

void msToTime(int duration){
    int minutes = 0;
    int seconds = 0;
    minutes = (duration / 1000) / 60;
    seconds = (duration / 1000) % 60;
    cout << minutes << ":" <<  setfill('0') << setw(2) << seconds << setfill(' ');
}

void printList(char songs[][2][MAXCHAR], int otherData[][2], int count) {
    cout << left << setw(5) << "#" << setw(30) << "Song" << setw(40) << "Artist" << right << "Duration" << endl;
    cout << setw(90) << setfill('-') << '-' << endl;
    cout << setfill(' ');

    for (int i = 0; i < count; i++) {
        cout << left << setw(5) << otherData[i][0] << setw(30) << songs[i][0] << setw(40) << songs[i][1] << right << " ";
        msToTime(otherData[i][1]);
        cout << endl;
    }

    cout << string(90, '-') << endl;
}

void songCompare(char songs[][2][MAXCHAR], int otherData[][2], int count){
    int longestSong = 0, shortestSong = 0;
    for (int i = 0; i < count; i++){
        if(otherData[i][1] > otherData[longestSong][1]){
            longestSong = i;
        } else if(otherData[i][1] < otherData[shortestSong][1]){
            shortestSong = i;
        }
    }
    cout << "The longest song in the list is " << songs[longestSong][0] << " by " << songs[longestSong][1] << " and is ";
    msToTime(otherData[longestSong][1]);
    cout << "." << endl;
    cout << "The shortest song in the list is " << songs[shortestSong][0] << " by " << songs[shortestSong][1] << " and is ";
    msToTime(otherData[shortestSong][1]);
    cout << "." << endl;
}

void avgSongLength(char songs[][2][MAXCHAR], int otherData[][2], int count){
    int avgSongLength = 0;
    for(int i = 0; i < count; i++){
        avgSongLength += otherData[i][1];
    }
    avgSongLength /= count;
    cout << "The average song length is ";
    msToTime(avgSongLength);
    cout << "." << endl;
}



// ------------- DESIGN -------------
/*
Program Name: Song length analyzer

Program Description:
My Program looks at the top songs from the spotify-world.csv file and shows the longest song, shortest song and average song longth.


Design:
A. INPUT
Define the input variables including name data type.
ifstream inFile;

B. OUTPUT
Define the output variables including data types.
songs[SONGS][2][MAXCHAR];
otherData[SONGS][2];

C. CALCULATIONS
Describe calculations used by algorithms in step D.
List all formulas.
If there are no calculations needed, state there are no calculations.
int minutes = (duration / 1000) / 60;
int seconds = (duration / 1000) % 60;


D. LOGIC and ALGORITHMS
Design the logic of your program using pseudocode or flowcharts.
Use conditionals, loops, functions or array constructs.
List the steps in transforming inputs into outputs.
https://github.com/Glen-Sasek-PCC-Instructor/2025-06-22/blob/main/Pseudocode-Reference.txt

DECLARE
DISPLAY
INPUT
SET


DECLARE ifstream inFile
DECLARE int count = 0
DECLARE char songs[SONGS][2][MAXCHAR]
DECLARE int otherData[SONGS][2] = {0}
DECLARE if(!openFile(inFile)) {
    DISPLAY "File did not open! Program terminating!"
    exit(0)
}

// loadData(inFile, songs, otherData, count);
DECLARE char temp[512]
inFile.getline(temp, 512, '\n')

while (!inFile.eof() && count < SONGS) {
    inFile.ignore(MAXCHAR, ',');
    
    SET otherData[count][0] = inFile
    inFile.ignore(1, ',')

    SET songs[count][0] = inFile.getline(songs[count][0], MAXCHAR, ',')
    
    set songs[count][0] = inFile.getline(songs[count][1], MAXCHAR, ',')

    inFile.ignore(MAXCHAR, ',');

    SET otherData[count][1] = inFile
    inFile.ignore(1, ',')

    // Skip rest
    inFile.ignore(MAXCHAR, ',')
    inFile.ignore(MAXCHAR, ',')
    inFile.ignore(MAXCHAR, ',')
    inFile.ignore(MAXCHAR, ',')
    inFile.ignore(MAXCHAR, '\n')

    // Increment count
    count++

}

// printList(songs, otherData, count);

DISPLAY "#" + "Song" + "Artist" + "Duration" 
DISPLAY setw(90) << setfill('-') << '-'

for (int i = 0; i < count; i++) {
    DISPLAY otherData[i][0] + songs[i][0] + songs[i][1] +    msToTime(otherData[i][1])
}

// songCompare(songs, otherData, count);

DECLARE int longestSong = 0, shortestSong = 0
for (int i = 0; i < count; i++){
    if(otherData[i][1] > otherData[longestSong][1]){
        SET longestSong = i
    } else if(otherData[i][1] < otherData[shortestSong][1]){
        SET shortestSong = i
    }
}
DISPLAY "The longest song in the list is " + songs[longestSong][0] + " by " + songs[longestSong][1] + " and is "
msToTime(otherData[longestSong][1]) + "."
DISPLAY "The shortest song in the list is " + songs[shortestSong][0] + " by " + songs[shortestSong][1] + " and is "+ msToTime(otherData[shortestSong][1]) + "."

// avgSongLength(songs, otherData, count);
DECLARE int avgSongLength = 0
for(int i = 0; i < count; i++){
    SET avgSongLength += otherData[i][1];
}
SET avgSongLength /= count
DISPLAY "The average song length is " + msToTime(avgSongLength) + "."

inFile.close()
return 0

SAMPLE RUNS
Copy from assignment document.
//////////////////Sample Run 1//////////////////
Occupation Name          Employed  Automation  Percent %      
_______________          ________  __________  _________      
Administrative           23081     13849       60.0017%
Agriculture              1060      594         56.0377%
Arts Entertainment       2773      555         20.0144%
Business                 8067      1129        13.9953%
Computer                 4419      1635        36.9993%
Construction             6813      3407        50.0073%
Education                9427      1697        18.0015%
Engineering              2601      494         18.9927%
Facilities Care          5905      2893        48.9924%
Food Service             13206     10697       81.0011%
Health Practitioner      8752      2888        32.9982%
Health Support           4316      1726        39.9907%
Legal                    1283      488         38.0359%
Maintenance              5654      1187        20.994%
Management               9533      2193        23.0043%
Personal Care            6420      2183        34.0031%
Production               9357      7592        81.1371%
Protective               3506      1262        35.9954%
Sales                    15748     6772        43.0023%
Science                  1300      416         32    %
Social Service           2571      566         22.0148%
Transportation           10274     5651        55.0029%

Highest/Lowest Occupations Susceptible to Automation:
Production has the highest share (81%)
Business has the lowest share (14%)

////////////////////////////////////////////////

*/
