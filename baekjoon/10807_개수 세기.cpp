#include <iostream>
using namespace std;

int N, i;
int cnts[201];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    while (N--)
    {

        cin >> i;
        i += 100;
        ++cnts[i];
    }

    cin >> i;
    cout << cnts[i + 100];
    return 0;
}