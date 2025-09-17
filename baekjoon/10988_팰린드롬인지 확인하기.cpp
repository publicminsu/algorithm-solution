#include <iostream>
using namespace std;

string str;

bool isPalindrome()
{
    for (int i = 0; i < str.size() / 2; ++i)
    {
        if (str[i] != str[str.size() - i - 1])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> str;
    cout << isPalindrome();
    return 0;
}