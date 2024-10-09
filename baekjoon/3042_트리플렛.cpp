#include <iostream>
#include <vector>
using namespace std;
vector<char> v;
int N, NN, answer;

float calc(int a, int b)
{
    int ay = a / N;
    int ax = a % N;

    int by = b / N;
    int bx = b % N;

    float dy = ay - by;
    float dx = ax - bx;

    if (dx)
    {
        return dy / dx;
    }
    else
    {
        return 1;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    NN = N * N;

    v = vector<char>(NN);

    for (char &c : v)
    {
        cin >> c;
    }

    for (int i = 0; i < NN; ++i)
    {
        if (v[i] == '.')
        {
            continue;
        }

        for (int j = i + 1; j < NN; ++j)
        {
            if (v[j] == '.')
            {
                continue;
            }

            float d = calc(i, j);

            for (int k = j + 1; k < NN; ++k)
            {
                if (v[k] == '.')
                {
                    continue;
                }

                if (d == calc(j, k) && d == calc(i, k))
                {
                    ++answer;
                }
            }
        }
    }

    cout << answer;

    return 0;
}