#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int N, M, X, cnt = 0;
    cin >> N >> M;
    queue<int> bfs;
    vector<vector<int>> party(M, vector<int>()), human(N + 1);
    vector<vector<bool>> lieFind(2, vector<bool>(N + 1));
    cin >> X;
    while (X--)
    {
        int num;
        cin >> num;
        lieFind[0][num] = true;
    }
    while (M--)
    {
        int Y;
        cin >> Y;
        while (Y--)
        {
            int num;
            cin >> num;
            party[M].push_back(num);
            human[num].push_back(M);
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        if (!lieFind[0][i] || lieFind[1][i])
            continue;
        bfs.push(i);
        while (!bfs.empty())
        {
            int cur = bfs.front();
            bfs.pop();
            for (int j : human[cur])
            {
                for (int k : party[j])
                {
                    if (lieFind[1][k])
                        continue;
                    lieFind[1][k] = true;
                    bfs.push(k);
                }
            }
        }
    }
    for (auto i : party)
    {
        bool isLie = false;
        for (int j : i)
        {
            if (lieFind[1][j])
            {
                isLie = true;
                break;
            }
        }
        if (!isLie)
            ++cnt;
    }
    cout << cnt;
    return 0;
}