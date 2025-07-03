#include <iostream>
using namespace std;
int a, branch, splittingFactor, pruning;
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
            cin >> splittingFactor >> pruning;
            branch *= splittingFactor;
            branch -= pruning;
        }

        cout << branch << "\n";
    }

    return 0;
}