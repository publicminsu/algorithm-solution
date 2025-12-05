#include <iostream>
#include <queue>
using namespace std;

using pdi = pair<double, int>;
using pdiii = pair<pdi, int>;

int N, K;
int cost[50][50];
bool isVisited[50][51];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            char c;
            cin >> c;

            cost[i][j] = c - '0';
        }
    }
}

void dijkstra()
{
    priority_queue<pdiii, vector<pdiii>, greater<pdiii>> pq;
    pq.push({{0, 0}, 0});

    while (!pq.empty())
    {
        pdiii curNode = pq.top();
        pq.pop();
        double curTime = curNode.first.first;
        int cnt = curNode.first.second;
        int idx = curNode.second;

        if (isVisited[idx][cnt])
        {
            continue;
        }

        isVisited[idx][cnt] = true;

        if (idx == 1)
        {
            cout << curTime;
            break;
        }

        for (int i = 0; i < N; ++i)
        {
            if (idx == i)
            {
                continue;
            }

            pq.push({{curTime + cost[idx][i], cnt}, i});
            if (cnt < K)
            {
                pq.push({{curTime + static_cast<double>(cost[idx][i]) / 2, cnt + 1}, i});
            }
        }
    }
}

int main()
{
    input();
    dijkstra();
    return 0;
}