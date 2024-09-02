#include <iostream>
using namespace std;

pair<string, string> table[] = {
    {"\\\\'", "w"},
    {"\\'", "v"},
    {"7", "t"},
    {"0", "o"},
    {"^", "n"},
    {";", "j"},
    {"!", "i"},
    {"[", "c"},
    {"@", "a"},
};

int N;
string str;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> str;

        int cnt = 0;

        for (const pair<string, string> &kv : table)
        {
            while (true)
            {
                auto idx = str.find(kv.first);

                if (idx == string::npos)
                {
                    break;
                }

                ++cnt;

                str.replace(idx, kv.first.size(), kv.second);
            }
        }

        bool isUnderstand = cnt * 2 < str.size();

        cout << (isUnderstand ? str : "I don't understand") << "\n";
    }
    return 0;
}