#include <iostream>
using namespace std;
int N, answer = 987654321;
int wall[999];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N - 2; ++i)
    {
        string line;
        cin >> line;

        for (int j = 0; j < 4; ++j)
        {
            if (line[j] == '0')
            {
                wall[i] = j;
                break;
            }
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        int sum = 0;

        for (int j = 0; j < N - 2; ++j)
        {
            int value = abs(wall[j] - i);

            if (value == 3)
            {
                value = 1;
            }

            sum += value;
        }

        answer = min(answer, sum);
    }

    answer += 2 + N;

    cout << answer;
    return 0;
}