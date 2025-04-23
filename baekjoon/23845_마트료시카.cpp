#include <iostream>
#include <algorithm>
using namespace std;

int N;
int X[200000], cntArr[100002];
long long answer;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> X[i];
        ++cntArr[X[i]];
    }

    sort(X, X + N);

    for (int i = 0; i < N; ++i)
    {
        int x = X[i];

        if (!cntArr[x])
        {
            continue;
        }

        --cntArr[x];
        long long cnt = 1;

        for (int j = x + 1;; ++j)
        {
            if (cntArr[j])
            {
                --cntArr[j];
                ++cnt;
            }
            else
            {
                answer += cnt * (j - 1);
                break;
            }
        }
    }

    cout << answer;

    return 0;
}