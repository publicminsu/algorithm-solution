#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    string word;
    regex re("[\\w\\s]*U[\\w\\s]*C[\\w\\s]*P[\\w\\s]*C[\\w\\s]*", regex::optimize);

    getline(cin, word);

    if (regex_match(word, re))
    {
        cout << "I love UCPC";
    }
    else
    {
        cout << "I hate UCPC";
    }
    return 0;
}