#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
struct node
{
    ll num;
    int cnt;
};
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int A, B;
    cin >> A >> B;
    queue<node> q;
    q.push({A, 1});
    while (!q.empty())
    {
        node cur = q.front();
        if (cur.num == B)
        {
            cout << cur.cnt;
            return 0;
        }
        q.pop();
        // 2를 곱한다.
        ll next1 = cur.num << 1;
        if (next1 <= B)
            q.push({next1, cur.cnt + 1});
        // 1을 수의 가장 오른쪽에 추가한다.
        ll next2 = cur.num * 10 + 1;
        if (next2 <= B)
        {
            q.push({next2, cur.cnt + 1});
        }
    }
    cout << -1;
    return 0;
}