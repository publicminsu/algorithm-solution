#include <iostream>
using namespace std;
int T, M, N, x, y;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> M >> N >> x >> y;

        while (true)
        {
            if (x == y)
            {
                cout << x << "\n";
                break;
            }
            else if (x > M * N)
            {
                cout << -1 << "\n";
                break;
            }

            if (x < y)
            {
                x += M;
            }
            else
            {
                y += N;
            }
        }
    }
    return 0;
}