#include <iostream>
using namespace std;

int num1, num2;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    while (true)
    {
        cin >> num1 >> num2;

        if (num1 == 0 && num2 == 0)
        {
            break;
        }

        cout << (num1 > num2 ? "Yes" : "No") << "\n";
    }

    return 0;
}