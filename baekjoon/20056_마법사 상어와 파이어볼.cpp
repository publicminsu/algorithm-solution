#include <iostream>
#include <vector>
using namespace std;
struct fireball
{
    int m, s, d;
};
int N, M, K;
vector<vector<vector<fireball>>> map, temp;
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M >> K;

    map = temp = vector<vector<vector<fireball>>>(N, vector<vector<fireball>>(N, vector<fireball>()));
    while (M--)
    {
        int r, c;
        fireball f = {};

        cin >> r >> c >> f.m >> f.s >> f.d;

        map[--r][--c].push_back(f);
    }
}

void clearTemp()
{
    for (vector<vector<fireball>> &line : temp)
    {
        for (vector<fireball> &pos : line)
        {
            pos.clear();
        }
    }
}

void move()
{
    clearTemp();

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < map[i][j].size(); ++k)
            {
                fireball curFireBall = map[i][j][k];
                int ny = ((dy[curFireBall.d] + N) * curFireBall.s + i) % N;
                int nx = ((dx[curFireBall.d] + N) * curFireBall.s + j) % N;

                temp[ny][nx].push_back(curFireBall);
            }
        }
    }

    swap(map, temp);
}

void split()
{
    clearTemp();

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int size = map[i][j].size();
            if (size <= 1)
            {
                if (size == 1)
                {
                    temp[i][j].push_back(map[i][j][0]);
                }
                continue;
            }

            int m = 0, s = 0;
            bool isOdd = false;

            for (int k = 0; k < map[i][j].size(); ++k)
            {
                fireball curFireBall = map[i][j][k];

                m += curFireBall.m;
                s += curFireBall.s;

                if (k != 0 && (curFireBall.d % 2 != map[i][j][k - 1].d % 2))
                {
                    isOdd = true;
                }
            }

            m /= 5;

            if (m == 0)
            {
                continue;
            }

            s /= size;

            for (int k = 0; k <= 6; k += 2)
            {
                temp[i][j].push_back({m, s, k + isOdd});
            }
        }
    }

    swap(map, temp);
}

void print()
{
    int answer = 0;

    for (const vector<vector<fireball>> &line : map)
    {
        for (const vector<fireball> &pos : line)
        {
            for (const fireball &curFireBall : pos)
            {
                answer += curFireBall.m;
            }
        }
    }

    cout << answer;
}

int main()
{
    input();
    while (K--)
    {
        move();
        split();
    }
    print();
    return 0;
}