#include <iostream>
using namespace std;

int N;
int S[1000][1000];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> S[i][j];
        }
    }

    if (N == 2)
    {
        cout << "1 1";
    }
    else
    {
        int a1 = (S[0][1] + S[0][2] - S[1][2]) / 2;

        cout << a1;

        for (int i = 1; i < N; ++i)
        {
            cout << " " << S[0][i] - a1;
        }
    }

    return 0;
}