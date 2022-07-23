#include "IlligalArraySizeException.h"

string IlligalArraySizeException::what()
{
    return "Illigal Array Size Exception, your size is " + Exception::what() + ".";
}
