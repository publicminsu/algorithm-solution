#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int N;
string A, B;
map<string, vector<string>> graph;

bool isConnect(string x, string y)
{
    map<string, bool> m;
    queue<string> q;

    q.push(x);
    m[x] = true;

    while (!q.empty())
    {
        string cur = q.front();
        q.pop();

        for (string next : graph[cur])
        {
            if (m[next])
            {
                continue;
            }

            m[next] = true;

            if (next == y)
            {
                return true;
            }

            q.push(next);
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    while (--N)
    {
        cin >> A >> B;
        graph[B].push_back(A);
    }

    cin >> A >> B;

    cout << (isConnect(B, A) || isConnect(A, B));
    return 0;
}