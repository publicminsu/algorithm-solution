#include <iostream>
using namespace std;
char c;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> c;
    cout << static_cast<int>(c);
    return 0;
}