#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    cout.fill('0');

    cout.width(4);
    cout << (t->tm_year + 1900) << "-";
    cout.width(2);
    cout << (t->tm_mon + 1) << "-";
    cout << (t->tm_mday);
    return 0;
}