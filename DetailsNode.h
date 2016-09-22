#include "stdafx.h"
struct PDetails //struct to store first name, last name and phone number
{

	
	string FirstName;
	string LastNam;
	int PhoneNum;

	//operator overloading
	bool operator < (const PDetails &info) {
		if (LastNam < info.LastNam) return true;
		if (LastNam > info.LastNam) return false;
		return (FirstName < info.FirstName);
	}

	bool operator >(const PDetails &info) {
		if (LastNam > info.LastNam) return true;
		if (LastNam < info.LastNam) return false;
		return (FirstName > info.FirstName);
	}

	bool operator < (const string info) {
		return (LastNam < info);
	}

	bool operator >(const string info) {
		return (LastNam > info);
	}
	bool operator < (const char info) {
		return (LastNam[0] < info);
	}

	bool operator >(const char info) {
		return (LastNam[0] > info);
	}
	PDetails& operator = (PDetails &info) {
		FirstName = info.FirstName;
		LastNam = info.LastNam;
		PhoneNum = info.PhoneNum;
		return *this;
	}
	//print method, for when the contact is found. Either by the first letter of the surname or by the surname.
	void print(){

		cout << "\n\t___________________________________________\n";
		cout <<"\n\t\tFIRST NAME: "<<FirstName << endl;
		cout <<"\t\tSURNAME: "<< LastNam << endl;
		cout <<"\t\tPHONE NUMBER: "<< PhoneNum << endl;
	}

};

