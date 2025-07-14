#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>
using namespace std;

int N;
int x[4000];
set<int> s;
vector<int> answer;
unordered_set<int> visited;
unordered_set<int> existed;

void init()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    answer.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> x[i];
        existed.insert(x[i]);
    }

    for (int i = 1; i < N; ++i)
    {
        s.insert(x[i] - x[0]);
    }
}

bool isCanine(const int &k)
{
    visited.clear();

    for (int i = 0; i < N; ++i)
    {
        const int &curX = x[i];
        const int nextX = curX + k;

        if (existed.find(nextX) != existed.end())
        {
            visited.insert(curX);
            visited.insert(nextX);
        }
    }

    return visited.size() == N;
}

void solve()
{
    for (const int &k : s)
    {
        if (isCanine(k))
        {
            answer.push_back(k);
        }
    }

    cout << answer.size() << "\n";

    for (const int &k : answer)
    {
        cout << k << " ";
    }
}

int main()
{
    init();
    solve();
    return 0;
}