#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
using piii = pair<int, pii>;
int N;
vector<piii> v;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    v = vector<piii>(N);

    for (piii &p : v)
    {
        cin >> p.second.first >> p.second.second >> p.first;
    }

    sort(v.begin(), v.end(), greater<piii>());

    const pii &gold = v[0].second;
    const pii &silver = v[1].second;

    cout << gold.first << " " << gold.second << "\n";
    cout << silver.first << " " << silver.second << "\n";

    for (int i = 2; i < N; ++i)
    {
        const pii &p = v[i].second;
        if (gold.first == silver.first && silver.first == p.first)
        {
            continue;
        }

        cout << p.first << " " << p.second << "\n";
        break;
    }
    return 0;
}