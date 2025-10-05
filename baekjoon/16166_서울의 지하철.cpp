#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
using pii = pair<int, int>;

#define INF 987654321

struct node
{
    int line, station, cnt;

    bool operator<(const node &other) const
    {
        return cnt > other.cnt;
    }
};

unordered_map<int, vector<pii>> graph;
int buffer[10];
int N, K, goal;

void init()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> K;

        for (int j = 0; j < K; ++j)
        {
            cin >> buffer[j];
        }

        for (int j = 0; j < K; ++j)
        {
            for (int k = j + 1; k < K; ++k)
            {
                if (buffer[j] == buffer[k])
                {
                    continue;
                }

                graph[buffer[k]].push_back({i, buffer[j]});
                graph[buffer[j]].push_back({i, buffer[k]});
            }
        }
    }

    cin >> goal;
}

void dijkstra()
{
    if (goal == 0)
    {
        cout << 0;
        return;
    }

    int answer = INF;
    unordered_map<int, int> us;
    priority_queue<node> q;

    for (auto p : graph)
    {
        for (auto i : p.second)
        {
            if (i.second == 0)
            {
                q.push({i.first, 0, 0});
            }
        }
    }

    us[0] = 0;

    while (!q.empty())
    {
        node curNode = q.top();
        q.pop();

        for (auto p : graph[curNode.station])
        {
            int cnt = curNode.cnt;
            if (p.first != curNode.line)
            {
                ++cnt;
            }

            if (us.find(p.second) != us.end() && cnt >= us[p.second])
            {
                continue;
            }

            us[p.second] = cnt;

            if (p.second == goal)
            {
                answer = min(answer, cnt);
                continue;
            }

            q.push({p.first, p.second, cnt});
        }
    }

    if (answer == INF)
    {
        answer = -1;
    }
    cout << answer;
}

int main()
{
    init();
    dijkstra();
    return 0;
}