#include <iostream>
using namespace std;
int N;
int cnt[10001];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    while (N--)
    {
        int i;
        cin >> i;
        ++cnt[i];
    }

    for (int i = 0; i < 10001; ++i)
    {
        while (cnt[i]--)
        {
            cout << i << "\n";
        }
    }
    return 0;
}