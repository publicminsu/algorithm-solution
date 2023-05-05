#include <iostream>
#include <string>
using namespace std;
string name;
int alpha[26];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> name;
    for (char a : name)
    {
        ++alpha[a - 'A'];
    }
    int lastOne = -1;
    for (int i = 0, j = 0; i < 26; ++i)
    {
        if (alpha[i] % 2)
        {
            if (lastOne != -1)
            {
                lastOne = -2;
                break;
            }
            lastOne = i;
        }
        while (alpha[i] && alpha[i] != 1)
        {
            alpha[i] -= 2;
            name[j] = name[name.length() - 1 - j] = i + 'A';
            ++j;
        }
    }
    if (lastOne == -2)
        name = "I'm Sorry Hansoo";
    else if (lastOne != -1)
        name[name.length() / 2] = lastOne + 'A';
    cout << name;
    return 0;
}