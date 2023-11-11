#include <iostream>
#include <vector>
using namespace std;
int N, M;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    vector<vector<int>> v(N + 1, vector<int>(2, -1));
    while (M--)
    {
        int a, c;
        char b;
        cin >> a >> b >> c;
        if (b == 'P') // 광합성인 경우
        {
            v[a][0] = c;
        }
        else // 운동성인 경우
        {
            v[a][1] = c;
        }
    }
    int min = 0, max = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (v[i][0] != 0 && v[i][1] != 1) // 광합성을 하지 않는 경우가 아니면서 운동성이 있는 경우가 아닌 것
        {
            ++max;
            if (v[i][0] == 1 && v[i][1] == 0) // 광합성을 하고 운동성이 없는 경우
            {
                ++min;
            }
        }
    }
    cout << min << " " << max;
    return 0;
}