#include <iostream>
using namespace std;
int N, M;
int matrix[101][101];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0, l; k < M; ++k)
            {
                cin >> l;
                matrix[j][k] += l;
            }
        }
    }

    for (int j = 0; j < N; ++j)
    {
        for (int k = 0, l; k < M; ++k)
        {
            cout << matrix[j][k] << " ";
        }
        cout << "\n";
    }
    return 0;
}