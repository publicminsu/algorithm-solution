#include <iostream>
using namespace std;
string str;
int cnt;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (true)
    {
        getline(cin, str);

        if (str == "#")
        {
            break;
        }

        cnt = 0;

        for (char &c : str)
        {
            if (c < 'a')
            {
                c += 32;
            }

            switch (c)
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++cnt;
            }
        }

        cout << cnt << "\n";
    }
    return 0;
}