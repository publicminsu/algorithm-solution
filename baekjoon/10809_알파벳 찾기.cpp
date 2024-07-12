#include <iostream>
#include <string>
using namespace std;
string str;
int ch[26];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int &i : ch)
    {
        i = -1;
    }

    cin >> str;
    for (int i = 0; i < str.size(); ++i)
    {
        int &j = ch[str[i] - 'a'];

        if (j == -1)
        {
            j = i;
        }
    }

    for (const int &i : ch)
    {
        cout << i << " ";
    }
    return 0;
}