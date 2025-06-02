#include <iostream>

using namespace std;

string A, B, outA, outB;

bool IsVowel(char ch)
{
    switch (ch)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

bool TryExtract(const string &inStr, string &outStr)
{
    outStr = "";

    for (int i = 0; i < inStr.size(); ++i)
    {
        outStr += inStr[i];

        if (IsVowel(inStr[i]))
        {
            if (i + 1 < inStr.size())
            {
                if (IsVowel(inStr[i + 1]))
                {
                    continue;
                }
                else
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> A >> B;

    if (TryExtract(A, outA) && TryExtract(B, outB))
    {
        cout << outA << outB;
    }
    else
    {
        cout << "no such exercise";
    }

    return 0;
}