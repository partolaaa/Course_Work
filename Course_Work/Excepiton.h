#pragma once
#include <string>
using namespace std;
class Exception {
private:
	int value;
public:
	Exception(int value);
	virtual string what();
};