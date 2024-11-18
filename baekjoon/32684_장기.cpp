#include <iostream>
using namespace std;
int points[] = {26, 14, 10, 6, 6, 4};
int sum1, sum2 = 3;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 0, j; i < 6; ++i)
    {
        cin >> j;
        sum1 += points[i] * j;
    }

    for (int i = 0, j; i < 6; ++i)
    {
        cin >> j;
        sum2 += points[i] * j;
    }

    cout << (sum1 > sum2 ? "cocjr0208" : "ekwoo");
    return 0;
}