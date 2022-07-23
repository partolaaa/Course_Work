#include "User.h"
void User::playGames()
{
	cout << name << " is playing games now!" << endl;
	isStudying = false;
	isPlaying = true;
}

void User::study()
{
	cout << name << " is studying now!" << endl;
	isStudying = true;
	isPlaying = false;
}

void User::printUserInfo()
{
	cout << "Name: " << name << endl;
	cout << "\t\t\t\t\tGrade: " << grade << endl;
	cout << "\t\t\t\t\tStatus: ";
	if (isPlaying) cout << "Playing games" << endl;
	if (isStudying) cout << "Studying" << endl;
}

void User::addToFile(string path)
{
	string str = "";
	//Если файл пустой, то пишем нового пользвателя с первой строки, если нет - со следующей строки
	//Я использовал проверку "пустой ли файл" с помощью потока ввода, если 1 элемент это указатель на конец файла, то файл пустой
	ifstream fin;
	try
	{
		fin.open(path);
	}
	catch (const std::exception&)
	{

	}
	if (fin.peek() == std::ifstream::traits_type::eof())
	{
		str = name + "," + grade + "," + (isPlaying == false ? "no" : "yes") + "," + computer->getSystemUnit().getDataToFile() +
			computer->getMonitor().getDataToFile() +
			computer->getHeadphones().getDataToFile() +
			computer->getKeyboard().getDataToFile() +
			computer->getMouse().getDataToFile();
	}
	else
	{
		str = "\n" + name + "," + grade + "," + (isPlaying == false ? "no" : "yes") + "," + computer->getSystemUnit().getDataToFile() +
			computer->getMonitor().getDataToFile() +
			computer->getHeadphones().getDataToFile() +
			computer->getKeyboard().getDataToFile() +
			computer->getMouse().getDataToFile();
	}
	fin.close();
	try
	{
		ofstream fout(path, ios::app);

		fout << str;
		fout.close();

	}
	catch (const std::exception& ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}
}
Computer User::getComputer()
{
	return *computer;
}

User::User()
{
	string status;
	cout << "Enter user's name: ";
	cin >> name;
	cout << endl;

	cout << "Enter user's grade: ";
	cin >> grade;
	cout << endl;

	cout << "Is user playing games now? (yes or no): ";
	cin >> status;
	if (status._Equal("yes")) {
		isPlaying = true;
		isStudying = false;
	}

	computer = new Computer();
}


User::User(string name, string grade, bool isPlaying, Computer computer)
{
	this->name = name;
	this->grade = grade;
	this->isPlaying = isPlaying;
	if (isPlaying)
	{
		isStudying = false;
	}

	this->computer = new Computer(computer);
}
