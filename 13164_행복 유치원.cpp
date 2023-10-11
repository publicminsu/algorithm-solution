#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K, sum;
vector<int> v, gap;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    v = vector<int>(N);
    cin >> v[0];
    for (int i = 1; i < N; ++i)
    {
        cin >> v[i];
        gap.push_back(v[i] - v[i - 1]);
    }
    sort(gap.begin(), gap.end());
    while (--K)
        gap.pop_back();
    for (int i : gap)
        sum += i;
    cout << sum;
    return 0;
}