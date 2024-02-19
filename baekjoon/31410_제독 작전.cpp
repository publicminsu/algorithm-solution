#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
ll N;
ll answer, leftVal, rightVal;
vector<pii> targets;
void input()
{
    cin >> N;
    targets = vector<pii>(N);

    for (int i = 0; i < N; ++i)
    {
        pii &target = targets[i];

        cin >> target.first >> target.second;
    }
}
void getVal()
{
    sort(targets.begin(), targets.end());

    // 모든 곳을 왼쪽부터 제독한 값
    int cnt = 1;
    ll x = targets.front().first;
    leftVal = targets.front().second;
    for (int i = 1; i < N; ++i)
    {
        pii &target = targets[i];
        leftVal += (target.second) + (target.first - x) * cnt++;
        x = target.first;
    }

    // 모든 곳을 오른쪽부터 제독한 값
    cnt = 1;
    x = targets.back().first;
    rightVal = targets.back().second;
    for (int i = N - 2; i >= 0; --i)
    {
        pii &target = targets[i];
        rightVal += (target.second) + (x - target.first) * cnt++;
        x = target.first;
    }
}
void solve()
{
    ll leftCalc, rightCalc;
    pii target;

    // 0 남겨두기
    target = targets.front();
    leftCalc = leftVal - target.second - (targets.back().first - target.first);
    rightCalc = rightVal - target.second - (N - 1) * (targets[1].first - target.first);
    answer = min(leftCalc, rightCalc);

    // N-1 남겨두기
    target = targets.back();
    leftCalc = leftVal - target.second - (N - 1) * (target.first - targets[N - 2].first);
    rightCalc = rightVal - target.second - (target.first - targets.front().first);
    answer = min(answer, min(leftCalc, rightCalc));

    // 1~N-2 남겨두기
    for (int i = 1; i < N - 1; ++i)
    {
        target = targets[i];

        leftCalc = leftVal - target.second - (targets.back().first - target.first);
        rightCalc = rightVal - target.second - (target.first - targets.front().first);

        answer = min(answer, min(leftCalc, rightCalc));
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    input();
    getVal();
    solve();
    cout << answer;
    return 0;
}