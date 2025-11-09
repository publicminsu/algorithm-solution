#include <iostream>

using namespace std;

int N, cnt;
string map;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> map;
    for (int i = 1; i < N; ++i)
    {
        if (map[i] == 'W' && map[i - 1] == 'E')
        {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}
