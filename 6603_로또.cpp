#include <iostream>
using namespace std;
int num[13], k, buff[13];
void dfs(int idx, int cnt)
{
    if (cnt == 6)
    {
        for (int i = 0; i < 6; ++i)
            cout << buff[i] << " ";
        cout << "\n";
        return;
    }
    if (idx == k)
        return;
    buff[cnt] = num[idx];
    dfs(idx + 1, cnt + 1);
    buff[cnt] = 0;
    dfs(idx + 1, cnt);
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    while (true)
    {
        cin >> k;
        if (k == 0)
            break;
        for (int i = 0; i < k; ++i)
            cin >> num[i];
        dfs(0, 0);
        cout << "\n";
        for (int i = 0; i < k; ++i)
            num[i] = 0;
    }
    return 0;
}