#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, ret = INT_MIN;
    cin >> N >> M;
    vector<vector<int>> matrix(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> matrix[i][j];
            matrix[i][j] += matrix[i][j - 1];
        }
    }
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            matrix[i][j] += matrix[i - 1][j];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            for (int k = i + 1; k <= N; ++k)
                for (int l = j + 1; l <= M; ++l)
                {
                    int sum = matrix[k][l] - matrix[i][l] - matrix[k][j] + matrix[i][j];
                    ret = sum > ret ? sum : ret;
                }
    cout << ret;
    return 0;
}