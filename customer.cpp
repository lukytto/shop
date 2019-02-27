#include "pch.h"
#include "Customer.h"

extern Log rec;
extern Container lib;
extern string account;

void Customer::BuyItem() { // Customer buy items
	system("cls");
	string id, temp;
	cout << "Please input the ID number of the item that you want to buy " << endl;
	cin >> id; // Input the ID number
	for (size_t i = 0; i < lib.ItemArray.size(); i++)
		if (lib.ItemArray[i].GetID() == id) { // If find that ID number
			cout << "There are " << lib.ItemArray[i].GetNumber() << " units of the items, how many do you want to buy?  " << endl;
			while (1) {
				cin >> temp; // Input how many item customer want to buy
				if (IsAllDigit(temp)) break;
				cout << "Pleass input a digital number :)   Try again." << endl;
			}
			if (stoi(temp) > lib.ItemArray[i].GetNumber()) { // If item is not enough for customer to buy
				cout << "Item number is is too big! " << endl;
				Sleep(1000);
			}
			else {
				lib.ItemArray[i].SetNumber(lib.ItemArray[i].GetNumber() - stoi(temp)); // Decrease the number of this item in lib.ItemArray
				cout << "Buy " << stoi(temp) << " copies of that item, succsessfully!~ " << endl;
				Sleep(1000);
				cout << "Automatic quit after 3 seconds." << endl;
				Sleep(2000);
				rec.ItemLog(account, id, "buy", stoi(temp)); // Update ItemLog.txt with "buy" operation
				rec.CashLog(account, id, "buy", lib.ItemArray[i].NetPrice(stoi(temp))); // Update CashLog.txt with "buy" operation
				PrintItemArray(); // Output item information to Item.txt
				PrintCash(); // Output cash information to Cash.txt
			}
			return;
		}
	cout << "Not found this item! " << endl; // Item not found in Item.txt
	Sleep(1000);
}

void Customer::Refund() { // Customer ask for refund
	system("cls");
	string id, temp;
	cout << "Please input the ID number of the item that you want to ask for refund " << endl;
	cin >> id; // Input the ID number
	for (size_t i = 0; i < lib.ItemArray.size(); i++)
		if (lib.ItemArray[i].GetID() == id) { // If find that ID number
			cout << " How many copies of that item do you want to ask for refund?  " << endl;
			while (1) {
				cin >> temp; // Input how many items customer wants to refund
				if (IsAllDigit(temp)) break;
				cout << "Pleass input a digital number :)   Try again." << endl;
			}
			lib.ItemArray[i].SetNumber(lib.ItemArray[i].GetNumber() + stoi(temp)); // Increase the number of this item in lib.ItemArray
			cout << "Refund " << stoi(temp) << " copies of that items, succsessfully!~ " << endl;
			Sleep(1000);
			cout << "Automatic quit after 3 seconds." << endl;
			Sleep(2000);
			rec.ItemLog(account, id, "ref", stoi(temp)); // Update ItemLog.txt with "buy" operation
			rec.CashLog(account, id, "ref", lib.ItemArray[i].NetPrice(stoi(temp))); // Update CashLog.txt with "buy" operation
			PrintItemArray(); // Output item information to Item.txt
			PrintCash(); // Output cash information to Cash.txt
			return;
		}
	cout << "This is not our store's item! " << endl; // Item not found in Item.txt
	Sleep(1000);
}

void Customer::Interface(string username) { // Admin interface
	char command;
	int stop = 0;
	while (1) {
		system("cls");
		cout << "Welcome! " << username << " You are a customer~" << endl;
		cout << "Please choose what you want to do by input a number " << endl;
		while (1) { // The operation list
			cout << "1 ----- Buy item" << endl;
			cout << "2 ----- Refund" << endl;
			cout << "3 ----- List item (ALL)" << endl;
			cout << "4 ----- List item (By Category)" << endl;
			cout << "5 ----- List item (By Name)" << endl;
			cout << "6 ----- Show more item information by ID number" << endl;
			cout << "7 ----- Change my password" << endl;
			cout << "0 ----- Exit;" << endl;
			cin >> command;
			if (command < '0' || command > '7') {
				cout << endl << "Wrong!! You should input number between 0-7 " << endl;
				cout << "Please repick a number :) " << endl;
			}
			else break;
		}
		switch (command) {
		case '1':
			BuyItem(); // Customer buy item
			break;
		case '2':
			Refund(); // Customer ask for refund
			break;
		case '3':
			ListItemAll(); // List all items
			break;
		case '4':
			ListItemByC(); // List items by category
			break;
		case '5':
			ListItemByN(); // List item by name
			break;
		case '6':
			ItemInfor(); // See more information of one item
			break;
		case '7':
			ChangePsw(); // Change password
			break;
		case '0':
			stop = 1;
			cout << "System will quit after 3 seconds " << endl;
			Sleep(3000);
			break;
		}
		if (stop) break;
	}
}