//main driver file
//add header comments here.
#include "person.h"
const int CAPACITY = 20;

//function protoypes

//main and then functions.
int main()
{
	PersonType list[CAPACITY];
	int 	   count  = 0;
	char	   fileName[] = "persons.txt";

	cout << "Welcome to my Citizen's Database." << endl;

	populatePersons(list, count, fileName);

	cout << "\nHere is your list so far:\n" << endl;
	printPersons(list, count);

	//call your functions here to do what is required.
	if(addPerson(list, count) == true){
		// output list
		cout << "\nAfter adding a person, the list is:\n" << endl;
		printPersons(list, count);
	}
	
	cout << "\nThank you for using my Citizen Database!!" << endl;

	return 0;
}


