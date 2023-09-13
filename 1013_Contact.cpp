#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    regex re("(100+1+|01)+", regex::optimize);
    string pattern;
    int T;
    cin >> T;
    while (T--)
    {
        cin >> pattern;
        cout << (regex_match(pattern, re) ? "YES" : "NO") << "\n";
    }
}