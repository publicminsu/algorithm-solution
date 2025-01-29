#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
vector<pii> trees;
int n;
ll answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    trees = vector<pii>(n);

    for (pii &p : trees)
    {
        cin >> p.second;
    }

    for (pii &p : trees)
    {
        cin >> p.first;
    }

    sort(trees.begin(), trees.end());

    for (int i = 0; i < n; ++i)
    {
        answer += trees[i].second + trees[i].first * i;
    }

    cout << answer;
    return 0;
}