#pragma once
#include <iostream>

using namespace std;
class WLAN {
private:
	int internetConnection = 1;
	int checkInernetConnection();
public:
	//1 - �������� ����������, 2 - ������, 3 - ������

	void setInternetConnection(int internetConnection);
	string getInternetConnection();

	void operator()(int);
};