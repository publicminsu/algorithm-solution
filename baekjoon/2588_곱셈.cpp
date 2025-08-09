#include <iostream>

using namespace std;

int num1, num2;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> num1 >> num2;

    for (int i = num2; i > 0; i /= 10)
    {
        cout << num1 * (i % 10) << "\n";
    }

    cout << num1 * num2;
    return 0;
}