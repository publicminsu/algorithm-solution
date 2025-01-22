#include <iostream>
using namespace std;
int N, K, idx, S;
char wheel[26], ch;
bool isUsed[26];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> K;

    for (char &c : wheel)
    {
        c = '?';
    }

    while (K--)
    {
        cin >> S >> ch;

        idx = (idx + S) % N;

        if (wheel[idx] == ch)
        {
            continue;
        }

        bool &check = isUsed[ch - 'A'];

        if (wheel[idx] != '?' || check)
        {
            cout << '!';
            return 0;
        }

        check = true;

        wheel[idx] = ch;
    }

    for (int i = idx; i >= 0; --i)
    {
        cout << wheel[i];
    }

    for (int i = N - 1; i > idx; --i)
    {
        cout << wheel[i];
    }
    return 0;
}