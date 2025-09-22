#include <iostream>
using namespace std;

int A, B, C;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> A >> B >> C;

    int sum = A + B;
    int cost = C * 2;

    if (sum >= cost)
    {
        cout << sum - C * 2;
    }
    else
    {
        cout << sum;
    }
    return 0;
}