#pragma once
#include "InputDevice.h"


class Mouse : public InputDevice
{
private:
	string mouseType;//optic or michanic
	double numberOfKeys;
	double price;

public:
	void showInfoAboutDevice() override;
	double getPrice() override;
	string getDataToFile() override;

	Mouse();
	Mouse(string connectionType, string mouseType, double numberOfKeys, double price);
};