#include <iostream>
using namespace std;
int n, answer = 100000, cnt;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    while (n > 0)
    {
        if (!(n % 2))
        {
            answer = min(answer, n / 2 + cnt);
        }

        if (!(n % 5))
        {
            answer = min(answer, n / 5 + cnt);
        }

        ++cnt;
        n -= 5;
    }

    cout << (answer == 100000 ? -1 : answer);
    return 0;
}