#include <iostream>
#include <string>
using namespace std;
string str;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    getline(cin, str);

    int start = 0, end = 0;

    while (true)
    {
        start = str.find("What is", start);

        if (start == string::npos)
        {
            break;
        }

        end = str.find_first_of("?.", start);

        string substr = str.substr(start + 4, end - start - 3);

        if (substr.back() == '?')
        {
            substr.pop_back();

            cout << "Forty-two" + substr + ".\n";
        }

        start = end;
    }
    return 0;
}