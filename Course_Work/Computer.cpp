#include "Computer.h"

Computer::Computer()
{
	cout << "\t***CREATING A COMPUTER***" << endl;

	cout << "---CREATING A SYSTEM UNIT---" << endl;
	Computer::systemUnit = new SystemUnit();

	cout << "---CREATING A MONITOR---" << endl;
	 Computer::monitor = new Monitor();

	cout << "---CREATING A HEADPHONES---" << endl;
	Computer::headphones = new Headphones();

	cout << "---CREATING A KEYBOARD---" << endl;
	Computer::keyboard = new Keyboard();


	cout << "---CREATING A MOUSE---" << endl;
	Computer::mouse = new Mouse();
}

Computer::Computer(SystemUnit systemUnit, Monitor monitor, Headphones headphones, Keyboard keyboard, Mouse mouse)
{
	this->systemUnit = new SystemUnit(systemUnit);
	this->monitor = new Monitor(monitor);
	this->headphones = new Headphones(headphones);
	this->keyboard = new Keyboard(keyboard);
	this->mouse = new Mouse(mouse);
}

double Computer::getPrice()
{
	price = monitor->getPrice() + headphones->getPrice() + keyboard->getPrice() + mouse->getPrice() + systemUnit->getPrice();
	return price;
}

void Computer::printComputer()
{
	cout << "\n\t---SYSTEM UNIT---" << endl;
	cout << *systemUnit;

	cout << "\n\t---MONITOR---" << endl;
	monitor->showInfoAboutDevice();

	cout << "\n\t---HEADPHONES---" << endl;
	headphones->showInfoAboutDevice();

	cout << "\n\t---KEYBOARD---" << endl;
	keyboard->showInfoAboutDevice();

	cout << "\n\t---MOUSE---" << endl;
	mouse->showInfoAboutDevice();
}

SystemUnit Computer::getSystemUnit()
{
	return *systemUnit;
}

Monitor Computer::getMonitor()
{
	return *monitor;
}

Mouse Computer::getMouse()
{
	return *mouse;
}

Keyboard Computer::getKeyboard()
{
	return *keyboard;
}

Headphones Computer::getHeadphones()
{
	return *headphones;
}
