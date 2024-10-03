#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
using pii = pair<int, int>;
#define PRIME_LIMIT 100001
#define LIMIT 1000001
bool isNotPrime[PRIME_LIMIT]{true, true};
bool isVisited[LIMIT];
int T, N, A, B;
queue<pii> q;

void InitPrimes()
{
    for (int i = 2; i * i < PRIME_LIMIT; ++i)
    {
        if (isNotPrime[i])
        {
            continue;
        }

        for (int j = i + i; j < PRIME_LIMIT; j += i)
        {
            isNotPrime[j] = true;
        }
    }
}

void push(pii p)
{
    if (p.first < 0 || p.first >= LIMIT || isVisited[p.first])
    {
        return;
    }

    isVisited[p.first] = true;
    q.push(p);
}

int find()
{
    memset(isVisited, 0, sizeof(isVisited));
    while (!q.empty())
    {
        q.pop();
    }

    isVisited[N] = true;
    q.push({N, 1});

    while (!q.empty())
    {
        pii &cur = q.front();
        q.pop();

        int &num = cur.first;

        if (num >= A && num <= B && !isNotPrime[num])
        {
            return cur.second - 1;
        }

        int nextCost = cur.second + 1;

        push({num / 2, nextCost});
        push({num / 3, nextCost});
        push({num + 1, nextCost});
        push({num - 1, nextCost});
    }

    return -1;
}

void solve()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> A >> B;
        cout << find() << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    InitPrimes();
    solve();
    return 0;
}