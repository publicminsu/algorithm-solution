#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> map;
vector<vector<vector<int>>> nodeMap;
int N, K;
struct position
{
    int y, x;
    const position operator+(const position &other) const
    {
        return {y + other.y, x + other.x};
    }
    const bool isOut() const // 범위를 벗어났거나 파란색인 경우
    {
        return y < 0 || x < 0 || y >= N || x >= N || map[y][x] == 2;
    }
} dir[] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
struct node
{
    position pos;
    int dir;
    void changeDir() // 방향 반대로 변경
    {
        switch (dir)
        {
        case 0:
            dir = 1;
            break;
        case 1:
            dir = 0;
            break;
        case 2:
            dir = 3;
            break;
        case 3:
            dir = 2;
            break;
        }
    }
};
vector<node> nodes;
void input()
{
    cin >> N >> K;
    map = vector<vector<int>>(N, vector<int>(N));
    nodeMap = vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>()));
    nodes = vector<node>(K);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < K; ++i)
    {
        cin >> nodes[i].pos.y >> nodes[i].pos.x >> nodes[i].dir;
        --nodes[i].pos.y, --nodes[i].pos.x, --nodes[i].dir;   // 0부터 시작하게 수정
        nodeMap[nodes[i].pos.y][nodes[i].pos.x].push_back(i); // 말을 놓기
    }
}
bool move()
{
    for (int i = 0; i < K; ++i)
    {
        node &n = nodes[i];
        position nextPos = n.pos + dir[n.dir];

        if (nextPos.isOut())
        {
            n.changeDir();
            nextPos = n.pos + dir[n.dir];

            if (nextPos.isOut()) // 방향을 바꿨음에도 범위를 벗어났거나 파란색인 경우
            {
                continue;
            }
        }

        vector<int> &group = nodeMap[n.pos.y][n.pos.x]; // 해당 좌표에 쌓인 모든 말들

        auto iter = find(group.begin(), group.end(), i);                          // 내 말의 위치
        vector<int> myGroup = vector<int>(iter, nodeMap[n.pos.y][n.pos.x].end()); // 내 말을 포함하여 쌓인 말들
        group.erase(iter, group.end());                                           // 내 말을 포함하여 쌓인 말들 제거

        if (map[nextPos.y][nextPos.x] == 1) // 만약 빨간색인 경우
        {
            reverse(myGroup.begin(), myGroup.end()); // 쌓여있는 순서 반대로 바꾸기
        }

        for (int j : myGroup)
        {
            nodes[j].pos = nextPos;                     // 위치 변경
            nodeMap[nextPos.y][nextPos.x].push_back(j); // 쌓기
        }

        if (nodeMap[nextPos.y][nextPos.x].size() >= 4) // 4개 이상 쌓인 경우
        {
            return true;
        }
    }
    return false;
}
int main()
{
    input();
    for (int i = 1; i <= 1000; ++i) // 1000 이하
    {
        if (move())
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}