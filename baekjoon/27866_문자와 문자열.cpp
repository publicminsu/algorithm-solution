#include <iostream>
using namespace std;
string str;
int i;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> str >> i;
    cout << str[i - 1];
    return 0;
}