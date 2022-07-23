#include "Excepiton.h"

Exception::Exception(int value)
{
	this->value = value;
}

string Exception::what()
{
	return to_string(value);
}
