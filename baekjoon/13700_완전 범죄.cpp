#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, S, D, F, B, K;
vector<int> buildings;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> S >> D >> F >> B >> K;

    buildings = vector<int>(N + 1);

    while (K--)
    {
        int i;
        cin >> i;
        buildings[i] = -1;
    }

    queue<int> q;
    q.push(S);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == D)
        {
            break;
        }

        int next = cur + F;
        if (next <= N && !buildings[next])
        {
            buildings[next] = buildings[cur] + 1;
            q.push(next);
        }
        next = cur - B;
        if (next >= 0 && !buildings[next])
        {
            buildings[next] = buildings[cur] + 1;
            q.push(next);
        }
    }

    cout << (buildings[D] ? to_string(buildings[D]) : "BUG FOUND");
    return 0;
}