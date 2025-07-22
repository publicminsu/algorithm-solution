#include <iostream>
#include <algorithm>
using namespace std;

int n, b, a, sum;
int prices[100001];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> b >> a;

    for (int i = 0; i < n; ++i)
    {
        cin >> prices[i];
    }

    sort(prices, prices + n);

    for (int i = 0; i < n; ++i)
    {
        sum += prices[i] / 2;

        if (i + 1 > a)
        {
            sum += prices[i - a] / 2;
        }

        if (sum > b)
        {
            cout << i;
            return 0;
        }
    }

    cout << n;
    return 0;
}