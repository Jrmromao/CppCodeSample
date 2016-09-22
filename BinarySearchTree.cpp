// Assigment_6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DetailsNode.h"
#include "TreeType.h"

//PROTOTYPS
int menu();
void EnterPhoneList();
void printPhoneList();
void searchItem();
void searchItemLetter();
void exit();
void deletItem();
void ReseteList();

//global variables

bool Quitflag = false;
TreeType <PDetails> TT;
PDetails details;


int _tmain(int argc, _TCHAR* argv[])
{

	int option;

	do
	{
		option = menu();

		switch (option)
		{

		case 1:
			ReseteList();
			break;
		case 2:
			EnterPhoneList();
			break;
		case 3:
			printPhoneList();
			break;
		case 4:
			deletItem();
			break;
		case 5:
			searchItemLetter();
			break;
		case 6:
			searchItem();
			break;
		case 7:
			exit();
			break;
		default:
			cout << "\n\n\t\tWRONG OPTION!";
			break;
		}



	} while (!Quitflag);



	return 0;
}


//Function definition
//menu
#pragma region 
int menu(){
	system("COLOR 6");
	int option = 0;
	cout << "\n\n\n\t\t\n\t\t\t\t_M E N U_ ";
	cout << "\n\t________________________________________________________________\n";
	cout << "\n\t\t1. Clear Address Book";
	cout << "\n\t\t2. Add Contacts To the Phone Book";
	cout << "\n\t\t3. Print All Contacts On the Phone Book";
	cout << "\n\t\t4. Delete Entry From the Phone Book";
	cout << "\n\t\t5. Search The Address Book [BY LETTER]";
	cout << "\n\t\t6. Search The Address Book [BY SURNAME]";
	cout << "\n\t\t7. Exit! ";
	cout << "\n\t________________________________________________________________\n";
	cout << "\n\t\tOption: ";
	cin >> option;


	system("cls");
	return option;
}
#pragma endregion Menu

//option 1
#pragma region 
void ReseteList(){

	if (TT.IsEmpty())
	{
		cout << "\n\t" << char(218) << "-------------------------------" << char(191);
		cout << "\n\t" << char(179) << "\tPHONE BOOK IS EMPTY!\t" << char(179);
		cout << "\n\t" << char(192) << "-------------------------------" << char(217);
	}
	else {
		TT.ResetTree();
		cout << "\n\t" << char(218) << "-------------------------------" << char(191);
		cout << "\n\t" << char(179) << "\tPHONE BOOK IS EMPTY!\t" << char(179);
		cout << "\n\t" << char(192) << "-------------------------------" << char(217);
	}
		
}
#pragma endregion Reset Phonebook

//Option 2
#pragma region 
void EnterPhoneList(){

		details.FirstName = "Barack";
		details.LastNam = "Obama";
		details.PhoneNum = 0012024561111;
		TT.InsertItem(details);

		details.FirstName = "Dimitri";
		details.LastNam = "Vegas";
		details.PhoneNum = 003225551222;
		TT.InsertItem(details);

		details.FirstName = "Filipe";
		details.LastNam = "Variado";
		details.PhoneNum = 00351242202244;
		TT.InsertItem(details);

		details.FirstName = "Joao";
		details.LastNam = "Romao";
		details.PhoneNum = 00351245244255;
		TT.InsertItem(details);

		details.FirstName = "Mario";
		details.LastNam = "Ramalho";
		details.PhoneNum = 00351212012012;
		TT.InsertItem(details);


	//cout << "\n\t" << char(218) << "-------------------------------" << char(191);
	//cout << "\n\t" << char(179) << "\tADD CONTACT NUMBER!\t" << char(179);
	//cout << "\n\t" << char(192) << "-------------------------------" << char(217);


	//cout << "\n\tEnter First Name: ";
	//cin >> details.FirstName;
	//cout << "\tEnter Surname: ";
	//cin >> details.LastNam;
	//cout << "\tEnter Phone Number: ";
	//cin >> details.PhoneNum;
	//TT.InsertItem(details);
	//cout << "\n\t" << char(218) << "-------------------------------" << char(191);
	//cout << "\n\t" << char(179) << "\tCONTACT NUMBER ADDED!\t" << char(179);
	//cout << "\n\t" << char(192) << "-------------------------------" << char(217);


		cout << "\n\t" << char(218) << "-------------------------------" << char(191);
		cout << "\n\t" << char(179) << "\tCONTACT NUMBERS ADDED!\t" << char(179);
		cout << "\n\t" << char(192) << "-------------------------------" << char(217);



} 
#pragma endregion Add contacts to the phonebook

//option 3
#pragma region comment
void printPhoneList(){

	if (TT.IsEmpty())
	{
		cout << "\n\t"<<char(218)<<"-------------------------------"<<char(191); 
		cout << "\n\t"<<char(179)<<"\tPHONE BOOK IS EMPTY!\t"<<char(179);
		cout << "\n\t"<< char(192) << "-------------------------------" << char(217);
	}
		
	else{
		TT.PrintTree();
	}
		
}
#pragma endregion Print Phonebook

#pragma region
//option 4
void deletItem(){

	bool found = false;
	PDetails S2;

	//if phone book is empty, print this
	if (TT.IsEmpty())
	{
		cout << "\n\t" << char(218) << "-------------------------------" << char(191);
		cout << "\n\t" << char(179) << "\tPHONE BOOK IS EMPTY!\t" << char(179);
		cout << "\n\t" << char(192) << "-------------------------------" << char(217);
	}

	else
	{//else, enter the surname and confirm with a message
		cout << "\n\n\t\tPlease Enter a Surname: ";
		cin >> S2.LastNam;
		TT.DeleteItem(S2);
		cout << "\n\t" << char(218) << "-------------------------------" << char(191);
		cout << "\n\t" << char(179) << "\tITEM DELETED!\t\t" << char(179);
		cout << "\n\t" << char(192) << "-------------------------------" << char(217);

	}
	
}
#pragma endregion Delete Item

//option 5
#pragma region
void searchItemLetter(){

	bool found = false;
	string S2;

	//if phone book is empty, print this
	if (TT.IsEmpty())
	{
		cout << "\n\t" << char(218) << "-------------------------------" << char(191);
		cout << "\n\t" << char(179) << "\tPHONE BOOK IS EMPTY!\t" << char(179);
		cout << "\n\t" << char(192) << "-------------------------------" << char(217);
	}

	else
	{//else, ask the user to enter a the firs letter of the surname
		cout << "\n\n\tPlease Enter The First Letter of The Surname: ";
		cin >> S2;
		string info = S2.substr(0, 1);
		TT.RetrieveItem(info, found);
	}
	
}
#pragma endregion Search Item By Letter

//option 6 
#pragma region 
//option 6
void searchItem(){

	bool found = false;
	string S2;

	//if phone book is empty, print this
	if (TT.IsEmpty())
	{
		cout << "\n\t" << char(218) << "-------------------------------" << char(191);
		cout << "\n\t" << char(179) << "\tPHONE BOOK IS EMPTY!\t" << char(179);
		cout << "\n\t" << char(192) << "-------------------------------" << char(217);
	}
	//else, ask the user to enter the surname
	else
	{
		cout << "\n\n\tPlease Enter Surname: ";
		cin >> S2;
		TT.RetrieveItemByFullS(S2, found);
	}

}

#pragma endregion search Item By Surname

//option 7 

#pragma region
void exit(){
//function to exit
	Quitflag = true;
}
#pragma endregion Exite
