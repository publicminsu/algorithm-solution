#include <iostream>
using namespace std;

int n;
string name;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    cin.ignore();

    while (n--)
    {
        getline(cin, name);

        int gCnt = 0;
        int bCnt = 0;

        for (const char &c : name)
        {
            switch (c)
            {
            case 'g':
            case 'G':
                ++gCnt;
                break;
            case 'b':
            case 'B':
                ++bCnt;
            default:
                break;
            }
        }

        cout << name << " is ";

        if (gCnt > bCnt)
        {
            cout << "GOOD";
        }
        else if (gCnt == bCnt)
        {
            cout << "NEUTRAL";
        }
        else
        {
            cout << "A BADDY";
        }

        cout << "\n";
    }

    return 0;
}