#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
bool box[101][101], visited[101][101];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}, M, N, K;
int bfs(int x, int y, bool isBox)
{
    if (visited[x][y])
    {
        return 0;
    }
    visited[x][y] = true;
    int cnt = 1;
    for (int i = 0; i < 4; ++i)
    {
        int nextX = dx[i] + x, nextY = dy[i] + y;
        if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M && box[nextX][nextY] == isBox)
            cnt += bfs(nextX, nextY, isBox);
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(box, false, sizeof(box));
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    vector<int> answer;
    cin >> M >> N >> K;
    while (K--)
    {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        for (int i = lx; i < rx; ++i)
        {
            for (int j = ly; j < ry; ++j)
            {
                box[i][j] = true;
            }
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (visited[i][j])
                continue;
            bool isBox = box[i][j];
            int cnt = bfs(i, j, isBox);
            if (!isBox)
            {
                answer.push_back(cnt);
            }
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for (int a : answer)
    {
        cout << a << " ";
    }
    return 0;
}