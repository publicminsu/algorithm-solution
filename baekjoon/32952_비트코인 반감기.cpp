#include <iostream>
using namespace std;
long long R, K, M;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> R >> K >> M;

    int i = M / K;

    while (i-- && R > 0)
    {
        R >>= 1;
    }
    cout << R;
    return 0;
}