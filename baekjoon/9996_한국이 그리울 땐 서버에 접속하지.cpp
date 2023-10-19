#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    string pattern, input;
    cin >> N;
    cin >> pattern;
    pattern.replace(pattern.find("*"), 1, "\\w*");
    regex re(pattern, regex::optimize);
    while (N--)
    {
        cin >> input;
        if (regex_match(input, re))
            cout << "DA";
        else
            cout << "NE";
        cout << "\n";
    }
    return 0;
}