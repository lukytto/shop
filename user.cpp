#include "pch.h"
#include "User.h"
#include "container.h"

extern Log rec;
extern Container lib;
extern string account;

void User::PrintUserArray() { // Output user information to User.txt
	ofstream fout;
	fout.open("User.txt"); // Open and cover User.txt
	if (!fout) { // If can't open
		cerr << "User.txt can't open" << endl;
		abort(); // Exit
	}
	for (size_t i = 0; i < lib.UserArray.size(); i++) // Output each user's information
		fout << lib.UserArray[i].GetUsername() << " " << lib.UserArray[i].GetPassword() << " " << lib.UserArray[i].GetStatus() << endl;
	fout.close(); // Close User.txt
}

void User::PrintItemArray() { // Output item information to item.txt
	ofstream fout;
	fout.open("Item.txt"); // Open and cover item.txt
	if (!fout) { // If can't open
		cerr << "cannnot open Item.txt" << endl;
		abort(); // Exit
	}
	for (size_t i = 0; i < lib.ItemArray.size(); i++) // Output each item's information
		fout << lib.ItemArray[i].GetName() << " " << lib.ItemArray[i].GetID() << " " << lib.ItemArray[i].GetManufacturer()
		<< " " << lib.ItemArray[i].GetNumber() << " " << lib.ItemArray[i].GetCategory()
		<< " " << lib.ItemArray[i].GetPrice() << " " << lib.ItemArray[i].GetDiscount()
		<< " " << lib.ItemArray[i].GetDisc_num() << " " << lib.ItemArray[i].GetInformation() << endl;
	fout.close(); // Close Item.txt
}

void User::PrintCash() { // Output cash information to Cash.txt
	ofstream fout;
	fout.open("Cash.txt"); // Open and cover Cash.txt
	if (!fout) { // If can't open
		cerr << " cannott openCash.txt" << endl;
		abort(); // Exit
	}
	fout << lib.GetIncome() << endl; // Output income
	fout << lib.GetOutcome() << endl; // Output outcome
	fout.close(); // Close Item.txt
}

int User::IsAllDigit(const string& str) { // Check if str is all made of digital number
	int i;
	for (i = 0; i != str.length(); i++)
		if (!isdigit(str[i]) && (str[i] != '.')) return 0; // '.' for double number
	return 1;
}

void User::ListItemAll() { // List all items
	system("cls");
	string temp;
	cout << "This is the list of all the products:" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "|       ID         |             Name            | Number |    Price    |" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	for (size_t i = 0; i < lib.ItemArray.size(); i++) { // Output each item information
		cout << "|" << setw(18) << lib.ItemArray[i].GetID() << "|" << setw(29) << lib.ItemArray[i].GetName() << "|"
			<< setw(8) << lib.ItemArray[i].GetNumber() << "|" << setw(13) << setiosflags(ios::fixed) << setprecision(2) << lib.ItemArray[i].GetPrice() << "|" << endl;
	}
	cout << "-------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "Input 0 to exit" << endl;
	cin >> temp;
	while (temp != "0")
		cin >> temp;
}

void User::ListItemByC() { // List items by category
	system("cls");
	string temp, category;
	cout << "Please input the category that you want to list: " << endl;
	while (1) {
		cin >> category;
		if (IsAllDigit(category)) break;
		cout << "Pleass input a digital number :)   Try again." << endl;
	}
	system("cls");
	cout << "This is the list of all the items in category " << category << " :" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "|       ID         |             Name            | Number |    Price    |" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	for (size_t i = 0; i < lib.ItemArray.size(); i++) // Output each item information in this category
		if (lib.ItemArray[i].GetCategory() == stoi(category)) {
			cout << "|" << setw(18) << lib.ItemArray[i].GetID() << "|" << setw(29) << lib.ItemArray[i].GetName() << "|"
				<< setw(8) << lib.ItemArray[i].GetNumber() << "|" << setw(13) << setiosflags(ios::fixed) << setprecision(2) << lib.ItemArray[i].GetPrice() << "|" << endl;
		}
	cout << "-------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "Input 0 to exit" << endl;
	cin >> temp;
	while (temp != "0")
		cin >> temp;
}

void User::ListItemByN() { // List item by name
	system("cls");
	string temp, name;
	cout << "Please input the name that you want to find: " << endl;
	cin >> name;
	system("cls");
	cout << "This is the list of all the items that name contains string \"" << name << " \" :" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "|       ID         |             Name            | Number |    Price    |" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	for (size_t i = 0; i < lib.ItemArray.size(); i++) // Output each items information match this name
		if (lib.ItemArray[i].GetName().find(name) != string::npos) {
			cout << "|" << setw(18) << lib.ItemArray[i].GetID() << "|" << setw(29) << lib.ItemArray[i].GetName() << "|"
				<< setw(8) << lib.ItemArray[i].GetNumber() << "|" << setw(13) << setiosflags(ios::fixed) << setprecision(2) << lib.ItemArray[i].GetPrice() << "|" << endl;
		}
	cout << "-------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "Input 0 to exit" << endl;
	cin >> temp;
	while (temp != "0")
		cin >> temp;
}

void User::ItemInfor() { // See more information of one item
	system("cls");
	string temp, id;
	cout << "Please input the ID number of the item that you want to find: " << endl;
	cin >> id;
	for (size_t i = 0; i < lib.ItemArray.size(); i++)
		if (lib.ItemArray[i].GetID() == id) { // If exist, list its detail information
			system("cls");
			cout << "Detail information of the item with ID number " << id << " : " << endl;
			cout << "Name            : " << lib.ItemArray[i].GetName() << endl;
			cout << "Manufacturer    : " << lib.ItemArray[i].GetManufacturer() << endl;
			cout << "Number          : " << lib.ItemArray[i].GetNumber() << endl;
			cout << "Category        : " << lib.ItemArray[i].GetCategory() << endl;
			cout << "Price           : " << setiosflags(ios::fixed) << setprecision(2) << lib.ItemArray[i].GetPrice() << endl;
			cout << "Discount        : " << setiosflags(ios::fixed) << setprecision(2) << lib.ItemArray[i].GetDiscount() << endl;
			cout << "Disc_num        : " << lib.ItemArray[i].GetDisc_num() << endl;
			cout << "Information        : " << lib.ItemArray[i].GetInformation() << endl;
			cout << endl;
			cout << "Input 0 to exit" << endl;
			cin >> temp;
			while (temp != "0")
				cin >> temp;
			return;
		}
	cout << "Not found this item! " << endl;
	Sleep(1000);
}

void User::ChangePsw() { // User choose to change his or her password
	system("cls");
	string temp, password;
	cout << "Please input the new password that you want: " << endl;
	cin >> password;
	cout << "Please repeat it: " << endl;
	cin >> temp;
	if (temp != password) { // If two input are not match then exit
		cout << "Two password doesn't match!! Change password failed... " << endl;
		Sleep(1500);
		return;
	}
	else {
		for (size_t i = 0; i < lib.ItemArray.size(); i++)
			if (lib.UserArray[i].GetUsername() == account)
				lib.UserArray[i].SetPassword(password); // Change password
		cout << "Password change successfully !~~ " << endl;
		rec.UserLog(account, account, "psw", 0); // Update UserLog.txt with "psw" operation
		PrintUserArray(); // Output user information to User.txt
		Sleep(2000);
	}
}