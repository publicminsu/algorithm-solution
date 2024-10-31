#include <iostream>
using namespace std;
int N, R;
int M[101];
int S[101];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 0; i <= 100; ++i)
    {
        M[i] = -1;
    }
    cin >> N;
    for (int i = 0, e, n; i < N; ++i)
    {
        cin >> e >> n;
        M[e] = n;
    }
    cin >> R;
    for (int i = 0, L; i < R; ++i)
    {
        cin >> L;
        bool isDied = false;
        for (int j = 0; j < L; ++j)
        {
            cin >> S[j];
            if (M[S[j]] == -1)
            {
                isDied = true;
            }
        }

        if (isDied)
        {
            cout << "YOU DIED";
        }
        else
        {
            for (int j = 0; j < L; ++j)
            {
                cout << M[S[j]] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}