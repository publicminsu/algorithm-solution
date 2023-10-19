#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, A;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    cin >> N;
    while (N--)
    {
        cin >> A;
        cout << binary_search(v.begin(), v.end(), A) << "\n";
    }
    return 0;
}