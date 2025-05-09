#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int N, pos;
ll sum, halfSum;
pii X[100001];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> X[i].first >> X[i].second;
        sum += X[i].second;
    }

    sort(X, X + N);

    for (int i = 0; i < N; ++i)
    {
        halfSum += X[i].second;

        if (halfSum * 2 >= sum)
        {
            pos = X[i].first;
            break;
        }
    }

    cout << pos;
    return 0;
}