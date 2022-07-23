#pragma once
#include "InputDevice.h"

class Keyboard : public InputDevice
{
private:
	string keyboardType;
	double numberOfKeys;
	double price;

public:
	void showInfoAboutDevice() override;
	double getPrice() override;
	string getDataToFile() override;

	Keyboard();
	Keyboard(string connectionType, string keyboardType, double numberOfKeys, double price);
};
