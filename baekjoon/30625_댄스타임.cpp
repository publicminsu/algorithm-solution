#include <iostream>
using namespace std;
#define MOD 1000000007
using ll = long long;
int N, M, B;
ll answer, cnt;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    cin >> B >> B;

    answer = M;

    if (B)
    {
        cnt = M - 1;
    }
    else
    {
        cnt = 1;
    }

    for (int i = 1; i < N; ++i)
    {
        cin >> B >> B;

        if (B)
        {
            answer = answer * (M - 1) + cnt;
            cnt = cnt * (M - 1) % MOD;
        }
        else
        {
            answer += cnt * (M - 1);
        }
        answer %= MOD;
    }

    cout << answer;
    return 0;
}