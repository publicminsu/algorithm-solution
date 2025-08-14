#include <iostream>
using namespace std;
int T;
string str;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> str;

        cout << (str[0] - '0' + str[2] - '0') << "\n";
    }
    return 0;
}