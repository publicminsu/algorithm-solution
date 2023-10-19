#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, ret = 0, idx = 0;
    string S;
    cin >> N >> M >> S;
    while (idx < M)
    {
        if (S[idx] == 'I')
        {
            int cnt = 0;
            while (idx + cnt * 2 + 2 < M)
            {
                if (S[idx + cnt * 2 + 1] == 'O' && S[idx + cnt * 2 + 2] == 'I')
                    ++cnt;
                else
                    break;
            }
            if (cnt - (N - 1) > 0)
                ret += cnt - (N - 1);
            idx += cnt * 2 + 1;
        }
        else
            ++idx;
    }
    cout << ret;
    return 0;
}