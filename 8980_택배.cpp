#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
vector<vector<pii>> graph;
vector<pii> boxs;
int N, C, M, startTown, endTown, boxNum, ret;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> C >> M;
    graph = vector<vector<pii>>(N + 1, vector<pii>());
    while (M--)
    {
        cin >> startTown >> endTown >> boxNum;
        graph[startTown].push_back({endTown, boxNum});
    }
    for (int i = 1; i <= N; ++i)
    {
        sort(boxs.begin(), boxs.end(), greater<pii>());
        while (true)
        {
            if (boxs.empty())
                break;
            if (boxs.back().first <= i)
            {
                ret += boxs.back().second;
                boxs.pop_back();
            }
            else
                break;
        }
        sort(graph[i].begin(), graph[i].end());
        for (pii p : graph[i])
            boxs.push_back(p);
        sort(boxs.begin(), boxs.end());
        int curBox = 0;
        for (int j = 0; j < boxs.size();)
        {
            curBox += boxs[j].second;
            if (curBox > C)
            {
                boxs[j].second = boxs[j].second - (curBox - C);
                boxs.erase(boxs.begin() + j + 1, boxs.end());
                break;
            }
            else
                ++j;
        }
    }
    cout << ret;
    return 0;
}