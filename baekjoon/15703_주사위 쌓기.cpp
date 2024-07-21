#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int N, answer, nCount;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    v = vector<int>(N);

    for (int &i : v)
    {
        cin >> i;
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= N; ++i)
    {
        int count = 0;

        for (int j = 0; j < N; ++j)
        {
            if (count <= v[j])
            {
                ++count;
                ++nCount;

                v[j] = -1;
            }
        }

        if (nCount == N)
        {
            cout << i;
            break;
        }
    }
    return 0;
}