#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int min(int n1, int n2)
{
    return n1 > n2 ? n2 : n1;
}
int max(int n1, int n2)
{
    return n1 > n2 ? n1 : n2;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, i, j, k;
    pii ret[3], temp[3];
    cin >> N;
    --N;
    cin >> i >> j >> k;
    ret[0].first = ret[0].second = i;
    ret[1].first = ret[1].second = j;
    ret[2].first = ret[2].second = k;
    while (N--)
    {
        cin >> i >> j >> k;
        temp[0].first = max(ret[0].first, ret[1].first) + i;
        temp[0].second = min(ret[0].second, ret[1].second) + i;
        temp[1].first = max(max(ret[0].first, ret[1].first), ret[2].first) + j;
        temp[1].second = min(min(ret[0].second, ret[1].second), ret[2].second) + j;
        temp[2].first = max(ret[1].first, ret[2].first) + k;
        temp[2].second = min(ret[1].second, ret[2].second) + k;
        ret[0].first = temp[0].first;
        ret[0].second = temp[0].second;
        ret[1].first = temp[1].first;
        ret[1].second = temp[1].second;
        ret[2].first = temp[2].first;
        ret[2].second = temp[2].second;
    }
    int retMax = max(max(ret[0].first, ret[1].first), ret[2].first), retMin = min(min(ret[0].second, ret[1].second), ret[2].second);
    cout << retMax << " " << retMin;
    return 0;
}