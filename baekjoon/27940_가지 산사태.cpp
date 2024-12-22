#include <iostream>
using namespace std;
int N, M, K, t, r, sum;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;

    for (int i = 1; i <= M; ++i)
    {
        cin >> t >> r;

        sum += r;

        if (sum > K)
        {
            cout << i << " " << 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}