#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, n1, n2;
    cin >> N;
    vector<vector<int>> tree(N + 1, vector<int>());
    vector<int> parents(N + 1);
    queue<int> q;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }
    parents[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i : tree[cur])
        {
            if (parents[i])
                continue;
            parents[i] = cur;
            q.push(i);
        }
    }
    for (int i = 2; i <= N; ++i)
    {
        cout << parents[i] << "\n";
    }
}