#include <iostream>
using namespace std;

int A, B, C, N, highestScore;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> A >> B >> C >> N;

    for (int i = 0; i < N; ++i)
    {
        int score = 0;

        for (int j = 0; j < 3; ++j)
        {
            int a, b, c;
            cin >> a >> b >> c;

            score += a * A + b * B + c * C;
        }

        highestScore = max(score, highestScore);
    }

    cout << highestScore;
    return 0;
}