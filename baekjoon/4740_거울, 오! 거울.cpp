#include <iostream>
using namespace std;

string str;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    while (true)
    {
        getline(cin, str);

        if (str == "***")
        {
            break;
        }

        for (int i = str.size() - 1; i >= 0; --i)
        {
            cout << str[i];
        }

        cout << "\n";
    }

    return 0;
}