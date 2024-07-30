#include <iostream>
using namespace std;
int n, answer = 4;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    for (int i = 1; i * i <= n; ++i)
    {
        int sum1 = i * i;

        if (sum1 == n)
        {
            answer = 1;
            break;
        }

        for (int j = i; sum1 + j * j <= n; ++j)
        {
            int sum2 = sum1 + j * j;

            if (sum2 == n || answer == 2)
            {
                answer = 2;
                break;
            }

            for (int k = j; sum2 + k * k <= n; ++k)
            {
                int sum3 = sum2 + k * k;

                if (sum3 == n || answer == 3)
                {
                    answer = 3;
                    break;
                }
            }
        }
    }

    cout << answer;
    return 0;
}