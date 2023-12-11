#include <iostream>
#include <stack>
using namespace std;
int N, P, n, p, ret;
stack<int> finger[7];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> P;
    while (N--)
    {
        cin >> n >> p;
        while (!finger[n].empty() && finger[n].top() > p) // 현재 프렛보다 높은 프렛들
        {
            ++ret;
            finger[n].pop();
        }
        if (!finger[n].empty() && finger[n].top() == p) // 현재 프렛과 다음 프렛이 같으면
        {
            continue;
        }
        finger[n].push(p);
        ++ret;
    }
    cout << ret;
    return 0;
}