
//CLASS HERE 

class Contact{
	private:
		char fName[50], lName[50], email[50];
		long phoneN;
	public:
		void createContact();
		void showContact();
	//GETTERS
	char* getFName();
	char* getLName();
	char* getEmail();
	long getPhoneN();
};
