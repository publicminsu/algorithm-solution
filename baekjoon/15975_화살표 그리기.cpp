#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
vector<vector<int>> pos;
int N;
ll answer;
int main()
{
    cin >> N;
    pos = vector<vector<int>>(N, vector<int>());
    for (int i = 0, x, y; i < N; ++i)
    {
        cin >> x >> y;
        --y;
        pos[y].push_back(x);
    }

    for (int i = 0; i < N; ++i)
    {
        sort(pos[i].begin(), pos[i].end());

        if (pos[i].size() <= 1)
        {
            continue;
        }

        for (int j = 0; j < pos[i].size(); ++j)
        {
            ll cur = pos[i][j];

            ll left = j - 1 >= 0 ? pos[i][j - 1] : -10000000001;
            ll right = j + 1 < pos[i].size() ? pos[i][j + 1] : 10000000001;

            answer += min(cur - left, right - cur);
        }
    }
    cout << answer;
    return 0;
}