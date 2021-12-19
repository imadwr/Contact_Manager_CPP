#include <iostream>
#include "class.h"
#include <fstream>

using namespace std;


void Contact::createContact(){
	cout << "First Name: ";
	cin >> fName;
	cout << "Last Name: ";
	cin >> lName;
	cout << "Phone: ";
	cin >> phoneN;
	cout << "Email: ";
	cin >> email;
}

void Contact::showContact(){
	cout << "First Name: " << this->fName << "\nLast Name: " << this->lName << "\nPhone: " << this->phoneN << "\nEmail: " << this->email << endl;
}

char* Contact::getFName(){
	return this->fName;
}

char* Contact::getLName(){
	return this->lName;
}

char* Contact::getEmail(){
	return this->email;
}

long Contact::getPhoneN(){
	return this->phoneN;
}



Contact C;

void writeOnFile(){
	char ch;
	ofstream f;
	f.open("CMS.dat", ios::binary | ios::app);
	
	do{
		C.createContact();
		f.write(reinterpret_cast<char*>(&C), sizeof(Contact));
		cout << "Do you want to add another contact? (y ou n): ";
		cin >> ch;
	}while(ch == 'y');
	
	cout << "Contact has been Sucessfully Created...";
	f.close();
}


void readFromFile(){
	ifstream f;
	f.open("CMS.dat", ios::binary);
	if(!f){
		cout << "ERROR: Cannot open file!";
	} else {
		cout << "\n================================\n";
		cout << "LIST OF CONTACTS";
		cout << "\n================================\n";
		
		while(!f.eof()){
			if (f.read(reinterpret_cast<char*>(&C), sizeof(Contact))){
				C.showContact();
				cout << "\n================================\n";
			}
		}
		f.close();
	}
}


void searchOnFile(){
	ifstream f;
	string name;
	bool found = false;
	
	cout << "Enter the name you want to look for: ";
	cin >> name;
	f.open("CMS.dat", ios::binary);
	while(!f.eof()){
		if(f.read(reinterpret_cast<char*>(&C), sizeof(Contact))){
			if(name == C.getFName()){
				cout << "\n================================\n";
				cout << "CONTACTS FOUND";
				cout << "\n================================\n";
				C.showContact();
				cout << "\n================================\n";
				found = true;
			}
		}
	} 
	
	if(!found) {
		cout << "\n\n No record not found";
	}
	f.close();
}


void deleteFromFile(){
	ifstream f;
	ofstream f1;
	long phone;
	bool found = false;
	
	cout << "Enter phone number of contact to delete: ";
	cin >> phone;
	
	f.open("CMS.dat", ios::binary);
	f1.open("TEMP.dat", ios::binary);
	f.seekg(0,ios::beg);
	while(!f.eof()){
		if(f.read(reinterpret_cast<char*>(&C), sizeof(Contact))){
			if(phone != C.getPhoneN()){
				f1.write(reinterpret_cast<char*>(&C), sizeof(Contact));
			} else {
				found = true;
			}
		}
	}
	f.close();
	f1.close();
	remove("CMS.dat");
	rename("TEMP.dat","CMS.dat");
	if(found){
		cout<<endl<<"Contact has been Sucessfully Deleted...";
	} else {
		cout <<endl << "Contact with this phone number doesn't exist...";
	}
}

void editOnFile(){
	ifstream f;
	ofstream f1;
	long phone;
	bool found;
	
	cout << "Enter phone number of contact to modify: ";
	cin >> phone;
	
	f.open("CMS.dat", ios::binary);
	f1.open("TEMP.dat", ios::binary);
	f.seekg(0,ios::beg);
	while(!f.eof()){
		if(f.read(reinterpret_cast<char*>(&C), sizeof(Contact))){
			if(phone != C.getPhoneN()){
				f1.write(reinterpret_cast<char*>(&C), sizeof(Contact));
			} else {
				C.createContact();
				f1.write(reinterpret_cast<char*>(&C), sizeof(Contact));
				found = true;
			}
		}
	}
	f.close();
	f1.close();
	remove("CMS.dat");
	rename("TEMP.dat","CMS.dat");
	if(found){
		cout<<endl<<"Contact has been Sucessfully Modified...";
	} else {
		cout <<endl << "Contact with this phone number doesn't exist...";
	}
	
}








