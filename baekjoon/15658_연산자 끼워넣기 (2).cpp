#include <iostream>
using namespace std;
int op[4], N, arr[11], retMin = 1000000001, retMax = -1000000001;
void dfs(int idx, int sum)
{
    if (idx == N)
    {
        retMin = sum < retMin ? sum : retMin;
        retMax = sum > retMax ? sum : retMax;
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        int nextSum = sum;
        if (!op[i])
            continue;
        --op[i];
        if (i == 0)
            nextSum += arr[idx];
        else if (i == 1)
            nextSum -= arr[idx];
        else if (i == 2)
            nextSum *= arr[idx];
        else if (i == 3)
            nextSum /= arr[idx];
        dfs(idx + 1, nextSum);
        ++op[i];
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    for (int i = 0; i < 4; ++i)
        cin >> op[i];
    dfs(1, arr[0]);
    cout << retMax << "\n"
         << retMin;
    return 0;
}