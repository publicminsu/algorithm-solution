#include <iostream>
#include <vector>
using namespace std;
int N, ret = 987654321;
vector<vector<int>> S;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    S = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> S[i][j];
        }
    }
}
void calc(int mask)
{
    int start = 0, link = 0;
    for (int i = 0; i < N; ++i)
    {
        int maskI = 1 << i;
        for (int j = 0; j < N; ++j)
        {
            int maskJ = 1 << j;

            if (((mask & maskI) == maskI) != ((mask & maskJ) == maskJ)) // 켜져 있는 두 곳이 동일한지 확인
            {
                continue;
            }

            if (mask & maskI) // 어떤 팀인지 확인
            {
                start += S[i][j];
            }
            else
            {
                link += S[i][j];
            }
        }
    }
    ret = min(ret, abs(start - link));
}
void comb(int depth, int mask, int index)
{
    if (depth == N / 2) // N/2만큼 나누었으면
    {
        calc(mask);
        return;
    }
    for (int i = index; i < N; ++i)
    {
        comb(depth + 1, mask | (1 << i), i + 1);
    }
}
int main()
{
    input();
    comb(0, 0, 0);
    cout << ret;
    return 0;
}