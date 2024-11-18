#include <iostream>
using namespace std;
int num, password;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 0; i < 3; ++i)
    {
        cin >> num;

        for (int j = 3; j >= 0; --j)
        {
            bool bit = num & (1 << j);
            password = (password << 1) + bit;
        }
    }
    cout.width(4);
    cout.fill('0');
    cout << password;
    return 0;
}