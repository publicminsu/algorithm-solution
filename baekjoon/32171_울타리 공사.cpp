#include <iostream>
using namespace std;
int N, A = 10, B = 10, C = -10, D = -10, a, b, c, d;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> a >> b >> c >> d;
        A = min(a, A);
        B = min(b, B);
        C = max(c, C);
        D = max(d, D);

        cout << ((D - B) + (C - A)) * 2 << "\n";
    }
    return 0;
}