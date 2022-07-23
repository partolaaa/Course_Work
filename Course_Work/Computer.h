#pragma once
#include <string>
#include "Keyboard.h"
#include "Headphones.h"
#include "Mouse.h"
#include "Monitor.h"
#include "SystemUnit.h"
using namespace std;


class Computer
{
private:
	SystemUnit* systemUnit;
	Monitor* monitor;
	Mouse* mouse;
	Keyboard* keyboard;
	Headphones* headphones;

	double price;

public:
	Computer();
	Computer(SystemUnit systemUnit, Monitor monitor, Headphones headphones, Keyboard keyboard, Mouse mouse);

	double getPrice();
	void printComputer();

	SystemUnit getSystemUnit();
	Monitor getMonitor();
	Mouse getMouse();
	Keyboard getKeyboard();
	Headphones getHeadphones();
};
