#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int T, K, M, P, A, B;
map<int, vector<int>> graph;
queue<int> q;
int strahlers[1001];
int counts[1001];
int inCounts[1001];

void init()
{
    graph.clear();
    memset(strahlers, 0, sizeof(strahlers));
    memset(counts, 0, sizeof(counts));
    memset(inCounts, 0, sizeof(inCounts));

    cin >> K >> M >> P;

    while (P--)
    {
        cin >> A >> B;
        graph[A].push_back(B);
        ++inCounts[B];
    }

    for (int i = 1; i <= M; ++i)
    {
        if (inCounts[i] == 0)
        {
            q.push(i);
            strahlers[i] = 1;
        }
    }
}

void solve()
{
    int answer = 0;

    while (!q.empty())
    {
        int curNode = q.front();
        int curStrahler = strahlers[curNode];

        if (counts[curNode] >= 2)
        {
            ++curStrahler;
        }

        answer = max(answer, curStrahler);

        q.pop();

        for (int nextNode : graph[curNode])
        {
            int &nextStrahler = strahlers[nextNode];

            if (nextStrahler < curStrahler)
            {
                nextStrahler = curStrahler;
                counts[nextNode] = 1;
            }
            else if (nextStrahler == curStrahler)
            {
                ++counts[nextNode];
            }

            --inCounts[nextNode];
            if (inCounts[nextNode] == 0)
            {
                q.push(nextNode);
            }
        }
    }

    cout << K << " " << answer << "\n";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;
    while (T--)
    {
        init();
        solve();
    }
    return 0;
}