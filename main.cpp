#include <iostream>
#include "class.cpp"

using namespace std;

int main(){
	
	int choice;
	
	
	do {
		system("CLS");
		cout << "\n\t********** CONTACT MANAGER APP **********";
		cout << "\n\n";
		cout << "\t\tMAIN MENU:";
		cout << "\n\t\t----------------------";
		cout << "\n\t\t[1] Add new Contact";
		cout << "\n\t\t[2] Edit a Contact";
		cout << "\n\t\t[3] Show all Contacts";
		cout << "\n\t\t[4] Find a Contact";
		cout << "\n\t\t[5] Delete a Contact";
		cout << "\n\t\t[0] Exit";
		cout << "\n\t\t----------------------";
		cout << "\n\t\tWhat do you want to do: ";
		cin >> choice;
		
		switch(choice){
			case 1:
				system("CLS");
				writeOnFile();
				break;
			case 2:
				system("CLS");
				editOnFile();
				break;
			case 3:
				system("CLS");
				readFromFile();
				break;
			case 4:
				system("CLS");
				searchOnFile();
				break;
			case 5:
				system("CLS");
				deleteFromFile();
				break;
			case 0:
				break;
			default: 
			continue;
		}
		
		int opt;
		cout << "\n\n..::Entrer votre choix:\n[1] Menu principal\t\t[0] QUITTER\n";
		cin >> opt;

		switch (opt) {
		case 0:
			system("cls");
			cout << "\n\n\n\t\t\tMerci de utilliser notre application." << endl << endl;
			exit(0);
			break;

		default:
			continue;
		}
  
	}while(choice != 0);
	
	return 0;
}
