#include <iostream>
#include <cstring>
using namespace std;

struct node
{
    int x, y, R;
};

int T, N;
int groupCnt;
node nodes[3000];
int group[3000];
bool isUsed[3000];

int find(int a)
{
    if (group[a] == a)
    {
        return a;
    }

    return group[a] = find(group[a]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    group[b] = a;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> N;

        for (int i = 0; i < N; ++i)
        {
            node &n = nodes[i];
            cin >> n.x >> n.y >> n.R;
            group[i] = i;
        }

        for (int i = 0; i < N; ++i)
        {
            const node &a = nodes[i];

            for (int j = i + 1; j < N; ++j)
            {
                const node &b = nodes[j];

                int dx = a.x - b.x;
                int dy = a.y - b.y;
                int dist = dx * dx + dy * dy;

                int rr = a.R + b.R;

                if (dist <= rr * rr)
                {
                    merge(i, j);
                }
            }
        }

        groupCnt = 0;

        memset(isUsed, false, sizeof(isUsed));

        for (int i = 0; i < N; ++i)
        {
            int j = find(i);

            if (isUsed[j])
            {
                continue;
            }

            isUsed[j] = true;
            ++groupCnt;
        }

        cout << groupCnt << "\n";
    }

    return 0;
}
