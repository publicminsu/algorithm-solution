#include <iostream>
using namespace std;

int N, M, K;
int x1, y1, x2, y2;
int prefixSum[1025][1025];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> prefixSum[i][j];
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            prefixSum[i][j] += prefixSum[i][j - 1];
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            prefixSum[i][j] += prefixSum[i - 1][j];
        }
    }

    cin >> K;

    while (K--)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        cout << (prefixSum[x2][y2] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1] + prefixSum[x1 - 1][y1 - 1]) << "\n";
    }

    return 0;
}