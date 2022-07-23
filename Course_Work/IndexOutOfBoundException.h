#pragma once
#include "Excepiton.h"
class IndexOutOfBoundException : public Exception {
public:
	string what() override;
	IndexOutOfBoundException(int value) : Exception(value) {};
};