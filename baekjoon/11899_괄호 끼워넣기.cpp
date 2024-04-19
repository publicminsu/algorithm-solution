#include <iostream>
#include <stack>
using namespace std;

string S;
int rightBracket, answer;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> S;

    for (const char &c : S)
    {
        if (c == '(')
        {
            ++rightBracket;
        }
        else
        {
            if (!rightBracket)
            {
                ++answer;
                continue;
            }

            --rightBracket;
        }
    }

    cout << answer + rightBracket;
    return 0;
}