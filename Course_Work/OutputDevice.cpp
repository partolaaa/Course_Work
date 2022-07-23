#include "OutputDevice.h"

string OutputDevice::getConnectionType()
{
	return connectionType;
}

OutputDevice::OutputDevice()
{
	cout << "Connection type: ";
	cin >> connectionType;
	cout << endl;
}


OutputDevice::OutputDevice(string connectionType)
{
	this->connectionType = connectionType;
}
void OutputDevice::showInfoAboutDevice()
{
	cout << typeid(*this).name() << endl;
	cout << connectionType << endl;
}