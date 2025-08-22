#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int sum = 0;

    for (int i = 0; i < 5; ++i)
    {
        int num;
        cin >> num;

        num = max(40, num);
        sum += num;
    }

    cout << sum / 5;

    return 0;
}