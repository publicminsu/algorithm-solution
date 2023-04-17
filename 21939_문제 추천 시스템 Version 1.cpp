#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef pair<int, int> pii;
int diff[100001];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, id, d;
    string com;
    priority_queue<pii> hq;
    priority_queue<pii, vector<pii>, greater<pii>> lq;
    cin >> N;
    while (N--)
    {
        cin >> id >> d;
        diff[id] = d;
        hq.push({d, id});
        lq.push({d, id});
    }
    cin >> M;
    while (M--)
    {
        cin >> com >> id;
        if (com == "add")
        {
            cin >> d;
            diff[id] = d;
            hq.push({d, id});
            lq.push({d, id});
        }
        else if (com == "solved")
        {
            diff[id] = 0;
        }
        else
        {
            if (id == 1)
            {
                while (true)
                {
                    pii cur = hq.top();
                    int prevDiff = diff[cur.second];
                    if (!prevDiff || prevDiff != cur.first)
                    {
                        hq.pop();
                        continue;
                    }
                    cout << cur.second << "\n";
                    break;
                }
            }
            else
            {
                while (true)
                {
                    pii cur = lq.top();
                    int prevDiff = diff[cur.second];
                    if (!prevDiff || prevDiff != cur.first)
                    {
                        lq.pop();
                        continue;
                    }
                    cout << cur.second << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}
