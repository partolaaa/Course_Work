#pragma once
#include "OutputDevice.h"

class Headphones : public OutputDevice
{
private:
	string soundQuality;
	double price;

public:
	void showInfoAboutDevice() override;
	double getPrice() override;
	string getDataToFile() override;

	Headphones();
	Headphones(string connectionType, string soundQuality, double price);
};