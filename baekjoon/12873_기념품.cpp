#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
queue<int> q;
int N;
ll step = 1;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        q.push(i);
    }

    while (q.size() != 1)
    {
        ll cnt = step * step * step++;

        cnt %= q.size();

        if (!cnt)
        {
            cnt = q.size();
        }

        while (--cnt)
        {
            q.push(q.front());
            q.pop();
        }

        q.pop();
    }

    cout << q.front();
    return 0;
}