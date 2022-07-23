#pragma once
#include "Excepiton.h"
class IlligalArraySizeException : public Exception {
public:
	string what() override;
	IlligalArraySizeException(int value) : Exception(value){};
};