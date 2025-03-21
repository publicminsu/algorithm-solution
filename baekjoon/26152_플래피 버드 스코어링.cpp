#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_SIZE 250000
using pii = pair<int, int>;
int N, Q, cnt;
int diffs[MAX_SIZE], answers[MAX_SIZE];
pii birds[MAX_SIZE];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0, j; i < N; ++i)
    {
        cin >> diffs[i];
    }

    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;
        diffs[i] = diffs[i] - j;
    }

    cin >> Q;

    for (int i = 0; i < Q; ++i)
    {
        cin >> birds[i].first;
        birds[i].second = i;
    }

    sort(birds, birds + Q, greater<pii>());

    for (int i = 0; i < Q; ++i)
    {
        while (cnt < N && diffs[cnt] >= birds[i].first)
        {
            ++cnt;
        }

        answers[birds[i].second] = cnt;
    }

    for (int i = 0; i < Q; ++i)
    {
        cout << answers[i] << "\n";
    }
    return 0;
}