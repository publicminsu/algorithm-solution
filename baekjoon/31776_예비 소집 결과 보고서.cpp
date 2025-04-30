#include <iostream>
using namespace std;

int N, cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        bool check = false;
        int p = 0;

        for (int j = 0, k; j < 3; ++j)
        {
            cin >> k;

            if (j == 0 && k == -1)
            {
                check = true;
            }

            if (p == -1)
            {
                if (k != -1)
                {
                    check = true;
                }
            }
            else
            {
                if (k != -1 && p > k)
                {
                    check = true;
                }
            }

            p = k;
        }

        cnt += !check;
    }

    cout << cnt;
    return 0;
}