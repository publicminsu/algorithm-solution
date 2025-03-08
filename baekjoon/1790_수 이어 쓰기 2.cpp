#include <iostream>
#include <stack>
using namespace std;
int N, k, cnt;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> k;

    for (int i = 1, j = 1, l = 10; i <= N; ++i)
    {
        if (i >= l)
        {
            l *= 10;
            ++j;
        }

        if (cnt + j < k)
        {
            cnt += j;
        }
        else
        {
            stack<int> s;

            while (i)
            {
                s.push(i % 10);
                i /= 10;
            }

            while (true)
            {
                int cur = s.top();
                s.pop();
                ++cnt;

                if (cnt == k)
                {
                    cout << cur;
                    return 0;
                }
            }
        }
    }

    cout << -1;
    return 0;
}