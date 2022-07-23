#include "ComputerClass.h"
vector<User> ComputerClass::fillComputerClassFromFile()
{
	char* next_token = NULL;
	char* part;

	SystemUnit* systemUnit;
	Monitor* monitor;
	Mouse* mouse;
	Keyboard* keyboard;
	Headphones* headphones;

	Computer* computer;
	WLAN WLANconnection{};
	User* user;

	vector<string> list;
	ifstream fin;
	fin.exceptions(ifstream::badbit | ifstream::failbit);
	try
	{
		fin.open(path);
	}
	catch (ifstream::failure & ex)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);
		cout << "Exception: File not found. You entered file name: " << path << "." << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
		system("pause");
		throw 505;
		exit;
	}

	try
	{
		for (string line; getline(fin, line);)
		{
			char* str = new char[line.size() + 1];
			strcpy(str, line.c_str());

			part = strtok_s(str, ",", &next_token);
			list.push_back(part);

			//считывание всех данных одной строки из файла
			for (int i = 0; i < 21; i++)
			{
				part = strtok_s(NULL, ",", &next_token);
				list.push_back(part);
			}

			bool stringToBool = list[6] == "1";
			systemUnit = new SystemUnit(list[3], stod(list[4]), stod(list[5]), stringToBool, stod(list[7]));

			monitor = new Monitor(stod(list[8]), stod(list[9]), stod(list[10]));

			headphones = new Headphones(list[11], list[12], stod(list[13]));

			keyboard = new Keyboard(list[14], list[15], stod(list[16]), stod(list[17]));

			mouse = new Mouse(list[18], list[19], stod(list[20]), stod(list[21]));

			computer = new Computer(*systemUnit, *monitor, *headphones, *keyboard, *mouse);

			user = new User(list[0], list[1], (list[2] == "yes" ? 1 : 0), *computer);

			computerClass.push_back(*user);
			list.clear();
		}
		fin.close();
	}
	catch (const std::exception&){}
	
	return computerClass;
}

vector<User> ComputerClass::getComputerClass()
{
	return computerClass;
}

string ComputerClass::getWLANConnection()
{
	return wlanConnection.getInternetConnection();
}
string ComputerClass::getClassName() {
	return className;
}
string ComputerClass::getPath() {
	return path;
}
void ComputerClass::printComputerClassUsers()
{
	cout << "\t\t\t\t==================================" << endl;
	for (int i = 0; i < computerClass.size(); i++)
	{
		cout <<"\t\t\t\t\t" << i + 1 << ". ";
		computerClass[i].printUserInfo();
		if (i != computerClass.size()-1)
		{
			cout << "\t\t\t\t|--------------------------------|" << endl;
		}
	}
	cout << "\t\t\t\t==================================" << endl;
}
void ComputerClass::printInfoAboutClass()
{
	for (int i = 0; i < computerClass.size(); i++)
	{
		totalPrice += computerClass[i].getComputer().getPrice();
	}
	cout << "Class name: " << className << endl;
	cout << "Number of students and computers: " << computerClass.size() << endl;
	cout << "The total price of all computers in the class: $" << totalPrice << endl;
}

void ComputerClass::setClassName(string className)
{
	this->className = className;
}

void ComputerClass::addUserToClass(User user)
{
	computerClass.push_back(user);
	user.addToFile(path);
}
void ComputerClass::deleteUsersFromClass()
{
	int selector = 0;
	while (true)
	{
		system("cls");
		printComputerClassUsers();

		cout << "\t\t\tWhich user to remove? (enter 0 to return): ";
		cin >> selector;


		if (selector > 0 && selector <= computerClass.size())
		{
			//Здесь не использую vector<User>(computerClass).swap(computerClass); так как в будущем возможно нужно будет расширять массив
			computerClass.erase(computerClass.begin() + (selector - 1));

			//Код для очистки файла, чтобы записать в него новый список computerClass
			fstream clear_file(path, ios::out);
			clear_file.close();

			for (int i = 0; i < computerClass.size(); i++)
			{
				computerClass[i].addToFile(path);
			}
		}
		else if(selector == 0)
		{
			system("cls");
			return;
		}
		else {
			system("cls");
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
}

void ComputerClass::deleteClass()
{
	fstream clear_file(path, ios::out);
	clear_file.close();
}
ComputerClass::ComputerClass(){}
ComputerClass::ComputerClass(string className, string path)
{
	this->path = path;
	this->className = className;
}

ComputerClass::ComputerClass(string className, vector<User> computerClass, WLAN wlanConnection)
{
	this->className = className;
	this->computerClass = computerClass;
	this->wlanConnection = wlanConnection;
}