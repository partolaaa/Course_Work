#pragma once
#include <iostream>
#include <string>
using namespace std;

class OutputDevice {
private:
	string connectionType;
public:
	virtual void showInfoAboutDevice() = 0;
	virtual double getPrice() = 0;
	virtual string getDataToFile() = 0;
	string getConnectionType();

	OutputDevice();
	OutputDevice(string connectionType);
};