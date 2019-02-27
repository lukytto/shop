#ifndef LOG_H
#define LOG_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Log {
public:
	void UserLog(string loginname, string username, string operation, int status); // Add new information to UserLog.txt
	void ItemLog(string loginname, string itemid, string operation, int number); // Add new information to ItemLog.txt
	void CashLog(string loginname, string itemid, string operation, double money); // Add new information to CashLog.txt
};

#endif