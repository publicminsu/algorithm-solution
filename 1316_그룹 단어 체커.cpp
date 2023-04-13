#include <iostream>
#include <string>
#include <cstring>
using namespace std;
bool ch[26];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    bool isGroup;
    int ret = 0, N;
    cin >> N;
    string word;
    while (N--)
    {
        cin >> word;
        memset(ch, false, sizeof(ch));
        ch[word[0] - 'a'] = true;
        isGroup = true;
        for (int i = 1; i < word.length(); ++i)
        {
            if (ch[word[i] - 'a'])
            {
                if (word[i - 1] != word[i])
                {
                    isGroup = false;
                    break;
                }
            }
            else
            {
                ch[word[i] - 'a'] = true;
            }
        }
        if (isGroup)
            ++ret;
    }
    cout << ret;
    return 0;
}
