//implememtation file for struct PersonType
#include "person.h"

//function to read from file and populate list
void populatePersons(PersonType list[], int& count, const char fileName[])
{
    ifstream        inFile;
    char            name[MAX_CHAR];
    char            citizen[MAX_CHAR];
    int age = 0;

    inFile.open(fileName);
    if(!inFile)
    {
        cerr << "Fail to open " << fileName << " to populate inventory!" << endl;
        exit(1);
    }
    inFile >> name;
    while(!inFile.eof())
    {
        inFile >> citizen;
        inFile >> age;
        strcpy(list[count].name, name);
        strcpy(list[count].citizenship, citizen);
        list[count].age = age;
        count++;

        inFile >> name;
    }
    inFile.close();
}

//function to print list
void printPersons(const PersonType list[], int count)
{
    cout << "List of citizen database!" << endl;
    for(int index = 0; index < count; index++)
    {
        cout << list[index].name << ";" << list[index].citizenship;
        cout << ";" << list[index].age << endl;
    }
}

//add your function here
// Create a function to read a person’s information
// and insert into the list at a given position.
// The function returns true if the insertion is
// successful and it returns false if the array is
// out of capacity.
bool addPerson(PersonType list[], int &count){
    char name[MAX_CHAR], citizenship[MAX_CHAR];
    int age, position;

    //read in person name, person citizenship, and age and populate aPerson
    //e.g strcpy(aPerson.name, tempName)
    cout << "\nEnter your name:" << endl;
    cin.getline(name, MAX_CHAR);

    cout << "Enter your citizenship:" << endl;
    cin.getline(citizenship, MAX_CHAR);
    
    cout << "Enter your age:" << endl;
    cin >> age;
    
    PersonType person;
    strcpy(person.name, name);
    strcpy(person.citizenship, citizenship);
    person.age = age;

    //read position to insert inside the function - see sample //run
    cout << "Enter position number:" << endl;
    cin >> position;

    //position could be read from the user or you could set a //number that is not more than count. If you read from the //user, check to make sure position is not > than count.
    if(position > count){
        cout << "\nError! Invalid position." << endl;
        return 0;
    } else {
        //shift and insert aPerson in the right position
        for(int i = count; i > position; i--){
            list[i] = list[i - 1];
        }
        list[position] = person;
        count++;
    }


    return 1;
}