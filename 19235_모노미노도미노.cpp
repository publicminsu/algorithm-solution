#include <iostream>
using namespace std;
int map[2][6][4]; // false은 초록, true은 파랑
int ret;
// 타입 확인 (끊기는 경우도 있음 그럴 경우 1로 반환)
int checkType(bool isBlue, int x, int y)
{
    if (y + 1 < 4 && map[isBlue][x][y] == map[isBlue][x][y + 1])
        return 2;
    else if (x - 1 >= 0 && map[isBlue][x][y] == map[isBlue][x - 1][y])
        return 3;
    else
        return 1;
}
// 블록 설치해주기
void setBlock(bool isBlue, int x, int y, int t, int idx)
{
    map[isBlue][x][y] = idx;
    if (t == 2)
        map[isBlue][x][y + 1] = idx;
    else if (t == 3)
        map[isBlue][x - 1][y] = idx;
}
// 밑으로 내려가기
void drop(bool isBlue, int x, int y, int t, int idx)
{
    for (int i = x; i < 6; ++i)
    {
        if (map[isBlue][i][y]) // 해당 위치에 블럭이 있다면 이전 높이에 설치
        {
            --i;
            setBlock(isBlue, i, y, t, idx);
            return;
        }
        else if (t == 2 && map[isBlue][i][y + 1]) // 가로가 긴 경우
        {
            --i;
            setBlock(isBlue, i, y, t, idx);
            return;
        }
    }
    setBlock(isBlue, 5, y, t, idx);
}
// 삭제 후 위의 블럭들 타입 유지하여 밑으로 내리기
void remove(bool isBlue, int x)
{
    for (int i = 0; i < 4; ++i)
        map[isBlue][x][i] = 0;
    for (int i = x - 1; i >= 0; --i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (!map[isBlue][i][j])
                continue;
            int idx = map[isBlue][i][j];
            int type = checkType(isBlue, i, j);
            map[isBlue][i][j] = 0;
            if (type == 2)
                map[isBlue][i][j + 1] = 0;
            else if (type == 3)
                map[isBlue][i - 1][j] = 0;
            drop(isBlue, i, j, type, idx);
        }
    }
}
// 한 줄이 가득찬지 확인
void checkFull(bool isBlue)
{
    for (int i = 0; i < 6; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < 4; ++j)
            if (map[isBlue][i][j])
                ++cnt;
        if (cnt == 4)
        {
            ++ret;
            remove(isBlue, i);
        }
    }
}
// 확인 후 가장 밑에 값 삭제
void checkLimit(bool isBlue)
{
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j < 4; ++j)
            if (map[isBlue][i][j])
                remove(isBlue, 5);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, t, x, y, idx = 0, cnt = 0;
    cin >> N;
    while (N--)
    {
        cin >> t >> x >> y;
        drop(false, 0, y, t, ++idx);
        if (t == 1)
            drop(true, 0, x, 1, idx);
        else if (t == 2)
            drop(true, 0, x, 3, idx);
        else
            drop(true, 0, x, 2, idx);
        checkFull(false);
        checkFull(true);
        checkLimit(false);
        checkLimit(true);
    }
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 6; ++j)
            for (int k = 0; k < 4; ++k)
                if (map[i][j][k])
                    ++cnt;
    cout << ret << "\n"
         << cnt;
    return 0;
}