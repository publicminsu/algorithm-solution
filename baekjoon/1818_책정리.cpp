#include <iostream>
#include <algorithm>
using namespace std;

int N;
int book;
int lisArr[200000], lis = 1;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> lisArr[0];

    for (int i = 1; i < N; ++i)
    {
        cin >> book;

        int idx = lower_bound(lisArr, lisArr + lis, book) - lisArr;

        lis = max(idx + 1, lis);
        lisArr[idx] = book;
    }

    cout << N - lis;
    return 0;
}