#include <iostream>
using namespace std;
int tc;
string str;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> tc;
    while (tc--)
    {
        cin >> str;

        int point = 0, count = 0;

        for (const char &c : str)
        {
            if (c == 'O')
            {
                ++count;
            }
            else
            {
                count = 0;
            }

            point += count;
        }

        cout << point << "\n";
    }
    return 0;
}