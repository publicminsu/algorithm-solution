#include <iostream>
#include <cstring>
using namespace std;
int sudoku[9][9];
bool checkRow(int y, int curNum)
{
    for (int i = 0; i < 9; ++i)
    {
        if (sudoku[y][i] == curNum) // 이미 사용된 값이면
        {
            return false;
        }
    }
    return true;
}
bool checkCol(int x, int curNum)
{
    for (int i = 0; i < 9; ++i)
    {
        if (sudoku[i][x] == curNum) // 이미 사용된 값이면
        {
            return false;
        }
    }
    return true;
}
bool checkBox(int y, int x, int curNum)
{
    y = (y / 3) * 3;
    x = (x / 3) * 3;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            int ny = y + i;
            int nx = x + j;
            if (sudoku[ny][nx] == curNum) // 이미 사용된 값이면
            {
                return false;
            }
        }
    }
    return true;
}
void dfs(int idx)
{
    if (idx == 81) // 끝에 도달한 경우
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                cout << sudoku[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }

    int y = idx / 9;
    int x = idx % 9;

    if (sudoku[y][x]) // 이미 값이 존재한 경우
    {
        dfs(idx + 1);
        return;
    }

    for (int i = 1; i <= 9; ++i)
    {
        if (checkBox(y, x, i) && checkCol(x, i) && checkRow(y, i)) // 스도쿠 규칙을 지킨 경우
        {
            sudoku[y][x] = i;
            dfs(idx + 1);
            sudoku[y][x] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cin >> sudoku[i][j];
        }
    }
    dfs(0);
    return 0;
}