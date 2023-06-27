#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, K, i, cnt = 0;
    cin >> N >> K;
    i = K - 1;
    vector<int> v(N);
    for (int i = 1; i <= N; ++i)
    {
        v[i - 1] = i;
    }
    cout << "<";
    while (v.size() > 1)
    {
        cout << v[i] << ", ";
        v.erase(v.begin() + i);
        i = (i + K - 1) % v.size();
    }
    cout << v[0] << ">";
    return 0;
}