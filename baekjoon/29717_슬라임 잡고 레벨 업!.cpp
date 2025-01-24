#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
int T;
ll N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N;

        ll sum = N * (N + 1) / 2;

        ll X = sqrt(sum);

        if (X * (X + 1) > sum)
        {
            --X;
        }

        cout << X + 1 << "\n";
    }
    return 0;
}