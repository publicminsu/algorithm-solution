#include <iostream>
#include <vector>
using namespace std;
int N, M, answer = 2500;
vector<vector<char>> flag;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    flag = vector<vector<char>>(N, vector<char>(M));
    for (auto &line : flag)
    {
        for (auto &c : line)
        {
            cin >> c;
        }
    }
}
void solve()
{
    for (int i = 1; i <= N - 2; ++i)
    {
        for (int j = 1; j <= N - i - 1; ++j)
        {
            int k = N - i - j;
            int cnt = 0;

            for (int l = 0; l < i; ++l)
            {
                for (int m = 0; m < M; ++m)
                {
                    if (flag[l][m] != 'W')
                    {
                        ++cnt;
                    }
                }
            }

            for (int l = i; l < i + j; ++l)
            {
                for (int m = 0; m < M; ++m)
                {
                    if (flag[l][m] != 'B')
                    {
                        ++cnt;
                    }
                }
            }

            for (int l = i + j; l < i + j + k; ++l)
            {
                for (int m = 0; m < M; ++m)
                {
                    if (flag[l][m] != 'R')
                    {
                        ++cnt;
                    }
                }
            }

            answer = min(answer, cnt);
        }
    }
}
int main()
{
    input();
    solve();
    cout << answer;
    return 0;
}