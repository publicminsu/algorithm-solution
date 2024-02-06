#include <iostream>
using namespace std;
bool map[100][100];
int paperLen, x, y, answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> paperLen;
    while (paperLen--)
    {
        cin >> x >> y;
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                map[i + y][j + x] = true;
            }
        }
    }
    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            if (map[i][j]) // 검은 영역 확인
            {
                ++answer;
            }
        }
    }
    cout << answer;
    return 0;
}