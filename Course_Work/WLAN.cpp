#include "WLAN.h"

int WLAN::checkInernetConnection()
{
    srand(time(0));
    int weight[]{1, 1, 2, 2, 2, 3};

    int random = rand() % 6;
    return weight[random];
}

void WLAN::setInternetConnection(int internetConnection)
{
    this->internetConnection = internetConnection;
}

string WLAN::getInternetConnection()
{
    internetConnection = checkInernetConnection();

    if (internetConnection == 1) return "nice";
    else if (internetConnection == 2) return "good";
    else if (internetConnection == 3) return "bad";
    else return "No internet connection";
}

void WLAN::operator()(int connection)
{
    setInternetConnection(connection);
}
