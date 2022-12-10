#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> v(N + 1);
    v[0] = v[1] = 0;
    for (int i = 2; i <= N; ++i)
    {
        if (i % 6 == 0)
            v[i] = min(min(v[i / 3] + 1, v[i / 2] + 1), v[i - 1] + 1);
        else if (i % 3 == 0)
            v[i] = min(v[i / 3] + 1, v[i - 1] + 1);
        else if (i % 2 == 0)
            v[i] = min(v[i / 2] + 1, v[i - 1] + 1);
        else
            v[i] = v[i - 1] + 1;
    }
    cout << v[N];
    return 0;
}