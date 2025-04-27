#include <iostream>
#include <vector>
using namespace std;

int N;
int mValues[4];
int values[15][5];
vector<int> answer;

bool isSatisfied(vector<int> v)
{
    for (int i = 0; i < 4; ++i)
    {
        if (v[i] < mValues[i])
        {
            return false;
        }
    }

    return true;
}

int calcLen(int value)
{
    int len = 0;
    while (value)
    {
        value >>= 1;
        ++len;
    }
    return len;
}

void updateAnswer(vector<int> v)
{
    if (answer.empty() || answer[4] > v[4])
    {
        answer = v;
    }
    else if (answer[4] == v[4])
    {
        int x = answer[5];
        int y = v[5];

        while (x && y)
        {
            bool xValue = x & 1;
            bool yValue = y & 1;

            if (xValue && !yValue)
            {
                return;
            }
            else if (yValue && !xValue)
            {
                answer = v;
                return;
            }

            x >>= 1;
            y >>= 1;
        }

        if (x)
        {
            answer = v;
        }
    }
}

void comb(int index, vector<int> v)
{
    if (index == N)
    {
        if (!isSatisfied(v))
        {
            return;
        }

        updateAnswer(v);

        return;
    }

    comb(index + 1, v);

    for (int i = 0; i < 5; ++i)
    {
        v[i] += values[index][i];
    }

    v[5] |= (1 << index);

    comb(index + 1, v);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < 4; ++i)
    {
        cin >> mValues[i];
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> values[i][j];
        }
    }

    comb(0, vector<int>(6));

    if (answer.empty())
    {
        cout << -1;
    }
    else
    {
        cout << answer[4] << "\n";

        int x = answer[5];
        int index = 1;

        while (x)
        {
            if (x & 1)
            {
                cout << index << " ";
            }

            ++index;
            x >>= 1;
        }
    }
    return 0;
}