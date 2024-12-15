#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int N, L[100001];
int cnt[100001], idx[100001];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> L[i];
    }
}

void push(int i)
{
    const int &l = L[i];

    while (!s.empty() && L[s.top()] <= l)
    {
        s.pop();
    }

    if (!s.empty())
    {
        if (!idx[i])
        {
            idx[i] = s.top() + 1;
        }
        else
        {
            int curIdx = i + 1;
            int nextIdx = s.top() + 1;

            int nextLen = abs(curIdx - nextIdx);
            int savedLen = abs(curIdx - idx[i]);

            if (savedLen > nextLen)
            {
                idx[i] = nextIdx;
            }
            else if (savedLen == nextLen)
            {
                idx[i] = min(idx[i], nextIdx);
            }
        }

        cnt[i] += s.size();
    }

    s.push(i);
}

void solve()
{
    for (int i = 0; i < N; ++i)
    {
        push(i);
    }

    while (!s.empty())
    {
        s.pop();
    }

    for (int i = N - 1; i >= 0; --i)
    {
        push(i);
    }
}

void print()
{
    for (int i = 0; i < N; ++i)
    {
        cout << cnt[i];

        if (cnt[i])
        {
            cout << " " << idx[i];
        }

        cout << "\n";
    }
}

int main()
{
    input();
    solve();
    print();
    return 0;
}