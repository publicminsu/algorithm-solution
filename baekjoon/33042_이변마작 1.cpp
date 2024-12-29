#include <iostream>
#include <map>
using namespace std;
int N;
map<string, int> cnt;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        string card;
        cin >> card;

        if (++cnt[card] > 4)
        {
            cout << i;
            return 0;
        }
    }

    cout << 0;
    return 0;
}