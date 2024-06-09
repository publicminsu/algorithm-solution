#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int N;
ll answer;
vector<int> ranks;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    ranks = vector<int>(N);

    for (int &rank : ranks)
    {
        cin >> rank;
    }

    sort(ranks.begin(), ranks.end());

    for (int i = 0; i < ranks.size(); ++i)
    {
        answer += abs(ranks[i] - (i + 1));
    }

    cout << answer;
    return 0;
}