#include <iostream>
#include <queue>
using namespace std;
int N, answer, p, n;
priority_queue<int> pq;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> p;
    while (--N)
    {
        cin >> n;
        answer += p * n;
        p += n;
    }

    cout << answer;
    return 0;
}