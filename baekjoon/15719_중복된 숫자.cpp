#include <iostream>

using namespace std;
using ll = long long;

ll N;
ll sum, originalSum;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        sum += num;
    }

    originalSum = (N * (N - 1)) / 2;

    cout << sum - originalSum;
    return 0;
}