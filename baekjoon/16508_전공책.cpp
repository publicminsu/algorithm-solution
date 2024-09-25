#include <iostream>
#include <vector>
using namespace std;
using pis = pair<int, string>;
#define INF 1600001
string T;
int N, answer = INF;
vector<pis> v;

bool check(const vector<bool> &isVisited)
{
    for (int i = 0; i < T.size(); ++i)
    {
        if (!isVisited[i])
        {
            return false;
        }
    }

    return true;
}

void dfs(int index, int cost, vector<bool> isVisited)
{
    if (check(isVisited))
    {
        answer = min(answer, cost);
        return;
    }

    if (index == N)
    {
        return;
    }

    dfs(index + 1, cost, isVisited);

    for (char c : v[index].second)
    {
        for (int i = 0; i < T.size(); ++i)
        {
            if (isVisited[i])
            {
                continue;
            }

            if (T[i] == c)
            {
                isVisited[i] = true;
                break;
            }
        }
    }

    dfs(index + 1, cost + v[index].first, isVisited);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T >> N;
    v = vector<pis>(N);
    for (pis &p : v)
    {
        cin >> p.first >> p.second;
    }
    dfs(0, 0, vector<bool>(T.size()));
    cout << (answer == INF ? -1 : answer);
    return 0;
}