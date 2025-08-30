#include <iostream>
#include <queue>
using namespace std;

int N, M, cnt;
string S;
queue<char> q;
bool hasChar[26];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        char c;
        cin >> c;
        q.push(c);
        hasChar[c - 'a'] = true;
    }

    for (int i = 0; i < N - 1; ++i)
    {
        q.push(q.front());
        q.pop();
    }

    cin >> M >> S;

    for (const char &c : S)
    {
        if (!hasChar[c - 'a'])
        {
            cout << -1;
            return 0;
        }
    }

    for (const char &c : S)
    {
        do
        {
            ++cnt;
            q.push(q.front());
            q.pop();
        } while (q.front() != c);
    }

    cout << cnt;
    return 0;
}
