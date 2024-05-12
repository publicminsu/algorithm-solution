#include <iostream>
using namespace std;
char c;
int sum, temp;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> c)
    {
        if (c <= '9' && c >= '0')
        {
            temp = temp * 10 + (c - '0');
        }
        else if (c == ',')
        {
            sum += temp;
            temp = 0;
        }
    }
    cout << (sum + temp);
}