#include <iostream>
using namespace std;
int C, N;
int scores[1000];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cout << fixed;
    cout.precision(3);

    cin >> C;

    while (C--)
    {
        cin >> N;

        double avg = 0;

        for (int i = 0; i < N; ++i)
        {
            cin >> scores[i];
            avg += scores[i];
        }

        avg /= N;

        int cnt = 0;

        for (int i = 0; i < N; ++i)
        {
            if (avg < scores[i])
            {
                ++cnt;
            }
        }

        double result = (double)cnt / N * 100;

        cout << result << "%\n";
    }
    return 0;
}