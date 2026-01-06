#include <iostream>
using namespace std;

int T, N, K;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> N >> K;

        if (K == 1)
        {
            if (N <= 3)
            {
                cout << -1;
            }
            else
            {
                for (int i = 2; i <= N; i += 2)
                {
                    cout << i << " ";
                }
                for (int i = 1; i <= N; i += 2)
                {
                    cout << i << " ";
                }
            }
        }
        else
        {
            for (int i = 1; i <= N; ++i)
            {
                cout << i << " ";
            }
        }

        cout << "\n";
    }
    return 0;
}