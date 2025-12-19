#include <iostream>

using namespace std;

int A, B;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (true)
    {
        cin >> A >> B;

        if (A == 0 && B == 0)
        {
            break;
        }

        if (A > B)
        {
            if (A % B == 0)
            {
                cout << "multiple";
            }
            else
            {
                cout << "neither";
            }
        }
        else
        {
            if (B % A == 0)
            {
                cout << "factor";
            }
            else
            {
                cout << "neither";
            }
        }

        cout << "\n";
    }
    return 0;
}