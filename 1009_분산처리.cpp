#include <iostream>
using namespace std;
int part(int a, int b)
{
    if (b == 1)
        return a % 10;
    int ret = part(a, b / 2);
    ret = (ret * ret) % 10;
    if (b % 2)
        ret = (ret * a) % 10;
    return ret;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T, a, b;
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        int ret = part(a, b);
        if (!ret)
            ret = 10;
        cout << ret << "\n";
    }
    return 0;
}