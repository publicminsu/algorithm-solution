#include <iostream>
using namespace std;

string S;

bool isVisited[51][51][51][4][4];

bool comb(int a, int b, int c, int prev, int pprev, string str)
{
    if (str.size() > 50)
    {
        return false;
    }

    if (a == 0 && b == 0 && c == 0)
    {
        cout << str;
        return true;
    }

    if (isVisited[a][b][c][prev][pprev])
    {
        return false;
    }

    isVisited[a][b][c][prev][pprev] = true;

    if (a)
    {
        if (comb(a - 1, b, c, 0, prev, str + "A"))
        {
            return true;
        }
    }

    if (b && prev != 1)
    {
        if (comb(a, b - 1, c, 1, prev, str + "B"))
        {
            return true;
        }
    }

    if (c && prev != 2 && pprev != 2)
    {
        if (comb(a, b, c - 1, 2, prev, str + "C"))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> S;

    int a = 0, b = 0, c = 0;

    for (const char &ch : S)
    {
        switch (ch)
        {
        case 'A':
            ++a;
            break;
        case 'B':
            ++b;
            break;
        case 'C':
            ++c;
            break;
        }
    }

    if (!comb(a, b, c, 3, 3, ""))
    {
        cout << -1;
    }
    return 0;
}