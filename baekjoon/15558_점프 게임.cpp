#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int y, x, time;
};

int N, k;
string map[2];
bool isVisited[2][100000];
queue<node> q;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> k;
    for (int i = 0; i < 2; ++i)
    {
        cin >> map[i];
    }
}

bool push(node nextNode)
{
    if (nextNode.x >= N)
    {
        return true;
    }

    if (isVisited[nextNode.y][nextNode.x])
    {
        return false;
    }

    if (map[nextNode.y][nextNode.x] == '0')
    {
        return false;
    }

    if (nextNode.time > nextNode.x)
    {
        return false;
    }

    isVisited[nextNode.y][nextNode.x] = true;
    q.push(nextNode);

    return false;
}

bool isClearable()
{
    q.push({0, 0, 0});

    while (!q.empty())
    {
        node curNode = q.front();
        q.pop();

        if (push({(curNode.y + 1) % 2, curNode.x + k, curNode.time + 1}) ||
            push({curNode.y, curNode.x + 1, curNode.time + 1}) ||
            push({curNode.y, curNode.x - 1, curNode.time + 1}))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    input();
    cout << isClearable();
    return 0;
}