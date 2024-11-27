#include <iostream>
#include <vector>
using namespace std;
int N, cnt;
vector<int> v;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    v = vector<int>(N + 1);

    v[1] = ++cnt;
    for (int i = 2; i <= N; ++i)
    {
        if (v[i])
        {
            continue;
        }

        v[i] = ++cnt;

        for (int j = i + i; j <= N; j += i)
        {
            v[j] = cnt;
        }
    }

    cout << cnt << "\n";
    for (int i = 1; i <= N; ++i)
    {
        cout << v[i] << " ";
    }
    return 0;
}