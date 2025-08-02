#include <iostream>
using namespace std;

int pieces[] = {1, 1, 2, 2, 2, 8};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 0, j; i < 6; ++i)
    {
        cin >> j;
        cout << pieces[i] - j << " ";
    }
    return 0;
}