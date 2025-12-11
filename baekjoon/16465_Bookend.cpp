#include <iostream>
using namespace std;

int N, M, L;
int bookWidthSum;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> L;
    for (int i = 0; i < N; ++i)
    {
        int width;
        cin >> width;
        bookWidthSum += width;
    }
}

int solve()
{
    if (bookWidthSum > M)
    {
        return -1;
    }

    if (M == bookWidthSum)
    {
        return 0;
    }

    if (bookWidthSum >= L)
    {
        return 1;
    }

    if (M - bookWidthSum >= L)
    {
        return 1;
    }

    return -1;
}

int main()
{
    input();
    cout << solve();
    return 0;
}