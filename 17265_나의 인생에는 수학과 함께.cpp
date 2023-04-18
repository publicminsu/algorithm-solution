#include <iostream>
#include <vector>
using namespace std;
int N, minRet = 20000, maxRet = -20000;
vector<vector<char>> map;
void dfs(int i, int j, int sum, char prev)
{
    if (!(prev <= '5' && prev >= '0'))
    {
        int num = map[i][j] - '0';
        if (prev == '+')
            sum += num;
        else if (prev == '-')
            sum -= num;
        else
            sum *= num;
        if (i == N - 1 && j == N - 1)
        {
            minRet = sum < minRet ? sum : minRet;
            maxRet = sum > maxRet ? sum : maxRet;
            return;
        }
    }
    if (i != N - 1)
        dfs(i + 1, j, sum, map[i][j]);
    if (j != N - 1)
        dfs(i, j + 1, sum, map[i][j]);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    map = vector<vector<char>>(N, vector<char>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> map[i][j];
        }
    dfs(0, 0, map[0][0] - '0', map[0][0]);
    cout << maxRet << " " << minRet;
    return 0;
}