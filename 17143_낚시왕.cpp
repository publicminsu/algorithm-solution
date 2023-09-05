#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
typedef tuple<int, int, int, int, int> shark; // 행, 열, 속력, 방향, 크기
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, 1, -1}, R, C, M, ret;
vector<vector<int>> map;
vector<shark> sharks, buffer;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> R >> C >> M;
    map = vector<vector<int>>(R, vector<int>(C, -1));
    int r, c, s, d, z, twiceR = R - 1 << 1, twiceC = C - 1 << 1;
    while (M--)
    {
        cin >> r >> c >> s >> d >> z;
        --r, --c, --d;
        if (r == 0 && d == 0) // 위로 가려는 것
            d = 1;
        else if (r == R - 1 && d == 1)
            d = 0;
        else if (c == C - 1 && d == 2)
            d = 3;
        else if (c == 0 && d == 3)
            d = 2;
        if (d < 2) // 제자리로 가는 비용은 줄인다.
            s %= twiceR;
        else
            s %= twiceC;
        map[r][c] = buffer.size();
        buffer.push_back({r, c, s, d, z});
    }
}
void move()
{
    for (auto &m : map)
        fill(m.begin(), m.end(), -1);
    for (int i = 0; i < sharks.size(); ++i)
    {
        shark cur = sharks[i];
        int r = get<0>(cur);
        int c = get<1>(cur);
        int s = get<2>(cur);
        int d = get<3>(cur);
        int z = get<4>(cur);
        if (d < 2) // 위, 아래
        {
            for (int i = 0; i < s; ++i)
            {
                r += dy[d];
                if (r == 0)
                    d = 1;
                else if (r == R - 1)
                    d = 0;
            }
            get<0>(cur) = r;
        }
        else // 오른쪽, 왼쪽
        {
            for (int i = 0; i < s; ++i)
            {
                c += dx[d];
                if (c == 0)
                    d = 2;
                else if (c == C - 1)
                    d = 3;
            }
            get<1>(cur) = c;
        }
        get<3>(cur) = d;
        if (map[r][c] != -1) // 만약 해당 좌표에 이미 값이 존재한다면
        {
            shark next = buffer[map[r][c]];
            if (get<4>(next) > z) // 기존 상어의 값이 더 크다면 무시
                continue;
            get<2>(next) = s;
            get<3>(next) = d;
            get<4>(next) = z;
            buffer[map[r][c]] = next;
        }
        else // 해당 좌표에 값이 존재하지 않는다면
        {
            map[r][c] = buffer.size();
            buffer.push_back(cur);
        }
    }
}
void solve()
{
    for (int i = 0; i < C; ++i)
    {
        for (int j = 0; j < R; ++j)
            if (map[j][i] != -1)
            {
                int idx = map[j][i];
                ret += get<4>(buffer[idx]);
                buffer.erase(buffer.begin() + idx);
                break;
            }
        sharks.clear();
        sharks.swap(buffer);
        move();
    }
    cout << ret;
}
int main()
{
    input();
    solve();
    return 0;
}