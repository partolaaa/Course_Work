#include "SystemUnit.h"

double SystemUnit::getPrice()
{
	return price;
}

string SystemUnit::getDataToFile()
{
	return (proccesorType + "," + to_string(GHz) + "," + to_string(hardDriveVolume) + "," + to_string(cdDrive) + "," + to_string(price) + ",");
}

SystemUnit::SystemUnit()
{
	cout << "Proccesor type: ";
	cin >> proccesorType;
	cout << endl;

	cout << "GHz: ";
	cin >> GHz;
	cout << endl;

	cout << "Hard drive volume: ";
	cin >> hardDriveVolume;
	cout << endl;

	cout << "CD drive? (1 - yes, 0 - no): ";
	cin >> cdDrive;
	cout << endl;

	cout << "Price: ";
	cin >> price;
	cout << endl;

}

SystemUnit::SystemUnit(string proccesorType, double GHz, double hardDriveVolume, bool cdDrive, double price)
{
	this->proccesorType = proccesorType;
	this->GHz = GHz;
	this->hardDriveVolume = hardDriveVolume;
	this->cdDrive = cdDrive;
	this->price = price;
}

ostream& operator<<(ostream& out, const SystemUnit& systemUnit)
{
	out << "Proccesor type: " << systemUnit.proccesorType << endl;
	out << "GHz: " << systemUnit.GHz << endl;
	out << "Hard drive volume: " << systemUnit.hardDriveVolume<< endl;
	out << "CD drive: ";
	if (systemUnit.cdDrive) cout << "available" << endl;
	else cout << "not available" << endl;
	out << "Price: " << systemUnit.price << endl;

	return out;
}

istream& operator>>(istream& in, SystemUnit& systemUnit)
{
	cout << "Proccesor type: ";
	in >> systemUnit.proccesorType;
	cout << endl;

	cout << "GHz: ";
	in >> systemUnit.GHz;
	cout << endl;

	cout << "Hard drive volume: ";
	in >> systemUnit.hardDriveVolume;
	cout << endl;

	cout << "CD drive? (1 - yes, 0 - no): ";
	in >> systemUnit.cdDrive;
	cout << endl;

	cout << "Price: ";
	in >> systemUnit.price;
	cout << endl;

	return in;
}
