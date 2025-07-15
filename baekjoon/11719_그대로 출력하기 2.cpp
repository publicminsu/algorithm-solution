#include <iostream>
using namespace std;

string str;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (getline(cin, str))
    {
        cout << str << "\n";
    }
    return 0;
}