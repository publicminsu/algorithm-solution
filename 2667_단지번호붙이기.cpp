#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int>> map(N, vector<int>(N));
    vector<int> answer;
    queue<pair<int, int>> bfs;
    for (int i = 0; i < N; ++i)
    {
        string num;
        cin >> num;
        for (int j = 0; j < N; ++j)
        {
            map[i][j] = num[j] - '0';
        }
    }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            if (!map[i][j])
                continue;
            bfs.push({i, j});
            int sum = 1;
            map[i][j] = 0;
            while (!bfs.empty())
            {
                auto cur = bfs.front();
                bfs.pop();
                for (int i = 0; i < 4; ++i)
                {
                    pair<int, int> next = {cur.first + dx[i], cur.second + dy[i]};
                    if (next.first < 0 || next.second < 0 || next.first >= N || next.second >= N)
                        continue;
                    if (map[next.first][next.second])
                    {
                        ++sum;
                        map[next.first][next.second] = 0;
                        bfs.push(next);
                    }
                }
            }
            if (sum)
                answer.push_back(sum);
        }
    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for (int i : answer)
    {
        cout << i << "\n";
    }
    return 0;
}