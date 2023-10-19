#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    vector<int> rankList;
    int N, newScore, P;
    cin >> N >> newScore >> P;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        rankList.push_back(num);
    }
    sort(rankList.begin(), rankList.end(), greater<int>());
    if (N == P && rankList[N - 1] >= newScore)
    {
        cout << -1;
    }
    else
    {
        int cnt = 1;
        for (int i = 0; i < N; ++i)
        {
            if (rankList[i] > newScore)
                ++cnt;
            else
                break;
        }
        cout << cnt;
    }
}