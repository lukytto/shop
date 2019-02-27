#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
public:
	// Get different information of Item
	string GetName() { return name; }
	string GetID() { return id; }
	string GetManufacturer() { return manufacturer; }
	int GetNumber() { return number; }
	int GetCategory() { return category; }
	double GetPrice() { return price; }
	double GetDiscount() { return discount; }
	int GetDisc_num() { return disc_num; }
	string GetInformation() { return information; }

	// Change different information of Item
	void SetName(string new_name) { name = new_name; }
	void SetID(string new_id) { id = new_id; }
	void SetManufacturer(string new_manufacturer) { manufacturer = new_manufacturer; }
	void SetNumber(int new_number) { number = new_number; }
	void SetCategory(int new_category) { category = new_category; }
	void SetPrice(double new_price) { price = new_price; }
	void SetDiscount(double new_discount) { discount = new_discount; }
	void SetDisc_num(int new_disc_num) { disc_num = new_disc_num; }
	void SetInformation(string new_imfor) { information = new_imfor; }

	// Calculate the money of buy (num) items
	double NetPrice(int num) {
		if (num > number)
			return ((double)num * price * discount);
		else
			return ((double)num * price);
	}
private:
	string name;
	string id; // ID number
	string manufacturer;
	int number; // The copy number of item
	int category; // The category number
	double price; // Unit-price of items
	double discount; // The discount that give to customer if him buy a lot of items
	int disc_num; // The at least number of items that customer can enjoy discount
	string information; // More commentary of that item
};

#endif