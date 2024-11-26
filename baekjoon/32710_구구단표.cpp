#include <iostream>
using namespace std;
int N, isFind;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    if (N == 1)
    {
        cout << 1;
        return 0;
    }

    for (int i = 9; i >= 2; --i)
    {
        if (N % i == 0)
        {
            if (N / i <= 9)
            {
                isFind = true;
            }
            break;
        }
    }

    cout << isFind;
    return 0;
}