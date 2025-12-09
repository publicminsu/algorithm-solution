#include <iostream>
using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    int line = 2;

    while (N--)
    {
        line = line * 2 - 1;
    }

    cout << line * line;
    return 0;
}