#include <iostream>

using namespace std;

int T, n;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> n;

        int sum = 0;

        for (int i = 1; i <= n; ++i)
        {
            sum += (i * (i + 1) * (i + 2) / 2);
        }

        cout << sum << "\n";
    }
    return 0;
}