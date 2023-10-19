#include <iostream>
#include <cstring>
using namespace std;
int arr[100001];
bool isVisted[100001], isDone[100001];
int ret;
void dfs(int cur)
{
    isVisted[cur] = true;
    int next = arr[cur];
    if (!isVisted[next])
    {
        dfs(next);
    }
    else if (!isDone[next])
    {
        for (int i = next; i != cur; i = arr[i])
            ++ret;
        ++ret;
    }
    isDone[cur] = true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        memset(isDone, false, sizeof(isDone));
        memset(isVisted, false, sizeof(isVisted));
        ret = 0;
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> arr[i];
        for (int i = 1; i <= n; ++i)
            if (!isVisted[i])
                dfs(i);
        cout << n - ret << "\n";
    }
    return 0;
}