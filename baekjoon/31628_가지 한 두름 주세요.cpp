#include <iostream>
using namespace std;
string str[10][10];
void input()
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cin >> str[i][j];
        }
    }
}
void solve()
{
    for (int i = 0; i < 10; ++i)
    {
        bool isFind = true;
        string first = str[i][0];
        for (int j = 0; j < 10; ++j)
        {
            if (first != str[i][j])
            {
                isFind = false;
            }
        }
        if (isFind)
        {
            cout << 1;
            return;
        }

        isFind = true;
        first = str[0][i];
        for (int j = 0; j < 10; ++j)
        {
            if (first != str[j][i])
            {
                isFind = false;
            }
        }
        if (isFind)
        {
            cout << 1;
            return;
        }
    }
    cout << 0;
}
int main()
{
    input();
    solve();
    return 0;
}