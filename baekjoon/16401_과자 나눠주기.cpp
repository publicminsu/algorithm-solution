#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int M, N, cnt;
ll answer, l, r, m;
vector<int> L;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> M >> N;
    L = vector<int>(N);
    for (int &l : L)
    {
        cin >> l;
    }
    sort(L.begin(), L.end(), greater<int>());

    r = L.front() << 1;

    while (l <= r)
    {
        cnt = 0;
        m = (l + r) >> 1;
        if (!m)
        {
            break;
        }

        for (const int &l : L)
        {
            cnt += l / m;

            if (m > l || cnt > M)
            {
                break;
            }
        }

        if (cnt >= M)
        {
            answer = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    cout << answer;
    return 0;
}