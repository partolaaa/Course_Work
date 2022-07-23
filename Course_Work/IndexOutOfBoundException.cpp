#include "IndexOutOfBoundException.h"

string IndexOutOfBoundException::what()
{
    return "Index Out Of Bound Exception, your index is " + Exception::what() + ".";
}
