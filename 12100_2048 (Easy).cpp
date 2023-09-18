#include <iostream>
#include <vector>
using namespace std;
int N, ret;
vector<vector<int>> temp;
void dfs(int depth, vector<vector<int>> map);
void rotate(vector<vector<int>> &map)
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            temp[j][N - 1 - i] = map[i][j];
    map = temp;
}
void left(int depth, vector<vector<int>> &map)
{
    vector<vector<int>> nextMap = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; ++i) // 세로
    {
        int k = 0;
        for (int j = 0; j < N; ++j) // 가로
            if (map[i][j])          // 왼쪽 값이 존재한다면
                if (j + 1 == N)     // 끝에 값
                    nextMap[i][k] = map[i][j];
                else
                {
                    int l = j + 1;
                    for (; l < N; ++l)
                        if (map[i][l])
                            break;
                    if (map[i][j] == map[i][l])
                    {
                        nextMap[i][k++] = map[i][j] * 2;
                        j = l;
                    }
                    else
                    {
                        nextMap[i][k++] = map[i][j];
                        j = l - 1;
                    }
                }
    }
    dfs(depth + 1, nextMap);
}
void dfs(int depth, vector<vector<int>> map)
{
    if (depth == 5)
    {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                ret = max(map[i][j], ret);
        return;
    }
    left(depth, map);
    for (int i = 0; i < 3; ++i)
    {
        rotate(map);
        left(depth, map);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    vector<vector<int>> map;
    map = temp = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> map[i][j];
    dfs(0, map);
    cout << ret;
    return 0;
}