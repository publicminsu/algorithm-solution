#include <iostream>
using namespace std;
int N, M, K, answer;

int gcd(int a, int b)
{
    if (!b)
    {
        return a;
    }

    return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i <= N; ++i)
    {
        for (int j = 0; j <= M; ++j)
        {
            for (int k = 0; k <= N; ++k)
            {
                for (int l = 0; l <= M; ++l)
                {
                    if (abs(gcd(k - i, l - j)) + 1 == K)
                    {
                        ++answer;
                    }
                }
            }
        }
    }

    cout << answer / 2;
    return 0;
}