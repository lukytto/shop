#include "pch.h"
#include "container.h"

void Container::LoadUser() { // Load User.txt
	User olduser;
	string str;
	ifstream fin("User.txt"); // Open and read User.txt
	if (!fin) { // If can't open
		cerr << "User.txt can't open" << endl;
		abort(); // Exit
	}
	while (getline(fin, str)) {
		size_t i = str.find(" "); // Find fisrt spacebar
		olduser.SetUsername(str.substr(0, i)); // Divide str by spacebar and get username
		str = str.substr(i + 1);

		i = str.find(" "); // Find second spacebar
		olduser.SetPassword(str.substr(0, i)); // Divide str by spacebar and get password
		olduser.SetStatus(stoi(str.substr(i + 1))); // Divide str by spacebar and get status

		UserArray.push_back(olduser); // Add to lib.UserArray
	}
	fin.close(); // Close User.txt
}

void Container::LoadItem() { // Load Item.txt
	Item olditem;
	string str;
	ifstream fin("Item.txt"); // Open and read Item.txt
	if (!fin) { // If can't open
		cerr << "Item.txt can't open" << endl;
		abort(); // Exit
	}
	while (getline(fin, str)) {
		size_t i = str.find(" "); // Find fisrt spacebar
		olditem.SetName(str.substr(0, i)); // Divide str by spacebar and get item name
		str = str.substr(i + 1);

		i = str.find(" "); // Find second spacebar
		olditem.SetID(str.substr(0, i)); // Divide str by spacebar and get ID number
		str = str.substr(i + 1);

		i = str.find(" ");
		olditem.SetManufacturer(str.substr(0, i)); // Divide str by spacebar and get manufacturer
		str = str.substr(i + 1);

		i = str.find(" ");
		olditem.SetNumber(stoi(str.substr(0, i))); // Divide str by spacebar and get unit number
		str = str.substr(i + 1);

		i = str.find(" ");
		olditem.SetCategory(stoi(str.substr(0, i))); // Divide str by spacebar and get category number
		str = str.substr(i + 1);

		i = str.find(" ");
		olditem.SetPrice(stoi(str.substr(0, i))); // Divide str by spacebar and get price
		str = str.substr(i + 1);

		i = str.find(" ");
		olditem.SetDiscount(stod(str.substr(0, i))); // Divide str by spacebar and get discount
		str = str.substr(i + 1);

		i = str.find(" ");
		olditem.SetDisc_num(stoi(str.substr(0, i))); // Divide str by spacebar and get disc_num
		olditem.SetInformation(str.substr(i + 1)); // Divide str by spacebar and get more item information

		ItemArray.push_back(olditem); // Add to lib.ItemArray
	}
	fin.close(); // Close Item.txt
}

void Container::LoadCash() { // Load Cash.txt
	ifstream fin("Cash.txt"); // Open and read Item.txt
	if (!fin) { // If can't open
		cerr << "Cash.txt can't open" << endl;
		abort(); // Exit
	}
	fin >> income; // Input income
	fin >> outcome; // Input outcome
	fin.close(); // Close Cash.txt
}