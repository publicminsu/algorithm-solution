#include <iostream>

using namespace std;

char A[51][51], B[51][51];
int N, M;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> B[i][j];
        }
    }
}

void solve()
{
    int count = 0;

    for (int i = 0; i < N - 2; ++i)
    {
        for (int j = 0; j < M - 2; ++j)
        {
            if (A[i][j] == B[i][j])
            {
                continue;
            }

            ++count;

            for (int k = 0; k < 3; ++k)
            {
                for (int l = 0; l < 3; ++l)
                {
                    A[i + k][j + l] = (A[i + k][j + l] == '0' ? '1' : '0');
                }
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (A[i][j] == B[i][j])
            {
                continue;
            }

            cout << -1;
            return;
        }
    }

    cout << count;
}

int main()
{
    input();
    solve();
    return 0;
}