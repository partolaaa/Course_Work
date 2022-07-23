#include "Monitor.h"

Monitor::Monitor() : OutputDevice("wired")
{
	cout << "Diagonal: ";
	cin >> diagonal;
	cout << endl;

	cout << "Screen resolution: ";
	cin >> screenResolution;
	cout << endl;

	cout << "Price: ";
	cin >> price;
	cout << endl;
}

Monitor::Monitor(double diagonal, double screenResolution, double price) : OutputDevice("wired")
{
	this->diagonal = diagonal;
	this->screenResolution = screenResolution;
	this->price = price;
}
void Monitor::showInfoAboutDevice()
{
	cout << "Connection type: " << OutputDevice::getConnectionType() << endl;
	cout << "Diagonal: " << diagonal<< endl;
	cout << "Screen resolution: " << screenResolution << endl;
	cout << "Price: " << price << endl;
}

double Monitor::getPrice()
{
	return price;
}

string Monitor::getDataToFile()
{
	return to_string(diagonal) + "," + to_string(screenResolution) + "," + to_string(price) + ",";
}
