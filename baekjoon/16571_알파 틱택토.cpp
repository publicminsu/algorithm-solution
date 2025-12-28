#include <iostream>
#include <vector>
#include <map>

using namespace std;
using vvi = vector<vector<int>>;

vvi board;
map<vvi, int> counts;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    board = vector<vector<int>>(3, vector<int>(3));

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> board[i][j];
        }
    }
}

int getPlayerTurn()
{
    int turnCnt[3] = {0, 0, 0};

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            ++turnCnt[board[i][j]];
        }
    }

    return (turnCnt[1] > turnCnt[2] ? 2 : 1);
}

bool isFinished()
{
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return true;
        }

        if (board[0][i] != 0 && board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return true;
        }
    }

    if (board[1][1] != 0)
    {
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        {
            return true;
        }

        if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
        {
            return true;
        }
    }

    return false;
}

int dfs(int turn)
{
    if (counts.find(board) != counts.end())
    {
        return counts[board];
    }

    if (isFinished())
    {
        return counts[board] = -1;
    }

    const int INF = 2;
    int ret = INF;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] != 0)
            {
                continue;
            }

            board[i][j] = turn;

            ret = min(ret, dfs(turn % 2 + 1));

            board[i][j] = 0;
        }
    }

    if (ret == INF)
    {
        ret = 0;
    }

    ret = -ret;

    return counts[board] = ret;
}

char solve()
{
    switch (dfs(getPlayerTurn()))
    {
    case -1:
        return 'L';
    case 0:
        return 'D';
    default:
        return 'W';
    }
}

int main()
{
    input();
    cout << solve();
    return 0;
}