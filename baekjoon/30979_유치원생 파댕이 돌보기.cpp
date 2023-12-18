#include <iostream>
using namespace std;
int T, N, F;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T >> N;
    while (N--)
    {
        cin >> F;
        T -= F;
    }

    cout << "Padaeng_i ";

    if (T > 0) // 시간이 남았다면
    {
        cout << "Cry";
    }
    else
    {
        cout << "Happy";
    }
    return 0;
}