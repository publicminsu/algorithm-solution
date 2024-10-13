#include <iostream>
#include <vector>
using namespace std;
int N, sum, answer;
vector<vector<int>> tree;

void init()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0, cnt, depth = 0, idx = 0; i < N; ++i)
    {
        cin >> cnt;

        if (cnt == 1)
        {
            if (depth)
            {
                sum += depth;
                tree.push_back({depth, depth});
                depth = 0;
            }

            sum += 1;
            tree.push_back({1});
        }
        else
        {
            ++depth;

            if (i == N - 1)
            {
                sum += depth;
                tree.push_back({depth, depth});
            }
        }
    }
}

void solve()
{
    for (int i = 0; i < tree.size(); ++i)
    {
        answer = max(answer, sum + (tree[i].size() == 1 ? 0 : tree[i][0]));

        sum -= tree[i][0];
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    init();
    solve();

    cout << answer;
    return 0;
}