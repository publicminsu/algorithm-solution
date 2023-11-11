#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b, R, time = 0;
    cin >> a >> b >> R;
    vector<vector<bool>> map(R, vector<bool>(R));
    map[a][b] = true;
    while (true)
    {
        ++time;
        if (a + b + 2 < R)
        {
            ++a;
            ++b;
        }
        else
        {
            a >>= 1;
            b >>= 1;
        }
        if (map[a][b]) // 이미 방문한 곳이라면
        {
            cout << time;
            break;
        }
        map[a][b] = true;
    }
}
