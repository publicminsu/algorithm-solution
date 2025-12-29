#include <iostream>

using namespace std;

int N, M;
int table[50][50];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> table[i][j];
        }
    }
}

void sort()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            if (table[i][0] > table[j][0])
            {
                swap(table[i], table[j]);
            }
        }
    }

    for (int i = 0; i < M; ++i)
    {
        for (int j = i + 1; j < M; ++j)
        {
            if (table[0][i] > table[0][j])
            {
                for (int k = 0; k < N; ++k)
                {
                    swap(table[k][i], table[k][j]);
                }
            }
        }
    }
}

bool isSorted()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (table[i][j] != i * M + j + 1)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    input();
    sort();
    cout << isSorted();
    return 0;
}