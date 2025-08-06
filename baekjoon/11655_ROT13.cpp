#include <iostream>
using namespace std;
string str;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    getline(cin, str);

    for (unsigned char c : str)
    {
        if (c >= 'A' && c <= 'Z')
        {
            c += 13;
            if (c > 'Z')
            {
                c -= 26;
            }
        }
        else if (c >= 'a' && c <= 'z')
        {
            c += 13;
            if (c > 'z')
            {
                c -= 26;
            }
        }
        cout << c;
    }

    return 0;
}