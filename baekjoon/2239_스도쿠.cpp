#include <iostream>
#include <string>
using namespace std;
int map[9][9];
bool isExist[2][9][10];       // (가로, 세로) 여부, 몇 번째 줄, 어느 값
bool isSquareExist[3][3][10]; // 영역, 어느 값
void dfs(int index)
{
    if (index == 81)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
                cout << map[i][j];
            cout << "\n";
        }
        exit(0);
    }
    int y = index / 9;
    int x = index % 9;
    if (map[y][x])
        dfs(index + 1);
    else
        for (int i = 1; i <= 9; ++i)
        {
            if (isExist[0][y][i] || isExist[1][x][i] || isSquareExist[y / 3][x / 3][i])
                continue;
            isExist[0][y][i] = isExist[1][x][i] = isSquareExist[y / 3][x / 3][i] = true;
            map[y][x] = i;
            dfs(index + 1);
            map[y][x] = 0;
            isExist[0][y][i] = isExist[1][x][i] = isSquareExist[y / 3][x / 3][i] = false;
        }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string input;
    for (int i = 0; i < 9; ++i)
    {
        cin >> input;
        for (int j = 0; j < 9; ++j)
        {
            map[i][j] = input[j] - '0';
            isExist[0][i][map[i][j]] = isExist[1][j][map[i][j]] = isSquareExist[i / 3][j / 3][map[i][j]] = true;
        }
    }
    dfs(0);
    return 0;
}