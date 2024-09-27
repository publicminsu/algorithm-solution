#include <iostream>
using namespace std;
int month, day;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> month >> day;
    day += (month - 1) * 31;
    if (day == 49)
    {
        cout << "Special";
    }
    else if (day > 49)
    {
        cout << "After";
    }
    else
    {
        cout << "Before";
    }
    return 0;
}