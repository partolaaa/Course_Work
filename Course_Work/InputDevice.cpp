#include "InputDevice.h"

InputDevice::InputDevice()
{
	cout << "Connection type: ";
	cin >> connectionType;
	cout << endl;
}
InputDevice::InputDevice(string connectionType)
{
	this->connectionType = connectionType;
}

void InputDevice::showInfoAboutDevice()
{
	cout << typeid(*this).name() << endl;
	cout << connectionType << endl;
}

string InputDevice::getConnectionType() {
	return connectionType;
}

