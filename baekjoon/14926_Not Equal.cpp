#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool>> v;
int N;

void solve()
{
    int target = 1;

    v[1][N] = v[N][1] = true;

    for (int i = 1; i <= (N * (N - 1) / 2); ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (j == target || v[target][j])
            {
                continue;
            }

            cout << "a" << target << " ";

            v[target][j] = v[j][target] = true;

            target = j;

            break;
        }
    }

    cout << "a" << target << " ";

    cout << "a1";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    v = vector<vector<bool>>(N + 1, vector<bool>(N + 1));

    solve();

    return 0;
}