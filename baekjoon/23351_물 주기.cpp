#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K, A, B, day;
vector<int> v;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> K >> A >> B;
    v = vector<int>(N, K);

    while (v.front() > day)
    {
        for (int i = 0; i < A; ++i)
        {
            v[i] += B;
        }

        sort(v.begin(), v.end());
        ++day;
    }

    cout << day;
    return 0;
}