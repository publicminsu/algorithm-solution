#include <iostream>
using namespace std;

int N, answer, evenOddCheck = -1;
int temp[100000];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> temp[i];
    }

    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;

        temp[i] -= j;
    }

    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;

        if (temp[i] % j)
        {
            cout << -1;
            return 0;
        }

        int value = abs(temp[i] / j);

        if (evenOddCheck == -1)
        {
            evenOddCheck = value % 2;
        }
        else
        {
            if (value % 2 != evenOddCheck)
            {
                cout << -1;
                return 0;
            }
        }

        answer = max(answer, value);
    }

    cout << answer;
    return 0;
}