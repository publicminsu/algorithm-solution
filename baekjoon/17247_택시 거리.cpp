#include <iostream>
using namespace std;
int N, M;
int x1 = -1, y1, k;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> k;
            if (k)
            {
                if (x1 == -1)
                {
                    y1 = i;
                    x1 = j;
                }
                else
                {
                    cout << abs(i - y1) + abs(j - x1);
                    break;
                }
            }
        }
    }
    return 0;
}