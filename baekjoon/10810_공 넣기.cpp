#include <iostream>

using namespace std;

int N, M;
int balls[100];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    while (M--)
    {
        int i, j, k;
        cin >> i >> j >> k;

        --i;

        while (i < j)
        {
            balls[i] = k;
            ++i;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        cout << balls[i] << " ";
    }
    return 0;
}