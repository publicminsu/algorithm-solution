#include <iostream>
#include <vector>
using namespace std;

int N, M, S;
vector<int> graph[100001];
bool hasFanClub[100001];

bool dfs(int curNode)
{
    if (hasFanClub[curNode])
    {
        return false;
    }

    if (graph[curNode].empty())
    {
        return true;
    }

    for (const int &nextNode : graph[curNode])
    {
        if (dfs(nextNode))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    while (M--)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
    }

    cin >> S;

    while (S--)
    {
        int s;
        cin >> s;
        hasFanClub[s] = true;
    }

    bool fanClubNotFound = dfs(1);

    cout << (fanClubNotFound ? "yes" : "Yes");
    return 0;
}