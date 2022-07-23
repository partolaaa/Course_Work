#include "Menu.h"
#include <windows.h>
#include <conio.h>
#define ESC 27
Container<ComputerClass> Menu::container;
void Menu::printMenu()
{
	while (true)
	{	
		system("cls");
		string agree;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);
		cout << "Please, to avoid mistakes, use only the ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6);
		cout << "English alphabet";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);

		cout << ", when specifying a path to a file, \nuse";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6);
		cout << " \\\\ ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);
		cout << "instead of";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6);
		cout << " \\ ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);
		cout << ", use ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6);
		cout << " - or _ ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);
		cout << "in file name instead of ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6);
		cout << "spaces";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);
		cout << ", please." << endl;
		cout << "\nEnter \"";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6);
		cout << "YES"; 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);
		cout<< "\" after reading this carefully: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6);
		cin >> agree;
		if (agree != "YES") continue;
		else break;
	}

	int selector = 0;
	char key;
	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x1);
		cout << "\t\t  _____                             _               _____ _\n"
			"\t\t / ____|                           | |             / ____| |       \n"
			"\t\t | |     ___  _ __ ___  _ __  _   _| |_ ___ _ __  | |    | | __ _ ___ ___\n"
		    "\t\t | |    / _ \\| '_ ` _ \\| '_ \\| | | | __/ _ \\ '__| | |    | |/ _` / __/ __|\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6);
			cout<<"\t\t | |___| (_) | | | | | | |_) | |_| | ||  __/ |    | |____| | (_| \\__ \\__ \\ \n"
			"\t\t \\_____|\\___/|_| |_| |_| .__ /\\__,_|\\__\\___|_|     \\_____|_|\\__,_|___/___/\n" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
		cout << "\t\t\t=============================================================" << endl;
		cout << "\t\t\t|                1. Create computer class manually          |" << endl;
		cout << "\t\t\t|-----------------------------------------------------------|" << endl;
		cout << "\t\t\t|                2. Get computer class from file            |" << endl;
		cout << "\t\t\t|-----------------------------------------------------------|" << endl;
		cout << "\t\t\t|                3. Add users to class manually             |" << endl;
		cout << "\t\t\t|-----------------------------------------------------------|" << endl;
		cout << "\t\t\t|                4. Show all users of class                 |" << endl;
		cout << "\t\t\t|-----------------------------------------------------------|" << endl;
		cout << "\t\t\t|                5. Show user's computer                    |" << endl;
		cout << "\t\t\t|-----------------------------------------------------------|" << endl;
		cout << "\t\t\t|                6. Show brief info about class             |" << endl;
		cout << "\t\t\t|-----------------------------------------------------------|" << endl;
		cout << "\t\t\t|                7. Show WLAN connection of class           |" << endl;
		cout << "\t\t\t|-----------------------------------------------------------|" << endl;
		cout << "\t\t\t|                8. Delete users from class                 |" << endl;
		cout << "\t\t\t|-----------------------------------------------------------|" << endl;
		cout << "\t\t\t|                9. Delete class                            |" << endl;
		cout << "\t\t\t|--------------------------------------*********************|" << endl;
		cout << "\t\t\t|  By Ivan Partola.                    -> Press ESC to exit |" << endl;
		cout << "\t\t\t=============================================================" << endl;

		cout << "\n                         Enter a number from menu: ";
		key = _getch();
		switch (key)
		{
		case '1': {
			system("cls");
			int quantityOfUsers = 0;
			string path, className;

			cout << "\t\t\tEnter class name: ";
			cin.ignore();
			getline(cin, className);
			path += className + ".txt";

			ComputerClass computerClass(className,path);
			container.add(computerClass);

			cout << "\t\t\tHow many users will be in your new class?: ";
			cin >> quantityOfUsers;

			for (int i = 0; i < quantityOfUsers; i++)
			{
				system("cls");
				cout << "User #" << i + 1 << ": " << endl;
				User user;
				container[container.size() - 1].addUserToClass(user);
			}
			system("cls");
			cout << "\t\t\tYou successfully added " << quantityOfUsers << " user(s) to " << className << endl;
			system("pause");
		}break;

		case '2': {
			system("cls");
			string path, className;
			cout << "Enter the path to the file with your class (\"file-name.txt\"): ";
			cin >> path;

			cout << "Enter class name: ";
			cin.ignore();
			getline(cin, className);

			ComputerClass computerClass(className, path);
			try
			{
				computerClass.fillComputerClassFromFile();
			}
			catch (...) { continue; }

			container.add(computerClass);
		}break;

		case '3': {
			system("cls");
			if (container.size() == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);
				cout << "\t\t\tYou have no classes. You need to create some manually or get from file." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
				system("pause");
				break;
			}
			int quantityOfUsers;
			cout << "\t\t\tHow many users you want to add to class manually?: ";
			cin >> quantityOfUsers;
			cout << endl;

			showAllClasses();
			cout << endl;
			cout << "\t\t\tWhat class do you want to add users to? (Write a number): ";
			cin >> selector;

			for (int i = 0; i < quantityOfUsers; i++)
			{
				system("cls");
				cout << "User #" << i + 1 << ": " << endl;
				User user;
				container[selector - 1].addUserToClass(user);
			}
			system("cls");
			cout << "\t\t\tYou successfully added " << quantityOfUsers << " user(s) to " << container[selector - 1].getClassName() << endl;
			system("pause");
		}break;

		case '4': {
			system("cls");
			if (container.size() == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);
				cout << "\t\t\tYou have no classes. You need to create some manually or get from file." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
				system("pause");
				break;
			}
			showAllClasses();
			cout << "\n                         Enter a class number for which to show all users: ";
			cin >> selector;

			container[selector - 1].printComputerClassUsers();
			system("pause");
		}break;
		case '5': {
			system("cls");
			if (container.size() == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);
				cout << "\t\t\tYou have no classes. You need to create some manually or get from file." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
				system("pause");
				break;
			}
			showAllClasses();
			cout << "\n                         Enter a class number for which to show users: ";
			cin >> selector;

			container[selector - 1].printComputerClassUsers();

			cout << "\n                         Enter a class number for which to show user's computer: ";
			int selector2;
			cin >> selector2;

			container[selector - 1].getComputerClass()[selector2-1].getComputer().printComputer();
			
			system("pause");
		}break;

		case '6': {
			system("cls");
			if (container.size() == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);
				cout << "\t\t\tYou have no classes. You need to create some manually or get from file." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
				system("pause");
				break;
			}
			showAllClasses();
			cout << "\n                         Enter a class number for which to show a brief information: ";
			cin >> selector;

			system("cls");
			cout << "\t\t\t=============================================================" << endl;
			cout << "\t\t\t                       INFO ABOUT "<< container[selector - 1].getClassName() << endl;
			cout << "\t\t\t|-----------------------------------------------------------|" << endl;
			container[selector - 1].printInfoAboutClass();
			system("pause");
		}break;

		case '7': {
			system("cls");
			if (container.size() == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);
				cout << "\t\t\tYou have no classes. You need to create some manually or get from file." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
				system("pause");
				break;
			}
			showAllClasses();
			cout << "\n                         Enter a class number to check WLAN connection: ";
			cin >> selector;

			cout << endl;
			cout << "WLAN connection for class " << container[selector - 1].getClassName() << " is " << container[selector - 1].getWLANConnection() << "." << endl;
			system("pause");
		}break;

		case '8': {
			system("cls");
			if (container.size() == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);
				cout << "\t\t\tYou have no classes. You need to create some manually or get from file." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
				system("pause");
				break;
			}
			showAllClasses();
			cout << "\n                         Enter a class number in which to delete users: ";
			cin >> selector;

			container[selector - 1].deleteUsersFromClass();
		} break;

		case '9': {
			system("cls");
			if (container.size() == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);
				cout << "\t\t\tYou have no classes. You need to create some manually or get from file." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
				system("pause");
				break;
			}
			showAllClasses();
			cout << "\n                         Enter a class number to delete: ";
			cin >> selector;

			fstream clear_file(container[selector - 1].getPath(), ios::out);
			clear_file.close();

			container.remove(selector - 1);
		} break;
		case ESC:
			return;
			break;
		default:
			system("cls");
			cin.clear();
			cin.ignore(10000, '\n');
			break;
		}
	}
}
void Menu::showAllClasses()
{
	cout << "\t\t\t=============================================================" << endl;
	cout << "\t\t\t|                        ALL CLASSES                        |" << endl;
	cout << "\t\t\t|-----------------------------------------------------------|" << endl;
	for (int i = 0; i < container.size(); i++)
	{
		cout << "\t\t\t" << i+1 << ". " << container[i].getClassName() << endl;
	}
}
