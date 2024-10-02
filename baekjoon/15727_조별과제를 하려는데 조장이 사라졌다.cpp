#include <iostream>
using namespace std;
int L;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> L;
    cout << L / 5 + (L % 5 ? 1 : 0);
    return 0;
}