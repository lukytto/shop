#ifndef STAFF_H
#define STAFF_H

#include "User.h"
#include "container.h"

class Staff : public User {
public:
	void AddItem(); // Add new items
	void DelItem(); // Delete some items
	void SetItem(); // Change items' information
	void Interface(string username); // Staff interface
protected:
	void ViewProfit(); // Lookup net profit
};

#endif