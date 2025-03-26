#include <iostream>
using namespace std;
int n;
bool check[31];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 0, j; i < 28; ++i)
    {
        cin >> j;
        check[j] = true;
    }
    for (int i = 1; i <= 30; ++i)
    {
        if (!check[i])
        {
            cout << i << "\n";
        }
    }
    return 0;
}