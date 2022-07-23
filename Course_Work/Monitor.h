#pragma once
#include "OutputDevice.h"


class Monitor : public OutputDevice
{
private:
	double diagonal;
	double screenResolution;
	double price;

public:
	void showInfoAboutDevice() override;
	double getPrice() override;
	string getDataToFile() override;

	Monitor();
	Monitor(double diagonal, double screenResolution, double price);
};
