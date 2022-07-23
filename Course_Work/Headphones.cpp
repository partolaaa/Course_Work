#include "Headphones.h"

Headphones::Headphones()
{


	cout << "Sound quality: ";
	cin >> soundQuality;
	cout << endl;

	cout << "Price: ";
	cin >> price;
	cout << endl;
}
Headphones::Headphones(string connectionType, string soundQuality, double price) : OutputDevice(connectionType)
{
	this->soundQuality = soundQuality;
	this->price = price;
}

void Headphones::showInfoAboutDevice()
{
	cout << "Connection type: " << OutputDevice::getConnectionType() << endl;
	cout << "Sound quality: " << soundQuality << endl;
	cout << "Price: " << price << endl;
}

double Headphones::getPrice()
{
	return price;
}

string Headphones::getDataToFile()
{
	return OutputDevice::getConnectionType() + "," + soundQuality + "," + to_string(price) + ",";
}
