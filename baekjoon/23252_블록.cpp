#include <iostream>

using namespace std;

int T, A, B, C;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> A >> B >> C;

        bool isYes = true;

        if (C > A)
        {
            isYes = false;
        }
        else if ((C + A) % 2)
        {
            isYes = false;
        }
        else if (C == 0 && A == 0 && B % 2)
        {
            isYes = false;
        }

        cout << (isYes ? "Yes" : "No") << "\n";
    }
    return 0;
}