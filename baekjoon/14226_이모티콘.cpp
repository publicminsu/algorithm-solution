#include <iostream>
#include <queue>
using namespace std;
bool visted[1001][1001];
struct node
{
    int screen, clip, time;
};
queue<node> q;
int S;
void push(node next)
{
    if (next.screen < 0 || next.screen > 1000 || visted[next.screen][next.clip])
        return;
    else if (next.screen == S)
    {
        cout << next.time;
        exit(0);
    }
    visted[next.screen][next.clip] = true;
    q.push(next);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> S;
    if (S == 1)
    {
        cout << 0;
        return 0;
    }
    q.push({1, 0, 0});
    while (!q.empty())
    {
        node cur = q.front();
        q.pop();
        // 복사
        push({cur.screen, cur.screen, cur.time + 1});
        // 붙여넣기
        push({cur.screen + cur.clip, cur.clip, cur.time + 1});
        // 삭제
        push({cur.screen - 1, cur.clip, cur.time + 1});
    }
    return 0;
}