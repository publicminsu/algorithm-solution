#include <iostream>

using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    int cnt = 0;

    while (N > 1)
    {
        ++cnt;
        N /= 2;
    }

    cout << (8 + cnt + 2);
    return 0;
}