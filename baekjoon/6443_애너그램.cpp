#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int alpha[26];
string anagram, word;
void dfs()
{
    if (anagram.length() == word.length())
    {
        cout << anagram << "\n";
        return;
    }
    for (int i = 0; i < 26; ++i)
    {
        if (!alpha[i])
            continue;
        --alpha[i];
        anagram.push_back(i + 'a');
        dfs();
        anagram.pop_back();
        ++alpha[i];
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    while (N--)
    {
        memset(alpha, 0, sizeof(alpha));
        cin >> word;
        for (char c : word)
        {
            ++alpha[c - 'a'];
        }
        dfs();
    }
    return 0;
}