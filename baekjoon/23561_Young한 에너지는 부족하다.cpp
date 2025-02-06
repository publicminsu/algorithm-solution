#include <iostream>
#include <algorithm>
using namespace std;
int a[300000];
int N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N * 3; ++i)
    {
        cin >> a[i];
    }

    sort(a, a + N * 3);

    cout << a[N * 2 - 1] - a[N];
    return 0;
}