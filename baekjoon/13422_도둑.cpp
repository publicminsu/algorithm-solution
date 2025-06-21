#include <iostream>
using namespace std;

int nums[100000];
int T, N, M, K, cnt, sum;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;

    while (T--)
    {
        cin >> N >> M >> K;

        for (int i = 0; i < N; ++i)
        {
            cin >> nums[i];
        }

        cnt = 0;
        sum = 0;

        for (int i = 0; i < M; ++i)
        {
            sum += nums[i];
        }

        if (M == N)
        {
            if (sum < K)
            {
                ++cnt;
            }
        }
        else
        {
            for (int i = 0; i < N; ++i)
            {
                if (sum < K)
                {
                    ++cnt;
                }

                int j = (M + i) % N;
                sum += nums[j];
                sum -= nums[i];
            }
        }

        cout << cnt << "\n";
    }
    return 0;
}