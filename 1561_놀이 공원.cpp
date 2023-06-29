#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int N, M;
ull targetTime;
vector<int> times;
void binarySearch(ull left, ull right)
{
    if (left > right)
        return;
    ull mid = (left + right) >> 1;
    ull sum = 0;
    for (int i = 1; i <= M; ++i)
    {
        int div = mid / times[i];
        sum += div + 1;
    }
    if (sum >= N)
    {
        targetTime = mid;
        binarySearch(left, mid - 1);
    }
    else
    {
        binarySearch(mid + 1, right);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    times = vector<int>(M + 1);
    if (N <= M)
    {
        cout << N;
        return 0;
    }
    for (int i = 1; i <= M; ++i)
        cin >> times[i];
    binarySearch(0, 60000000000);
    ull sum = 0;
    for (int i = 1; i <= M; ++i)
        sum += ((targetTime - 1) / times[i]) + 1;
    for (int i = 1; i <= M; ++i)
    {
        if (targetTime % times[i])
            continue;
        ++sum;
        if (sum == N)
        {
            cout << i;
            break;
        }
    }
    return 0;
}