#include <iostream>
#include <algorithm>
using namespace std;
#define LIMIT 100000
int n;
int x[LIMIT], y[LIMIT];
long long sum;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
    }

    sort(x, x + n);
    sort(y, y + n);

    int midIndex = n / 2;
    int midX = x[midIndex];
    int midY = y[midIndex];

    for (int i = 0; i < n; ++i)
    {
        sum += abs(midX - x[i]);
        sum += abs(midY - y[i]);
    }

    cout << sum;
    return 0;
}