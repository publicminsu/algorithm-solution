#include <iostream>
using namespace std;

int N, answer;
char X[10000000];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> X[i];
    }

    for (int i = N - 1; i >= 1; --i)
    {
        if (answer)
        {
            if (X[i] == '0')
            {
                ++answer;
            }
        }
        else
        {
            if (X[i] == '1')
            {
                answer = 1;
            }
        }
    }

    cout << answer;
    return 0;
}