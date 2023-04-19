#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N, M, ret = 11, totalSong = -1;
string guitar, song;
vector<vector<int>> graph;
vector<bool> isPlay;
void dfs(int idx, int songCnt, int guitarCnt)
{
    if (idx == N)
    {
        if (!songCnt)
            return;
        else if (totalSong < songCnt)
        {
            totalSong = songCnt;
            ret = guitarCnt;
        }
        else if (totalSong == songCnt && guitarCnt < ret)
        {
            ret = guitarCnt;
        }
        return;
    }
    vector<int> isUsed;
    for (int i : graph[idx])
    {
        if (isPlay[i])
            continue;
        isUsed.push_back(i);
        isPlay[i] = true;
    }
    if (isUsed.size())
    {
        dfs(idx + 1, songCnt + isUsed.size(), guitarCnt + 1);
        for (int i : isUsed)
            isPlay[i] = false;
    }
    dfs(idx + 1, songCnt, guitarCnt);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    graph = vector<vector<int>>(N, vector<int>());
    isPlay = vector<bool>(M);
    for (int i = 0; i < N; ++i)
    {
        cin >> guitar >> song;
        for (int j = 0; j < song.length(); ++j)
        {
            if (song[j] == 'Y')
                graph[i].push_back(j);
        }
    }
    dfs(0, 0, 0);
    if (ret == 11)
        ret = -1;
    cout << ret;
    return 0;
}