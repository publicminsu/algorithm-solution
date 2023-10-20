#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int S, C;
    ll start = 1, end = 1e9;
    cin >> S >> C;

    vector<int> L(S);
    for (int i = 0; i < S; ++i)
    {
        cin >> L[i];
    }

    while (start <= end)
    {
        ll mid = (start + end) >> 1;

        int cnt = 0;

        for (int i = 0; i < S; ++i) // 몇 개의 파닭에 넣을 수 있는지 확인
        {
            cnt += L[i] / mid;
        }

        if (cnt < C) // 주문받은 파닭을 충족하지 못한다면 파닭에 넣을 파를 줄인다.
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    ll sum = 0;
    for (int i : L)
    {
        sum += i;
    }
    cout << sum - end * C;
    return 0;
}