#include "stdafx.h"
struct PDetails
{
	string FirstName;
	string LastNam;
	int PhoneNum;


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

	void print(){

		cout << "\n\t___________________________________________\n";
		cout <<"\n\t\tFIRST NAME: "<<FirstName << endl;
		cout <<"\t\tSURNAME: "<< LastNam << endl;
		cout <<"\t\tPHONE NUMBER: "<< PhoneNum << endl;
	}

};

