#include <iostream>
using namespace std;

int N, M, U, V;

char uv[200][200];
char map[200][200];
string wrapMode;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M >> U >> V;

    for (int i = 0; i < U; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            cin >> uv[i][j];
        }
    }

    cin >> wrapMode;
}

void clampToEdge()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            map[i][j] = uv[min(i, U - 1)][min(j, V - 1)];
        }
    }
}

void repeat()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            map[i][j] = uv[i % U][j % V];
        }
    }
}

void mirroredRepeat()
{
    const auto mirror = [](const int &i)
    {
        return i >= 0 ? i : -(1 + i);
    };

    const auto mirroredRepeat = [&](int i, int size)
    {
        return size - 1 - mirror(i % (size * 2) - size);
    };

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            map[i][j] = uv[mirroredRepeat(i, U)][mirroredRepeat(j, V)];
        }
    }
}

void wrap()
{
    if (wrapMode == "clamp-to-edge")
    {
        clampToEdge();
    }
    else if (wrapMode == "repeat")
    {
        repeat();
    }
    else if (wrapMode == "mirrored-repeat")
    {
        mirroredRepeat();
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cout << map[i][j];
        }
        cout << "\n";
    }
}

int main()
{
    input();
    wrap();
    return 0;
}