#pragma once
#include <iostream>
#include <string>
using namespace std;

class InputDevice {
private:
	string connectionType;
public:
	virtual void showInfoAboutDevice() = 0;
	virtual double getPrice() = 0;
	virtual string getDataToFile() = 0;
	string getConnectionType();

	InputDevice();
	InputDevice(string connectionType);
};