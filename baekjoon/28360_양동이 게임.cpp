#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> graph[51];
float amounts[51];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    while (M--)
    {
        int v, w;
        cin >> v >> w;
        graph[v].push_back(w);
    }
}

void solve()
{
    float maxAmount = 0;
    amounts[1] = 100;

    for (int i = 1; i <= N; ++i)
    {
        int size = graph[i].size();
        float amount = amounts[i];

        if (size == 0)
        {
            maxAmount = max(maxAmount, amount);
            continue;
        }

        amount /= size;

        for (int j = 0; j < size; ++j)
        {
            amounts[graph[i][j]] += amount;
        }
    }

    cout << maxAmount;
}

int main()
{
    input();
    solve();
    return 0;
}