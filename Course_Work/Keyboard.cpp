#include "Keyboard.h"

double Keyboard::getPrice()
{
	return price;
}

string Keyboard::getDataToFile()
{
	return InputDevice::getConnectionType() + "," + keyboardType + "," + to_string(numberOfKeys) + "," + to_string(price) + ",";
}

Keyboard::Keyboard()
{
	cout << "Keyboard type: ";
	cin >> keyboardType;
	cout << endl;

	cout << "Number of keys: ";
	cin >> numberOfKeys;
	cout << endl;

	cout << "Price: ";
	cin >> price;
	cout << endl;
}

Keyboard::Keyboard(string connectionType, string keyboardType, double numberOfKeys, double price) : InputDevice(connectionType)
{
	this->keyboardType = keyboardType;
	this->numberOfKeys = numberOfKeys;
	this->price = price;
}
void Keyboard::showInfoAboutDevice()
{
	cout << "Connection type: " << InputDevice::getConnectionType() << endl;
	cout << "Keyboard type: " << keyboardType << endl;
	cout << "Number of keys: " << numberOfKeys << endl;
	cout << "Price: " << price << endl;
}