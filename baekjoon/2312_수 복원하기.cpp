#include <iostream>
using namespace std;
int tc, N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> tc;
    while (tc--)
    {
        cin >> N;
        for (int i = 2, cnt;; ++i)
        {
            cnt = 0;
            if (N == 1) // N이 1인 경우
            {
                break;
            }
            while (N % i == 0) // 나머지가 0이면
            {
                ++cnt;
                N /= i;
            }
            if (cnt != 0)
            {
                cout << i << " " << cnt << "\n";
            }
        }
    }
    return 0;
}