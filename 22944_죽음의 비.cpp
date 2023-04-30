#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
vector<pii> umb;
vector<bool> visted;
pii start, target;
int N, H, D, ret = 60001;
int abs(int num)
{
    return num < 0 ? -num : num;
}
int min(int num1, int num2)
{
    return num1 < num2 ? num1 : num2;
}
int getLen(pii p1, pii p2)
{
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
bool checkEnd(pii cur, int hp, int cnt)
{
    int len = getLen(cur, target);
    if (hp > len - 1)
    {
        ret = min(ret, cnt + len);
        return true;
    }
    return false;
}
void dfs(pii cur, int hp, int cnt)
{
    if (checkEnd(cur, hp + D - 1, cnt))
        return;
    for (int i = 0; i < umb.size(); ++i)
    {
        if (visted[i])
            continue;
        pii u = umb[i];
        int len = getLen(cur, u);
        if (hp + D < len)
            continue;
        visted[i] = true;
        if (D > len) // 내구도 안에 도착하는 경우
        {
            dfs(u, hp, cnt + len);
        }
        else
        {
            dfs(u, hp - (len - D), cnt + len);
        }
        visted[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    char ch;
    cin >> N >> H >> D;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> ch;
            if (ch == 'U')
                umb.push_back({i, j});
            else if (ch == 'S')
                start = {i, j};
            else if (ch == 'E')
                target = {i, j};
        }
    if (checkEnd(start, H, 0)) // 우산을 거칠 필요 없이 도착했는가?
    {
        cout << ret;
        return 0;
    };
    visted = vector<bool>(umb.size());
    for (int i = 0; i < umb.size(); ++i)
    {
        pii u = umb[i];
        int len = getLen(start, u);
        if (H < len)
            continue;
        visted[i] = true;
        dfs(u, H - (len - 1), len);
        visted[i] = false;
    }
    if (ret == 60001)
        ret = -1;
    cout << ret;
    return 0;
}