#include <iostream>
using namespace std;
int N, cnt;
string T;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> T;
    for (int i = 0; i < N / 2; ++i)
    {
        if (T[i] == T[N - i - 1])
        {
            if (T[i] == '?')
            {
                cnt += 26;
            }
        }
        else
        {
            if (T[i] == '?' || T[N - i - 1] == '?')
            {
                ++cnt;
            }
            else
            {
                cout << 0;
                return 0;
            }
        }
    }
    cout << cnt;
    return 0;
}