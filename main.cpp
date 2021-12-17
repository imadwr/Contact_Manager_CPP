#include <iostream>
#include "class.cpp"

using namespace std;

int main(){
	
	int choice;
	
	
	do {
		cout << "\n\t**********Contact Manager Application**********";
		cout << "\n\n";
		cout << "\t\tMain Menu:";
		cout << "\n\t\t----------------------";
		cout << "\n\t\t[1] Add a new Contact";
		cout << "\n\t\t[2] Edit a Contact";
		cout << "\n\t\t[3] Show all Contacts";
		cout << "\n\t\t[4] Search for Contact";
		cout << "\n\t\t[5] Delete a Contact";
		cout << "\n\t\t[0] Exit";
		cout << "\n\t\t----------------------";
		cout << "\n\t\tWhat do you want to do: ";
		cin >> choice;
		
		switch(choice){
			case 1:
				//add contact
				break;
			case 2:
				//edit contact
				break;
			case 3:
				//show contacts
				break;
			case 4:
				//shearch for cointact
				break;
			case 5:
				//delete contact
				break;
			case 0:
				break;
			default: 
			continue;
		}
  
	}while(choice != 0);
	
	return 0;
}
