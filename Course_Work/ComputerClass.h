#pragma once
#include "User.h"
#include "WLAN.h"
#include <windows.h>
class ComputerClass{
private:
	vector<User> computerClass;
	WLAN wlanConnection;
	string className = "This class has no name.";
	string path;
	double totalPrice = 0;
public:
	vector<User> fillComputerClassFromFile();
	vector<User> getComputerClass();
	string getClassName();
	string getPath();

	string getWLANConnection();
	void printComputerClassUsers();
	void printInfoAboutClass();
	void setClassName(string className);

	void addUserToClass(User user);

	void deleteUsersFromClass();
	void deleteClass();

	ComputerClass();
	ComputerClass(string className, string path);
	ComputerClass(string className, vector<User> computerClass, WLAN wlanConnection);
};