#include <iostream>
#include <string>
using namespace std;
string pikachu[] = {"pi", "ka", "chu"};
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string S;
    int idx = 0;
    cin >> S;
    while (idx < S.length())
    {
        bool isFind = false;
        for (int i = 0; i < 3; ++i)
        {
            string word = pikachu[i];
            int k = 0;
            for (int j = 0; j < word.length(); ++j)
            {
                int next = idx + j;
                if (S.length() <= next)
                    break;
                if (S[next] == word[j])
                    ++k;
            }
            if (k == word.length())
            {
                idx += word.length();
                isFind = true;
                break;
            }
        }
        if (!isFind)
            break;
    }
    if (idx == S.length())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}