#include <iostream>
#include <queue>
using namespace std;

#define COST 0.99f

float C;
int N;
queue<int> q;
int maxDays, maxCnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> C >> N;

    C = min(C, COST * 2);

    while (N--)
    {
        int cnt;
        cin >> cnt;
        maxCnt = max(maxCnt, cnt);

        if (cnt == 0)
        {
            if (C >= COST)
            {
                C -= COST;

                q.push(cnt);
            }
            else
            {
                while (!q.empty())
                {
                    int prevCnt = q.front();
                    q.pop();

                    if (prevCnt == 0)
                    {
                        C += COST;
                        break;
                    }
                }

                if (C >= COST)
                {
                    C -= COST;

                    q.push(cnt);
                }
            }
        }
        else
        {
            q.push(cnt);
        }

        maxDays = max(maxDays, (int)q.size());
    }

    cout << maxDays << "\n"
         << maxCnt;
    return 0;
}