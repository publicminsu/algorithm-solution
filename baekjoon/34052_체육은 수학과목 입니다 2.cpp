#include <iostream>

using namespace std;

int sum, t;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 0; i < 4; ++i)
    {
        cin >> t;
        sum += t;
    }

    cout << (sum <= 1500 ? "Yes" : "No");
    return 0;
}