#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
int N;
ll answer, time[1000];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0, j, k; i < N; ++i)
    {
        cin >> j;
        while (j--)
        {
            cin >> k;
            time[i] += k;
        }
    }

    sort(time, time + N);

    for (int i = 1; i < N; ++i)
    {
        time[i] += time[i - 1];
    }

    for (int i = 0; i < N; ++i)
    {
        answer += time[i];
    }

    cout << answer;
    return 0;
}