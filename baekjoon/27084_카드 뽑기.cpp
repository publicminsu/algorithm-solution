#include <iostream>
using namespace std;
using ll = long long;
int N, A;
ll answer = 1;
int cnt[200001];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    while (N--)
    {
        cin >> A;
        ++cnt[A];
    }

    for (int i = 1; i < 200001; ++i)
    {
        answer = (answer * (cnt[i] + 1)) % 1000000007;
    }

    cout << answer - 1;
    return 0;
}