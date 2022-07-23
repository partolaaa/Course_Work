#pragma once
#include <iostream>

using namespace std;
class WLAN {
private:
	int internetConnection = 1;
	int checkInernetConnection();
public:
	//1 - отличное соединение, 2 - плохое, 3 - худшее

	void setInternetConnection(int internetConnection);
	string getInternetConnection();

	void operator()(int);
};