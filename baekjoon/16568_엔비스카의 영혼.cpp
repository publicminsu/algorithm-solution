#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using pii = pair<int, int>;
vector<bool> isVisited;
int N, a, b;
queue<pii> q;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> a >> b;
    isVisited = vector<bool>(N + 1);

    q.push({0, 0});
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();

        if (cur.first == N)
        {
            cout << cur.second;
            break;
        }

        if (cur.first > N || isVisited[cur.first])
        {
            continue;
        }
        isVisited[cur.first] = true;

        ++cur.first;
        ++cur.second;

        q.push(cur);
        q.push({cur.first + a, cur.second});
        q.push({cur.first + b, cur.second});
    }
    return 0;
}