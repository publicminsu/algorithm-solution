#include <iostream>
#include <unordered_set>
using namespace std;
unordered_set<string> s;
char map[5][5];
int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};

void dfs(int y, int x, string num)
{
    if (num.size() == 6)
    {
        s.insert(num);

        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
        {
            continue;
        }

        dfs(ny, nx, num + map[ny][nx]);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            dfs(i, j, "");
        }
    }

    cout << s.size();
    return 0;
}