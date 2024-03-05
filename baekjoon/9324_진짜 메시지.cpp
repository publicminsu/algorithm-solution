#include <iostream>
#include <cstring>
using namespace std;
int cnt[26];
int tc;
string message;
bool isFake()
{
    for (int i = 0; i < message.size(); ++i)
    {
        char c = message[i];
        if (++cnt[c - 'A'] == 3) // 3번 등장했는가?
        {
            if (i + 1 == message.size() || message[i + 1] != c) // 한 번 더 삽입 안됐는가?
            {
                return true;
            }
            cnt[c - 'A'] = 0;
            ++i;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> tc;
    while (tc--)
    {
        memset(cnt, 0, sizeof(cnt));
        cin >> message;
        cout << (isFake() ? "FAKE" : "OK") << "\n";
    }
    return 0;
}