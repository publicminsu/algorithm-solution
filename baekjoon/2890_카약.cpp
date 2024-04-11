#include <iostream>
#include <vector>
using namespace std;
int R, C;
vector<string> map;
int ranks[10];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> R >> C;
    map = vector<string>(R);
    for (string &s : map)
    {
        cin >> s;
    }

    for (int i = 1, cnt = 1; i < C; ++i)
    {
        bool isFind = false;
        for (int j = 0; j < R; ++j)
        {
            if (map[j][C - i] <= '9' && map[j][C - i] >= '1' && !ranks[map[j][C - i] - '0'])
            {
                isFind = true;
                ranks[map[j][C - i] - '0'] = cnt;
            }
        }
        cnt += isFind;
    }

    for (int i = 1; i <= 9; ++i)
    {
        cout << ranks[i] << "\n";
    }
    return 0;
}