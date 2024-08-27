#include <iostream>
using namespace std;
int T, k, n;
int arr[15];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> k >> n;

        for (int i = 0; i < n; ++i)
        {
            arr[i] = i + 1;
        }

        while (k--)
        {
            for (int i = 1; i < n; ++i)
            {
                arr[i] += arr[i - 1];
            }
        }

        cout << arr[n - 1] << "\n";
    }
    return 0;
}