#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int N;
int values[5000];
int answer[3];
ll answerSum = 3000000000;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> values[i];
    }
}

void updateAnswer(int buffer[3])
{
    if ((buffer[1] == buffer[2]) || (buffer[0] == buffer[2]))
    {
        return;
    }

    ll sum = 0;

    for (int i = 0; i < 3; ++i)
    {
        sum += buffer[i];
    }

    sum = abs(sum);

    if (sum < answerSum)
    {
        answerSum = sum;

        for (int i = 0; i < 3; ++i)
        {
            answer[i] = buffer[i];
        }
    }
}

void solve()
{
    sort(values, values + N);

    int buffer[3];

    for (int i = 0; i < N - 1; ++i)
    {
        buffer[0] = values[i];

        for (int j = i + 1; j < N; ++j)
        {
            buffer[1] = values[j];

            int target = -(buffer[0] + buffer[1]);

            int idx = lower_bound(values + j, values + N, target) - values;

            if (idx > 0)
            {
                buffer[2] = values[idx - 1];
                updateAnswer(buffer);
            }

            if (idx != N)
            {
                buffer[2] = values[idx];
                updateAnswer(buffer);
            }
        }
    }

    sort(answer, answer + 3);

    for (int i : answer)
    {
        cout << i << " ";
    }
}

int main()
{
    input();
    solve();
    return 0;
}