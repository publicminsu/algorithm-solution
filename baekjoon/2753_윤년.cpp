#include <iostream>
using namespace std;
int year;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> year;
    cout << (year % 400 == 0 || (year % 4 == 0 && year % 100));
    return 0;
}