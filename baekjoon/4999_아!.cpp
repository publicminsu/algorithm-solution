#include <iostream>
using namespace std;

string strs[2];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    for (string &str : strs)
    {
        cin >> str;
    }

    cout << (strs[0].length() >= strs[1].length() ? "go" : "no");
    return 0;
}