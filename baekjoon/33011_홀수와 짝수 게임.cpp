#include <iostream>
using namespace std;
int T, N, A;
int cnt[2];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N;

        cnt[0] = cnt[1] = 0;

        while (N--)
        {
            cin >> A;
            ++cnt[A % 2];
        }

        if (cnt[0] > cnt[1])
        {
            swap(cnt[0], cnt[1]);
        }

        string name;
        if (cnt[1] % 2 && cnt[0] != cnt[1])
        {
            name = "amsminn";
        }
        else
        {
            name = "heeda0528";
        }
        cout << name << "\n";
    }
    return 0;
}