#include <iostream>
using namespace std;

int N, M;
string words[10];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        cin >> words[i];
        M -= words[i].length();
    }

    int minUnderscore = M / (N - 1);

    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = 0; j < minUnderscore; ++j)
        {
            words[i] += '_';
        }
    }

    int remainUnderscore = M % (N - 1);

    for (int i = 1; i < N && remainUnderscore > 0; ++i)
    {
        if (words[i].front() >= 'a' && words[i].front() <= 'z')
        {
            words[i - 1] += '_';
            --remainUnderscore;
        }
    }

    for (int i = N - 1; i > 0 && remainUnderscore > 0; --i)
    {
        if (words[i].front() >= 'A' && words[i].front() <= 'Z')
        {
            words[i - 1] += '_';
            --remainUnderscore;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        cout << words[i];
    }
    return 0;
}