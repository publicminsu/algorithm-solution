#include <iostream>
using namespace std;
int n, j, m, index, len = 987654321;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> j >> m;

        int nextLen = ((j - 1) / (m + 1) + 1) * 2;

        if (nextLen < len)
        {
            len = nextLen;
            index = i;
        }
    }

    cout << index << " " << len;
    return 0;
}