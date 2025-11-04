#include <iostream>
using namespace std;

#define MAX_SIZE 100000

using ll = long long;

int n;
int crossDists[MAX_SIZE], leftDists[MAX_SIZE], rightDists[MAX_SIZE];
ll rightSum;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> crossDists[i];
    }

    for (int i = 0; i < n - 1; ++i)
    {
        cin >> leftDists[i];
    }

    for (int i = 0; i < n - 1; ++i)
    {
        cin >> rightDists[i];
        rightSum += rightDists[i];
    }
}

void solve()
{
    int idx = 1;
    ll minDistSum = rightSum + crossDists[0];
    ll leftSum = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        rightSum -= rightDists[i];
        leftSum += leftDists[i];
        ll distSum = leftSum + rightSum + crossDists[i + 1];

        if (minDistSum > distSum)
        {
            idx = i + 2;
            minDistSum = distSum;
        }
    }

    cout << idx << " " << minDistSum;
}

int main()
{
    input();
    solve();
    return 0;
}