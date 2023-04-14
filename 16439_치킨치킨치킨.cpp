#include <iostream>
#include <vector>
// 조합으로 3개 고르고 선호도 높은거 합산후 최대값
// 3개 반복문 돌며 최대값 선정후 합산
using namespace std;
int N, M, ret = 0;
vector<int> chicken;
vector<vector<int>> a;
void comb(int idx)
{
    if (chicken.size() == 4)
        return;
    if (idx == M)
    {
        if (chicken.empty())
            return;
        int sum = 0;
        for (int i = 0, maxA; i < N; ++i)
        {
            maxA = 0;
            for (int c : chicken)
            {
                maxA = a[i][c] > maxA ? a[i][c] : maxA;
            }
            sum += maxA;
        }
        ret = sum > ret ? sum : ret;
        return;
    }
    comb(idx + 1);
    chicken.push_back(idx);
    comb(idx + 1);
    chicken.pop_back();
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    a = vector<vector<int>>(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> a[i][j];
    comb(0);
    cout << ret;
    return 0;
}