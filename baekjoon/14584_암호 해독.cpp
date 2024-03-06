#include <iostream>
#include <string>
#include <vector>
using namespace std;
string password;
vector<string> words;
int N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> password >> N;
    words = vector<string>(N);

    for (string &word : words)
    {
        cin >> word;
        for (int i = 0; i < 26; ++i)
        {
            for (char &c : word)
            {
                ++c;
                if (c > 'z')
                {
                    c = 'a';
                }
            }

            if (password.find(word) != string::npos) // 동일한 값을 찾으면
            {
                for (const char &c : password)
                {
                    cout << static_cast<char>(((c - 'a') - i + 25) % 26 + 'a');
                }
                return 0;
            }
        }
    }
    return 0;
}