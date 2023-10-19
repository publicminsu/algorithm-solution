#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int N, M;
void print(int target)
{
    cout << target << "\n";
    int i = 0, cnt = 1, smallCnt = 0, sum = 0;
    for (; i < N; ++i)
    {
        if (sum + v[i] <= target)
        {
            sum += v[i];
            ++smallCnt;
        }
        else
        {
            cout << smallCnt << " ";
            smallCnt = 1;
            ++cnt;
            sum = v[i];
        }
        if (cnt + N - i - 1 == M)
        {
            cout << smallCnt << " ";
            ++i;
            for (; i < N; ++i)
                cout << 1 << " ";
            return;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    v = vector<int>(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    int start = 0, mid, end = 30001;
    while (start <= end)
    {
        mid = (start + end) >> 1;
        int cnt = 1, sum = 0;
        for (int i = 0; i < N; ++i)
            if (sum + v[i] <= mid)
                sum += v[i];
            else if (v[i] > mid)
                cnt += 30001;
            else
            {
                ++cnt;
                sum = v[i];
            }
        if (cnt <= M)
            end = mid - 1;
        else
            start = mid + 1;
    }
    print(start);
}