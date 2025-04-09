#include <iostream>
using namespace std;
int K, minSize = 1, fullCnt, cnt;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> K;

    while (minSize < K)
    {
        minSize <<= 1;
    }

    cout << minSize << " ";

    while (K > 0)
    {
        if (K < minSize)
        {
            minSize >>= 1;
            ++cnt;
        }
        else
        {
            K -= minSize;
        }
    }

    cout << cnt;
    return 0;
}