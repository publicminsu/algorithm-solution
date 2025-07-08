#include <iostream>
#include <unordered_map>
using namespace std;

using ll = long long;

int N, K;
unordered_map<int, ll> cnts;
int prefix;
ll answer;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> K;

    cnts.reserve(N);
    cnts[0] = 1;

    while (N--)
    {
        int A;
        cin >> A;
        prefix += A;

        answer += cnts[prefix - K];
        ++cnts[prefix];
    }

    cout << answer;
    return 0;
}