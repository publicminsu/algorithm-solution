#include <iostream>
using namespace std;

int T, k;
string words[100];

bool isPalindrome(string word)
{
    for (int i = 0; i <= word.size() / 2; ++i)
    {
        if (word[i] != word[word.size() - 1 - i])
        {
            return false;
        }
    }

    return true;
}

string FindPalindrome()
{
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            if (i == j)
            {
                continue;
            }

            string word = words[i] + words[j];

            if (isPalindrome(word))
            {
                return word;
            }
        }
    }

    return "0";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> k;

        for (int i = 0; i < k; ++i)
        {
            cin >> words[i];
        }

        cout << FindPalindrome() << "\n";
    }

    return 0;
}