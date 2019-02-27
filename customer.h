#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "container.h"

class Customer : public User {
public:
	void BuyItem(); // Customer buy items
	void Refund(); // Customer ask for refund
	void Interface(string username); // Customer interface
};

#endif