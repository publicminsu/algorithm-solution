#include <iostream>
using namespace std;

int N, D, K, answer;
int maxStarPerDay;
int starCnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> D >> K;

    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;
        maxStarPerDay = max(maxStarPerDay, j);
    }
    while (D--)
    {
        starCnt += maxStarPerDay;
        if (starCnt > K)
        {
            starCnt = maxStarPerDay;
            ++answer;
        }
    }

    cout << answer;
}