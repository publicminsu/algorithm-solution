#include <iostream>

using namespace std;

int N, M;
int balls[101];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        balls[i] = i;
    }

    while (M--)
    {
        int i, j;
        cin >> i >> j;

        swap(balls[i], balls[j]);
    }

    for (int i = 1; i <= N; ++i)
    {
        cout << balls[i] << " ";
    }
    return 0;
}