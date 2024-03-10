#include <iostream>
using namespace std;
float a, m, n, answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cout << fixed;
    cout.precision(7);
    cin >> a >> m >> n;
    if (m > n) // n이 더 크게
    {
        swap(m, n);
    }

    answer = max(m, n / a);            // 동시에 돌리는 경우
    answer = min((m / a) * 2, answer); // 하나에 돌리는 경우

    cout << answer;
    return 0;
}