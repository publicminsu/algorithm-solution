#include <iostream>
using namespace std;
int arr[251][251][3]; // 기본, 최소, 최대
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

    while (K--)
    {
        int i, j, minNum = 251, maxNum = 0;
        cin >> i >> j;

        --i, --j;

        for (int k = 0; k < B; ++k)
        {
            minNum = min(minNum, arr[i + k][j][1]);
            maxNum = max(maxNum, arr[i + k][j][2]);
        }

        cout << (maxNum - minNum) << "\n";
    }
    return 0;
}