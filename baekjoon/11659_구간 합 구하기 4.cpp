#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, i, j;
    cin >> N >> M;
    vector<int> prefix(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> prefix[i];
        prefix[i] += prefix[i - 1];
    }
    while (M--)
    {
        cin >> i >> j;
        cout << prefix[j] - prefix[i - 1] << "\n";
    }
    return 0;
}