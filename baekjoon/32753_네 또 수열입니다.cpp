#include <iostream>

using namespace std;

int N, K;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    if (N != 1 && K != 1 || N > 2)
    {
        cout << -1;
    }
    else
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 0; j < K; ++j)
            {
                cout << i << " ";
            }
        }
    }
    return 0;
}