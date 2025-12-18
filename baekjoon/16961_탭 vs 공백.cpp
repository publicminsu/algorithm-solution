#include <iostream>

using namespace std;

int N;
int cnts[2][367];

char c;
int s, e, maxDays;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    while (N--)
    {
        cin >> c >> s >> e;

        int group = c == 'T' ? 0 : 1;

        for (int i = s; i <= e; ++i)
        {
            ++cnts[group][i];
        }

        maxDays = max(maxDays, e - s + 1);
    }
}

void print1()
{
    int days = 0;

    for (int i = 1; i <= 366; ++i)
    {
        if (cnts[0][i] || cnts[1][i])
        {
            ++days;
        }
    }

    cout << days << "\n";
}

void print2()
{
    int maxCnt = 0;

    for (int i = 1; i <= 366; ++i)
    {
        maxCnt = max(maxCnt, cnts[0][i] + cnts[1][i]);
    }

    cout << maxCnt << "\n";
}

void print3()
{
    int days = 0;

    for (int i = 1; i <= 366; ++i)
    {
        if (cnts[0][i] > 0 && cnts[0][i] == cnts[1][i])
        {
            ++days;
        }
    }

    cout << days << "\n";
}

void print4()
{
    int maxCnt = 0;

    for (int i = 1; i <= 366; ++i)
    {
        if (cnts[0][i] == cnts[1][i])
        {
            maxCnt = max(maxCnt, cnts[0][i] + cnts[1][i]);
        }
    }

    cout << maxCnt << "\n";
}

int main()
{
    input();
    print1();
    print2();
    print3();
    print4();
    cout << maxDays;
    return 0;
}