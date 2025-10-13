#include <iostream>
#include <deque>
using namespace std;

int N, M, R;
int map[301][301];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> R;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];
        }
    }
}

void rotate()
{
    for (int i = 0; i < min(N, M) / 2; ++i)
    {
        deque<int> dq;

        int rightEnd = M - i;
        int upEnd = N - i;

        for (int j = i; j < rightEnd; ++j)
        {
            dq.push_back(map[i][j]);
        }

        for (int j = i + 1; j < upEnd - 1; ++j)
        {
            dq.push_back(map[j][rightEnd - 1]);
        }

        for (int j = rightEnd - 1; j >= i; --j)
        {
            dq.push_back(map[upEnd - 1][j]);
        }

        for (int j = upEnd - 2; j > i; --j)
        {
            dq.push_back(map[j][i]);
        }

        for (int j = 0; j < R % dq.size(); ++j)
        {
            dq.push_back(dq.front());
            dq.pop_front();
        }

        for (int j = i; j < rightEnd; ++j)
        {
            map[i][j] = dq.front();
            dq.pop_front();
        }

        for (int j = i + 1; j < upEnd - 1; ++j)
        {
            map[j][rightEnd - 1] = dq.front();
            dq.pop_front();
        }

        for (int j = rightEnd - 1; j >= i; --j)
        {
            map[upEnd - 1][j] = dq.front();
            dq.pop_front();
        }

        for (int j = upEnd - 2; j > i; --j)
        {
            map[j][i] = dq.front();
            dq.pop_front();
        }
    }
}

void print()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    input();
    rotate();
    print();
    return 0;
}