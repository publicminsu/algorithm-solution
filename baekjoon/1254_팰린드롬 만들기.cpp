#include <iostream>
using namespace std;

string S;

bool isPalindrome(string buffer)
{
    for (int i = 0; i < buffer.size() / 2; ++i)
    {
        if (buffer[i] != buffer[buffer.size() - i - 1])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> S;

    if (isPalindrome(S))
    {
        cout << S.size();
        return 0;
    }

    for (int i = 0; i < S.size(); ++i)
    {
        string buffer = S;

        for (int j = i; j >= 0; --j)
        {
            buffer += S[j];

            if (isPalindrome(buffer))
            {
                cout << buffer.size();
                return 0;
            }
        }
    }
    return 0;
}