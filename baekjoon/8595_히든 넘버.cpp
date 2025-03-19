#include <iostream>
using namespace std;
int n, num;
long long sum;
char c;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    while (n--)
    {
        cin >> c;

        if (c <= '9' && c >= '0')
        {
            num = num * 10 + c - '0';
        }
        else
        {
            sum += num;
            num = 0;
        }
    }

    sum += num;

    cout << sum;
    return 0;
}