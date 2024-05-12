#include <iostream>
using namespace std;
string str;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (true)
    {
        getline(cin, str);
        if (str.empty())
        {
            break;
        }
        cout << str << "\n";
    }
}