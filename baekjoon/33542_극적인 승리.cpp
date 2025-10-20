#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_SIZE 500000
#define INF 987654321
using pii = pair<int, int>;

int A, B, N;
int L[MAX_SIZE];
pii R[MAX_SIZE];
int answerDiff = INF, X, Y;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> A >> B >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> L[i] >> R[i].first;
        R[i].second = i;
    }
}

void solve()
{
    if (A < B)
    {
        cout << "-1 -1";
        return;
    }

    sort(R, R + N);

    int diff = A - B + 1;

    for (int i = 0; i < N; ++i)
    {
        if (L[i] >= diff)
        {
            if (L[i] < answerDiff)
            {
                X = i + 1;
                Y = -1;
                answerDiff = L[i];
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        pii r = R[i];

        if (r.first >= diff)
        {
            if (r.first < answerDiff)
            {
                X = -1;
                Y = r.second + 1;
                answerDiff = R[i].first;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        int l = L[i];

        int target = diff - l;

        auto lb = lower_bound(R, R + N, make_pair(target, 0));

        if (lb == R + N)
        {
            continue;
        }

        if (lb->second == i)
        {
            lb = next(lb);
        }

        if (lb == R + N)
        {
            continue;
        }

        int nextDiff = l + lb->first;

        if (nextDiff < answerDiff)
        {
            X = i + 1;
            Y = lb->second + 1;
            answerDiff = nextDiff;
        }
    }

    if (answerDiff == INF)
    {
        cout << "No";
    }
    else
    {
        cout << X << " " << Y;
    }
}

int main()
{
    input();
    solve();
    return 0;
}