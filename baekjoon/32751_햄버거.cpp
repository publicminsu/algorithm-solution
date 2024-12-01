#include <iostream>
using namespace std;
int N, cnt[4];
string S;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    for (int i = 0; i < 4; ++i)
    {
        cin >> cnt[i];
    }
    cin >> S;
}

bool solve()
{
    if (!(S.front() == S.back() && S.front() == 'a'))
    {
        return false;
    }

    for (int i = 0; i < N; ++i)
    {
        if (--cnt[S[i] - 'a'] < 0)
        {
            return false;
        }

        if (i > 0 && S[i] == S[i - 1])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    input();
    cout << (solve() ? "Yes" : "No");
    return 0;
}