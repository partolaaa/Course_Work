#pragma once
#include <string>
#include "Keyboard.h"
#include "Mouse.h"
#include "Monitor.h"
#include "Headphones.h"
using namespace std;


class SystemUnit
{
private:
	string proccesorType;
	double GHz;
	double hardDriveVolume;
	bool cdDrive;
	double price;

public:
	friend ostream& operator << (ostream& out, const SystemUnit& systemUnit);
	friend istream& operator >>(istream& in, SystemUnit& systemUnit);
	double getPrice();
	string getDataToFile();

	SystemUnit();
	SystemUnit(string proccesorType,double GHz,double hardDriveVolume, bool cdDrive, double price);
};
