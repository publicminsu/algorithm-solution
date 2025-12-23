#include <iostream>

using namespace std;

string word;

char vowels[] = {'a', 'e', 'i', 'o', 'u'};
int cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> word;

    for (const char &c : word)
    {
        for (const char &vowel : vowels)
        {
            cnt += c == vowel;
        }
    }

    cout << cnt;
    return 0;
}