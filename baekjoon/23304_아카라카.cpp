#include <iostream>
using namespace std;
string S;
bool isPalindrome(int start, int end)
{
    int len = end - start;
    int halfLen = len / 2;

    if (len == 1)
    {
        return true;
    }

    for (int i = 0; i < halfLen; ++i)
    {
        if (S[start + i] != S[end - i - 1])
        {
            return false;
        }
    }

    return isPalindrome(start, start + halfLen) && isPalindrome(end - halfLen, end);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> S;

    cout << (isPalindrome(0, S.size()) ? "AKARAKA" : "IPSELENTI");

    return 0;
}