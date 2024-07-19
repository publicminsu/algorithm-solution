#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
int N, answer = 1;
vector<pii> v;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    v = vector<pii>(N);

    for (pii &i : v)
    {
        cin >> i.first >> i.second;
    }

    sort(v.begin(), v.end());

    pii prev = v.front();

    for (int i = 1; i < N; ++i)
    {
        pii cur = v[i];

        if (prev.first + prev.second < cur.first)
        {
            ++answer;
        }

        prev = cur;
    }

    cout << answer;
    return 0;
}