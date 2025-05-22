#include <iostream>
using namespace std;

int N, M, L;
int cnt[51];
int cur = 0, cntSum;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> L;

    while (true)
    {
        ++cnt[cur];
        ++cntSum;

        if (cnt[cur] == M)
        {
            break;
        }

        if (cnt[cur] % 2)
        {
            cur = (cur + L) % N;
        }
        else
        {
            cur = (cur - L + N) % N;
        }
    }

    cout << cntSum - 1;
    return 0;
}