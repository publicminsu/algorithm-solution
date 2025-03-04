#include <iostream>
#include <queue>
using namespace std;

using pii = pair<int, int>;

int X, Y, N, A, B;
int map[1001][1001];
pii dir[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> X >> Y >> N;

    X += 500;
    Y += 500;

    while (N--)
    {
        cin >> A >> B;

        A += 500;
        B += 500;

        map[B][A] = -1;
    }

    queue<pii> q;
    q.push({500, 500});
    map[500][500] = 1;

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();

        for (pii d : dir)
        {
            pii next = {cur.first + d.first, cur.second + d.second};

            if (next.first < 0 || next.second < 0 || next.first > 1000 || next.second > 1000)
            {
                continue;
            }

            int &nextValue = map[next.first][next.second];

            if (nextValue)
            {
                continue;
            }

            if (next.first == Y && next.second == X)
            {
                cout << map[cur.first][cur.second];
                return 0;
            }

            nextValue = map[cur.first][cur.second] + 1;
            q.push(next);
        }
    }

    return 0;
}