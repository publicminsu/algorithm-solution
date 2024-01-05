#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;
vector<pii> v;
vector<int> order;
int N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    v = vector<pii>(N);
    order = vector<int>(N);

    for (pii &i : v)
    {
        cin >> i.first >> i.second;
    }

    for (int i = 0; i < N; ++i)
    {
        int rank = 1;
        for (int j = 0; j < N; ++j)
        {
            if (v[i].first < v[j].first && v[i].second < v[j].second) // 자신보다 덩치가 큰 사람
            {
                ++rank;
            }
        }
        order[i] = rank;
    }

    for (int &i : order)
    {
        cout << i << " ";
    }
    return 0;
}