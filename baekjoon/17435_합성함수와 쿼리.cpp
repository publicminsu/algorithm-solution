#include <iostream>
#include <vector>
using namespace std;
#define LIMIT 19
vector<vector<int>> fx;
void init()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int m;
    cin >> m;

    fx = vector<vector<int>>(LIMIT, vector<int>(m + 1));

    for (int i = 1; i <= m; ++i)
    {
        cin >> fx[0][i];
    }
    for (int i = 1; i < LIMIT; ++i) // 다른 점의 값을 활용하여 2의 제곱 이동
    {
        for (int j = 1; j <= m; ++j)
        {
            int next = fx[i - 1][j];
            fx[i][j] = fx[i - 1][next];
        }
    }
}
void search()
{
    int Q;
    cin >> Q;
    while (Q--)
    {
        int n, x, jump = 0;
        cin >> n >> x;
        while (n)
        {
            if (n % 2) // 건너뛸 수 있는지 확인
            {
                x = fx[jump][x];
            }
            n >>= 1;
            ++jump; // 몇 제곱인지 확인
        }
        cout << x << "\n";
    }
}
int main()
{
    init();
    search();
    return 0;
}