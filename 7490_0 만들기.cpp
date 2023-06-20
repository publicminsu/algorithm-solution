#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int tc, N;
vector<string> ret;
void dfs(int idx, vector<int> arr, string cal)
{
    if (idx > N)
    {
        int sum = 0;
        for (int i : arr)
            sum += i;
        if (sum == 0)
            ret.push_back(cal);
        return;
    }
    arr.push_back(idx);
    dfs(idx + 1, arr, cal + '+' + char(idx + '0'));
    arr.pop_back();
    arr.push_back(-idx);
    dfs(idx + 1, arr, cal + '-' + char(idx + '0'));
    arr.pop_back();
    int val = arr.back() < 0 ? -idx : idx;
    arr.back() = arr.back() * 10 + val;
    dfs(idx + 1, arr, cal + ' ' + char(idx + '0'));
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> tc;
    for (int i = 0; i < tc; ++i)
    {
        ret.clear();
        cin >> N;
        dfs(2, {1}, "1");
        sort(ret.begin(), ret.end());
        for (string j : ret)
            cout << j << "\n";
        cout << "\n";
    }
    return 0;
}