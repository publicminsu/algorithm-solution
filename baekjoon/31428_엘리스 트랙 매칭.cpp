#include <iostream>
using namespace std;
int cnt[26];
int N;
char c;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    while (N--)
    {
        cin >> c;
        ++cnt[c - 'A'];
    }

    cin >> c;
    cout << cnt[c - 'A'];
    return 0;
}