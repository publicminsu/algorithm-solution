#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> birds;
vector<int> sum;
int N, M, answerIndex, answerSound = 987654321;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    birds = vector<vector<int>>(N + 1, vector<int>(M));
    sum = vector<int>(M);

    for (int i = 1; i <= N; ++i)
    {
        char dir;
        string sound;

        cin >> dir >> sound;

        for (int j = 0; j < M; ++j)
        {
            if (sound[j] == '1')
            {
                int value = (dir == 'L') ? -1 : 1;

                birds[i][j] = value;
                sum[j] += value;
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        int total = 0, maxTotal = 0;

        for (int j = 0; j < M; ++j)
        {
            total += sum[j] - birds[i][j];

            maxTotal = max(maxTotal, abs(total));
        }

        if (maxTotal < answerSound)
        {
            answerIndex = i;
            answerSound = maxTotal;
        }
    }

    cout << answerIndex << "\n"
         << answerSound;
    return 0;
}