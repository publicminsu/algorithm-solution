#include <iostream>
using namespace std;
int n, d, cnt;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> d;

    for (int i = 1; i <= n; ++i)
    {
        int j = i;

        while (j)
        {
            if (j % 10 == d)
            {
                ++cnt;
            }

            j /= 10;
        }
    }

    cout << cnt;
    return 0;
}