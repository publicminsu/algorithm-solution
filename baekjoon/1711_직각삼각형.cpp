#include <iostream>
using namespace std;
using ll = long long;

int N, cnt;
int x[1500], y[1500];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> x[i] >> y[i];
    }
}

ll GetDistance(int i, int j)
{
    ll distX = x[i] - x[j];
    ll distY = y[i] - y[j];
    return distX * distX + distY * distY;
}

void solve()
{
    for (int i = 0; i < N - 2; ++i)
    {
        for (int j = i + 1; j < N - 1; ++j)
        {
            for (int k = j + 1; k < N; ++k)
            {
                ll a = GetDistance(i, j);
                ll b = GetDistance(i, k);
                ll c = GetDistance(j, k);

                if (a > c)
                {
                    swap(a, c);
                }

                if (b > c)
                {
                    swap(b, c);
                }

                if (a + b == c)
                {
                    ++cnt;
                }
            }
        }
    }
    cout << cnt;
}

int main()
{
    input();
    solve();
    return 0;
}