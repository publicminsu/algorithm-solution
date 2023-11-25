#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
vector<vector<int>> map, groupMap;
vector<int> groupSize;
int N, M, groupIdx;
struct pos
{
    int y, x;
    const pos operator+(const pos &other) const
    {
        return {other.y + y, other.x + x};
    }
    const bool isOut() const
    {
        return y < 0 || x < 0 || y >= N || x >= M || map[y][x] > 0;
    }
} dir[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void bfs(pos start)
{
    int cnt = 1;

    queue<pos> q;
    q.push(start);
    groupMap[start.y][start.x] = ++groupIdx;
    while (!q.empty())
    {
        pos cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            pos next = dir[i] + cur;
            if (next.isOut() || groupMap[next.y][next.x] != 0) // 범위를 벗어났는지 확인하고 이미 그룹 번호가 매겨졌는지 확인
            {
                continue;
            }
            groupMap[next.y][next.x] = groupIdx;
            ++cnt;

            q.push(next);
        }
    }
    groupSize.push_back(cnt); // 그룹의 영역을 저장해 준다.
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;
    map = groupMap = vector<vector<int>>(N, vector<int>(M));

    for (int y = 0; y < N; ++y)
    {
        string input;
        cin >> input;
        for (int x = 0; x < M; ++x)
        {
            map[y][x] = input[x] - '0';
        }
    }

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            if (map[y][x] == 0) // 벽이 아닌 경우는 확인해 볼 필요가 없다.
            {
                continue;
            }

            unordered_set<int> us;
            pos cur = {y, x};

            for (int i = 0; i < 4; ++i)
            {
                pos next = dir[i] + cur;

                if (next.isOut()) // 범위를 벗어났는지 확인
                {
                    continue;
                }

                if (groupMap[next.y][next.x] == 0) // 그룹 번호가 없다면 탐색하지 않은 영역이므로 탐색한다.
                {
                    bfs(next);
                }
                us.insert(groupMap[next.y][next.x] - 1);
            }

            int sum = 0;
            for (int i : us) // 중복된 그룹은 무시한다.
            {
                sum += groupSize[i];
            }
            map[y][x] = sum + 1;
        }
    }

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            cout << map[y][x] % 10;
        }
        cout << "\n";
    }

    return 0;
}