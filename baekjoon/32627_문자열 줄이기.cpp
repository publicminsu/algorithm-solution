#include <iostream>
using namespace std;
int N, M, cnt[26], skipCnt[26];
string S, answer;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> S;
    for (const char &c : S)
    {
        ++cnt[c - 'a'];
    }

    for (int i = 0; i < 26; ++i)
    {
        if (cnt[i] > M)
        {
            skipCnt[i] = M;
            break;
        }
        else
        {
            skipCnt[i] = cnt[i];
            M -= cnt[i];
        }
    }
}

void solve()
{
    for (const char &c : S)
    {
        if (skipCnt[c - 'a']-- > 0)
        {
            continue;
        }

        answer += c;
    }
    cout << answer;
}

int main()
{
    input();
    solve();
    return 0;
}