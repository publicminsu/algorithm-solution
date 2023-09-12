#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    string pattern, input, rePattern;
    cin >> N;
    cin >> pattern;
    for (int i = 0; i < pattern.size(); ++i)
    {
        if (pattern[i] == '*')
            rePattern += "[a-z]*";
        else
            rePattern += pattern[i];
    }
    regex re(rePattern, regex::optimize);
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