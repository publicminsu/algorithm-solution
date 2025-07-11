#include <iostream>

using namespace std;

string word;

int cnts[26], maxCnt, maxIdx;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> word;

    for (int i = 0; i < word.size(); ++i)
    {
        char c = word[i];

        if ('A' <= c && 'Z' >= c)
        {
            c += 32;
        }

        ++cnts[c - 'a'];
    }

    for (int i = 0; i < 26; ++i)
    {
        if (cnts[i] > maxCnt)
        {
            maxCnt = cnts[i];
            maxIdx = i;
        }
        else if (cnts[i] == maxCnt)
        {
            maxIdx = -1;
        }
    }

    if (maxIdx == -1)
    {
        cout << '?';
    }
    else
    {
        cout << char('A' + maxIdx);
    }
    return 0;
}