#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <deque>
using namespace std;

typedef tuple<int, int, int> tree; // 나이, 위치 (x, y)
vector<vector<int>> A, map;
vector<tree> dieTrees;
deque<tree> trees, nextTrees;

int dy[] = {1, -1, 0, 0, 1, 1, -1, -1}, dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int N, M, K;

void spring()
{
    for (auto it = trees.begin(); it != trees.end(); ++it)
    {
        tree t = *it;

        int age = get<0>(t);
        int x = get<1>(t);
        int y = get<2>(t);

        if (map[x][y] >= age)
        {
            map[x][y] -= age;
            ++age;
            nextTrees.push_back({age, x, y});

            if (age % 5 == 0) // 가을 생략
            {
                for (int j = 0; j < 8; ++j)
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];

                    if (ny >= 0 && nx >= 0 && ny < N && nx < N)
                    {
                        nextTrees.push_front({1, nx, ny}); // 덱의 경우 앞, 뒤로 삽입 가능
                    }
                }
            }
        }
        else
        {
            dieTrees.push_back(t);
        }
    }
    trees.clear();
    trees.swap(nextTrees);
}

void summer()
{
    for (tree t : dieTrees)
    {
        int age = get<0>(t);
        int x = get<1>(t);
        int y = get<2>(t);

        map[x][y] += age / 2;
    }

    dieTrees.clear();
}

void winter()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            map[i][j] += A[i][j];
        }
    }
}

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M >> K;
    map = A = vector<vector<int>>(N, vector<int>(N, 5));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> A[i][j];
        }
    }

    for (int i = 0, x, y, z; i < M; ++i)
    {
        cin >> x >> y >> z;
        --x;
        --y;
        trees.push_back({z, x, y});
    }
    sort(trees.begin(), trees.end());
}

void solve()
{
    while (K--)
    {
        spring();
        summer();
        winter();
    }
    cout << trees.size();
}

int main()
{
    input();
    solve();
    return 0;
}