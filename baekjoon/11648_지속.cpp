#include <iostream>
using namespace std;

int num, level;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> num;

    while (num >= 10)
    {
        int nextNum = 1;

        while (num)
        {
            nextNum *= num % 10;
            num /= 10;
        }

        num = nextNum;
        ++level;
    }

    cout << level;
    return 0;
}