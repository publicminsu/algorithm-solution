#include <iostream>
using namespace std;
string str;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> str;

    for (char &c : str)
    {
        if (c >= 'a')
        {
            c -= 32;
        }
        else
        {
            c += 32;
        }

        cout << c;
    }
    return 0;
}