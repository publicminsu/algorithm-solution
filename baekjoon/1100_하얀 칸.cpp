#include <iostream>

using namespace std;

string board[8];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 0; i < 8; ++i)
    {
        cin >> board[i];
    }

    int cnt = 0;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] == 'F' && (i + j) % 2 == 0)
            {
                ++cnt;
            }
        }
    }

    cout << cnt;
    return 0;
}