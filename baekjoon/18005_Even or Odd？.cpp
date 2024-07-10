#include <iostream>
using namespace std;
int n;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    bool isSumOdd = (n * (n + 1) / 2) % 2;
    bool isNOdd = (isSumOdd + n) % 2;

    if (isSumOdd == isNOdd)
    {
        if (isNOdd)
        {
            cout << 1;
        }
        else
        {
            cout << 2;
        }
    }
    else
    {
        cout << 0;
    }

    return 0;
}