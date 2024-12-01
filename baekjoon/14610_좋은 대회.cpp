#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> map;
vector<int> K;
vector<bool> isSolved;
int N, M;
bool checkAll;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    map = vector<vector<int>>(N, vector<int>(M));
    K = vector<int>(N);
    isSolved = vector<bool>(M);

    for (int i = 0; i < N; ++i)
    {
        cin >> K[i];

        if (K[i] == 0 || K[i] == M)
        {
            checkAll = true;
        }

        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];

            if (map[i][j] == 1)
            {
                isSolved[j] = true;
                --K[i];
            }
        }
    }
}

bool solve()
{
    if (checkAll)
    {
        return false;
    }

    for (int i = N - 1; i >= 0; --i)
    {
        for (int j = M - 1; j >= 0; --j)
        {
            if (map[i][j] != -1 || K[i] == 0)
            {
                break;
            }

            if (isSolved[j])
            {
                continue;
            }

            --K[i];
            map[i][j] = 1;
            isSolved[j] = true;
        }
    }

    for (int i = 0; i < M; ++i)
    {
        if (!isSolved[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    input();
    cout << (solve() ? "YES" : "NO");
    return 0;
}