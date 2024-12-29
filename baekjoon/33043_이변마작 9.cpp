#include <iostream>
#include <map>
#include <queue>
using namespace std;
#define INF 987654321
int N, answer = INF;
map<string, queue<int>> mq;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        string card;
        cin >> card;

        mq[card].push(i);

        if (mq[card].size() == 5)
        {
            int prev = mq[card].front();
            mq[card].pop();

            answer = min(answer, i - prev + 1);
        }
    }

    if (answer == INF)
    {
        answer = -1;
    }
    cout << answer;
    return 0;
}