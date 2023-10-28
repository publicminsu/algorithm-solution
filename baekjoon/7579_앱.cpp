#include <iostream>
#include <vector>
using namespace std;
struct app
{
    int m, c;
};
vector<int> dp;
vector<app> apps;
int N, M, cSum;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    apps = vector<app>(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> apps[i].m;
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> apps[i].c;
        cSum += apps[i].c;
    }
    dp = vector<int>(cSum + 1); // 비용을 기준으로 dp
    for (int i = 0; i < N; ++i)
    {
        for (int j = cSum; j >= apps[i].c; --j)
        {
            dp[j] = max(dp[j], dp[j - apps[i].c] + apps[i].m); // 해당 비용에서 가장 많은 바이트인지 확인
        }
    }
    for (int i = 0; i <= cSum; ++i)
    {
        if (dp[i] >= M) // M 이상이면 출력
        {
            cout << i;
            break;
        }
    }
    return 0;
}