#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<ll, string> pis;
map<ll, bool> visted;
queue<pis> q;
ll s, t;
void push(ll num, string str)
{
    if (num > t || visted[num])
        return;
    visted[num] = true;
    if (num == t)
    {
        cout << str;
        exit(0);
    }
    q.push({num, str});
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> s >> t;
    if (s == t)
    {
        cout << 0;
        return 0;
    }
    else if ((s * s) == t)
    {
        cout << "*";
        return 0;
    }
    else if ((s << 1) == t)
    {
        cout << "+";
        return 0;
    }
    else if (t == 1)
    {
        cout << "/";
        return 0;
    }
    q.push({s * s, "*"});
    q.push({s << 1, "+"});
    q.push({1, "/"});
    visted[s] = visted[s * s] = visted[s << 1] = visted[1] = true;
    while (!q.empty())
    {
        pis cur = q.front();
        q.pop();
        push(cur.first * cur.first, cur.second + "*");
        push(cur.first << 1, cur.second + "+");
    }
    cout << -1;
    return 0;
}