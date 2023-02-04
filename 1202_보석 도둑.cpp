#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned long long ull;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    multiset<int> bag;
    vector<pair<int, int>> jewelry;
    int N, K;
    ull sum = 0;
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        pair<int, int> j;
        cin >> j.second >> j.first;
        jewelry.push_back(j);
    }
    for (int j = 0; j < K; ++j)
    {
        int b;
        cin >> b;
        bag.insert(b);
    }
    sort(jewelry.begin(), jewelry.end(), greater<>());
    for (auto j : jewelry)
    {
        auto it = bag.lower_bound(j.second);
        if (it != bag.end())
        {
            bag.erase(it);
            sum += j.first;
        }
    }
    cout << sum;
}