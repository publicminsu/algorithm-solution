#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    time_t curTime = time(NULL);
    tm *curLocalTime = localtime(&curTime);

    cout << curLocalTime->tm_year + 1900 << "\n"
         << curLocalTime->tm_mon + 1 << "\n"
         << curLocalTime->tm_mday;

    return 0;
}