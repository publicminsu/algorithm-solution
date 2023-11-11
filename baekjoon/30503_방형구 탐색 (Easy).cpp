#include <iostream>
#include <vector>
using namespace std;
int N, Q;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }
    cin >> Q;
    while (Q--)
    {
        int q, l, r;
        cin >> q >> l >> r;
        if (q == 1)
        {
            int k, cnt = 0;
            cin >> k;
            for (int i = l - 1; i < r; ++i)
            {
                if (k == v[i]) // k 종류의 꽃이 존재하는 곳
                {
                    ++cnt;
                }
            }
            cout << cnt << "\n";
        }
        else
        {
            for (int i = l - 1; i < r; ++i) // 밟아 없애기
            {
                v[i] = 0;
            }
        }
    }
    return 0;
}