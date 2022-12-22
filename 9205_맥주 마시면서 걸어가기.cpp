#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    bool isVisted[101];
    pair<int, int> store[101], start, dest;
    while (t--)
    {
        queue<pair<int, int>> bfs;
        int n;
        cin >> n;
        cin >> start.first >> start.second;
        for (int i = 0; i < n; ++i)
        {
            cin >> store[i].first >> store[i].second;
            isVisted[i] = false;
        }
        cin >> dest.first >> dest.second;

        bfs.push(start);
        while (!bfs.empty())
        {
            auto cur = bfs.front();
            if (abs(dest.first - cur.first) + abs(dest.second - cur.second) <= 1000)
            {
                break;
            }
            bfs.pop();
            for (int i = 0; i < n; ++i)
            {
                if (isVisted[i])
                    continue;
                auto next = store[i];
                if (abs(next.first - cur.first) + abs(next.second - cur.second) > 1000)
                    continue;
                bfs.push(next);
                isVisted[i] = true;
            }
        }
        if (bfs.empty())
            cout << "sad";
        else
            cout << "happy";
        cout << "\n";
    }
    return 0;
}