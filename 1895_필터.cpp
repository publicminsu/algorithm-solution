#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1, 0};
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int R, C, T, ret = 0;
    cin >> R >> C;
    vector<vector<int>> map(R, vector<int>(C));
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> map[i][j];
    cin >> T;
    for (int i = 1; i < R - 1; ++i)
        for (int j = 1; j < C - 1; ++j)
        {
            vector<int> v;
            for (int k = 0; k < 9; ++k)
                v.push_back(map[i + dy[k]][j + dx[k]]);
            sort(v.begin(), v.end());
            if (v[4] >= T) // 9개의 정렬된 값 중 중간값 인덱스는 4이다
                ++ret;
        }
    cout << ret;
    return 0;
}