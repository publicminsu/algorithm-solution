#include <iostream>
using namespace std;

int T, N;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N;

        int cnt = 0;

        if (N == 1)
        {
            cnt = 1;
        }
        else
        {

            for (int i = 9; i >= 2; --i)
            {
                while (N % i == 0)
                {
                    N /= i;
                    ++cnt;
                }
            }

            if (N > 1)
            {
                cnt = -1;
            }
        }

        cout << cnt << "\n";
    }
    return 0;
}