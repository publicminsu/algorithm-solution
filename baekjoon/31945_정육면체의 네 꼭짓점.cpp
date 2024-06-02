#include <iostream>
using namespace std;
int T, P[4];

bool checkSame(int i, int bit)
{
    for (int j = 1; j < 4; ++j)
    {
        bool otherBit = (P[j] >> i) & 1;

        if (otherBit != bit)
        {
            return false;
        }
    }

    return true;
}

bool checkFace()
{
    for (int i = 0; i < 3; ++i)
    {
        bool bit = (P[0] >> i) & 1;

        bool allSame = true;

        if (checkSame(i, bit))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;
    while (T--)
    {
        for (int i = 0; i < 4; ++i)
        {
            cin >> P[i];
        }

        bool isFace = checkFace();

        cout << (isFace ? "YES" : "NO") << "\n";
    }
}