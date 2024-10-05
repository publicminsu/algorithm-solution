#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
using ll = long long;
using plli = pair<ll, int>;
unordered_set<ll> isVisited;
queue<plli> q;
ll N;

void push(ll value, int cost)
{
    if (isVisited.find(value) != isVisited.end() || value < 1)
    {
        return;
    }

    if (value == 1)
    {
        cout << cost;
        exit(0);
    }

    isVisited.insert(value);
    q.push({value, cost});
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    push(N, 0);
    while (!q.empty())
    {
        plli cur = q.front();
        q.pop();

        int nextCost = cur.second + 1;
        if (cur.first % 3 == 0)
        {
            push(cur.first / 3, nextCost);
        }
        if (cur.first % 2 == 0)
        {
            push(cur.first / 2, nextCost);
        }
        push(cur.first - 1, nextCost);
    }
    return 0;
}