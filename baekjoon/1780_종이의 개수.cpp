#include <iostream>
#include <vector>
using namespace std;
int N;
vector<vector<int>> map;
int cnt[3];
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    map = vector<vector<int>>(N, vector<int>(N));
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            cin >> map[y][x];
        }
    }
}
int check(const int &startY, const int &endY, const int &startX, const int &endX)
{
    int first = map[startY][startX];
    for (int y = startY; y < endY; ++y)
    {
        for (int x = startX; x < endX; ++x)
        {
            if (first != map[y][x]) // 만약 처음과 같은 값이 아니면
            {
                return 2;
            }
        }
    }
    return first;
}
void recur(const int &startY, const int &endY, const int &startX, const int &endX)
{
    int ret = check(startY, endY, startX, endX);

    if (ret == 2) // 만약 범위 내 모든 값이 같지 않다면
    {
        int gap = (endY - startY) / 3;
        for (int y = startY; y < endY; y += gap)
        {
            for (int x = startX; x < endX; x += gap)
            {
                recur(y, y + gap, x, x + gap);
            }
        }
    }
    else
    {
        ++cnt[ret + 1]; //-1~1 같을 0~2의 값으로
    }
}
int main()
{
    input();
    recur(0, N, 0, N);
    for (int ret : cnt)
    {
        cout << ret << "\n";
    }
    return 0;
}