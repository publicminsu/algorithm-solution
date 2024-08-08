#include <iostream>
using namespace std;
using ll = long long;
int N, K;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;

    ll answer = 0;

    for (int i = 1; i <= N; ++i)
    {
        int j = i;
        while (j)
        {
            j /= 10;
            answer *= 10;
        }
        answer += i;

        answer %= K;
    }

    cout << answer;
    return 0;
}