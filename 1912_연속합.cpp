#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, num, sum = 0, ret = -1001;
    cin >> n;
    while (n--)
    {
        cin >> num;
        sum += num;
        ret = max(ret, sum);
        if (sum < 0)
            sum = 0;
    }
    cout << ret;
    return 0;
}