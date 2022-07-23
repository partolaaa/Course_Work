#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Computer.h"
#include <fstream>
#include <vector>

class User {
private:
	string name;
	string grade;
	bool isPlaying = false;
	bool isStudying = true; 
	Computer* computer;

public:
	void playGames();
	void study();
	void printUserInfo();
	void addToFile(string path);

	Computer getComputer();

	User();
	User(string name, string grade, bool isPlaying, Computer computer);

};