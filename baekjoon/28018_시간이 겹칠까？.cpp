#include <iostream>
using namespace std;
int N, S, E, Q, query;
int prefix[1000002];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> S >> E;
        ++prefix[S];
        --prefix[E + 1];
    }

    for (int i = 2; i < 1000001; ++i)
    {
        prefix[i] += prefix[i - 1];
    }

    cin >> Q;
    while (Q--)
    {
        cin >> query;
        cout << prefix[query] << "\n";
    }
    return 0;
}