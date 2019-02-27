#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include "item.h"
#include "User.h"

class Container {
public:
	void LoadUser(); // Load User.txt
	void LoadItem(); // Load Item.txt
	void LoadCash(); // Load Cash.txt
	void SetIncome(double new_income) { income = new_income; }; // Change income
	void SetOutcome(double new_outcome) { outcome = new_outcome; }; // Change outcome
	double GetIncome() { return income; };
	double GetOutcome() { return outcome; };
	vector<Item> ItemArray; // Store all items in vector
	vector<User> UserArray; // Store all users in vector
private:
	double income; // Total income
	double outcome; // Total outcome
};

#endif