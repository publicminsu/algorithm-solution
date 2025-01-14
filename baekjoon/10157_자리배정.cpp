#include <iostream>
using namespace std;

bool isVisited[1001][1001];

int C, R, K;

bool checkPos(int x, int y)
{
    if (x < 0 || y < 0 || x >= C || y >= R || isVisited[x][y])
    {
        return false;
    }

    return true;
}

bool check(int x, int y, int dir)
{
    switch (dir)
    {
    case 0:
        return checkPos(x, y + 1);
    case 1:
        return checkPos(x + 1, y);
    case 2:
        return checkPos(x, y - 1);
    case 3:
        return checkPos(x - 1, y);
    }
}

void recur(int x, int y, int dir)
{
    isVisited[x][y] = true;

    --K;

    if (K == 0)
    {
        cout << x + 1 << " " << y + 1;
        return;
    }

    if (!check(x, y, dir))
    {
        dir = (dir + 1) % 4;
    }

    switch (dir)
    {
    case 0:
        recur(x, y + 1, dir);
        break;
    case 1:
        recur(x + 1, y, dir);
        break;
    case 2:
        recur(x, y - 1, dir);
        break;
    case 3:
        recur(x - 1, y, dir);
        break;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> C >> R >> K;

    if (C * R < K)
    {
        cout << 0;
        return 0;
    }

    recur(0, 0, 0);
    return 0;
}