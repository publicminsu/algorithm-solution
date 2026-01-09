#include <iostream>
#include <algorithm>
using namespace std;

using pii = pair<int, int>;
using piii = pair<int, pii>;

int N, K;
piii target;
piii cnts[1000];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        int id;
        cin >> id >> cnts[i].first >> cnts[i].second.first >> cnts[i].second.second;

        if (id == K)
        {
            target = cnts[i];
        }
    }

    sort(cnts, cnts + N, greater<>());

    for (int i = 0; i < N; ++i)
    {
        if (cnts[i] == target)
        {
            cout << i + 1;
            break;
        }
    }
    return 0;
}