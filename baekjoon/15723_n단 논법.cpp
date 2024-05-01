#include <iostream>
using namespace std;
bool isTrue[26][26];
char a, b;
string is;
int n;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    while (n--)
    {
        cin >> a >> is >> b;

        isTrue[a - 'a'][b - 'a'] = true;
    }

    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            for (int k = 0; k < 26; ++k)
            {
                if (isTrue[j][k])
                {
                    continue;
                }

                isTrue[j][k] = isTrue[j][i] & isTrue[i][k];
            }
        }
    }

    cin >> n;
    while (n--)
    {
        cin >> a >> is >> b;

        cout << (isTrue[a - 'a'][b - 'a'] ? 'T' : 'F') << "\n";
    }
    return 0;
}