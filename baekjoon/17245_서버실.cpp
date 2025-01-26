#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
ll totalSum;
vector<int> counts;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int N;
    cin >> N;

    N *= N;

    counts.reserve(N);

    while (N--)
    {
        int count;
        cin >> count;
        if (count)
        {
            counts.push_back(count);
            totalSum += count;
        }
    }
}

void solve()
{
    sort(counts.begin(), counts.end());

    int left = 0;
    int right = 10000000;

    while (left <= right)
    {
        int mid = (left + right) >> 1;
        ll sum = 0;

        for (int i = 0; i < counts.size(); ++i)
        {
            const int &count = counts[i];

            if (count > mid)
            {
                sum += mid * (counts.size() - i);
                break;
            }
            else
            {
                sum += count;
            }
        }

        if ((sum << 1) >= totalSum)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << left;
}

int main()
{
    input();
    solve();
    return 0;
}