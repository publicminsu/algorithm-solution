#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
int N, M, V[100000];
ll sum, sumOfSupporters;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        cin >> V[i];
        sum += V[i];
    }

    sort(V, V + N, greater<int>());

    int idx = 0;

    while (sum > sumOfSupporters * 2)
    {
        sumOfSupporters += V[idx++];
    }

    cout << M / (idx + 1);
    return 0;
}