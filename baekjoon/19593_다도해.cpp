#include <iostream>
using namespace std;
using pic = pair<int, char>;

int T, N, Seed, A, B, cnt;
int parents[1000];

int find(int x)
{
    if (x == parents[x])
    {
        return x;
    }

    return parents[x] = find(parents[x]);
}

bool merge(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y)
    {
        return false;
    }

    if (x < y)
    {
        swap(x, y);
    }

    parents[x] = y;

    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> N >> Seed >> A >> B;

        for (int i = 0; i < N; ++i)
        {
            parents[i] = i;
        }

        cnt = 0;
        long long e = Seed % (N * N);
        int x = e / N;
        int y = e % N;
        cnt += merge(x, y);

        if (cnt == N - 1)
        {
            cout << "1\n";
            continue;
        }

        bool isFind = false;

        for (int i = 1; i < N * N; ++i)
        {
            e = (e * A + B) % (N * N);
            x = e / N;
            y = e % N;
            cnt += merge(x, y);

            if (cnt == N - 1)
            {
                cout << i + 1 << "\n";
                isFind = true;
                break;
            }
        }

        if (!isFind)
        {
            cout << "0\n";
        }
    }
    return 0;
}