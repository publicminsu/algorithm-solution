#include <iostream>
#include <regex>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    regex re("^[A-F]?A+F+C+[A-F]?$", regex::optimize);
    int T;
    string chromosome;
    cin >> T;
    while (T--)
    {
        cin >> chromosome;
        cout << (regex_match(chromosome, re) ? "Infected!" : "Good") << "\n";
    }
    return 0;
}