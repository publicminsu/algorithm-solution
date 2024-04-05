#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, L, answer;
vector<int> v;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> L;

    v = vector<int>(N);
    for (int &i : v)
    {
        cin >> i;
    }

    sort(v.begin(), v.end());

    for (int i = 0, x = -L; i < N; ++i)
    {
        if (x < v[i])
        {
            ++answer;
            x = v[i] + L - 1;
        }
    }

    cout << answer;
    return 0;
}