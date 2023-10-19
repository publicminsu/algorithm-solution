#include <iostream>
#include <string>
using namespace std;
int prefix[200001][26], q, l, r;
string str;
char c;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> str;
    ++prefix[0][str[0] - 'a'];
    for (int i = 1; i < str.length(); ++i)
    {
        int k = str[i] - 'a';
        for (int j = 0; j < 26; ++j)
        {
            if (k != j)
                prefix[i][j] = prefix[i - 1][j];
            else
                prefix[i][j] = prefix[i - 1][j] + 1;
        }
    }
    cin >> q;
    while (q--)
    {
        cin >> c >> l >> r;
        int alpha = c - 'a', sum;
        if (l != 0)
            sum = prefix[r][alpha] - prefix[l - 1][alpha];
        else
            sum = prefix[r][alpha];
        cout << sum << "\n";
    }
    return 0;
}