#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int, int> book;
bool isVisted[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        priority_queue<book, vector<book>, greater<book>> pq;
        memset(isVisted, false, sizeof(isVisted));
        int N, M, ret = 0, minA = 0; // 최솟값
        cin >> N >> M;
        while (M--)
        {
            int a, b;
            cin >> a >> b;
            pq.push({a, b});
        }
        while (!pq.empty())
        {
            book cur = pq.top();
            pq.pop();
            if (minA < cur.first)
                minA = cur.first;
            else if (minA + 1 <= cur.second)
            {
                pq.push({minA + 1, cur.second});
                continue;
            }
            else
                continue;
            if (!isVisted[minA])
            {
                isVisted[minA] = true;
                ret++;
            }
        }
        cout << ret << "\n";
    }
    return 0;
}