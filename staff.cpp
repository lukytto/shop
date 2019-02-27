#include "pch.h"
#include "Staff.h"

extern Container lib;
extern Log rec;
extern string account;

void Staff::AddItem() { // Add new items
	system("cls");
	Item newitem;
	string money, number, category, price, name, id, manufacturer, discount, disc_num, information;
	cout << "Please input the ID number of the item" << endl;
	cin >> id; // Input ID number of this new item
	for (size_t i = 0; i < lib.ItemArray.size(); i++)
		if (lib.ItemArray[i].GetID() == id) {
			cout << "This ID number already exist =. =" << endl; // ID number already exist
			Sleep(1000);
			return;
		}
	cout << "Please input the name of the item" << endl;
	cin >> name; // Input itemname
	cout << "Please input the manufacturer of the item" << endl;
	cin >> manufacturer; // Input manufacturer
	cout << "Please input the unit number of the item" << endl;
	while (1) {
		cin >> number; // Input unit number
		if (IsAllDigit(number)) break;
		cout << "Pleass input a digital number :)   Try again." << endl;
	}
	cout << "Please input the category of the item" << endl;
	while (1) {
		cin >> category; // Input category number
		if (IsAllDigit(category)) break;
		cout << "Pleass input a digital number :)   Try again." << endl;
	}
	cout << "Please input the price of the item" << endl;
	while (1) {
		cin >> price; // Input price
		if (IsAllDigit(price)) break;
		cout << "Pleass input a digital number :)   Try again." << endl;
	}
	cout << "Please input the discount of the item" << endl;
	while (1) {
		cin >> discount; // Input discount
		if (IsAllDigit(discount)) break;
		cout << "Pleass input a digital number :)   Try again." << endl;
	}
	cout << "Please input the number of the items to be discounted " << endl;
	while (1) {
		cin >> disc_num; // Input disc_num
		if (IsAllDigit(disc_num)) break;
		cout << "Pleass input a digital number :)   Try again." << endl;
	}
	cout << "Please input some information about this item" << endl;
	cin >> information; // Input detail information
	cout << "Please input the money that this item costs" << endl;
	while (1) {
		cin >> money; // Input the cost of the item
		if (IsAllDigit(money)) break;
		cout << "Pleass input a digital number :)   Try again." << endl;
	}
	newitem.SetName(name);
	newitem.SetID(id);
	newitem.SetManufacturer(manufacturer);
	newitem.SetNumber(stoi(number));
	newitem.SetCategory(stoi(category));
	newitem.SetPrice(stod(price));
	newitem.SetDiscount(stod(discount));
	newitem.SetDisc_num(stoi(disc_num));
	newitem.SetInformation(information);
	lib.ItemArray.push_back(newitem); // Add this newitem to lib.ItemArray
	cout << "Add item succsessfully!~ " << endl;
	Sleep(1000);
	cout << "Automatic quit after 3 seconds." << endl;
	Sleep(2000);
	rec.ItemLog(account, id, "add", stoi(number)); // Update ItemLog.txt with "add" operation
	rec.CashLog(account, id, "add", stod(money)); // Update CashLog.txt with "add" operation
	PrintItemArray(); // Output item information to Item.txt
	PrintCash(); // Output cash information to Cash.txt
}

void Staff::DelItem() { // Delete item
	system("cls");
	string id, temp;
	cout << "Please input the ID number of the item that you want to delete " << endl;
	cin >> id; // Input ID number of the item that you want to delete
	for (size_t i = 0; i < lib.ItemArray.size(); i++)
		if (lib.ItemArray[i].GetID() == id) {
			cout << "There are " << lib.ItemArray[i].GetNumber() << " units of this item, how many do you want to delete?  " << endl;
			while (1) {
				cin >> temp; // Input how many items you want to delete
				if (IsAllDigit(temp)) break;
				cout << "Pleass input a digital number :)   Try again." << endl;
			}
			if (stoi(temp) > lib.ItemArray[i].GetNumber()) { // Item number is not enough to delete
				cout << "Item number is too big! " << endl;
				Sleep(1000);
				cout << "Automatic quit after 3 seconds." << endl;
				Sleep(3000);
			}
			else {
				lib.ItemArray[i].SetNumber(lib.ItemArray[i].GetNumber() - stoi(temp)); // Change number of this item in lib.ItemArray
				cout << "Delete (" << stoi(temp) << ") of this item succsessfully!~ " << endl;
				Sleep(1000);
				cout << "Automatic quit after 3 seconds." << endl;
				Sleep(2000);
				rec.ItemLog(account, id, "del", stoi(temp)); // Update ItemLog.txt with "del" operation
				PrintItemArray(); // Output item information to Item.txt
			}
			return;
		}
	cout << "Not found this item! " << endl; // Item not exist in Item.txt
	Sleep(1000);
}

void Staff::SetItem() { // Change items' information
	system("cls");
	int choice;
	string number, category, price, name, id, manufacturer, discount, disc_num, information;
	cout << "Please input the ID number of the item that you want to change the information." << endl;
	cin >> id; // Input ID number of the item that you want to change information
	for (size_t i = 0; i < lib.ItemArray.size(); i++)
		if (lib.ItemArray[i].GetID() == id) {
			cout << "Do you want to change the name of the item? (input 1 for YES and 0 for NO )" << endl;
			cin >> choice;
			if (choice == 1) {
				cout << "Please input the new name of the item" << endl;
				cin >> name; // Input new itemname
				lib.ItemArray[i].SetName(name);
			}
			cout << "Do you want to change the ID number of the item? (input 1 for YES and 0 for NO )" << endl;
			cin >> choice;
			if (choice == 1) {
				cout << "Please input the new ID number of the item" << endl;
				cin >> id; // Input new ID number
				lib.ItemArray[i].SetID(id);
			}
			cout << "Do you want to change the manufacturer of the item? (input 1 for YES and 0 for NO )" << endl;
			cin >> choice;
			if (choice == 1) {
				cout << "Please input the new manufacturer of the item" << endl;
				cin >> manufacturer; // Input new manufacturer
				lib.ItemArray[i].SetManufacturer(manufacturer);
			}
		
			cout << "Do you want to change the category of the item? (input 1 for YES and 0 for NO )" << endl;
			cin >> choice;
			if (choice == 1) {
				cout << "Please input the new category of the item" << endl;
				while (1) {
					cin >> category; // Input new category number
					if (IsAllDigit(category)) break;
					cout << "Pleass input a digital number :)   Try again." << endl;
				}
				lib.ItemArray[i].SetCategory(stoi(category));
			}
			cout << "Do you want to change the price of the item? (input 1 for YES and 0 for NO )" << endl;
			cin >> choice;
			if (choice == 1) {
				cout << "Please input the new price of the item" << endl;
				while (1) {
					cin >> price; // Input new price
					if (IsAllDigit(price)) break;
					cout << "Pleass input a digital number :)   Try again." << endl;
				}
				lib.ItemArray[i].SetPrice(stod(price));
			}
			cout << "Do you want to change the discount of the item? (input 1 for YES and 0 for NO )" << endl;
			cin >> choice;
			if (choice == 1) {
				cout << "Please input the new discount of the item" << endl;
				while (1) {
					cin >> discount; // Input new discount
					if (IsAllDigit(discount)) break;
					cout << "Pleass input a digital number :)   Try again." << endl;
				}
				lib.ItemArray[i].SetDiscount(stod(discount));
			}
			cout << "Do you want to change the disc_num of the item? (input 1 for YES and 0 for NO )" << endl;
			cin >> choice;
			if (choice == 1) {
				cout << "Please input the new disc_num of the item" << endl;
				while (1) {
					cin >> disc_num; // Input new disc_num
					if (IsAllDigit(disc_num)) break;
					cout << "Pleass input a digital number :)   Try again." << endl;
				}
				lib.ItemArray[i].SetDisc_num(stoi(disc_num));
			}
			cout << "Do you want to change the information of the item? (input 1 for YES and 0 for NO )" << endl;
			cin >> choice;
			if (choice == 1) {
				cout << "Please input the new information of the item" << endl;
				cin >> information; // Input new detail information
				lib.ItemArray[i].SetInformation(information);
			}
			cout << "Change item information succsessfully!~ " << endl;
			Sleep(1000);
			cout << "Automatic quit after 3 seconds." << endl;
			Sleep(2000);
			rec.ItemLog(account, id, "set", 0); // Update ItemLog.txt with "set" operation
			PrintItemArray(); // Output item information to Item.txt
			return;
		}
	cout << "Not found this item! " << endl; // Item not exist in Item.txt
	Sleep(1000);
}

void Staff::ViewProfit() { // Lookup net profit
	system("cls");
	string temp;
	cout << "Total income: " << lib.GetIncome() << endl;
	cout << "Total outcome: " << lib.GetOutcome() << endl;
	cout << "Total net profit: " << lib.GetIncome() - lib.GetOutcome() << endl;
	cout << "Input 0 to exit" << endl;
	cin >> temp;
	while (temp != "0")
		cin >> temp;
	return;
}

void Staff::Interface(string username) { // Staff interface
	char command;
	int stop = 0;
	string str;
	while (1) {
		system("cls");
		cout << "Welcome! " << username << " You are staff~" << endl;
		cout << "Please choose what you want to do by input a number " << endl;
		while (1) { // The operation list
			cout << "1 ----- Add new item" << endl;
			cout << "2 ----- Delete item" << endl;
			cout << "3 ----- Change item information" << endl;
			cout << "4 ----- List items (ALL)" << endl;
			cout << "5 ----- List items (By Category)" << endl;
			cout << "6 ----- List item (By Name)" << endl;
			cout << "7 ----- Show more item information by ID number" << endl;
			cout << "8 ----- Lookup net profit" << endl;
			cout << "9 ----- Change my password" << endl;
			cout << "0 ----- Exit;" << endl;
			cin >> command;
			if (command < '0' || command > '9') { // If command doesn't match input rule
				cout << endl << "Wrong!! You should input number between 0-9 " << endl;
				cout << "Please repick a number :) " << endl; // Ask to input again
			}
			else break;
		}
		switch (command) {
		case '1':
			AddItem(); // Add new item
			break;
		case '2':
			DelItem(); // Delete  item
			break;
		case '3':
			SetItem(); // Change items' information
			break;
		case '4':
			ListItemAll(); // List all items
			break;
		case '5':
			ListItemByC(); // List items by category
			break;
		case '6':
			ListItemByN(); // List items by name
			break;
		case '7':
			ItemInfor(); // See more information of one item
			break;
		case '8':
			ViewProfit(); // Lookup profit
			break;
		case '9':
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