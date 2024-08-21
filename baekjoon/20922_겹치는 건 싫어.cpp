#include <iostream>
#include <queue>
using namespace std;
int N, K, a, count, answer;
int arr[100001];
queue<int> q;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;

    while (N--)
    {
        cin >> a;

        ++count;
        ++arr[a];

        while (arr[a] > K && q.size())
        {
            int i = q.front();
            q.pop();

            --arr[i];
            --count;
        }

        q.push(a);

        answer = max(answer, count);
    }

    cout << answer;
    return 0;
}