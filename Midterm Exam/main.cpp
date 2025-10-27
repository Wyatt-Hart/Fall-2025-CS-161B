// ------------- FILE HEADER -------------
// Author ✅: Wyatt Hart
// Assignment ✅: Midterm Exam
// Date ✅: 10/26/2025
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
// A. INPUT ✅: 
// B. OUTPUT ✅:
// C. CALCULATIONS ✅:
// D. LOGIC and ALGORITHMS ✅:
//    (Optional) flow chart link or file name: 


// ------------- TESTING -------------
// PASS ALL GIVEN SAMPLE RUN TESTS ✅: 
// (Optional) Additional tests count:   


// ------------- CODE -------------
#include <iostream>

using namespace std;

// Function prototypes (if any)
int enqueue(int queue[], int &size, int val);
int dequeue(int queue[], int &size, int val);
void printQueue(int queue[], int size);

// Constants
const int MAX = 3; // maximum size of queue

// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
int main(int argc, char* argv[]) {
    int queue[MAX]; // integer array for queue
    int size = 0;   // contains number of elements in queue
    int val;
    char option = ' ';

    // Add your code here

    cout << "Welcome to the FIFO Queue Program!" << std::endl;
    
    
    do{
      cout << "\nEnter option: ";
      cin >> option;

    switch(option){
        case '+':
            cout << "Integer: ";
            do{
                cin >> val;
                if (!cin ) {
                    cout << "Invalid input" << endl;
                    cin.clear();
                    cin.ignore(100, '\n');
                }
            } while(!cin);
            enqueue(queue, size, val);
            printQueue(queue, size);
            break;
        case '-':
            cout << "Integer: ";
            do{
                cin >> val;
                if (!cin ) {
                    cout << "\nInvalid input" << endl;
                    cin.clear();
                    cin.ignore(100, '\n');
                }
            } while(!cin);
            dequeue(queue, size, val);
            printQueue(queue, size);
            break;
        case 'p':
        case 'P':
            printQueue(queue, size);
            break;
        case 'q':
        case 'Q':
            break;
        default:
            cout << "Invalid option." << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }

    } while (option != 'q' && option != 'Q');

    cout << "\nGoodbye!" << endl;

    return 0;
}

// Function implementations (if any)

int enqueue(int queue[], int &size, int val){
    if(size + 1 > MAX){
        cout << "Error: Queue Overflow!" << endl;
        return 1;
    }else{
        queue[size] = val;
        size++;
        return 0;
    }
}

int dequeue(int queue[], int &size, int val){
    if(size == 0){
        cout << "Queue Empty." << endl;
        return 1;
    } else {
        for(int i = 0; i < size; i++){
            if(queue[i] == val){
                for(int j = 0; j < i; j++){
                    if(i + j < MAX){
                        queue[j] = queue[i + j + 1];
                    }
                }
                size = size - (i + 1);
                return 0;
            }
        }
    }

    cout << val << " is not in the queue." << endl;
    return 2;
}


void printQueue(int queue[], int size){
    cout << "[";
    for (int i = 0; i < size; i++){
        cout << queue[i];
        
        if (i != size - 1)
            cout << ", " ;
    }
    cout << "]" << endl;
}



// ------------- DESIGN -------------
/* 
Program Name: Midterm Exam

Program Description:
A queue is a data type with a bounded (predefined) capacity. It is a simple data structure that uses an array and adds elements in one end and removes them from the other end, just like a “queue” or “line” at the market checkout. You enter the line at the rear, and after you’ve paid for your items, you leave at the front. We call this a FIFO (First In First Out) structure. Every time an element is added, it goes in the REAR of the queue, and when an element is removed, all elements before it are also removed (look at the sample run)

Design:
A. INPUT
Define the input variables including name data type. 
char option;
int val;

B. OUTPUT
Define the output variables including data types. 
int val;
int queue[MAX]

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

DECLARE
DISPLAY
INPUT
SET

DECLARE int queue[MAX]
DECLARE int size = 0
DECLARE int val
DECLARE char option = ' '

DISPLAY "Welcome to the FIFO Queue Program!"


do{
    DISPLAY "Enter option: "
    INPUT option

switch(option){
    case '+':
        DISPLAY "Integer: "
        do{
            INPUT val
            if (!cin ) {
                DISPLAY "Invalid input"
            }
        } while(!cin)
        // enqueue(queue, size, val)
        if(size + 1 > MAX){
            DISPLAY "Error: Queue Overflow!"
            return 1
        }else{
            SET queue[size] = val
            SET size++
            return 0
        }
        // printQueue(queue, size)
        break
    case '-':
        DISPLAY "Integer: "
        do{
            INPUT  val
            if (!cin ) {
                DISPLAY "Invalid input"
            }
        } while(!cin)
        // dequeue(queue, size, val)
        if(size == 0){
            DISPLAY "Queue Empty."
            return 1
        } else {
            for(int i = 0; i < size; i++){
                if(queue[i] == val){
                    for(int j = 0; j < i; j++){
                        if(i + j < MAX){
                            SET queue[j] = queue[i + j + 1]
                        }
                    }
                    SET size = size - (i + 1)
                    return 0
                }
            }
        }

        
        DISPLAY  val + " is not in the queue."
        return 2
        // printQueue(queue, size)
        break
    case 'p':
    case 'P':
        // printQueue(queue, size)
        DISPLAY "["
        for (int i = 0; i < size; i++){
            DISPLAY queue[i]
            
            if (i != size - 1)
                DISPLAY ", "
        }
        DISPLAY "]"
        break
    case 'q':
    case 'Q':
        break
    default:
        DISPLAY "Invalid option."
    }

} while (option != 'q' && option != 'Q')

DISPLAY "Goodbye!"

SAMPLE RUNS
Copy from assignment document.
//////////////////Sample Run 1//////////////////
Welcome to the FIFO Queue Program!

Enter option: +
Integer: 9
[9]

Enter option: +
Integer: 3
[9, 3]

Enter option: +
Integer: -2
[9, 3, -2]

Enter option: +
Integer: 10
Error: Queue Overflow!
[9, 3, -2]

Enter option: -
Integer: 5
5 is not in the queue.
[9, 3, -2]

Enter option: -
Integer: 3
[-2]

Enter option: @
Invalid option.

Enter option: p
[-2]

Enter option: -
Integer: -2
[]

Enter option: -
Integer: 0
Queue Empty.
[]

Enter option: +
Integer: 23
[23]

Enter option: q

Goodbye!
////////////////////////////////////////////////

*/