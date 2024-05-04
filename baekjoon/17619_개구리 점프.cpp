#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
using piii = pair<pii, int>;
int N, Q;
vector<piii> logs;
vector<int> groupIDs;
int groupCnt, endX = -1;
void init()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> Q;
    groupIDs = vector<int>(N);
    logs = vector<piii>(N);

    for (int i = 0; i < N; ++i)
    {
        piii &log = logs[i];
        cin >> log.first.first >> log.first.second >> log.second;
        log.second = i; // 정렬 대비 통나무 번호 저장
    }

    sort(logs.begin(), logs.end());
}
void solve()
{
    for (int i = 0; i < N; ++i)
    {
        const piii &log = logs[i];

        if (endX < log.first.first) // 이어갈 수 없다면
        {
            groupIDs[log.second] = ++groupCnt;
            endX = log.first.second;
        }
        else
        {
            groupIDs[log.second] = groupCnt;
            endX = max(endX, log.first.second);
        }
    }
}
void query()
{
    while (Q--)
    {
        pii p;
        cin >> p.first >> p.second;

        cout << (groupIDs[--p.first] == groupIDs[--p.second]) << "\n";
    }
}
int main()
{
    init();
    solve();
    query();
    return 0;
}