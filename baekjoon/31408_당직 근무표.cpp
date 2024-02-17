#include <iostream>
using namespace std;
int N;
int cnt[100001];
int maxCnt;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;
        maxCnt = max(maxCnt, ++cnt[j]);
    }

    if (N & 1)
    {
        ++N;
    }
    N >>= 1;

    cout << (maxCnt > N ? "NO" : "YES"); // 절반보다 크면 불가능
    return 0;
}