#include <iostream>
using namespace std;
int a, branch, x, y;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    while (true)
    {
        cin >> a;

        if (a == 0)
        {
            break;
        }

        branch = 1;

        while (a--)
        {
            cin >> x >> y;
            branch *= x;
            branch -= y;
        }

        cout << branch << "\n";
    }

    return 0;
}