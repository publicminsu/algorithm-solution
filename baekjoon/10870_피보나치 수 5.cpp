#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    int fn2 = 0;
    int fn1 = 1;
    int fn = 1;

    cin >> n;

    if (n == 0)
    {
        fn = 0;
    }
    else
    {
        for (int i = 2; i < n; ++i)
        {
            fn2 = fn1;
            fn1 = fn;
            fn = fn1 + fn2;
        }
    }

    cout << fn;
}