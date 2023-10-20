#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int N;
vector<pii> jobs;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    jobs = vector<pii>(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> jobs[i].second >> jobs[i].first;
    }
}
void solve()
{
    sort(jobs.begin(), jobs.end(), greater<pii>());
    int endTime = jobs[0].first - jobs[0].second;
    for (int i = 1; i < N; ++i)
    {
        if (jobs[i].first < endTime) // 마지막 종료 시간보다 빠르다면
        {
            endTime = jobs[i].first; // 마지막 종료 시간으로 갱신
        }

        endTime -= jobs[i].second; // 필요한 시간 빼기
    }
    if (endTime < 0) // 불가능한 경우
    {
        cout << -1;
    }
    else
    {
        cout << endTime;
    }
}
int main()
{
    input();
    solve();
    return 0;
}