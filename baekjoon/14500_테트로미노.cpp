#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;
#define TetrominoLen 19
int N, M, answer;
vector<vector<int>> map;
pii tetromino[TetrominoLen][4] = {
    // 정사각형
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    // 직선
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    // 가로 기억
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    {{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    {{0, 0}, {0, 1}, {0, 2}, {-1, 0}},
    // 세로 기억
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {2, -1}},
    {{0, 0}, {1, 0}, {2, 0}, {0, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {0, -1}},
    // ㄹ
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 0}, {1, 0}, {1, -1}, {2, -1}},
    // ㅜ
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {-1, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {1, -1}},
};

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    map = vector<vector<int>>(N, vector<int>(M));
    for (vector<int> &line : map)
    {
        for (int &num : line)
        {
            cin >> num;
        }
    }
}

bool isPossible(int tetrominoIdx, int y, int x)
{
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + tetromino[tetrominoIdx][i].first;
        int nx = x + tetromino[tetrominoIdx][i].second;
        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
        {
            return false;
        }
    }
    return true;
}

int getSum(int tetrominoIdx, int y, int x)
{
    int sum = 0;
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + tetromino[tetrominoIdx][i].first;
        int nx = x + tetromino[tetrominoIdx][i].second;

        sum += map[ny][nx];
    }
    return sum;
}

void solve()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            for (int k = 0; k < TetrominoLen; ++k)
            {
                if (!isPossible(k, i, j))
                {
                    continue;
                }
                answer = max(answer, getSum(k, i, j));
            }
        }
    }
}
int main()
{
    input();
    solve();
    cout << answer;
    return 0;
}