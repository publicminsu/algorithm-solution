#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
vector<pii> v;
int N, answer;
pii maxIH;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    v = vector<pii>(N);
    for (pii &p : v)
    {
        cin >> p.first >> p.second;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; ++i)
    {
        if (v[i].second > maxIH.second)
        {
            maxIH = {i, v[i].second};
        }
    }

    answer = maxIH.second;
}
void calcLeft()
{
    int cur = maxIH.first;
    while (cur != 0)
    {
        pii next = {0, 0};

        for (int i = cur - 1; i >= 0; --i)
        {
            if (v[i].second > next.second)
            {
                next = {i, v[i].second};
            }
        }

        answer += (v[cur].first - v[next.first].first) * next.second;

        cur = next.first;
    }
}
void calcRight()
{
    int cur = maxIH.first;
    while (cur != N - 1)
    {
        pii next = {0, 0};

        for (int i = cur + 1; i < N; ++i)
        {
            if (v[i].second > next.second)
            {
                next = {i, v[i].second};
            }
        }

        answer += (v[next.first].first - v[cur].first) * next.second;

        cur = next.first;
    }
}
int main()
{
    input();
    calcLeft();
    calcRight();
    cout << answer;
    return 0;
}