#include <iostream>
#include <vector>
using namespace std;
int answer, N, M;
int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};
vector<vector<int>> map;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    answer += ((N * M) << 1); // 윗면, 아랫면

    map = vector<vector<int>>(N, vector<int>(M));
    for (vector<int> &line : map)
    {
        for (int &num : line)
        {
            cin >> num;
        }
    }
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            const int &height = map[y][x];
            for (int d = 0; d < 4; ++d)
            {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M) // 범위를 벗어난다면
                {
                    answer += height;
                    continue;
                }

                int gap = height - map[ny][nx];
                if (gap > 0) // 다른 곳보다 높아서 겉넓이가 존재한다면
                {
                    answer += gap;
                }
            }
        }
    }
    cout << answer;
    return 0;
}