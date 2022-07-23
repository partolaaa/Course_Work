#include "Mouse.h"

double Mouse::getPrice()
{
	return price;
}

string Mouse::getDataToFile()
{
	return InputDevice::getConnectionType() + "," + mouseType + "," + to_string(numberOfKeys) + "," + to_string(price);
}

Mouse::Mouse()
{
	cout << "Mouse type: ";
	cin >> mouseType;
	cout << endl;

	cout << "Number of keys: ";
	cin >> numberOfKeys;
	cout << endl;

	cout << "Price: ";
	cin >> price;
	cout << endl;
}

Mouse::Mouse(string connectionType, string mouseType, double numberOfKeys, double price) : InputDevice(connectionType)
{
	this->mouseType = mouseType;
	this->numberOfKeys = numberOfKeys;
	this->price = price;
}

void Mouse::showInfoAboutDevice()
{
	cout << "Connection type: " << InputDevice::getConnectionType() << endl;
	cout << "Keyboard type: " << mouseType << endl;
	cout << "Number of keys: " << numberOfKeys << endl;
	cout << "Price: " << price << endl;
}