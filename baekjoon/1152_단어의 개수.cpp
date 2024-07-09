#include <iostream>
using namespace std;
string str;
int count;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> str)
    {
        ++count;
    }
    cout << count;
    return 0;
}