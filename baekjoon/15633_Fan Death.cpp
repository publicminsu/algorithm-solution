#include <iostream>

using namespace std;

int n, answer;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0)
        {
            answer += i;
        }
    }

    answer = answer * 5 - 24;
    cout << answer;
    return 0;
}