#pragma once
#include "User.h"
#include "ComputerClass.h"
#include "Container.h"
class Menu{
private:
	static Container<ComputerClass> container;
	static void showAllClasses();
public:
	static void printMenu();
};