#include <iostream>
using namespace std;
int N, H;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> H;

    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;

        H -= j;

        if (H <= 0)
        {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}