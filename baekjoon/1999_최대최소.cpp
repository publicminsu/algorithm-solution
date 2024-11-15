#include <iostream>
using namespace std;
int arr[251][251][5]; // 기본, 가로 최소, 가로 최대, 최소, 최대
int N, B, K;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> B >> K;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> arr[i][j][0];
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= N - B; ++j)
        {
            arr[i][j][2] = arr[i][j][1] = arr[i][j][0];

            for (int k = 1; k < B; ++k)
            {
                arr[i][j][1] = min(arr[i][j][1], arr[i][j + k][0]);
                arr[i][j][2] = max(arr[i][j][2], arr[i][j + k][0]);
            }
        }
    }

    for (int i = 0; i <= N - B; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            arr[i][j][3] = arr[i][j][1];
            arr[i][j][4] = arr[i][j][2];

            for (int k = 1; k < B; ++k)
            {
                arr[i][j][3] = min(arr[i][j][3], arr[i + k][j][1]);
                arr[i][j][4] = max(arr[i][j][4], arr[i + k][j][2]);
            }
        }
    }

    while (K--)
    {
        int i, j;
        cin >> i >> j;
        --i, --j;

        cout << (arr[i][j][4] - arr[i][j][3]) << "\n";
    }
    return 0;
}