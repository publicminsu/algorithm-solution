#include <iostream>
#include <vector>
using namespace std;
int N, M, answer = 1;
vector<string> map;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    map = vector<string>(N);
    for (int y = 0; y < N; ++y)
    {
        cin >> map[y];
    }
}
bool isSquare(int width)
{
    for (int y = 0; y < N - width; ++y)
    {
        for (int x = 0; x < M - width; ++x)
        {
            if (map[y][x] == map[y][x + width] && map[y + width][x] == map[y + width][x + width] && map[y][x] == map[y + width][x]) // 꼭짓점이 같다면
            {
                return true;
            }
        }
    }
    return false;
}
void solve()
{
    for (int width = 1; width < min(N, M); ++width)
    {
        if (isSquare(width)) // 정사각형 있는지 확인
        {
            answer = width + 1;
        }
    }
    cout << answer * answer;
}
int main()
{
    input();
    solve();
    return 0;
}